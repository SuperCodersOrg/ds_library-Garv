#include <iostream>
#include <DynamicArray.h>
using namespace std;

int main()
{
    cout<<"Hello";
    DynamicArray<int> d;
    d.append(1);
    d.append(2);
    d.append(3);
    d.print();
}