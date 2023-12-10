#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix
{
    int num_rows;
    int num_cols;
    long long int **data;
} Matrix;

Matrix *create_matrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int **)calloc(r, sizeof(long long int *));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (long long int *)calloc(c, sizeof(long long int));
    }
    return m;
}

void destroy_matrix(Matrix *m)
{
    for (int i = 0; i < m->num_rows; i++)
    {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix *add_matrix(Matrix *A, Matrix *B)
{
    if (A->num_rows != B->num_rows || A->num_cols != B->num_cols)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;
    }

    Matrix *result = create_matrix(A->num_rows, A->num_cols);

    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < A->num_cols; j++)
        {
            result->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }

    return result;
}

Matrix *mult_matrix(Matrix *A, Matrix *B)
{
    if (A->num_cols != B->num_rows)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;
    }

    Matrix *result = create_matrix(A->num_rows, B->num_cols);

    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < B->num_cols; j++)
        {
            for (int k = 0; k < A->num_cols; k++)
            {
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return result;
}

Matrix *scalar_mult_matrix(long long int s, Matrix *M)
{
    Matrix *result = create_matrix(M->num_rows, M->num_cols);

    for (int i = 0; i < M->num_rows; i++)
    {
        for (int j = 0; j < M->num_cols; j++)
        {
            result->data[i][j] = s * M->data[i][j];
        }
    }

    return result;
}

Matrix *transpose_matrix(Matrix *A)
{
    Matrix *result = create_matrix(A->num_cols, A->num_rows);

    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < A->num_cols; j++)
        {
            result->data[j][i] = A->data[i][j];
        }
    }

    return result;
}

long long int determinant(Matrix *M)
{
    if (M->num_rows != M->num_cols)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return -1;
    }

    int n = M->num_rows;
    long long int det = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            while (M->data[j][i] != 0)
            {
                long long int ratio = M->data[i][i] / M->data[j][i];
                for (int k = 0; k < n; k++)
                {
                    M->data[i][k] -= ratio * M->data[j][k];
                }
                for (int k = 0; k < n; k++)
                {
                    M->data[i][k] ^= M->data[j][k] ^= M->data[i][k] ^= M->data[j][k];
                }
                det *= -1;
            }
        }
        det *= M->data[i][i];
    }

    return det;
}

void print_matrix(Matrix *m)
{
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int q;
    scanf("%d", &q);
    char operation[100];
    
    for (int i = 0; i < q; i++)
    {
        int check;
        scanf("%s %d", operation, check);
        if(strcmp(operation,"add_matrix")==0)
            {
                char input_file_1[100],input_file_2[100],output_file[100];
                scanf("%s %s",input_file_1,input_file_2);
                Matrix *A=read_matrix(input_file_1);
                Matrix *B=read_matrix(input_file_2);
                Matrix *result=add_matrix(A,B);
                if(result!=NULL)
                {
                    write_matrix(output_file,result);
                    destroy_matrix(result);

                }
            }
            else if(strcmp(operation,"mult_matrix"))
            {
                char input_file_1[100],input_file_2[100],output_file[100];
                scanf("%s %s",input_file_1,input_file_2);
                Matrix *A=read_matrix(input_file_1);
                Matrix *B=read_matrix(input_file_2);
                Matrix *result=mult_matrix(A,B);
                if(result!=NULL)
                {
                    write_matrix(output_file,result);
                    destroy_matrix(result);

                }
            }
            else if(strcmp(operation,"scalar_mult_matrix"))
            {
                char input_file[100],output_file[100];
                long long int s;
                scanf("%lld %s",&s,input_file);
                Matrix *M=read_matrix(input_file);
                Matrix *result=scalar_mult_matrix(s,M);
                if(result!=NULL)
                {
                    write_matrix(output_file,result);
                    destroy_matrix(result);

                }
            }
            else if(strcmp(operation,"transpose_matrix"))
            {
                char input_file[100],output_file[100];
                scanf("%s",input_file);
                Matrix *A=read_matrix(input_file);
                Matrix *result=transpose_matrix(A);
                if(result!=NULL)
                {
                    write_matrix(output_file,result);
                    destroy_matrix(result);

                }
            }
            else if(strcmp(operation,"determinant"))
            {
                char input_file[100];
                scanf("%s",input_file);
                Matrix *M=read_matrix(input_file);
                int result=determinant(M);
                printf("%d\n",result);
                destroy_matrix(M);
            }

        }
        return 0;
}
   