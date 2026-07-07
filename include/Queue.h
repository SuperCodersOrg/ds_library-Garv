#pragma once 

#include <SinglyList.h>

template<typename T>
class Queue{
    private:
        SinglyList<T> list;
    public:
        void enqueue(const T& value);
        T dequeue();
        T& front();
        const T& front()const;
        bool empty()const;
        int size()const;
        void clear();
};

#include "Queue.tpp"