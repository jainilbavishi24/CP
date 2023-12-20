#include <bits/stdc++.h>
using namespace std;

int RoundOff(int number, int roundoffValue)
{
    int temp = number % roundoffValue;
    int modifiedNumber = (number/roundoffValue)*roundoffValue;
    if(roundoffValue/2 <=  temp)
    {
        modifiedNumber += roundoffValue;
    }
    return modifiedNumber;
}

int main()
{
    int roundOffNumber = RoundOff(3451,1000);
    cout << "The rounded off value of 154 is: "<< roundOffNumber << endl;
}