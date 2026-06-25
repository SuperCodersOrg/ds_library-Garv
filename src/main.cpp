#include <iostream>
#include <DynamicArray.h>
#include <SinglyList.h>
#include <HashMap.h>

using namespace std;

class a{
    public:
    int b;
    string c;
    a(int b,string c):b(b),c(c){}

    bool operator==(const a& other)
    {
        return this==&other;
    }
};

int main()
{
    cout<<"Hello";
    DynamicArray<int> d;
    cout<<endl;
    d.append(1);
    d.append(2);
    d.append(3);
    d.print();
    SinglyList<string> e;
    cout<<endl;
    e.append("hello");
    e.append("hi");
    e.append("bye");
    e.append("bye");
    e.print();
    HashMap<int,int> f;
    cout<<endl;
    f.insert(1,2);
    f.insert(2,3);
    f.insert(3,4);
    f.insert(4,5);
    f.insert(5,6);
    f.insert(6,7);
    f.debugPrint();
    a g(5,"garv");
    HashMap<a,int> map;
    cout<<endl;
    map.insert(g,1);
    map.debugPrint();
}