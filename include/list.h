#include <iostream>
#pragma once
#include <memory>

template <class T>
class LinkedList;

template <class T>
class ListIter;

template <class T>
class Node{
    private:
        T data;
        std::shared_ptr<Node<T>> next;

    public:    
        Node() : data(T()), next(nullptr) {}

        Node(const T& value) : data(value), next(nullptr) {}

        Node(const T& value, std::shared_ptr<Node<T>> nextNode) : data(value), next(nextNode) {}

        friend LinkedList<T>;
        friend ListIter<T>;
};


template <class T>
class ListIter {
    private:
        std::shared_ptr<Node<T>> current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        ListIter(std::shared_ptr<Node<T>> node = nullptr) : current(node) {}

        ListIter(const ListIter &other) : current(other.current) {}

        reference operator*() const {
            if (current == nullptr) {
                throw std::runtime_error("Dereferencing null iterator");
            }
            return current->data;
        }

        pointer operator->() const {
            if (current == nullptr) {
                throw std::runtime_error("Dereferencing null iterator");
            }
            return &(current->data);
        }

        ListIter& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        ListIter operator++(int) {
            ListIter temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ListIter& other) const {
            return current == other.current;
        }

        bool operator!=(const ListIter& other) const {
            return !(*this == other);
        }
};

template <class T>
using ListAllocator = std::pmr::polymorphic_allocator<Node<T>>;

template <class T>
class LinkedList {
    private:
        class DestructionStrategy {
                private:
                    ListAllocator<T> allocator;
                    
                public:
                    DestructionStrategy (ListAllocator<T> allocatorObject) : allocator{allocatorObject} {}

                    void operator() (Node<T> *ptr) {
                        ptr->~Node();
                        allocator.deallocate(ptr, 1);
                    }
        };
    ListAllocator<T> allocator;
    std::shared_ptr<Node<T>> head;

public:

    LinkedList(ListAllocator<T> allocatorObject) : allocator{allocatorObject} {
    }

    void push_front(const T& value) {
        auto nodeAll = allocator.allocate(1);
        allocator.construct(nodeAll, value, head);
        std::shared_ptr<Node<T>> newNode(nodeAll, DestructionStrategy(allocator));
        head = newNode;
    }

    void pop_front() {
        if (head) {
            std::shared_ptr<Node<T>> temp = head;
            head = std::move(head->next);
        }
    }
    void push_back(const T& value) {
        auto nodeAll = allocator.allocate(1);
        allocator.construct(nodeAll, value, nullptr);
        std::shared_ptr<Node<T>> newNode(nodeAll, DestructionStrategy(allocator));
        if (head){
        std::shared_ptr<Node<T>> it = head;
        for (; it->next != nullptr; it = it->next);
        it->next = newNode;}
        else head = newNode;

    }
    void pop_back() {
        if (head) {
        std::shared_ptr<Node<T>> it = head;
        if (it->next == nullptr) {
            head.reset();
            head = nullptr;
            return;
        }
        for (; it->next->next != nullptr; it = it->next);
            it->next.reset();
            it->next = nullptr;
        }
    }

    ListIter<T> begin() const {
        return ListIter<T>(head);
    }

    ListIter<T> end() const {
        return ListIter<T>(nullptr);
    }

    T front() const {
        if (head) {
            return head->data;
        }
        throw std::runtime_error("List is empty");
    }

    bool empty() const {
        return head == nullptr;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    void print() const {
        std::shared_ptr<Node<T>> current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool operator==(const LinkedList& other) const {
        auto it2 = other.begin();
        for (auto it = begin(); it != end(); it++){
            if(it2 == other.end()) return false;
            if(*it != *it2) return false;
            it2++;
        }
        if(it2 != other.end()) return false;
        return true;
    }

    bool operator!=(const LinkedList& other) const {
        return !(*this == other);
    }
};
