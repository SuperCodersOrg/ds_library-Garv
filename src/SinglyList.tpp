#pragma once

#include <iostream>
#include <cstdlib>
#include <new>
#include <stdexcept>
#include <SinglyList.h>

using namespace std;
//helper methods - 

//allocate memory for a new node and create a new node
template<typename T>
typename SinglyList<T>::Node* SinglyList<T>::allocate(const T& value){
    void* raw = malloc(sizeof(Node));
    if(raw==nullptr)throw std::bad_alloc();
    try{
        return new(raw) Node(value);
    }
    catch(...){
        free(raw);
        throw;
    }
}

//destruct a node
template<typename T>
void SinglyList<T>::destruct(Node* node){
    if(node==nullptr)return;
    node->~Node();
    free(node);
}

//to reduce redudancy in constructors
template<typename T>
void SinglyList<T>::init(){
    head=nullptr;
    tail=nullptr;
    count=0;
}

//to deepcopy another linkedlist
template<typename T>
void SinglyList<T>::deepcopy(const SinglyList& list){
    init();
    //in case copy fails;
    try{
        Node* current = list.head;
        while(current)
        {
        Node* newnode = allocate(current->data);
        if(head==nullptr)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        count++;
        current=current->next;
        }
    }
    catch(...){
        clear();
        throw;
    }
}

//constructors-
template<typename T>
SinglyList<T>::SinglyList(){
    init();
}

//copy constructor
template<typename T>
SinglyList<T>::SinglyList(const SinglyList& list){
    deepcopy(list);
}

//helper function for assignment operator
template<typename T>
void SinglyList<T>::swap(SinglyList& other){
    Node* h=head;
    head=other.head;
    other.head=h;

    Node* t=tail;
    tail=other.tail;
    other.tail=t;

    int c=count;
    count=other.count;
    other.count=c;
}

//assignment operator for a=b
template<typename T>
SinglyList<T>& SinglyList<T>::operator=(const SinglyList& list){
    if(this==&list)return *this;
    SinglyList temp(list);
    swap(temp);
    //temp goes out of scope and temp list destructor runs
    return *this;
}

//construct list from any iterable data structure
template<typename T>
template<typename Iterator>
SinglyList<T>::SinglyList(Iterator start, Iterator end){
    init();
    try{
    for(auto it=start;it!=end;it++)
    {
        append(*it);
    }
    }
    catch(...)
    {
        clear();
        throw;
    }
}

//methods - 

//insert node at given index
template<typename T>
void SinglyList<T>::insert( int index,const T& value){
    if(index<0 || index>count)throw std::out_of_range("SinglyList:INVALID INDEX");
    Node* newnode = allocate(value);
    //if empty -1
    if(count==0)
    {
        head=tail=newnode;
    }
    //front -1
    else if(index==0)
    {
        newnode->next=head;
        head=newnode;
    }
    //end -1
    else if(index==count)
    {
        tail->next=newnode;
        tail=newnode;
    }
    //middle -n
    else
    {
        Node* temp= head;
        for(int i=0;i<index-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    count++;
}

//to insert at end
template<typename T>
void SinglyList<T>::append(const T& value){
    Node* newnode = allocate(value);
    if(head == nullptr)
    {
        head = tail = newnode;
    }
    else{
    tail->next=newnode;
    tail=newnode;
    }
    count++;
}

//insert at front
template<typename T>
void SinglyList<T>::insertFront(const T& value){
    Node* newnode = allocate(value);
    if(head==nullptr)head=tail=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
    count++;
}

//remove at given index
template<typename T>
void SinglyList<T>::remove(int index){
    if(index<0 || index>=count)throw std::out_of_range("SinglyList:INVALID INDEX");
    //singlenode
    if(count==1)
    {
        destruct(head);
        head=nullptr;
        tail=nullptr;
        count=0;
        return;
    }
    //remove front
    if(index==0)
    {
        Node* front = head;
        head = head->next;
        destruct(front);
        count--;
        return;
    }
    Node* temp = head;
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    Node* delnode = temp->next;
    temp->next = delnode->next;
    //move tail
    if(delnode == tail)tail=temp;
    destruct(delnode);
    count--;
}

//remove from front
template<typename T>
void SinglyList<T>::removeFront(){
    if(head == nullptr)throw std::out_of_range("EmptyList");
    if(count==1)
    {
        destruct(head);
        head=tail=nullptr; 
        count=0;
        return;
    }
    Node* front = head;
    head=head->next;
    destruct(front);
    count--;
}

//to retrieve value safely
template<typename T>
bool SinglyList<T>::get(int index,T& value) const{
    if(index<0 || index>=count)return false;
    Node* curr = head;
    for(int i=0;i<index;i++)
    {
        curr=curr->next;
    }
    value=curr->data;
    return true;
}

//search element and return index
template<typename T>
int SinglyList<T>::search(const T& value) const{
    Node* curr = head;
    int index=0;
    while(curr)
    {
        if(curr->data==value)return index;
        curr=curr->next;
        index++;
    }
    return -1;
}
        
//delete all nodes
template<typename T>
void SinglyList<T>::clear(){
    Node* current =head;
    while(current)
    {
        Node* next = current->next;
        destruct(current);
        current=next;
    }
    head=nullptr;
    tail=nullptr;
    count=0;
}

//print all elements
template<typename T>
void SinglyList<T>::print() const{
    Node* curr = head;
    while(curr){
        std::cout<<curr->data<<" ";
        curr=curr->next;
    }
    std::cout<<endl;
}

//returns size of the linkedlist
template<typename T>
int SinglyList<T>::size() const{
    return count;
}

//overloaded [] operator to access elements through it 
template<typename T>
T& SinglyList<T>::operator[](int index)
{
    if(index<0 || index>=count)throw std::out_of_range("SinglyList: INVALID INDEX");
    Node* curr = head;
    for(int i=0;i<index;i++)curr=curr->next;
    return curr->data;
}
//const
template<typename T>
const T& SinglyList<T>::operator[](int index) const
{
    if(index<0 || index>=count)throw std::out_of_range("SinglyList: INVALID INDEX");
    Node* curr = head;
    for(int i=0;i<index;i++)curr=curr->next;
    return curr->data;
}

//check whether empty
template<typename T>
bool SinglyList<T>::isEmpty() const{
    return head==nullptr;
}

//destructor 
template<typename T>
SinglyList<T>::~SinglyList(){
    clear();
}