#include <stdio.h>
#include <string.h>
void printUpdatedString(int lineNumber, char *newStr)
{
    FILE *fp;
    char line[1000];
    char lineAppear[1000];
    int lineNumberFileCount = 0;
    fp = fopen("a.txt", "r");
    while (fgets(line, 1000, fp) != NULL)
    {
        lineNumberFileCount++;
        if (lineNumberFileCount == lineNumber)
        {
            fprintf(fp, "\n%s", newStr);
        }
    }
    printf("Done");
    // printf("%s", lineAppear);
    fclose(fp);
}