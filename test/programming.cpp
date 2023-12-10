    #include <iostream>
    #include <stdio.h>
    #include<bits/stdc++.h>
    #include <vector>
    using namespace std;
    typedef long long lli;
    // code by JAINIL
   
         

      
     int main()
     {
        string s;
        lli t;
        lli cA=0,cO=0,cB=0,cAB=0;
        cin>>t;
        while(t--)
        {
         cin>>s;
         for(int i=0;i<s.length();i++)
         {
            if('O'==s[i])
            cO++;
            if('A'==s[i])
            cA=cA+1;
            //cout<<cA<<endl;
            if('B'==s[i])
            cB++;
            
         }
         for(int i=0;i<s.length()-1;i++)
         {
            auto c3 = string(1,s[i])+s[i+1];
            if("AB"==c3)
            cAB++;

         }
         cout<<cO+max(cA,cB)+cAB<<endl;
         //cout<<cA;
        }
     }
     

     