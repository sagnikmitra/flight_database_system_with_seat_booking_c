#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *temp;
    temp = fopen("a.txt", "a");
    char line1[1000];
    // removeFlightFromSlNo(lineNumber);
    while (fgets(line1, 1000, temp) != NULL)
    {
        lineNumberFileCount++;
        if (lineNumberFileCount == lineNumber)
        {
            fprintf(temp, "\n", updatedStr);
        }
    }
    fclose(temp);
    return 0;
}