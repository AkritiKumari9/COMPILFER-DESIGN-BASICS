
#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];

    // 1. Create & Write
    fp = fopen("file.txt", "w"); // "w" creates if not exist and writes
    if (fp == NULL)
    {
        printf("Cannot create file!\n");
        return 1;
    }
    fprintf(fp, "Hello, this is written to the file.\n");
    fclose(fp);
    printf("Data written to file.\n");

    // 2. Append
    fp = fopen("file.txt", "a"); // "a" appends to existing file
    fprintf(fp, "This line is appended.\n");
    fclose(fp);
    printf("Data appended to file.\n");

    // 3. Read
    fp = fopen("file.txt", "r"); // "r" reads file
    if (fp == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    printf("Reading file content:\n");
    while (fgets(data, sizeof(data), fp))
    {
        printf("%s", data);
    }
    fclose(fp);

    return 0;
}
