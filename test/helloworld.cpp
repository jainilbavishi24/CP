  
    #include <iostream>
    #include <stdio.h>
    #include<bits/stdc++.h>
    #include <vector>
    using namespace std;
    typedef long long lli;
    // code by JAINIL
    int main()
{
    lli t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        string s = ""; // Initialize an empty string for the binary representation
        
        // Handle the case when n is 0 separately
        if (n == 0)
        {
            s = "0";
        }
        else
        {
            while (n != 0)
            {
                char d = '0' + (n % 2); // Convert the remainder to a character
                s = d + s; // Prepend the character to the binary string
                n = n / 2;
            }
        }
        
        cout << s << endl; // Print the binary representation
    }

    return 0;
}
        
    
    /*int main()
    {
    const double pi=3.14;
    const double *cptr=&pi;
    cout<<cptr<<endl;
    double dval=3.14;
    cptr=&dval;
    cout<<cptr<<endl;

    }
    /*int main()
    {


    int a=4,b=6;
    int *p=&a;
    int* p2=&a;
    int &p1=a; 
    cout<<p<<" "<<p2<<" "<<p1<<endl;
    p=&b;
    p1=b;
    cout<<p<<" "<<p1<<endl;

    }
    
    
/*#include <iostream>
using namespace std;
int main()
{
   int a=4,b=6;
   int *p=&a;
   int &p1=a;
   cout<<p<<" "<<p1<<endl;
   p=&b;
   p1=b;
   cout<<p<<" "<<p1<<endl;



}     
//g++ -o .\exe\jainil.exe .\test\helloworld.cpp
//>.\exe\jainil.exe

#include<iostream>
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int e=0,o=0,i=0,x,n;
        cin>>n;
        for(;(++i)<=n;)
        {
            cin>>x;
            (x&1)?o+=x:e+=x;
        }
        cout<<(e>o?"yes":"no")<<'\n';}}
*/