#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k, m = 0;

int result[1001] = {0};
long long devil[1001][1001];
int answer[1001][1001];
unsigned long long memo[1001][1001];

unsigned long long knightmare(int n, int m, int i, int j)
{
    if (i == 1)
    {
        return 1;
    }

    if (memo[i][j] != -1&&devil[i][j]!=1)
    {
        return memo[i][j];
    }

    unsigned long long paths = 0;

    if (devil[i - 2][j + 1] != 1 && i - 2 >= 1&&i-2<=n && j+1>=1&&j + 1 <= m)
    {
        paths += knightmare(n, m, i - 2, j + 1);
    }

    if (devil[i - 1][j + 2] != 1 && i - 1 >= 1 && j + 2 <= m&&j+2>=1&&i-1<=n)
    {
        paths += knightmare(n, m, i - 1, j + 2);
    }

    if (devil[i - 2][j - 1] != 1 && i - 2 >= 1 && j - 1 >= 1&&j-1<=m&&i-2<=n)
    {
        paths += knightmare(n, m, i - 2, j - 1);
    }

    if (devil[i - 1][j - 2] != 1 && i - 1 >= 1 && j - 2 >= 1&&j-2<=m&&i-1<=n)
    {
        paths += knightmare(n, m, i - 1, j - 2);
    }
    paths = paths % 1000000007;
    memo[i][j] = paths;
    return paths;
}

int main()
{
    int n;
    scanf("%d %d %d", &n, &m, &k);
    if(n<=2&&m<=2){
        for(int i=1;i<=m;i++)
        {
            printf("0 ");
        }
        return 0;
    }
    memset(memo, -1, sizeof(memo));

    for (int i = 1; i <= k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        devil[x][y] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        unsigned long long paths = knightmare(n, m, n, i);
        paths = paths % 1000000007;
        printf("%llu \n", paths);
    }

    return 0;
}