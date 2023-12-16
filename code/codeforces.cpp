#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve()
{
    // cout<<"hello"<<endl;
    lli n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    lli flag = -1;
    lli i = 0;
    lli j = n - 1;
    lli count = 0;
    string rev;
    // Make T same as S
    /*
    abcde
    abxde
    */

    lli frontcnt = 0, reversecnt = 0;
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {

            frontcnt++;
        }
    }
    j = n - 1;
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[j])
        {
            j--;
            reversecnt++;
        }
        else
        {
            j--;
        }
    }
    // cout << frontcnt << " " << reversecnt << endl;
    /*
    hello
    olleo
    */
    i = 0;
    lli k = 0;
    string str = s2;
    lli ans = 2 * frontcnt - 1;
    if (frontcnt <= 1)
    {
        cout << frontcnt << endl;
        return;
    }
    if (reversecnt == 0)
    {
        cout << 0 << endl;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli testcases;
    cin >> testcases;
    while (testcases--)
    {
        solve();
    }
}
