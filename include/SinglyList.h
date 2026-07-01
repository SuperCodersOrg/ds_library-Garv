#pragma once

#include <iostream>
#include <cstdlib>
#include <new>
#include <stdexcept>

using namespace std;

template<typename T>
class SinglyList {
        struct Node{
            T data;
            Node* next;
            Node(const T& value):data(value),next(nullptr){}
        };
        Node* head;
        Node* tail;
        int count;

//helper methods-  
        //allocate memory for a new node and create a new node
        Node* allocate(const T& value);
        //destruct a node
        void destruct(Node* node);
        //to reduce redudancy in constructors
        void init();
        //to deepcopy another linkedlist
        void deepcopy(const SinglyList& list);
    public:
    //constructors-
        //default
        SinglyList();
        //copy constructor
        SinglyList(const SinglyList& list);
        //helper function for assignment operator

        void swap(SinglyList& other);
        //assignment operator for a=b
        SinglyList& operator=(const SinglyList& list);

        //construct list from any iterable data structure
        template<typename Iterator>
        SinglyList(Iterator start, Iterator end);

    //methods - 
        //insert node at given index
        void insert( int index,const T& value);
        //to insert at end
        void append(const T& value);
        //insert at front
        void insertFront(const T& value);
        //remove at given index
        void remove(int index);
        //remove from front
        void removeFront();
        //to retrieve value safely
        bool get(int index,T& value) const;
        //search element and return index
        int search(const T& value) const;
        //delete all nodes
        void clear();
        //print all elements
        void print() const;
        //returns size of the linkedlist
        int size() const;
        //overloaded [] operator to access elements through it 
        T& operator[](int index);
        //const
        const T& operator[](int index) const;
        //check whether empty
        bool isEmpty() const;
        //destructor 
        ~SinglyList();
};

#include "../src/SinglyList.tpp"
