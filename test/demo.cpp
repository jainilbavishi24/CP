  
    #include <iostream>
    // #include <stdio.h>
    // #include<bits/stdc++.h>
    // #include <vector>
    using namespace std;
    typedef long long lli;
    // code by JAINILaca
    int main()
    {
        lli t,i,n,m,k,H,V,c=0;
        cin>>t;
        // cin>>n;
        V=0;
        // cout<<t<<endl;
        // printf("%d\n",0);
        // scanf("%lld",&t);
        // cin>>t;
        for(i=0;i<t;i++)
        {
            cin>>n>>m>>k>>H;
        lli hn[n];
            for(lli j=0;j<n;j++)
            {
                cin>>hn[j];
                if(abs(hn[j]-H)%k==0&&abs(hn[j]-H)<=(m-1)*k &&abs(hn[j]-H)>0)
                c++;
            }
            cout<<c<<endl;
            c=0;
                
         }
            



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