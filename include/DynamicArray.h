    #pragma once

    #include <iostream>
    #include <cstdlib>
    #include <new>
    #include <stdexcept>

    template <typename T>
    class DynamicArray {
    private:
        int size_;
        int capacity_;
        T *data;
    //helper methods - 
        void destroy();//method to manually call destructors for each element in the array
        void copyelements(T* copyto,const T* copyfrom, int count);//internal method to copy elements from array into a new one (used in resize n deepcopy)
        void resize(int newcap);//internal method to resize the array whenever needed
        void deepcopy(const DynamicArray& other);//method to perform a deepcopy
        void init();//just to not repeat code in every constructor
        T* allocate(int cap);//function to call malloc and handle bad alloc exceptions as malloc does not throw an error but return a nullptr
        void construct(T* ptr,const T& value);//to construct an obj at the given ptr with the provided value
        void destroyobj(T* ptr);//destory a single object
    public:
    //constructors -
        DynamicArray();//default constructor
        DynamicArray(int count,const T& value = T());//to construct a Dynamic array of the given size with the all of them initialized to the same given value
        DynamicArray(const DynamicArray& other);//copy constructor to pass an array and make a copy

        void swap(DynamicArray& other);//helper function for =operator 
        DynamicArray& operator=(const DynamicArray&other);//assignment operator to use = operator to deepcopy that object

        template<typename Iterator>
        DynamicArray(Iterator start,Iterator end);//constructor to create a dynamic array from an iterable data structure if passed using begin,end addresses
        
        template<typename Ds>
        DynamicArray(const Ds& ds);//constructor to create a dynamic array from an iterable data structure if passed directly
        
    //methods - 
        void append(const T& value);//to add an element at the last index
        void clear();
        int size()const;//returns number of elements
        bool get(int index,T& value)const;//safe retrieval to elements at the given index
        void set(int index,const T& value);//to modify elements at the given index (parameter const to let Rvalue be passed to it too)
        void insert(int index,const T& value);//to insert an element to the given index
        void remove(int index);//to remove element from the given index 
        bool isEmpty()const;//to check if the array is empty
        void reserve(int newcap);//preallocate memory if needed without increasing size
        void shrinktosize();//to deallocate memory not in use to the size of the array        
        T& operator[](int index);//access elements using [] & is used to return a reference so using arr[10]=100 would be changeable
        const T& operator[](int index)const;//read only [] when const DA is used so it woudl return value in that case

        T* begin();//to return the starting address 
        const T* begin()const;

        T* end();//to return address of the location next of end
        const T* end()const;

    //testing purpose - 
        int capacity()const;//returns number if elements that can fit into the array
        void print()const;//prints all the elements in the existing array
        //destructor
        ~DynamicArray();
    };

#include "../src/DynamicArray.tpp"