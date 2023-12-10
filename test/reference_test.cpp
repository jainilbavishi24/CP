  
   

#include <iostream>
using namespace std;
int main()
{
   int a=4,b=6;
   int *p=&a;
   int &p1=a;
   cout<<p<<" "<<p1<<endl;
   p=&b;
    p1=b; //a = b
   b = 12;
   cout<<*p<<" "<<a<<endl;



}     
//g++ -o .\exe\jainil.exe .\test\helloworld.cpp
//>.\exe\jainil.exe
