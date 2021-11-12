#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void inserttext(char *updatedStr, int lineNumber)
{
    FILE *file1, *file2;
    char *f = malloc(100), *t = malloc(100);
    int l, i, r, y, n, index, nl = 0;
    int linelength = 0;
    long offset = 0;

    f = "a.txt";

    file1 = fopen(f, "r+");
    file2 = fopen("f2.txt", "w+");

    t = updatedStr;

    l = lineNumber;

    while ((r = fgetc(file1)) != EOF) //copying file1 contents into file2 contents
    {
        fputc(r, file2);
        if (r == '\n' && ++nl == l)
        {
            offset = ftell(file1); //save location in file
            while ((r = fgetc(file1)) != '\n' && r != EOF)
            {
                linelength++; //count characters in line
            }
            fseek(file1, offset, SEEK_SET); //seek  back to start of line
            //get index where to insert text
            do
            {
                printf("Enter to Continue");
                if ((scanf("%d", &index)) != 1)
                {
                    scanf("%*[^\n]"); //input not an integer. clear buffer
                    index = linelength;
                }
            } while (index >= linelength || index < 0);

            while (index)
            {
                r = fgetc(file1);
                fputc(r, file2);
                index--;
            }
            fprintf(file2, "%s ", t); //adding the inserted text
        }
    }
    fclose(file1);
    fclose(file2);
    remove("f2.txt");

    file1 = fopen(f, "r");
    printf("\n");
    while ((i = fgetc(file1)) != EOF) //showing the result after inserting
    {
        putchar(i);
    }
    fclose(file1);
    free(f);
    free(t);
}

int main()
{
    printf("Enter Line Number: ");
    int lineNumber;
    scanf("%d", &lineNumber);
    char *array[9];
    char updatedStr[] = "";
    for (int i = 0; i < 9; ++i)
    {
        array[i] = "Sagnik";
        strcat(updatedStr, array[i]);
        if (i < 8)
            strcat(updatedStr, " ");
        else
            strcat(updatedStr, "");
    }
    strcat(updatedStr, "\n");
    inserttext(updatedStr, lineNumber);
    return 0;
}