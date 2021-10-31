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
void box(int a, int b, int c, int d);
void box1(int a, int b, int c, int d);
void delay(int milliseconds);
void logo();
void anime();
void add();
void deleteone();
void edit();
void admin_intro();
void flight_data();
int search();
void user();
void update();
int *randomfunc(int n);
void seating(int n, int random[]);
int ticket(int i, struct customer_details d[], int *plan);
void PrintTicket(struct customer_details p);
void TicketFunc(int n, int TicketNumber, int *plan);

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
	char Num[11];
};

char FlightID[INT_MAX];
char Destination[INT_MAX];
char Origin[INT_MAX];
char Time[INT_MAX];
char seats[INT_MAX];
char date[INT_MAX];

int size_FlightID = 0;
void push_back_FlightID(char arr[], char data)
{
	arr[size_FlightID] = data;
	size_FlightID++;
}

int size_Destination = 0;
void push_back_Destination(char arr[], char data)
{
	arr[size_Destination] = data;
	size_Destination++;
}

int size_Origin = 0;
void push_back_Origin(char arr[], char data)
{
	arr[size_Origin] = data;
	size_Origin++;
}

int size_Time = 0;
void push_back_Time(char arr[], char data)
{
	arr[size_Time] = data;
	size_Time++;
}

int size_seats = 0;
void push_back_seats(char arr[], char data)
{
	arr[size_seats] = data;
	size_seats++;
}

int size_date = 0;
void push_back_date(char arr[], char data)
{
	arr[size_date] = data;
	size_date++;
}
void intro()
{
	int i, j;

check:
	printf("WELCOME TO BHARAT AIR");
	printf("1. User Sign Up");
	printf("2. User Login");
	printf("3. Admin Login");
	printf("4. Exit\n ");

	printf("  Enter Your Choice [1-4] = ");

	scanf("%d", &i);

	if (i == 1)
	{
		Register();
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
		fp = fopen("login.txt", "w");
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
		printf("Enter a different User ID");
		printf("Press any key to continue");
		goto credentials;
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
		printf("User Login Unsuccessful! Press any key to continue.");
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
	if (strcmp(username, "kripa") == 0)
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
	if (strcmp(username, "kripa") == 0 && strcmp(password, "iiserk") == 0)
	{
		printf("Welcome! Successful Admin Login");
		printf("Press any key to continue");
		admin_intro();
	}
}

void add()
{
	char a[100], b[100], c[100], d[100], e[100], f[100];

	printf("  Enter the Flight details ");

	printf("Flight ID: ");
	scanf("%s", a);
	printf("Destination: ");
	scanf("%s", b);
	printf("Origin: ");
	scanf("%s", c);
	printf("Date of Departure(DD/MM/YYYY): ");
	scanf("%s", f);
	printf("Time of Departure(xxxx hrs): ");
	scanf("%s", d);
	printf("Number of seats available ");
	scanf("%s", e);
	push_back_FlightID(FlightID, a);
	push_back_Destination(Destination, b);
	push_back_Origin(Origin, c);
	push_back_Time(Time, d);
	push_back_seats(seats, e);
	push_back_date(date, f);
	total = sizeof(FlightID) / sizeof(FlightID[0]);
	update();
	printf("Details have been successfully entered! Press enter to continue");
}

int search()
{
	int n = total;
	char word[100];
	int k = 0, t;

backagain:
	printf("Welcome to the free search menu");

	printf("1. Search by Flight ID");
	printf("2. Search by Destination");
	printf("3. Search by Orgin");
	printf("4. Search by Date and Time");
	printf("5. Skip Search.");
	printf("  Enter Your Choice [1-5] = ");

	scanf("%d", &t);

	if (t == 1)
	{
		int count = 0, line_count = 0, dd;
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Enter a valid Flight ID: ");
		scanf("%s", &word);
		int pos = 10;
		for (int i = 0; i < n; i++)
		{

			if (word == FlightID[i])
			{
				printf("%s\t", date[i]);
				printf("%s\t", FlightID[i]);
				printf("%s\t", Destination[i]);
				printf("%s\t", Origin[i]);
				printf("%s\t", Time[i]);
				printf("%s\t", seats[i]);
				count += 1;
				line_count += 1;
			}

			if (line_count == 11)
			{
				printf("Press 1 to see more or press 0 to exit the menu ");
				scanf("%d", &dd);
				if (dd == 1)
				{
					printf("Available flights");
					printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
					pos = 10;
					line_count = 0;
				}
				else
				{
					goto backagain;
				}
			}
		}
		if (count == 0)
		{
			printf("No such flight exists.");
			goto backagain;
		}
		printf("Press any key to continue.");
	}

	else if (t == 2)
	{
		int count = 0, line_count = 0, dd;
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Enter a valid Destination: ");
		scanf("%s", &word);
		int pos = 10;
		for (int i = 0; i < n; i++)
		{

			if (word == Destination[i])
			{

				printf("%s\t", date[i]);
				printf("%s\t", FlightID[i]);
				printf("%s\t", Destination[i]);
				printf("%s\t", Origin[i]);
				printf("%s\t", Time[i]);
				printf("%s\t", seats[i]);
				count += 1;
				line_count += 1;
			}
			if (line_count == 11)
			{
				printf("Press 1 to see more or press 0 to exit the menu ");
				scanf("%d", &dd);
				if (dd == 1)
				{

					printf("Available flights");
					printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
					pos = 10;
					line_count = 0;
				}
				else
				{
					goto backagain;
				}
			}
		}
		if (count == 0)
		{
			printf("No such flight exists.");
			goto backagain;
		}
		printf("Press any key to continue.");
	}

	else if (t == 3)
	{
		int count = 0, line_count = 0, dd;
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Enter a valid Origin: ");
		scanf("%s", &word);
		int pos = 10;

		for (int i = 0; i < n; i++)
		{

			if (word == Origin[i])
			{
				printf("%s\t", date[i]);
				printf("%s\t", FlightID[i]);
				printf("%s\t", Destination[i]);
				printf("%s\t", Origin[i]);
				printf("%s\t", Time[i]);
				printf("%s\t", seats[i]);
				printf("\n");
				count += 1;
				line_count += 1;
			}
			if (line_count == 11)
			{
				printf("Press 1 to see more or press 0 to exit the menu ");
				scanf("%d", &dd);
				if (dd == 1)
				{
					printf("Available flights");
					printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
					pos = 10;
					line_count = 0;
				}
				else
				{
					goto backagain;
				}
			}
		}
		if (count == 0)
		{
			printf("No such flight exists.");
			goto backagain;
		}
		printf("Press any key to continue.");
	}

	else if (t == 4)
	{
		int count = 0, g, line_count = 0, dd;
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Enter a date from Nov'20 to Dec'20 (DD/MM/YYYY): ");
		scanf("%s", &word);
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Press 1 to search for a specific time or 0 to list all flights: ");
		scanf("%d", &g);
		int pos = 10;
		if (g != 1)
		{

			for (int i = 0; i < n; i++)
			{

				if (word == date[i])
				{
					printf("%s\t", date[i]);
					printf("%s\t", FlightID[i]);
					printf("%s\t", Destination[i]);
					printf("%s\t", Origin[i]);
					printf("%s\t", Time[i]);
					printf("%s\t", seats[i]);
					count += 1;
					line_count += 1;
				}
				if (line_count == 11)
				{
					printf("Press 1 to see more or press 0 to exit the menu ");
					scanf("%d", &dd);
					if (dd == 1)
					{
						printf("Available flights");
						printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
						pos = 10;
						line_count = 0;
					}
					else
					{
						goto backagain;
					}
				}
			}
			if (count == 0)
			{
				printf("No such flight exists.");
				goto backagain;
			}
			printf("Press any key to continue.");
		}

		else
		{
			char times[100];
			printf("Available flights");
			printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
			printf("Enter time in 24 hours format: ");
			scanf("%s", &times);
			count = 0;
			pos = 10;
			for (int i = 0; i < n; i++)
			{

				if (word == date[i] && times == Time[i])
				{
					printf("%s\t", date[i]);
					printf("%s\t", FlightID[i]);
					printf("%s\t", Destination[i]);
					printf("%s\t", Origin[i]);
					printf("%s\t", Time[i]);
					printf("%s\t", seats[i]);
					printf("\n");
					count += 1;
					line_count += 1;
				}
				if (line_count == 11)
				{
					printf("Press 1 to see more or press 0 to exit the menu ");
					scanf("%d", &dd);
					if (dd == 1)
					{
						printf("Available flights");
						printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
						pos = 10;
						line_count = 0;
					}
					else
					{
						goto backagain;
					}
				}
			}
			if (count == 0)
			{
				printf("No such flight exists.");
				goto backagain;
			}
			printf("Press any key to continue.");
		}
	}

	else if (t == 5)
	{
		return 0;
	}
	else
	{
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Wrong option pressed!");
		goto backagain;
	}
}

void deleteone()
{
	search();
	printf("  Enter the flight details to be deleted ");

	char ID[20], dates[10];
	int recognised = -1;
	if (total == 0)
	{
		printf("You've no data to delete!'");
	}
	else
	{
		printf("Flight ID: ");
		scanf("%s", ID);
		printf("Date of the flight(DD/MM/YYYY): ");
		scanf("%s", dates);

		for (int i = 0; i < total; i++)
		{

			if (strcmp(FlightID[i], ID) == 0 && strcmp(date[i], dates) == 0)
			{
				FlightID[i] = "NA";
				Destination[i] = "NA";
				Origin[i] = "NA";
				Time[i] = "NA";
				seats[i] = "NA";
				date[i] = "NA";
				recognised += 1;
			}
		}

		if (recognised == -1)
		{
			printf("Sorry, there are no flights with the given Flight ID!");
		}
		else
		{
			total = sizeof(FlightID) / sizeof(FlightID[0]);
			update();
			printf("The data has been deleted!");
		}
	}
}

void edit()
{
	search();
	printf("  Enter the Flight details to be edited ");

	char ID[20], dat[10];
	int recognisedD = -1;
	int j;
	if (total == 0)
	{
		printf("You've no data to modify!'");
	}
	else
	{
		printf("Flight ID: ");
		scanf("%s", ID);
		printf("Date of the flight(DD/MM/YYYY): ");
		scanf("%s", dat);

		for (int i = 0; i < total; i++)
		{
			if (FlightID[i] == ID && date[i] == dat)
			{
				recognisedD = i;
			}
		}

		if (recognisedD != -1)
		{

			printf("What would you like to modify?");
			printf("1. Flight ID");
			printf("2. Destination");
			printf("3. Orgin");
			printf("4. Date");
			printf("5. Time");
			printf("6. Seats");
			printf("  Enter Your Choice [1-6] = ");
			scanf("%d", &j);

			if (j == 1)
			{
				char temp[20];
				printf(" Edit flight detail ");
				printf("Enter the modified Flight ID: ");
				scanf("%s", temp);
				FlightID[recognisedD] = temp;
			}

			if (j == 2)
			{
				char temp[20];
				printf(" Edit flight detail ");
				printf("Enter the modified Destination: ");
				scanf("%s", temp);
				Destination[recognisedD] = temp;
			}

			if (j == 3)
			{
				char temp[20];
				printf(" Edit flight detail ");
				printf("Enter the modified Origin: ");
				scanf("%s", temp);
				Origin[recognisedD] = temp;
			}
			if (j == 4)
			{
				char temp[10];
				printf(" Edit flight detail ");
				printf("Enter the modified Date(DD/MM/YYYY): ");
				scanf("%s", temp);
				date[recognisedD] = temp;
			}
			if (j == 5)
			{
				char temp[6];
				printf(" Edit flight detail ");
				printf("Enter the modified Time(24 hours) ");
				scanf("%s", temp);
				Time[recognisedD] = temp;
			}
			if (j == 6)
			{
				char temp[10];
				printf(" Edit flight detail ");
				printf("Enter the modified seats: ");
				scanf("%s", temp);
				seats[recognisedD] = temp;
			}
			update();
			printf("The details have been successfully modified!");
		}
	}

	if (recognisedD == -1)
	{
		printf("Sorry, there are no flights with the given Flight ID!");
	}
}

void admin_intro()
{
	int a, b;

back_admin:
	printf("Welcome Kripa! :)");
	printf("Kindly choose what change you'd like to make to the database.");

	printf("1. Add flights");
	printf("2. Delete flights");
	printf("3. Edit flight details");
	printf("4. Logout");

	printf("  Enter Your Choice [1-4] = ");

	scanf("%d", &a);

	if (a == 1)
	{
		add();

		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.\n");
		printf("  Enter Your Choice [0-1] = ");
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
		printf("Press any key to continue!");
		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.\n");
		printf("  Enter Your Choice [0-1] = ");

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
		printf("Press any key to continue!");
		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.");
		printf("  Enter Your Choice [0-1] = ");

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
		printf("Invalid Choice! Try again.");
		goto back_admin;
	}
}

void flight_data()
{

	FILE *ptr = fopen("Test.txt", "r");

	char a[100], b[100], c[100], d[100], e[100], f[100];
	while (fscanf(ptr, "%s %s %s %s %s %s", a, b, c, d, e, f) == 6)
	{
		push_back_FlightID(FlightID, a);
		push_back_Destination(Destination, b);
		push_back_Origin(Origin, c);
		push_back_Time(Time, d);
		push_back_seats(seats, e);
		push_back_date(date, f);
	}
	fclose(ptr);
	total = sizeof(FlightID) / sizeof(FlightID[0]);
}

int ticket(int i, struct customer_details d[], int *plan)
{
	int k, t, counter = 0;
	printf("Age: ");
	scanf("%d", &d[i].age);
	if (d[i].age <= 2)
	{
		printf("Ticket price is %d\n", infant);
		d[i].price = infant;
	}
	else if (d[i].age > 2 && d[i].age < 18)
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

	printf("Phone number: ");
	scanf("%s", d[i].Num);

seatsetting:
	printf("Seat number");
	scanf("%d", &k);

	for (t = 0; t < 100; t++)
	{
		if (plan[t] == k)
		{
			counter = 1;
		}
	}
	if (counter == 1)
	{
		d[i].seat_number = k;
		printf("%d", d[i].seat_number);
	}
	else
	{
		printf("    Invalid seat number. Please fill again");
		goto seatsetting;
	}
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

int *randomfunc(int n)
{
	int i, k = 0;
	bool arr[100] = {0};
	static int random[100] = {0};
	time_t t;
	srand((unsigned)time(&t));
	for (i = 0; i < n; ++i)
	{
		int r = rand() % 61;
		if (!arr[r] && r != 0)
		{
			random[k] = r;
			k++;
		}
		else
		{
			i--;
		}
		arr[r] = 1;
	}
	return random;
}

void seating(int n, int random[])
{
	int i, o, j, pos = 5;

	printf("  Seating Chart\n\n");

	printf("   x--------xx--------x\n   ");
	for (o = 1; o <= 60; o++)
	{
		printf("|");
		int counter = 0;
		for (j = 0; j < n; j++)
		{
			if (random[j] == o)
			{
				counter += 1;
			}
		}
		if (counter == 0)
		{
			if (o % 6 == 0)
			{
				printf("xx|\n   ");
			}
			else if (o % 3 == 0 && o % 6 != 0)
			{
				printf("xx|");
			}
			else
			{
				printf("xx");
			}
		}
		else
		{
			if (o % 6 == 0 && o / 10 == 0)
			{
				printf("0%d|\n   ", o);
			}
			else if (o % 3 == 0 && o % 6 != 0 && o / 10 == 0)
			{
				printf("0%d|", o);
			}
			else if (o % 3 == 0 && o % 6 != 0 && o / 10 != 0)
			{
				printf("%d|", o);
			}
			else if (o % 6 == 0 && o / 10 != 0)
			{
				printf("%d|\n   ", o);
			}
			else if (o % 3 != 0 && o % 6 != 0 && o / 10 == 0)
			{
				printf("0%d", o);
			}
			else
			{
				printf("%d", o);
			}
		}
	}
	printf("x--------xx--------x\n\n");
	printf(" xx--> unavailable seats.\n\n");
}

void TicketFunc(int n, int TicketNumber, int *plan)
{
	int age, i, j, q, n1 = n, b, sum = 0;
	struct customer_details d[TicketNumber];

	for (i = 0; i < TicketNumber; i++)
	{
		seating(n1, plan);
		printf("For Ticket %d:", i + 1);
		j = ticket(i, d, plan);
		for (q = 0; q < 100; q++)
		{
			if (plan[q] == j)
			{
				plan[q] = 0;
				--n1;
			}
		}
	}
	char str[10];
	itoa(n - TicketNumber, str, 10);
	seats[flight_book] = str;
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

int dayNumber(int day, int month, int year)
{

	static int t[] = {0, 3, 2, 5, 0, 3,
					  5, 1, 4, 6, 2, 4};
	year -= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

char getMonthName(int monthNumber)
{
	if (monthNumber == 0)
	{
		return "January";
	}

	if (monthNumber == 1)
	{
		return "February";
	}
	if (monthNumber == 2)
	{
		return "March";
	}
	if (monthNumber == 3)
	{
		return "April";
	}
	if (monthNumber == 4)
	{
		return "May";
	}
	if (monthNumber == 5)
	{
		return "June";
	}
	if (monthNumber == 6)
	{
		return "July";
	}
	if (monthNumber == 7)
	{
		return "August";
	}
	if (monthNumber == 8)
	{
		return "September";
	}
	if (monthNumber == 9)
	{
		return "October";
	}
	if (monthNumber == 10)
	{
		return "November";
	}
	if (monthNumber == 11)
	{
		return "December";
	}
}

void printCalendar(int year)
{

	printf("     \tCalendar - %d\n", year);

	int days;
	int current = dayNumber(1, 11, year);
	for (int i = 10; i < 12; i++)
	{
		if (i == 10)
		{
			days = 30;
		}
		else
		{
			days = 31;
		}

		printf("\n      ------------%s-------------\n  ",
			   getMonthName(i));

		printf("   Sun   Mon  Tue  Wed  Thu  Fri  Sat\n  ");

		int k;
		for (k = 0; k < current; k++)
			printf("     ");

		for (int j = 1; j <= days; j++)
		{
			printf("%5d", j);

			if (++k > 6)
			{
				k = 0;
				printf("\n  ");
			}
		}

		if (k)
			printf("\n  ");

		current = k;
	}
}

void display()
{
	printCalendar(2020);
	char dt[50];
	printf("Choose a date(DD/MM/YYYY): ");
	scanf("%s", dt);
	int n = total;
	int count = 0;
	printf("Available flights");
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
	int pos = 10;
	for (int i = 0; i < n; i++)
	{

		if (dt == date[i])
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
	printf("Press any key to continue.");
}

void user()
{
	int TicketNumber, i, j, b;
	char ID[20], dates[10];
check:

	printf("Welcome %s %s\n", u.firstname, u.lastname);
	printf("1. View calendar");
	printf("2. Free Search");
	printf("3. Book the flight");
	printf("4. Logout");

	printf("  Enter Your Choice [1-4] = ");

	scanf("%d", &i);
	if (i == 1)
	{
		display();
		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.\n");
		printf("  Enter Your Choice [0-1] = ");

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
		search();
		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.\n");
		printf("  Enter Your Choice [0-1] = ");

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

	else if (i == 3)
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

			for (int i = 0; i < total; i++)
			{

				if (strcmp(FlightID[i], ID) == 0 && strcmp(date[i], dates) == 0)
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
				int n = atoi(seats[flight_book]);

				int *plan = randomfunc(n);
			check2:
				printf("The number of available seats are %d", n);
				printf("Number of seats you wish to book: ");
				scanf("%d", &TicketNumber);
				if (TicketNumber <= n)
				{
					TicketFunc(n, TicketNumber, plan);
				}
				else
				{
					printf("Not enough seats available. Type another number!");
					goto check2;
				}
			}
		}
	}
	else if (i == 4)
	{
		intro();
	}
	else
	{
		printf("Invalid Choice! Try again.");
		goto check;
	}
}

void update()
{
	FILE *temp;
	temp = fopen("Test.txt", "w");
	for (int i = 0; i < total; i++)
	{
		const char *a = FlightID[i];
		const char *b = Destination[i];
		const char *c = Origin[i];
		const char *d = Time[i];
		const char *e = seats[i];
		const char *f = date[i];
		fprintf(temp, "%s %s %s %s %s %s\n", a, b, c, d, e, f);
	}
	fclose(temp);
}

int main()

{
	flight_data();
	intro();
	return 0;
}