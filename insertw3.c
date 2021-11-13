#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

void ReplaceFunc(char *updatedStr, int lineNumber)
{
    /* File pointer to hold reference of input file */
    FILE *fPtr;
    FILE *fTemp;

    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int line, count;

    line = lineNumber;

    /* Remove extra new line character from stdin */
    fflush(stdin);

    // printf("Replace '%d' line with: ", line);
    // fgets(newline, BUFFER_SIZE, stdin);
    strcpy(newline, updatedStr);

    /*  Open all required files */
    fPtr = fopen("a.txt", "r");
    fTemp = fopen("replace.tmp", "w");

    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

    /* Delete original source file */
    remove("a.txt");

    /* Rename temporary file as original file */
    rename("replace.tmp", "a.txt");

    printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);
}
int main()
{
    char updatedStr[BUFFER_SIZE];
    int lineNumber;

    printf("Enter line number to replace: ");
    scanf("%d", &lineNumber);

    printf("Enter updated string: ");
    scanf("%s", updatedStr);

    ReplaceFunc(updatedStr, lineNumber);

    return 0;
}