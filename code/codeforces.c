#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef long long lli;

lli max1(lli a, lli b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    lli t;
    scanf("%lld", &t);
    while (t--)
    {
        // lli n;
        // scanf("%lld", &n);
        // lli arr[n];
        // for (lli i = 0; i < n; i++)
        // {
        //     scanf("%lld", &arr[i]);
        // }
        // lli sum = arr[0];
        // lli max = INT_MIN; // 97 95 93 92 91
        // lli maxi=sum;
        // lli parity = abs(arr[0]) % 2;
        // for (lli i = 1; i < n; i++)
        // {
        //     if (arr[i] % 2 != parity)
        //     {
        //         sum += arr[i];
        //     }
        //     else
        //     {
        //         sum = arr[i];
        //     }
        //     if (sum < arr[i])
        //     {
        //         sum = arr[i];
        //     }

        //     maxi = max1(maxi, sum);
        //     parity = abs(arr[i]) % 2;
        // }
        lli n, b, sum = 0, max = INT_MIN, par = 0;
        scanf("%lld", &n);
        scanf("%lld", &b);
        sum = b;
        par = abs(b) % 2;
        max = sum;
        for (lli i = 1; i < n; i++)
        {
            scanf("%lld", &b);
            if (abs(b) % 2 != par)
            {
                sum += b;
            }
            else
            {
                sum = b;
            }
            if (b > sum)
            {
                sum = b;
            }
            par = abs(b) % 2;
            max = max1(sum, max);
        }
        printf("%lld\n", max);
        // return 0;
    }
}
