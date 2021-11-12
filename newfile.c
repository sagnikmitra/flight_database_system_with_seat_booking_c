#include <stdio.h>
void removeLineFromLineNumber(int lineNumber)
{
    FILE *fptr1, *fptr2;
    char file1[] = "TestTemp2.txt";
    char file2[] = "temp.txt";
    char curr;
    int del, line_number = 0;
    del = lineNumber;
    fptr1 = fopen(file1, "r");
    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);
    if (curr != EOF)
    {
        line_number = 1;
    }
    while (1)
    {
        if (del != line_number)
            putc(curr, fptr2);
        curr = getc(fptr1);
        if (curr == '\n')
            line_number++;
        if (curr == EOF)
            break;
    }
    fclose(fptr1);
    fclose(fptr2);
}
int lll()
{
    if (remove("TestTemp2.txt") == 0)
    {
        printf("");
    }
    else
    {
        printf("Could not delete file");
    }; // remove the original file
    char old_name[] = "temp.txt";
    char new_name[] = "TestTemp2.txt";
    int value;
    value = rename(old_name, new_name);
    if (!value)
    {
        printf("%s", "");
    }
    else
    {
        perror("Error");
    }
}
int removeFlightFromSlNo(int slNo)
{
    removeLineFromLineNumber(slNo);
    lll();
    return 0;
}