#include <stdio.h>
#include <string.h>
#include <ctype.h>
char keywords[][10] = {"int", "float", "if", "else", "while", "return", "char"};
int iskeyword(char *word)
{
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}
int main()
{
    FILE *fp = fopen("input.c", "r");
    char ch, buffer[100];
    int i = 0;
    if (!fp)
    {
        printf("cannot open file!\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
            printf("operator:%c\n", ch);
        else if (isalnum(ch))
        {
            buffer[i++] = ch;
        }
        else if (i > 0)
        {
            buffer[i] = '\0';
            i = 0;
            if (iskeyword(buffer))
                printf("keywords:%s\n", buffer);
            else
                printf("identifier:%s\n", buffer);
        }
    }
    fclose(fp);
    return 0;
}