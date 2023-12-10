#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex
{
    float *arr;
} com;

typedef struct result
{
    com arr[1000    ];
} result;

com addition(com c1, com c2, int n)
{
    com ans;
    ans.arr = (float *)(malloc(sizeof(float) * n));
    // ans.n = n;
    for (int i = 0; i < n; i++)
    {
        ans.arr[i] = c1.arr[i] + c2.arr[i];
    }
    return ans;
}

// com modulus(com c1, int n)
// {
//     com ans;
    
//     *ans.arr = 0;
    
//     for (int i = 0; i < n; i++)
//     {
//         float x= c1.arr[i];
//         *ans.arr = *ans.arr + x*x;

//     }
    
//     return ans;
// }

com subtract(com c1, com c2, int n)
{
    com ans;
    ans.arr = (float *)(malloc(sizeof(float) * n));
    for (int i = 0; i < n; i++)
    {
        ans.arr[i] = c1.arr[i] - c2.arr[i];
    }
    return ans;
}

com dot(com c1, com c2, int n)
{
    com ans;
    *ans.arr = 0;
    for (int i = 0; i < n; i++)
    {
        *ans.arr += c1.arr[i] * c2.arr[i];
    }
    return ans;
}

int main()
{
    result answer;
    int k = 0;
    com number;
    number.arr=(float*)(malloc(sizeof(float)*1000000));
    while (1)
    {
        com c1;
        com c2;

        char s[100];
        scanf("%s", s);
        if (strcmp(s, "-1") == 0)
        {
            break;
        }
        int n;
        scanf("%d", &n);
        c1.arr = (float *)(malloc(n * sizeof(float)));
        c2.arr = (float *)(malloc(n * sizeof(float)));

        if (strcmp(s, "ADD") == 0)
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &c1.arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &c2.arr[i]);
            }
            answer.arr[k] = addition(c1, c2, n);
            number.arr[k]=n;
        }
        // else if (strcmp(s, "MOD") == 0)
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         scanf("%f", &c1.arr[i]);
        //     }
        //     number.arr[k]=1;
        //     com ans=modulus(c1,n);
        //     // *ans.arr=sqrt(*ans.arr);
        //     answer.arr[k] =ans;
        // }
        else if (strcmp(s, "SUB") == 0)
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &c1.arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &c2.arr[i]);
            }
            answer.arr[k] = subtract(c1, c2, n);
            number.arr[k]=n;
        }
        else if (strcmp(s, "DOT") == 0)
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &c1.arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &c2.arr[i]);
            }
            answer.arr[k] = dot(c1, c2, n);
            number.arr[k]=1;
        }
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < number.arr[i]; j++)
        {
            printf("%0.2f ", answer.arr[i].arr[j]);
        }
        printf("\n");
    }
    
    
    return 0;
}