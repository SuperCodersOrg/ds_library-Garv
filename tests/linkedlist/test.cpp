#include <iostream>
#include <SinglyList>
using namespace std;
int main()
{
    try{
    SinglyList<string> l;
    l.insert(0,"garv");
    l.insert(0,"niles");
    l.insert(1,"anmol");
    l.insert(3,"bhupinder");
    l.print();
    std::cout<<l.size()<<endl;
    l.remove(4);
    l.print();
    }
    catch(...){
        cout<<"Error : "<<"out of bound"<<endl;
    }

}