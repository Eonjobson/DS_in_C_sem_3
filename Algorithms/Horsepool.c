#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void main()
{
    int table[126];
    char text[100];
    char pattern[25];
    printf("Enter text\t");
    gets(text);
    printf("\nEnter pattern\t");
    gets(pattern);
    int textlen = strlen(text);
    int patlen = strlen(pattern);
    for (int i = 0; i < 126; i++)
    {
        table[i] = patlen;
    }
    for (int j = 0; j < patlen - 2; j++)
    {
        table[pattern[j]] = patlen - j - 1;
    }
    // Table initialized
    int k = 0;
    bool flag = false;
    int i = patlen - 1;
    while (i < textlen)
    {
        // Check for match and move leftwards
        while (k <= patlen - 1 && pattern[patlen - 1 - k] == text[i - k])
        {
            k++;
        }
        if (k == patlen)
        {
            flag = true;
            printf("Found at position %d\n", i - patlen + 2);
            break;
        }
        else
        {
            i += table[text[i]];
        }
    }
    if (!flag)
    {
        printf("Not found");
    }
}