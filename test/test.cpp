#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/allocator.h"
#include "../include/list.h"


TEST(Allocator, bad_alloc) {
 
    StaticStruct<1> resource; 
    std::pmr::polymorphic_allocator<int> allocator(&resource);
    
    EXPECT_THROW({
    auto itemP = allocator.allocate(10000);}, std::bad_alloc);
} 
 

TEST(Allocator, alloc_empty) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
 
    bool result = counter == 1; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(Allocator, alloc_some) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(2); 
    allocator.construct(itemP, &counter); 
    allocator.construct(itemP + 1, &counter); 
 
    bool result = counter == 2; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(Allocator, alloc_begin) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
    auto itemP2 = allocator.allocate(1); 
    allocator.construct(itemP2, &counter); 
     
    itemP->~Item(); 
    allocator.deallocate(itemP, 1); 
 
    auto itemP3 = allocator.allocate(1); 
    allocator.construct(itemP3, &counter); 
 
    bool result = counter == 2; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(Allocator, alloc_end) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
    auto itemP2 = allocator.allocate(1); 
    allocator.construct(itemP2, &counter); 
    auto itemP3 = allocator.allocate(1); 
    allocator.construct(itemP3, &counter); 
 
    bool result = counter == 3; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(Allocator, alloc_middle) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
    auto itemP2 = allocator.allocate(1); 
    allocator.construct(itemP2, &counter); 
    auto itemP3 = allocator.allocate(1); 
    allocator.construct(itemP3, &counter); 
 
    itemP2->~Item(); 
    allocator.deallocate(itemP2, 1); 
 
    auto itemP4 = allocator.allocate(1); 
    allocator.construct(itemP4, &counter); 
 
    bool result = counter == 3; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(Allocator, dealloc) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
 
    itemP->~Item(); 
    allocator.deallocate(itemP, 1); 
 
    bool result = counter == 0; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(Allocator, dealloc_some) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource;
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(5); 
 
    for (int i = 0; i < 5; i++) { 
        allocator.construct(itemP + i, &counter); 
    } 
 
    for (int i = 0; i < 5; i++) { 
        (itemP + i)->~Item(); 
    } 
 
    allocator.deallocate(itemP, 5); 
 
    bool result = counter == 0; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(ListTest, create_empty) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == true); 
} 
 
TEST(ListTest, push_back_not_empty) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_back(0); 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == false); 
}
 
TEST(ListTest, pop_back) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_back(6); 
    list.pop_back();
 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == true); 
} 

TEST(ListTest, push_front_not_empty) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_front(0); 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == false); 
}
 
TEST(ListTest, pop_front) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_front(1); 
    list.pop_front();
 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == true); 
} 

TEST(ListTest, iterators) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_back(0); 
    list.push_back(1); 
    list.push_back(2); 
 
    auto it = list.begin(); 
 
    bool correct = true; 
    correct = correct && *it == 0; 
    it++; 
    correct = correct && *it == 1; 
    it++; 
    correct = correct && *it == 2; 
    it++; 
    correct = correct && it == list.end(); 
 
    bool result = correct == true; 
 
    ASSERT_TRUE(result == true); 
} 
 

TEST(ListTest, empty_equal) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
    LinkedList<int> list2(allocator); 
 
    bool result = list == list2;

    ASSERT_TRUE(result == true); 
}


TEST(ListTest, equal) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
    LinkedList<int> list2(allocator);
 
    list.push_back(0); 
    list.push_back(1); 
    list.push_back(2);
    list.push_front(3);
 
    list2.push_back(0); 
    list2.push_back(1); 
    list2.push_back(2);
    list2.push_front(3);
 
    bool result = list == list2;
 
    ASSERT_TRUE(result == true); 
} 


TEST(ListTest, not_equal) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
    LinkedList<int> list2(allocator); 
 
    list.push_back(0); 
 
    list2.push_back(0);
    list2.push_back(3); 
 
    bool result = list != list2;
    
    ASSERT_TRUE(result == true); 
} 


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}