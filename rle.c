
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ch;
    int i, count;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Compressed string: ");
    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        count = 1;
        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        printf("%c%d", ch, count);
    }

    return 0;
}
