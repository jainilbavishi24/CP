#include <bits/stdc++.h>
typedef long long lli;

using namespace std;

void solve()
{
    lli n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> save(n);
    save[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        save[i] = max(save[i - 1], b[i]);
    }
    int loop;
    loop = min(k, n);
    int result = 0;
    int total = 0;
    for (lli i = 0; i < loop; i++)
    {
        total += a[i];
        int remesaveer = k - (i + 1);
        int current = total + remesaveer * save[i];
        result = max(result, current);
    }
    cout << result << endl;
}

int main()
{
    int testcases = 1;
    cin >> testcases;
    while (testcases--)
    {
        solve();
    }

    return 0;
}
