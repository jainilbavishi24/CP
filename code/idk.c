#include <stdio.h>

void printSubsets(int arr[], int n, int k, int index, int subset[], int subsetSize)
{
    if (subsetSize == k)
    {
        
        printf("{");
        for (int i = 0; i < k; i++)
        {
            printf("%d", subset[i]);
            if (i < k - 1)
            {
                printf(", ");
            }
        }
        printf("}\n");
        return;
    }

    if (index == n)
    {
        return;
    }

   
    subset[subsetSize] = arr[index];
    printSubsets(arr, n, k, index + 1, subset, subsetSize + 1);

   
    printSubsets(arr, n, k, index + 1, subset, subsetSize);
}

int main()
{
    int n, k;

    // Input the values of n and k
    // printf("Enter the value of n: ");
    scanf("%d", &n);
    // printf("Enter the value of k: ");
    scanf("%d", &k);

    int arr[n];

    // Input the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int subset[k];

    // Print all subsets of size k
    // printf("Subsets of size %d are:\n", k);
    printSubsets(arr, n, k, 0, subset, 0);

    return 0;
}
