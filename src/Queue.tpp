#pragma once
#include <stdexcept>
#include "Queue.h"

template<typename T>
void Queue<T>::enqueue(const T& value)
{
    list.append(value);
}

template<typename T>
T Queue<T>::dequeue()
{
    if(list.isEmpty())throw std::out_of_range("Queue: Empty Queue");
    T value = list.front();
    list.removeFront();
    return value;
}

template<typename T>
T& Queue<T>::front()
{
    return list.front();
}

template<typename T>
const T& Queue<T>::front()const
{
    return list.front();
}

template<typename T>
bool Queue<T>::empty()const
{
    return list.isEmpty();
}

template<typename T>
int Queue<T>::size()const
{
    return list.size();
}

template<typename T>
void Queue<T>::clear()
{
    list.clear();
}
