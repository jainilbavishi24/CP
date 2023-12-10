#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main()
{
    lli n, m;
    cin >> n >> m;
    vector<lli> h;
    vector<lli> t;
    for (int i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        h.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        lli x;
        cin >> x;
        t.push_back(x);
    }
    sort(h.begin(), h.end());
    // sort(t,t+m);
    int j=0;
    for(int i=0;i<m;i++)
    {
        if(t[j]<=h[i])
        {
            t[j]=h[i];
            vector<lli>::iterator it = h.begin()+i;
            h.erase(it);    
            int j=0;

        }
        if(j==t.size())
            h[j]=-1;
        else
        {
            j++;
            i--;
        }
        
            


    }
    for(int i=0;i<n;i++)
        cout<<h[i]<<" ";

        /*10 15
    9 8 8 9 10 8 5 8 7 10

    5 7 8 8 8 8 9 9 10 10
    */

        return 0;
}