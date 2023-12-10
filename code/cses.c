#include <stdio.h>
int max1(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int findmaxsum(int arr[], int n)
{
    int max = arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];//1 2 3 -5 6  sum=6 max=6
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = findmaxsum(arr, n);
    printf("%d", max);
    return 0;
}

/*
prefixarray[n+1];
prefixarray[0] = arr[0];
for()
sum+=arr[i];
prefixarray[i]=sum;
int max=prefixsum[0];
int k(given)
for(int i=0;i<n-k;i++)
{
    if(prefixsum[i+k]-prefixsum[i])
}

*/


