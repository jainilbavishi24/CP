#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int cnt = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        cnt = 0;
        for (int e = 0; e < n; e++)
        {
            if (i & (1 << e))
            {
                cnt++;
            }
        }
        // printf("%d ", cnt);
       

            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    printf("%d ", arr[j]);
                }
            }
            printf("\n");
        
    }
}
