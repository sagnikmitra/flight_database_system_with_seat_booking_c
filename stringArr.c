#include <stdio.h>
#include <string.h>

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

int removeFlightFromSlNo(int slNo)
{
    removeLineFromLineNumber(slNo);
    lll();
    return 0;
}
int main()
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
    removeFlightFromSlNo(lineNumber);
    // writeToAFile();
    //Er opor porzonto kaj korche
    // writeToALineInFile(lineNumber, updatedStr);
    return 0;
}

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
                printf("\nindex(less than %d):\n", linelength);
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
    printf("\nDONE:\n");
    fclose(file1);
    fclose(file2);

    file1 = fopen(f, "w+");
    file2 = fopen("f2.txt", "r");
    while ((y = fgetc(file2)) != EOF)
    {
        fputc(y, file1);
    }
    fclose(file2);
    fclose(file1);
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