#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

lli countDigits(lli digits)
{
    return 9 * digits * pow(10, digits - 1);
}

lli findNumber(lli position)
{

    lli digits = 1;

    while (position > countDigits(digits))
    {
        position -= countDigits(digits);
        digits++;
    }

    lli number = pow(10, digits - 1) + (position - 1) / digits;

    lli digit_position = (position - 1) % digits;

    //string actualnumber = to_string(number);
    for (lli i = 0; i < digits - digit_position - 1; i++)
    {
        number /= 10;
    }

    return (number%10)  ;
}

int main()
{
    // Example usage
    lli testcases = 1;
    cin >> testcases;

    while (testcases--)
    {
        lli k;
        cin >> k;
        lli result = findNumber(k);
        cout << result << endl;
    }

    return 0;
}
