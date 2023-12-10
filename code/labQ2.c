#include <stdio.h>
int binarysearch(long long int god[], long long int element, long long int low, long long int high) {
    while (low <= high) {
        long long int mid = low + (high - low) / 2;
        if (element == god[mid]) {
            return mid + 1;
        }
        if (element > god[mid] && element <= god[mid + 1]) {
            return mid + 2;
        }
        if (element > god[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


int main()
{
    long long int n, q;
    scanf("%lld%lld", &n, &q);
    long long int arr1[n]; // number of books in each box
    long long int arr2[q]; // real book labels of friend

    long long int god[n];
    long long int arr5[q];
    long long int i;
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr1[i]);
    }
    for (i = 0; i < q; i++)
    {
        scanf("%lld", &arr2[i]);
    }

    god[0] = arr1[0];
    for (i = 1; i < n; i++)
    {
        god[i] = god[i - 1] + arr1[i];
    }
    for (i = 0; i < q; i++)
    {

        arr5[i] = binarysearch(god, arr2[i], 0, n - 1);
    }
    for(i=0;i<q;i++)
    {
        if(arr5[i]==-1)
        {
            printf("%lld ",n+1);
        }
        else
        {
            printf("%lld ",arr5[i]);
        }
    }
    

    /*for(i=0;i<n;i++)
    {
     printf("%d\n",god[i]);
    }

    */
}