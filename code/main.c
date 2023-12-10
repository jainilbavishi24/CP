#include "matrix.h"

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
            FILE *file = fopen("mx_history", "r");
            if (file == NULL)
            {
                printf("ERROR: INVALID ARGUMENT\n");
                return 0;
            }
            char c;
            do
            {
                c = fgetc(file);
                if(c == EOF)
                {
                    break;
                }
                printf("%c", c);
            } while (1);

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

                Matrix *M = create_matrix(n, m);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        scanf("%lld", &M->data[i][j]);
                    }
                }
                if (n != m)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    destroy_matrix(M);
                    continue;
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
                // printf("hello\n");
                char input_file_1[100], input_file_2[100], output_file[100];
                scanf("%s %s %s", input_file_1, input_file_2, output_file);
                Matrix *A = read_matrix_from_file(input_file_1);
                if (A == NULL)
                {
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *B = read_matrix_from_file(input_file_2);
                if (A == NULL || B == NULL)
                {
                    if (A != NULL)
                    {
                        destroy_matrix(A);
                    }
                    if (B != NULL)
                    {
                        destroy_matrix(B);
                    }
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *result = add_matrix(A, B);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
                destroy_matrix(A);
                destroy_matrix(B);
            }
            else if (strcmp(operation, "mult_matrix") == 0)
            {
                // printf("hello\n");
                char input_file_1[100], input_file_2[100], output_file[100];
                // printf("hello\n");
                scanf("%s %s %s", input_file_1, input_file_2, output_file);
                Matrix *A = read_matrix_from_file(input_file_1);
                if (A == NULL)
                {
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *B = read_matrix_from_file(input_file_2);
                if (A == NULL || B == NULL)
                {
                    if (A != NULL)
                    {
                        destroy_matrix(A);
                    }
                    if (B != NULL)
                    {
                        destroy_matrix(B);
                    }
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *result = mult_matrix(A, B);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
                destroy_matrix(A);
                destroy_matrix(B);
            }
            else if (strcmp(operation, "scalar_mult_matrix") == 0)
            {
                char input_file[100], output_file[100];
                long long int scalar;
                scanf("%lld %s %s", &scalar, input_file, output_file);
                Matrix *M = read_matrix_from_file(input_file);
                if (M == NULL)
                {
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *result = scalar_mult_matrix(scalar, M);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
                destroy_matrix(M);
            }
            else if (strcmp(operation, "transpose_matrix") == 0)
            {
                char input_file[100], output_file[100];
                scanf("%s %s", input_file, output_file);
                Matrix *A = read_matrix_from_file(input_file);
                if (A == NULL)
                {
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *result = transpose_matrix(A);
                if (result != NULL)
                {
                    write_matrix_to_file(output_file, result);
                    destroy_matrix(result);
                }
                destroy_matrix(A);
            }
            else if (strcmp(operation, "determinant") == 0)
            {
                char input_file[100];
                scanf("%s", input_file);
                Matrix *M = read_matrix_from_file(input_file);
                if (M == NULL)
                {
                    // destroy_matrix(M);
                    // printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                if (M->num_rows != M->num_cols)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    destroy_matrix(M);
                    continue;
                }
                int result = determinant(M);
                printf("%d\n", result);
                destroy_matrix(M);
            }
        }
    }
    return 0;
}