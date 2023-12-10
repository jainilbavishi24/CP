#include <stdio.h>
#include <stdbool.h>

void printCycleNotation(int arr[], int n)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int start = i;
            int current = i;

            printf("%d", current + 1);
            visited[current] = true;

            do
            {
                current = arr[current] - 1;
                printf(" -> %d", current + 1);
                visited[current] = true;
            } while (current != start);
            printf(", ");
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    int permutation[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &permutation[i]);
    }
    printCycleNotation(permutation, n);
    return 0;
}
