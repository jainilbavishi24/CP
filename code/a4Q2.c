#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct complexnumbers
{
    float *c1;
    float *c2;
} complexnumbers;

typedef struct result
{
    float *res;
} result;

void ADD(complexnumbers *c, result *r, int n)
{
    for (int i = 0; i < n; i++)
    {
        r->res[i] = c->c1[i] + c->c2[i];
    }
}

void SUB(complexnumbers *c, result *r, int n)
{
    for (int i = 0; i < n; i++)
    {
        r->res[i] = c->c1[i] - c->c2[i];
    }
}

float DOT(complexnumbers *c, int n)
{
    float ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += c->c1[i] * c->c2[i];
    }
    return ans;
}

float magnitude(float *c, int n)
{
    float mag = 0;
    for (int i = 0; i < n; i++)
    {
        mag += c[i] * c[i];
    }
    return sqrt(mag);
}

float cosineSimilarity(complexnumbers *c, int n)
{
    float dot = DOT(c, n);
    float mag_c1 = magnitude(c->c1, n);
    float mag_c2 = magnitude(c->c2, n);

    return dot / (mag_c1 * mag_c2);
}

int main()
{
    while(1)
    {
        char choice[10];
        printf("Enter the operation to perform (ADD, SUB, DOT, COSINE, -1 for EXIT): ");
        scanf("%s", choice);

        if (strcmp(choice, "-1") == 0) {
            break;
        }

        int n;
        printf("Enter the dimension of the complex numbers: ");
        scanf("%d", &n);

        complexnumbers cn;
        result res;

        cn.c1 = (float *)malloc(n * sizeof(float));
        cn.c2 = (float *)malloc(n * sizeof(float));
        res.res = (float *)malloc(n * sizeof(float));

        printf("Enter %d float values for the first complex number: ", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%f", &cn.c1[i]);
        }

        printf("Enter %d float values for the second complex number: ", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%f", &cn.c2[i]);
        }

        if (strcmp(choice, "ADD") == 0)
        {
            ADD(&cn, &res, n);
            printf("Addition Result:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%0.2f ", res.res[i]);
            }
        }
        else if (strcmp(choice, "SUB") == 0)
        {
            SUB(&cn, &res, n);
            printf("Subtraction Result:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%0.2f ", res.res[i]);
            }
        }
        else if (strcmp(choice, "DOT") == 0)
        {
            printf("Dot Product Result: %0.2f\n", DOT(&cn, n));
        }
        else if (strcmp(choice, "COSINE") == 0)
        {
            printf("Cosine Similarity Result: %0.2f\n", cosineSimilarity(&cn, n));
        }
        else
        {
            printf("Invalid choice\n");
        }

        free(cn.c1);
        free(cn.c2);
        free(res.res);
    }

    return 0;
}
