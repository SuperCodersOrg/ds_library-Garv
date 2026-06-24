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
    
}