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
    FILE *file = fopen("history.txt", "a");
    if (file==NULL)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }
    fprintf(file, "LOG::%s %d\n", operation, check);
    fclose(file);
}
void write_to_history_for_history(char *operation)
{
    FILE *file = fopen("history.txt", "a");
    if (!file)
    {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }
    fprintf(file, "LOG::%s\n", operation);
    fclose(file);
}
int main()
{
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        char operation[20];
        int file;
        scanf("%s", operation);
        if (strcmp(operation, "history") == 0)
        {
            write_to_history_for_history(operation);
            FILE *file = fopen("history.txt", "r");
            if (file==NULL)
            {
                printf("ERROR: INVALID ARGUMENT\n");
                return 0;
            }
            char c[100];
            while (fgets(c, sizeof(c), file))
            {
                printf("%c", c);
            }
            fclose(file);
            continue;
        }
        scanf("%d", &file);
        write_to_history(operation, file);
        if (file == 0)
        {
            if (strcmp(operation, "add_matrix") == 0)
            {
                int n1, m1, n2, m2;
                scanf("%d %d", &n1, &m1);
                Matrix *A = create_matrix(n1, m1);
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < m1; j++)
                    {
                        scanf("%lld", &A->data[i][j]);
                    }
                }

                scanf("%d %d", &n2, &m2);
                Matrix *B = create_matrix(n2, m2);
                for (int i = 0; i < n2; i++)
                {
                    for (int j = 0; j < m2; j++)
                    {
                        scanf("%lld", &B->data[i][j]);
                    }
                }

                Matrix *result = add_matrix(A, B);
                if (result != NULL)
                {
                    print_matrix(result);
                    destroy_matrix(result);
                }

                destroy_matrix(A);
                destroy_matrix(B);
            }
            else if (strcmp(operation, "mult_matrix") == 0)
            {
                int n1, m1, n2, m2;
                scanf("%d %d", &n1, &m1);
                Matrix *A = create_matrix(n1, m1);
                for (int i = 0; i < n1; i++)
                {
                    for (int j = 0; j < m1; j++)
                    {
                        scanf("%lld", &A->data[i][j]);
                    }
                }

                scanf("%d %d", &n2, &m2);
                Matrix *B = create_matrix(n2, m2);
                for (int i = 0; i < n2; i++)
                {
                    for (int j = 0; j < m2; j++)
                    {
                        scanf("%lld", &B->data[i][j]);
                    }
                }

                Matrix *result = mult_matrix(A, B);
                if (result != NULL)
                {
                    print_matrix(result);
                    destroy_matrix(result);
                }

                destroy_matrix(A);
                destroy_matrix(B);
            }
            else if (strcmp(operation, "scalar_mult_matrix") == 0)
            {
                long long int s;
                scanf("%lld", &s);

                int n, m;
                scanf("%d %d", &n, &m);
                Matrix *M = create_matrix(n, m);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        scanf("%lld", &M->data[i][j]);
                    }
                }

                Matrix *result = scalar_mult_matrix(s, M);
                if (result != NULL)
                {
                    print_matrix(result);
                    destroy_matrix(result);
                }

                destroy_matrix(M);
            }
            else if (strcmp(operation, "transpose_matrix") == 0)
            {
                int n, m;
                scanf("%d %d", &n, &m);
                Matrix *A = create_matrix(n, m);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        scanf("%lld", &A->data[i][j]);
                    }
                }

                Matrix *result = transpose_matrix(A);
                if (result != NULL)
                {
                    print_matrix(result);
                    destroy_matrix(result);
                }

                destroy_matrix(A);
            }
            else if (strcmp(operation, "determinant") == 0)
            {
                int n, m;
                scanf("%d %d", &n, &m);

                if (n != m)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }

                Matrix *M = create_matrix(n, m);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        scanf("%lld", &M->data[i][j]);
                    }
                }

                int result = determinant(M);
                printf("%d\n", result);

                destroy_matrix(M);
            }

            else
            {
                printf("ERROR: INVALID ARGUMENT\n");
            }
        }
        else
        {
            if (strcmp(operation, "add_matrix") == 0)
            {
                char input_file_1[100], input_file_2[100], output_file[100];
                scanf("%s %s %s", input_file_1, input_file_2,output_file);
                Matrix *A = read_matrix_from_file(input_file_1);
                Matrix *B = read_matrix_from_file(input_file_2);
                Matrix *result = add_matrix(A, B);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                    // print_matrix(result);
                    // destroy_matrix(result);
                }
            }
            else if (strcmp(operation, "mult_matrix"))
            {
                char input_file_1[100], input_file_2[100], output_file[100];
                scanf("%s %s %s", input_file_1, input_file_2,output_file);
                Matrix *A = read_matrix_from_file(input_file_1);
                Matrix *B = read_matrix_from_file(input_file_2);
                Matrix *result = mult_matrix(A, B);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
            }
            else if (strcmp(operation, "scalar_mult_matrix"))
            {
                char input_file[100], output_file[100];
                long long int s;
                scanf("%lld %s %s", &s, input_file,output_file);
                Matrix *M = read_matrix_from_file(input_file);
                Matrix *result = scalar_mult_matrix(s, M);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
            }
            else if (strcmp(operation, "transpose_matrix"))
            {
                char input_file[100], output_file[100];
                scanf("%s", input_file);
                Matrix *A = read_matrix_from_file(input_file);
                Matrix *result = transpose_matrix(A);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
            }
            else if (strcmp(operation, "determinant"))
            {
                char input_file[100];
                scanf("%s", input_file);
                Matrix *M = read_matrix_from_file(input_file);
                int result = determinant(M);
                printf("%d\n", result);
                destroy_matrix(M);
            }
        }
    }
    return 0;
}
