#include "matrix.h"

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

    int n = M->num_rows;

    if (n == 1)
    {
        return M->data[0][0];
    }

    long long int det = 0;
    Matrix *submatrix = create_matrix(n - 1, n - 1);

    for (int i = 0; i < n; i++)
    {
        int sub_i = 0;
        for (int j = 1; j < n; j++)
        {
            int sub_j = 0;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    submatrix->data[sub_i][sub_j] = M->data[j][k];
                    sub_j++;
                }
            }
            sub_i++;
        }
        int sign = (i % 2 == 0) ? 1 : -1;
        det += sign * M->data[0][i] * determinant(submatrix);
    }

    destroy_matrix(submatrix);
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
Matrix *read_matrix_from_file(char *file_name)
{
    FILE *file = fopen(file_name, "r+");
    if (file == NULL)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;
    }

    int num_rows, num_cols;
    fscanf(file, "%d %d", &num_rows, &num_cols);

    Matrix *m = create_matrix(num_rows, num_cols);

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            fscanf(file, "%lld", &m->data[i][j]);
        }
    }

    fclose(file);
    return m;
}

void write_matrix_to_file(char *file_name, Matrix *m)
{
    FILE *file = fopen(file_name, "w+");
    if (file == NULL)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }

    fprintf(file, "%d %d\n", m->num_rows, m->num_cols);

    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            fprintf(file, "%lld ", m->data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
void write_to_history(char *operation, int check)
{
    FILE *file = fopen("mx_history", "a");
    if (file == NULL)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }
    fprintf(file, "LOG::%s %d\n", operation, check);
    fclose(file);
}
void write_to_history_for_history(char *operation)
{
    FILE *file = fopen("mx_history", "a");
    if (file == NULL)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }
    fprintf(file, "LOG::%s\n", operation);
    fclose(file);
}