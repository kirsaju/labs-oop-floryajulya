#pragma once
#include <iostream>
#include <memory>
#include <memory_resource>
#include <exception>
#include "map"

template <size_t sizePool>
class StaticStruct : public std::pmr::memory_resource
{
    private:
        unsigned char pool[sizePool];
        std::map<unsigned char*, size_t> allocatedBlocks;
    public:
        void *do_allocate(size_t bytes, size_t alignment) override{
        if (bytes > sizePool) throw std::bad_alloc();
        if(allocatedBlocks.empty() && (bytes <= sizePool)){
            allocatedBlocks[pool] = bytes;
        //    std::cout << "Alloc: " << static_cast<void*>(pool) << std::endl;
            return pool;}
        if(allocatedBlocks.begin()->first - pool >= bytes){
            allocatedBlocks[pool] = bytes;
    //        std::cout << "Alloc: " << static_cast<void*>(pool) << std::endl;
            return pool;
            }
        for (auto it = allocatedBlocks.begin(); it != --allocatedBlocks.end(); ++it){
            unsigned char* endFirstBlock = it->first + it->second;
            if(std::next(it)->first - endFirstBlock >= bytes){
                allocatedBlocks[endFirstBlock] = bytes;
    //            std::cout << "Alloc: " << static_cast<void*>(endFirstBlock) << std::endl;
                return endFirstBlock;
            }}
        auto lastBlock = --allocatedBlocks.end();
        if(pool + sizePool - (lastBlock->first + lastBlock->second)){
        allocatedBlocks[lastBlock->first + lastBlock->second] = bytes;
    //    std::cout << "Alloc: " << static_cast<void*>(lastBlock->first + lastBlock->second) << std::endl;
        return lastBlock->first + lastBlock->second;
        }
        throw std::bad_alloc();
    }
    
    void do_deallocate(void *ptr, size_t bytes, size_t alignment) override
    {
        unsigned char* block = static_cast<unsigned char*>(ptr);
        if (allocatedBlocks.contains(block)){
        //    std::cout << "dealloc: " << ptr << std::endl;
            allocatedBlocks.erase(block);
            return;
        }
        throw std::logic_error("Failed delete, block isn't exist");
    }
    
    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override
    {
        return this == &other;
    }
};