#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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

int total, flight_book = -1;
int infant = 1000, child = 2200, adult = 3000;

struct login
{
    char firstname[50];
    char lastname[20];
    char email[40];
    char username[50];

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

int ticket(int n, int i, struct customer_details d[]);
void PrintTicket(struct customer_details p);

char FlightID[100];
char Destination[100];
char Origin[100];
char Time[100];
char seats[100];
char date[100];

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
    // printf("%s", lineAppear);
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
int lll()
{
    if (remove("Test.txt") == 0)
    {
        printf("");
    }
    else
    {
        printf("Could not delete file");
    }; // remove the original file
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
    lll();
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
        printf("Enter username: ");
        scanf("%s", a.username);

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
    printf("Enter username: ");
    scanf("%s", &user);

    s = 0;
    while (!feof(fp))

    {
        fread(&b, sizeof(b), 1, fp);
        if (strcmp(user, b.username) == 0)
        {
            s += 1;
        }
    }

    if (s > 0)

    {
        printf("User ID already exists");
        Login();
    }
    else
    {
        fclose(fp);
        printf("Re-enter User name: ");
        scanf("%s", a.username);

        fp = fopen("login.txt", "a");
        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);
    }
next:

    printf("Your Username is the unique UserID\n");
    printf("Press any key to login with new UserID\n");
    printf("Press any key to continue\n");
    Login();
}

void Login()
{
    char username[50];
    int sum = 0;

    FILE *fp;
    if (fp = fopen("login.txt", "r"))
    {
        fclose(fp);
        goto login;
    }
    else
    {
        printf("No user ID has been registered in the file. Sign-up first to Continue");
        printf("Press any key to go back and Sign-up first");
        intro();
    }

login:
    fp = fopen("login.txt", "r");

    struct login a;

    printf("Enter valid UserID: ");
    scanf("%s", &username);

    while (!feof(fp))

    {
        fread(&a, sizeof(a), 1, fp);
        if (strcmp(username, a.username) == 0)
        {
            sum += 1;
            strcpy(u.username, a.username);
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
    printf("Origin: ");
    scanf("%s", &c);
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

    else if (t == 3)
    {
        int count = 0, line_count = 0, dd;
        printf("Available flights\n\n\n");
        printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
        printf("Enter a valid Origin: ");
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

int ticket(int n, int i, struct customer_details d[])
{
    int k, t, counter = 0;
    printf("Age: ");
    scanf("%d", &d[i].age);
    if (d[i].age <= 5)
    {
        printf("Ticket price is %d\n", infant);
        d[i].price = infant;
    }
    else if (d[i].age > 5 && d[i].age < 18)
    {
        printf("Ticket price is %d\n", child);
        d[i].price = child;
    }
    else
    {
        printf("Ticket price is %d\n", adult);
        d[i].price = adult;
    }

    printf("First Name: ");
    scanf("%s", d[i].FirstName);

    printf("Last Name: ");
    scanf("%s", d[i].LastName);

    printf("AADHAR number: ");
    scanf("%s", d[i].Num);

    printf("Seat number is %d\n", n - i);

    d[i].seat_number = n - i;
    return d[i].seat_number;
}

void PrintTicket(struct customer_details p)
{
    FILE *fptr;
    fptr = fopen("boarding.txt", "a");
    int i = 0, j;

    printf("  ====================================================================================\n");
    fprintf(fptr, "  ====================================================================================\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < i;)
        {
            if (j / 2 == 0)
            {
                printf(" ||                                                                                  ||\n");
                fprintf(fptr, " ||                                                                                  ||\n");
            }
            else
            {
                printf("                                                                                       \n");
                fprintf(fptr, "                                                                                               \n");
            }
            j++;
        }
    }
    printf("                               Flight ID          %s                                   \n\n", FlightID[flight_book]);
    printf(" ||                                                                                  ||\n");
    printf("                                 Name           %s %s                                  \n\n", p.FirstName, p.LastName);
    printf(" ||                                                                                  ||\n");
    printf("                                 Price            Rs. %d/-                             \n\n", p.price);
    printf(" ||                                                                                  ||\n");
    printf("                          To:%s                 From:%s                                 \n\n", Origin[flight_book], Destination[flight_book]);
    printf(" ||                                                                                  ||\n");
    printf("                          Date:%s             Time:%s                                 \n\n", date[flight_book], Time[flight_book]);
    printf(" ||                                                                                  ||\n");
    printf("                               Seat Number        %d                                   \n\n", p.seat_number);
    printf(" ||                                                                                  ||\n");
    printf("                                Gate Number       2A                                   \n\n");

    fprintf(fptr, "                               Flight ID          %s                                   \n\n", FlightID[flight_book]);
    fprintf(fptr, " ||                                                                                  ||\n");
    fprintf(fptr, "                                 Name           %s %s                                  \n\n", p.FirstName, p.LastName);
    fprintf(fptr, " ||                                                                                  ||\n");
    fprintf(fptr, "                                 Price             Rs. %d /-                                   \n\n", p.price);
    fprintf(fptr, " ||                                                                                  ||\n");
    fprintf(fptr, "                          To:%s                 From:%s                                  \n\n", Origin[flight_book], Destination[flight_book]);
    fprintf(fptr, " ||                                                                                  ||\n");
    fprintf(fptr, "                          Date:%s             Time:%s                                 \n\n", date[flight_book], Time[flight_book]);
    fprintf(fptr, " ||                                                                                  ||\n");
    fprintf(fptr, "                               Seat Number        %d                                   \n\n", p.seat_number);
    fprintf(fptr, " ||                                                                                  ||\n");
    fprintf(fptr, "                                Gate Number       2A                                   \n\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (j / 2 == 0)
            {
                printf(" ||                                                                                  ||\n");
                fprintf(fptr, " ||                                                                                  ||\n");
            }
            else
            {
                printf("                                                                                       \n");
                fprintf(fptr, "                                                                                       \n");
            }
        }
    }
    printf("  ====================================================================================\n");
    fprintf(fptr, "  ====================================================================================\n");

    fclose(fptr);
}

void TicketFunc(int n, int TicketNumber)
{
    int age, i, j, q, b, sum = 0;
    struct customer_details d[TicketNumber];

    for (i = 0; i < TicketNumber; i++)
    {
        printf("For Ticket %d:", i + 1);
        ticket(n, i, d);
    }
    char str[10];
    itoa(n - TicketNumber, str, 10);
    seats[flight_book] = *str;
    update();
    for (i = 0; i < TicketNumber; i++)
    {
        PrintTicket(d[i]);
        sum += d[i].price;
    }
    printf("\n\t\t\t\t Total price: Rs. %d\n\n", sum);

    printf("Press 0 to go back to the user page.\n");
    printf("Press 1 to go the main page.\n");
    printf("Press 2 to Exit.\n");
    scanf("%d", &b);
    switch (b)
    {
    case 0:

        user();
        break;
    case 1:

        intro();
        break;
    case 2:

        exit(0);
        break;
    }
}

void display()
{
    //printCalendar(2021);
    char dt[50];
    printf("Choose a date(DD/MM/YYYY): ");
    scanf("%s", dt);
    int n = total;
    int count = 0;
    printf("Available flights\n\n\n");
    printf("Date\t\tID\tTo\tFrom\tTime\tSeats");

    int i = 0;
    for (i = 0; i < n; i++)
    {

        if (date[i] == *dt)
        {
            printf("%s\t", date[i]);
            printf("%s\t", FlightID[i]);
            printf("%s\t", Destination[i]);
            printf("%s\t", Origin[i]);
            printf("%s\t", Time[i]);
            printf("%s\t", seats[i]);
            count += 1;
        }
    }
    if (count == 0)
    {
        printf("No such flight exists.");
    }
    printf("Press any key to continue.\n");
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
        if (total == 0)
        {
            printf("There are no flights available!'");
            intro();
        }

        else
        {
            printf(" Book the flight ");
            printf("Enter the date(DD/MM/YYYY): ");
            scanf("%s", dates);
            printf("Enter flight ID: ");
            scanf("%s", ID);

            int i = 0;
            for (i = 0; i < total; i++)
            {

                if (strcmp(&(FlightID[i]), ID) == 0 && strcmp(&(date[i]), dates) == 0)
                {
                    flight_book = i;
                }
            }
            if (flight_book == -1)
            {
                printf("Sorry, there is no such flight that you are looking for!");
                printf("Try again.");
                goto check;
            }
            else
            {
                int n = atoi(&(seats[flight_book]));

                //int *plan = randomfunc(n);
            check2:
                printf("The number of available seats are %d", n);
                printf("Number of seats you wish to book: ");
                scanf("%d", &TicketNumber);
                if (TicketNumber <= n)
                {
                    TicketFunc(n, TicketNumber);
                }
                else
                {
                    printf("Not enough seats available. Type another number!");
                    goto check2;
                }
            }
        }
    }
    else if (i == 3)
    {
        intro();
    }
    else
    {
        printf("Invalid Choice! Try again.\n");
        goto check;
    }
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
#define BUFFER_SIZE 1000
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
    // printf("%s", lineAppear);
    fclose(fp);
}
int writeToAFile()
{
    FILE *fp;
    char line[1000];
    int lineNumberFileCount = 0;
    fp = fopen("Test.txt", "w");
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
    fPtr = fopen("Test.txt", "r");
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
    remove("Test.txt");

    /* Rename temporary file as original file */
    rename("replace.tmp", "Test.txt");

    // printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);
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
    srcFile = fopen("Test.txt", "r");

    /* Open temporary file */
    tempFile = fopen("temp.txt", "w");

    /* Remove empty lines from source file and write to temporary file */
    removeEmptyLines(srcFile, tempFile);

    /* Close all files to release resource */
    fclose(srcFile);
    fclose(tempFile);

    /* Delete original source file */
    remove("Test.txt");

    /* Rename temporary file as original file */
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
    // return 0;
}
void edit()
{
    search();
    editFlightDetails();
}
int main()

{
    flight_data();
    intro();
    return 0;
}