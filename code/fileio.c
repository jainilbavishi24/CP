#include <stdio.h>
#include <stdlib.h>
int main()
{
    // File pointer
    FILE *fp;

    // Opening a file for writing
    fp = fopen("C:\\Users\\bavis\\OneDrive\\Desktop\\CP\\code\\input.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    // Writing to the file using fputs and fprintf
    fputs("Hello, World!\n", fp);
    fprintf(fp, "This is a test.\n");

    // Closing the file
    fclose(fp);

    // Opening the file for reading
    fp = fopen("C:\\Users\\bavis\\OneDrive\\Desktop\\CP\\code\\input.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    char buffer[100];

    // Reading from the file using fgets
    while (fgets(buffer, sizeof(buffer), fp))
    {
        printf("%s", buffer);
    }

    // Closing the file
    fclose(fp);

    return 0;
}
