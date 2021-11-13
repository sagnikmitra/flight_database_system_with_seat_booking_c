#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

void printLineFromLineNumber(int lineNumber)
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
            strncpy(lineAppear, line, sizeof(lineAppear));
        }
    }
    printf("Done");
    // printf("%s", lineAppear);
    fclose(fp);
}
int searchItem(char *word)
{
    FILE *fp;
    char line[1000];
    int count = 0;
    int lineNumber = 0;
    fp = fopen("a.txt", "r");
findNextLine:
    while (fgets(line, 1000, fp) != NULL)
    {

        lineNumber++;
        if (strstr(line, word) != NULL)
        {
            count++;
            printLineFromLineNumber(lineNumber);
            goto findNextLine;
        }
    }
    fclose(fp);
    return count;
}

void removeLineFromLineNumber(int lineNumber)
{
    FILE *fptr1, *fptr2;
    char file1[] = "a.txt";
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
    if (remove("a.txt") == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Could not delete file");
    }; // remove the original file
    char old_name[] = "temp.txt";
    char new_name[] = "a.txt";
    int value;
    value = rename(old_name, new_name);
    if (!value)
    {
        printf("%s", "File name changed successfully");
    }
    else
    {
        perror("Error");
    }
}
int writeToALineInFile(int lineNumber, char *word)
{
    FILE *fp;
    char line[1000];
    int lineNumberFileCount = 0;
    fp = fopen("a.txt", "w");
    while (fgets(line, 1000, fp) != NULL)
    {
        lineNumberFileCount++;
        if (lineNumberFileCount == lineNumber)
        {
            fprintf(fp, "%s", word);
        }
    }
    printf("Done");
    // printf("%s", lineAppear);
    fclose(fp);
}
int writeToAFile()
{
    FILE *fp;
    char line[1000];
    int lineNumberFileCount = 0;
    fp = fopen("a.txt", "w");
    fprintf(fp, "Sagnik");
    // printf("%s", lineAppear);
    fclose(fp);
}
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
    strcat(updatedStr, "\n");
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

    // printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);
}

int removeFlightFromSlNo(int slNo)
{
    removeLineFromLineNumber(slNo);
    lll();
    return 0;
}
int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);

        // Check non whitespace character
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}

/**
 * Function to remove empty lines from a file.
 */
void removeEmptyLines(FILE *srcFile, FILE *tempFile)
{
    char buffer[BUFFER_SIZE];

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
    {
        /* If current line is not empty then write to temporary file */
        if (!isEmpty(buffer))
            fputs(buffer, tempFile);
    }
}
void removeEmptyLinesFromFile()
{
    FILE *srcFile, *tempFile;

    /* Open source file */
    srcFile = fopen("a.txt", "r");

    /* Open temporary file */
    tempFile = fopen("temp.txt", "w");

    /* Remove empty lines from source file and write to temporary file */
    removeEmptyLines(srcFile, tempFile);

    /* Close all files to release resource */
    fclose(srcFile);
    fclose(tempFile);

    /* Delete original source file */
    remove("a.txt");

    /* Rename temporary file as original file */
    rename("temp.txt", "a.txt");
}
void editFlightDetails()
{
    printf("Enter Line Number: ");
    int lineNumber;
    scanf("%d", &lineNumber);
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
            strncpy(lineAppear, line, sizeof(lineAppear));
        }
    }
    fclose(fp);
    // char buf[] = lineAppear;
    int i = 0;
    char *p = strtok(lineAppear, " ");
    char *array[9];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok(NULL, " ");
    }

    for (i = 0; i < 9; ++i)
        printf("%s ", array[i]);
    printf("\nEnter Your Choice:\n1: Edit ID\n2: Edit Destination\n3: Edit Origin\n4: Edit Time\n5: Edit Seat Availability\n6: Edit Date\n7: Edit Adult Fare\n8: Edit Child Fare\n9:Edit Infant Fare\n");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter New ID:\n");
        char newID[100];
        scanf("%s", newID);
        array[0] = newID;
        break;
    case 2:
        printf("Enter New Destination:\n");
        char newDestination[100];
        scanf("%s", newDestination);
        array[1] = newDestination;
        break;
    case 3:
        printf("Enter New Origin:\n");
        char newOrigin[100];
        scanf("%s", newOrigin);
        array[2] = newOrigin;
        break;
    case 4:
        printf("Enter New Time:\n");
        char newTime[100];
        scanf("%s", newTime);
        array[3] = newTime;
        break;
    case 5:
        printf("Enter New Seat Availability:\n");
        char newSeatAvailability[100];
        scanf("%s", newSeatAvailability);
        array[4] = newSeatAvailability;
        break;
    case 6:
        printf("Enter New Date:\n");
        char newDate[100];
        scanf("%s", newDate);
        array[5] = newDate;
        break;
    case 7:
        printf("Enter New Adult Fare:\n");
        char newAdultFare[100];
        scanf("%s", newAdultFare);
        array[6] = newAdultFare;
        break;
    case 8:
        printf("Enter New Child Fare:\n");
        char newChildFare[100];
        scanf("%s", newChildFare);
        array[7] = newChildFare;
        break;
    case 9:
        printf("Enter New Infant Fare:\n");
        char newInfantFare[100];
        scanf("%s", newInfantFare);
        array[8] = newInfantFare;
        break;
    default:
        printf("Invalid Choice\n");
    }
    char updatedStr[] = "";
    for (i = 0; i < 9; ++i)
    {
        strcat(updatedStr, array[i]);
        strcat(updatedStr, " ");
    }
    printf("%s", updatedStr);
    ReplaceFunc(updatedStr, lineNumber);
    removeEmptyLinesFromFile();
    // writeToAFile();
    //Er opor porzonto kaj korche
    // writeToALineInFile(lineNumber, updatedStr);
    return 0;
}
