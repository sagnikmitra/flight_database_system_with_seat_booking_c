#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define BUFFER_SIZE 1000

void intro();
void Register();
void Login();
void admin();
void add();
void deleteone();
void edit();
void admin_intro();
void flight_data();
int search();
void user();
void update();
void TicketFunc(int n, int TicketNumber);
void editFlightDetails();
void removeLineFromLineNumber(int lineNumber);
void printLineFromLineNumber(int lineNumber);
int removeFlightFromSlNo(int slNo);
int removeFileAndRename();
int searchItem(char *word);
void ReplaceFunc(char *updatedStr, int lineNumber);
void removeEmptyLines(FILE *srcFile, FILE *tempFile);
void removeEmptyLinesFromFile();
int writeToAFile();
int writeToALineInFile(int lineNumber, char *word);

int total, flight_book = -1;

struct login
{
    char firstname[50];
    char lastname[20];
    char email[40];
    char password[50];

} u;

struct customer_details
{
    char FirstName[50];
    char LastName[50];
    int seat_number;
    int age;
    int price;
    char Num[12];
};

char FlightID[100];
char Destination[100];
char Origin[100];
char Time[100];
char seats[100];
char date[100];

//Function to Print Line from a text file with the help of line number
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
    printf("%d: %s", lineNumber, lineAppear);

    fclose(fp);
}

int searchItem(char *word)
{
    FILE *fp;
    char line[1000];
    int count = 0;
    int lineNumber = 0;
    fp = fopen("Test.txt", "r");
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

//Remove a line from given line number
void removeLineFromLineNumber(int lineNumber)
{
    FILE *fptr1, *fptr2;
    char file1[] = "Test.txt";
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

//Remove a file and rename temporary file to the previously deleted file name
int removeFileAndRename()
{
    if (remove("Test.txt") == 0)
    {
        printf("");
    }
    else
    {
        printf("Could not delete file");
    };
    char old_name[] = "temp.txt";
    char new_name[] = "Test.txt";
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
    removeFileAndRename();
    return 0;
}
void intro()
{
    int i, j;

check:
    printf("Welcome to Vistara IISERK\n");
    printf("1. User Sign Up\n");
    printf("2. User Login\n");
    printf("3. Admin Login\n");
    printf("4. Exit\n");

    printf("Enter Your Choice [1-4] = ");

    scanf("%d", &i);

    if (i == 1)
    {
        Register();
        printf("Press 0 to go Back to Main Page\n");
        printf("Press 1 to Exit\n");
        printf("Enter Your Choice [0-1]= ");
        scanf("%d", &j);
        if (j == 0)
        {
            goto check;
        }
        else if (j == 1)
        {
            exit(0);
        }
    }

    if (i == 2)
    {
        Login();
        printf("Press 0 to go Back to Main Page");
        printf("Press 1 to Exit\n");
        printf(" Enter Your Choice [0-1]= ");
        scanf("%d", &j);
        if (j == 0)
        {

            goto check;
        }
        else if (j == 1)
        {
            exit(0);
        }
    }
    else if (i == 3)
    {
        admin();
        printf("Press any key to continue\n");
        printf("Press 0 to go Back to Main Page\n");
        printf("Press 1 to Exit\n");
        printf("Enter Your Choice [0-1]= ");
        scanf("%d", &j);
        if (j == 0)
        {
            goto check;
        }
        else if (j == 1)
        {
            exit(0);
        }
    }
    if (i == 4)
    {

        exit(0);
    }
}
void Register()
{
    char user[50];
    int s;
    FILE *fp;
    if (fp = fopen("login.txt", "r"))
    {
        fclose(fp);
        goto credentials;
    }
    else
    {
        struct login a;
        fp = fopen("login.txt", "a");
        printf(" Enter the user account details ");
        printf("Enter first name: ");
        scanf("%s", a.firstname);
        printf("Enter last name: ");
        scanf("%s", a.lastname);
        printf("Enter email id: ");
        scanf("%s", a.email);
        printf("Enter password: ");
        scanf("%s", a.password);

        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);

        goto next;
    }

credentials:
    fp = fopen("login.txt", "r");
    struct login a, b;
    printf(" Enter the user account details ");
    printf("Enter first name: ");
    scanf("%s", a.firstname);
    printf("Enter last name: ");
    scanf("%s", a.lastname);
    printf("Enter email id: ");
    scanf("%s", a.email);
    printf("Enter password: ");
    scanf("%s", &user);

    s = 0;
    while (!feof(fp))

    {
        fread(&b, sizeof(b), 1, fp);
        if (strcmp(user, b.email) == 0)
        {
            s += 1;
        }
    }

    if (s > 0)

    {
        printf("Email ID already exists");
        Login();
    }
    else
    {
        fclose(fp);
        printf("Re-enter password: ");
        scanf("%s", a.password);

        fp = fopen("login.txt", "a");
        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);
    }
next:

    printf("Your Email ID is the unique UserID\n");
    printf("Press any key to login with new UserID\n");
    printf("Press any key to continue\n");
    Login();
}
void Login()
{
    char username[40];
    char password[50];
    int sum = 0;

    FILE *fp;
    if (fp = fopen("login.txt", "r"))
    {
        fclose(fp);
        goto login;
    }
    else
    {

        printf("Press any key to go back and Sign-up first");
        intro();
    }

login:
    fp = fopen("login.txt", "r");

    struct login a;

    printf("Enter valid UserID: ");
    scanf("%s", &username);
    printf("Enter password: ");
    scanf("%s", &password);

    while (!feof(fp))

    {
        fread(&a, sizeof(a), 1, fp);
        if (strcmp(username, a.email) == 0 && strcmp(password, a.password) == 0)
        {
            sum += 1;
            strcpy(u.password, a.password);
            strcpy(u.firstname, a.firstname);
            strcpy(u.email, a.email);
            strcpy(u.lastname, a.lastname);
        }
    }
    if (sum > 0)

    {
        printf("Welcome! Successful User Login \n");
        printf("Press any key to continue");
        user();
    }

    else if (sum == 0)
    {
        printf("Enter valid UserID");
        printf("User Login Unsuccessful! Press any key to continue.\n");
    }
    fclose(fp);
}
void admin()
{
    char username[50];
    char password[20];
adminuser:
    printf(" Sign in to the admin account ");
    printf("Enter Valid Admin ID: ");
    scanf("%s", &username);
    printf("Enter Valid Password: ");
    scanf("%s", &password);
    if (strcmp(username, "vistara") == 0)
    {
        printf("Admin ID is Valid");
        printf("Press any key to continue");
    }
    else
    {
        printf("Invalid Admin ID");
        printf("Press any key to go back and enter valid Admin ID");
        goto adminuser;
    }
    if (strcmp(password, "iiserk") == 0)
    {
        printf("Password is Valid");
        printf("Press any key to continue");
    }
    else
    {
        printf("Invalid Password");
        printf("Press any key to go back and enter valid Password");
        goto adminuser;
    }
    if (strcmp(username, "vistara") == 0 && strcmp(password, "iiserk") == 0)
    {
        printf("Welcome! Successful Admin Login");
        printf("Press any key to continue");
        admin_intro();
    }
}
void add()
{
    char a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], q[100];

    printf("  Enter the Flight details ");

    printf("Enter the Four Digit Flight ID: ");
    scanf("%s", &a);
    printf("Destination: ");
    scanf("%s", &b);
    strcat("Des:", b);
    printf("Origin: ");
    scanf("%s", &c);
    strcat("Ori:", b);
    printf("Date of Departure(DD/MM/YYYY): ");
    scanf("%s", &f);
    printf("Time of Departure(xxxx hrs): ");
    scanf("%s", &d);
    printf("Number of seats available ");
    scanf("%s", &e);
    printf("Enter Adult Fare ");
    scanf("%s", &g);
    printf("Enter Child Fare ");
    scanf("%s", &h);
    printf("Enter Infant Fare ");
    scanf("%s", &q);
    int i = 0;
    FILE *temp;
    temp = fopen("Test.txt", "a");
    fprintf(temp, "%s %s %s %s %s %s %s %s %s\n", a, b, c, d, e, f, g, h, q);
    fclose(temp);
    printf("Details have been successfully entered! Press enter to continue");
}
int search()
{
    int n = total;
    char word[100];
    int k = 0, t;

backagain:
    printf("Welcome to the free search menu\n");

    printf("1. Search by Flight ID\n");
    printf("2. Search by Destination\n");
    printf("3. Search by Origin\n");
    printf("4. Search by Date and Time\n");
    printf("5. Skip Search.\n");
    printf("Enter Your Choice [1-5] = ");

    scanf("%d", &t);

    if (t == 1)
    {
        int count = 0, line_count = 0, dd;

        printf("Enter a valid Flight ID: ");
        scanf("%s", &word);
        printf("Available flights\n\n\n");
        printf("Sl.  Id   To   From     Time SA Date\n");

        if (searchItem(word) == 0)
        {
            printf("-    -    -      -      -    -  -\n");
            printf("No such flight exists.\n");
            goto backagain;
        }
        printf("Press any key to continue.\n");
    }

    else if (t == 2)
    {
        int count = 0, line_count = 0, dd;
        printf("Enter a valid Destination: ");
        scanf("%s", &word);
        printf("%s", word);
        char desStr[200] = "Des:";
        strcat(desStr, word);
        printf("%s", desStr);
        printf("Available flights\n\n\n");
        printf("Sl.  Id   To   From     Time SA Date\n");

        if (searchItem(desStr) == 0)
        {
            printf("-    -    -      -      -    -  -\n");
            printf("No such flight exists.\n");
            goto backagain;
        }
        printf("Press any key to continue.\n");
    }

    else if (t == 3)
    {
        int count = 0, line_count = 0, dd;
        printf("Available flights\n\n\n");
        printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
        printf("Enter a valid Origin: ");
        scanf("%s", &word);
        char oriStr[200] = "Ori:";
        strcat(oriStr, word);

        printf("Available flights\n\n\n");
        printf("Sl.  Id   To   From     Time SA Date\n");

        if (searchItem(oriStr) == 0)
        {
            printf("-    -    -      -      -    -  -\n");
            printf("No such flight exists.\n");
            goto backagain;
        }
        printf("Press any key to continue.\n");
    }

    else if (t == 4)
    {
        int count = 0, g, line_count = 0, dd;
        printf("Enter 1 to Search by Date, 2 to Search by Time");
        scanf("%d", &g);
        if (g == 1)
        {
            printf("Enter a valid Date: (DD/MM/YYYY)");
            scanf("%s", &word);
            printf("Available flights\n\n\n");
            printf("Sl.  Id   To   From     Time SA Date\n");

            if (searchItem(word) == 0)
            {
                printf("-    -    -      -      -    -  -\n");
                printf("No such flight exists.\n");
                goto backagain;
            }
            printf("Press any key to continue.\n");
        }
        else if (g == 2)
        {
            printf("Enter a valid Time: [Format: 19 hours 10 minutes will be entered as 1910]");
            scanf("%s", &word);
            printf("Available flights\n\n\n");
            printf("Sl.  Id   To   From     Time SA Date\n");

            if (searchItem(word) == 0)
            {
                printf("-    -    -      -      -    -  -\n");
                printf("No such flight exists.\n");
                goto backagain;
            }
            printf("Press any key to continue.\n");
        }
    }

    else if (t == 5)
    {
        return 0;
    }
    else
    {
        printf("Wrong option pressed!");
        goto backagain;
    }
}
void deleteone()
{
    int lineNumber;
    search();
    printf("Enter the Correct Sl. No. from the Above table");
    scanf("%d", &lineNumber);
    removeFlightFromSlNo(lineNumber);
    printf("Flight deleted successfully!");
}
void admin_intro()
{
    int a, b;

back_admin:
    printf("Welcome vistara! :)\n");
    printf("Kindly choose what change you'd like to make to the database.\n");

    printf("1. Add flights\n");
    printf("2. Delete flights\n");
    printf("3. Edit flight details\n");
    printf("4. Logout\n");

    printf("Enter Your Choice [1-4] = ");

    scanf("%d", &a);

    if (a == 1)
    {
        add();

        printf("Press 0 to go back to the main page.\n");
        printf("Press 1 to Exit.\n\n");
        printf("Enter Your Choice [0-1] = ");
        scanf("%d", &b);

        if (b == 0)
        {
            goto back_admin;
        }
        else if (b == 1)
        {
            exit(0);
        }
    }

    if (a == 2)
    {
        deleteone();
        printf("Press any key to continue.\n");
        printf("Press 0 to go back to the main page.\n");
        printf("Press 1 to Exit.\n\n");
        printf("Enter Your Choice [0-1] = ");

        scanf("%d", &b);

        if (b == 0)
        {
            goto back_admin;
        }
        else if (b == 1)
        {
            exit(0);
        }
    }

    if (a == 3)
    {
        edit();
        printf("Press any key to continue.\n");
        printf("Press 0 to go back to the main page.\n");
        printf("Press 1 to Exit.\n");
        printf("Enter Your Choice [0-1] = ");

        scanf("%d", &b);

        if (b == 0)
        {
            goto back_admin;
        }
        else if (b == 1)
        {
            exit(0);
        }
    }

    if (a == 4)
    {
        intro();
    }

    else
    {
        printf("Invalid Choice! Try again.\n");
        goto back_admin;
    }
}
void flight_data()
{
    int i = 0;
    FILE *temp;
    temp = fopen("Test.txt", "a");
    for (i = 0; i < total; i++)
    {
        char a = FlightID[i];
        char b = Destination[i];
        char c = Origin[i];
        char d = Time[i];
        char e = seats[i];
        char f = date[i];
        fprintf(temp, "%s %s %s %s %s %s\n", a, b, c, d, e, f);
    }
    fclose(temp);
}
void update()
{
    int i = 0;
    FILE *temp;
    temp = fopen("Test.txt", "a");
    for (i = 0; i < total; i++)
    {
        char a = FlightID[i];
        char b = Destination[i];
        char c = Origin[i];
        char d = Time[i];
        char e = seats[i];
        char f = date[i];
        fprintf(temp, "%s %s %s %s %s %s\n", a, b, c, d, e, f);
    }
    fclose(temp);
}
int writeToALineInFile(int lineNumber, char *word)
{
    FILE *fp;
    char line[1000];
    int lineNumberFileCount = 0;
    fp = fopen("Test.txt", "w");
    while (fgets(line, 1000, fp) != NULL)
    {
        lineNumberFileCount++;
        if (lineNumberFileCount == lineNumber)
        {
            fprintf(fp, "%s", word);
        }
    }
    printf("Done");

    fclose(fp);
}
int writeToAFile()
{
    FILE *fp;
    char line[1000];
    int lineNumberFileCount = 0;
    fp = fopen("Test.txt", "w");
    fprintf(fp, "Sagnik");

    fclose(fp);
}
void ReplaceFunc(char *updatedStr, int lineNumber)
{

    FILE *fPtr;
    FILE *fTemp;

    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int line, count;

    line = lineNumber;

    fflush(stdin);

    strcat(updatedStr, "\n");
    strcpy(newline, updatedStr);

    fPtr = fopen("Test.txt", "r");
    fTemp = fopen("replace.tmp", "w");

    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);

    remove("Test.txt");

    rename("replace.tmp", "Test.txt");
}
int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);

        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}
void removeEmptyLines(FILE *srcFile, FILE *tempFile)
{
    char buffer[BUFFER_SIZE];

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
    {

        if (!isEmpty(buffer))
            fputs(buffer, tempFile);
    }
}
void removeEmptyLinesFromFile()
{
    FILE *srcFile, *tempFile;

    srcFile = fopen("Test.txt", "r");

    tempFile = fopen("temp.txt", "w");

    removeEmptyLines(srcFile, tempFile);

    fclose(srcFile);
    fclose(tempFile);

    remove("Test.txt");

    rename("temp.txt", "Test.txt");
}
void editFlightDetails()
{
    printf("Enter Valid Serial Number from the Table Displayed: ");
    int lineNumber;
    scanf("%d", &lineNumber);
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
    fclose(fp);

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
}
void edit()
{
    search();
    editFlightDetails();
}
void user()
{
    int TicketNumber, i, j, b;
    char ID[20], dates[10];
check:

    printf("Welcome %s %s\n", u.firstname, u.lastname);
    printf("1. Free Search\n");
    printf("2. Book the flight\n");
    printf("3. Logout\n");

    printf("Enter Your Choice [1-3] = ");

    scanf("%d", &i);
    if (i == 1)
    {
        search();
        printf("Press 0 to go back to the main page.\n");
        printf("Press 1 to Exit.\n\n");
        printf("Enter Your Choice [0-1] = ");

        scanf("%d", &b);
        if (b == 0)
        {
            goto check;
        }
        else if (b == 1)
        {
            exit(0);
        }
    }

    else if (i == 2)
    {
        int vuid;

        int totalTickets = 0;
        search();
        printf("Book the flight: ");
        printf("Enter the Vistara Unique Id from the above table: ");
        scanf("%d", &vuid);
        int lineNumber = vuid;
        printf("Enter the Total Number of Tickets you want to Book: ");
        scanf("%d", &totalTickets);
        const int totalTickets1 = totalTickets;
        int tTypeArr[totalTickets];
    choice:
        for (i = 0; i < totalTickets; i++)
        {
            int j = 0;
            printf("Enter the Type of Ticket for Ticket %d", i + 1);
            printf("\n1. Adult\n2. Child\n3. Infant");

            printf("\nEnter Your Choice [1-3] = ");
            scanf("%d", &j);

            if (j == 1)
            {
                tTypeArr[i] = 0;
            }
            else if (j == 2)
            {
                tTypeArr[i] = 1;
            }
            else if (j == 3)
            {
                tTypeArr[i] = 2;
            }
            else
            {
                goto choice;
            }
        }
        FILE *fp;
        char line[1000];
        char lineAppear[1000];
        int lineNumberFileCount = 0;
        fp = fopen("Test.txt", "r");
        while (fgets(line, 1000, fp) != NULL)
        {
            lineNumberFileCount++;
            if (lineNumberFileCount == vuid)
            {
                strncpy(lineAppear, line, sizeof(lineAppear));
                break;
            }
        }
        fclose(fp);

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

        char myb64[1024];
        strcpy(myb64, array[4]);
        int atoiSA = atoi(myb64);
        int seatPrev = 0;
        seatPrev = atoiSA;
        const int counter2 = seatPrev;
        printf("Old Value: %d\n", seatPrev);
        if (atoiSA < totalTickets)
            printf("Ticket Underflow");
        else
        {

            atoiSA -= totalTickets;
            itoa(atoiSA, array[4], 10);
        }

        char updatedStr[] = "";
        for (i = 0; i < 9; ++i)
        {
            strcat(updatedStr, array[i]);
            strcat(updatedStr, " ");
        }

        int totalFare = 0;
        int counter = counter2;
        printf("New Seat Prev Value: %d\n", counter2 + 1);
        int totalTickets2 = totalTickets1;
        for (int i = 0; i < totalTickets2; i++)
        {

            char FirstName[50];
            char LastName[50];
            char Aadhaar[12];
            printf("\n\nEnter First Name: ");
            scanf("%s", FirstName);
            printf("Enter Last Name: ");
            scanf("%s", LastName);
            printf("Enter Aadhaar Number: ");
            scanf("%s", Aadhaar);
            printf("\nTICKET-%d\n---------", i + 1);
            printf("Name: %s %s\n", FirstName, LastName);
            printf("Aadhaar Number: %s\n", Aadhaar);
            printf("Flight ID: %s\n", array[0]);
            printf("Destination: %s\n", array[1]);
            printf("Origin: %s\n", array[2]);
            printf("Time: %s\n", array[3]);
            printf("Date of Journey: %s\n", array[5]);
            printf("Seat Number: %d\n", counter);
            char ticketType[50];
            int fare = 0;
            if (tTypeArr[i] == 0)
            {
                printf("Adult Ticket\n");
                printf("Fare: %s\n", array[6]);
                totalFare += atoi(array[6]);
            }
            else if (tTypeArr[i] == 1)
            {
                printf("Child Ticket\n");
                printf("Fare: %s\n", array[7]);
                totalFare += atoi(array[7]);
            }
            else if (tTypeArr[i] == 2)
            {
                printf("Infant Ticket\n");
                printf("Fare: %s\n", array[8]);
                totalFare += atoi(array[8]);
            }

            counter--;
        }

        printf("Total Fare: %d\n", totalFare);

        ReplaceFunc(updatedStr, lineNumber);
        removeEmptyLinesFromFile();
    }
}
int main()

{
    flight_data();
    intro();
    return 0;
}