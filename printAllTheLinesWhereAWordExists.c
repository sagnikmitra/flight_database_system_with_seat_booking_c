#include <stdio.h>
#include <string.h>

void printLineFromLineNumber(int lineNumber)
{
    FILE *fp;
    char line[1000];
    char lineAppear[1000];
    int lineNumberFileCount = 0;
    fp = fopen("Test.txt", "r");
    while (fgets(line, 1000, fp) != NULL)
    {
        lineNumberFileCount++;
        if (lineNumberFileCount == lineNumber)
        {
            strncpy(lineAppear, line, sizeof(lineAppear));
        }
    }
    //printf("%d: %s", lineNumber, lineAppear);
    printf("%s", lineAppear);
    fclose(fp);
}

int searchItem(char *word)
{
    FILE *fp;
    char line[1000];

    int lineNumber = 0;
    fp = fopen("Test.txt", "r");
findNextLine:
    while (fgets(line, 1000, fp) != NULL)
    {

        lineNumber++;
        if (strstr(line, word) != NULL)
        {
            printLineFromLineNumber(lineNumber);
            goto findNextLine;
        }
    }
    fclose(fp);
    return -1;
}
int main()
{
    char word[1000];
    printf("Enter a word: ");
    scanf("%s", word);
    searchItem(word);
    return 0;
}