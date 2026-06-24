#include <iostream>
#include <HashMap>

using namespace std;

int main()
{   //functor

    struct IntHash
    {
        size_t operator()(int key) const{
            return key*31;
        }
    };

    HashMap<int,int,IntHash> map;
    map.insert(10,100);
    map.insert(20,200);
    map.insert(30,300);
    map.insert(40,400);
    map.insert(50,500);
    cout<<map.size()<<'\n';
    map.debugPrint();
    
    HashMap<int,std::string,IntHash> map1;
    map1.insert(1,"Garv");
    map1.insert(2,"Nilesh");
    map1.insert(1,"M");
    string x,y,z;
    cout<<map1.get(1,x)<<x;
    cout<<endl;
    cout<<map1.get(2,y)<<y;
    cout<<endl;
    cout<<map1.get(30,z)<<z;
    cout<<endl;

}