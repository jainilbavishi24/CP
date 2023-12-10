#include <stdio.h>
#include <string.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
void find(char S[])
{
    int i = 0;
    int freq[26] = {0};
    while (S[i] != '\0')
    {
        freq[S[i] - 'a']++;
        i++;
    }
    selectionSort(freq, 26);
    // for(int i=0;i<26;i++){
    printf("%d", freq[25]);
    //}
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char str[n + 1];
    char cnt[n + 1];
    int c = 0;
    int flag = 0;
    int i = 0;
    scanf("%s", str);
    if (k == 1)
    {
        find(str);
    }
    if (k != 1)
    {
        while ((c < k) && (i < n - 1) && (k != 1))
        {
            if (str[i] == str[i + 1])
            {
                c++;
                i++;
                if (c == (k - 1))
                {
                    c = 0;
                    cnt[flag] = str[i];
                    i++;
                    flag++;
                }
            }
            else
            {
                i++;
            }
        }
        find(cnt);
    }
    return 0;
}