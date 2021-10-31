#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void intro();											   // function for the introduction page with the small animation, logo and the 4 subfunctions under it- user sign up, user login, admin login and exit
void Register();										   // function for user registration
void Login();											   // function for user login
void admin();											   // function for admin login
void box(int a, int b, int c, int d);					   // box function with double line box for the main text
void box1(int a, int b, int c, int d);					   // function used for moving the cursor to particular coordinates of the screen
void delay(int milliseconds);							   // function to suspend the execution of the program/particular statement for a given time in milliseconds
void logo();											   // function that displays the logo of our airlines
void anime();											   // function that displays the animation of the airline
void add();												   // function that appends flight details to the internal database.
void deleteone();										   // function that deletes flight details from an internal database.
void edit();											   // function that edits or modifies flight details.
void admin_intro();										   // function to display admin page
void flight_data();										   // To input the Flight details to arrays, perform the edit/add/delete/search function
int search();											   // free search function
void user();											   // function to display user menu page
void update();											   // to update the file with all the changed details after the edit/add/delete function
int *randomfunc(int n);									   // function to return flight seating pattern with available seats
void seating(int n, int random[]);						   // prints the seating pattern for each booking for a flight
int ticket(int i, struct customer_details d[], int *plan); // collects data from customer about their details and stores it
void PrintTicket(struct customer_details p);			   // prints the ticket for each individual
void TicketFunc(int n, int TicketNumber, int *plan);	   // calls the ticket and PrintTicket function based on the total number of tickets to be booked and runs a loop for it

int total, flight_book = -1;				   // global variable where total stores the number of flights, flight_book stores the flight that the user books
int infant = 1000, child = 2200, adult = 3000; // global variable for prices of each seat based on age

struct login // This login structure will keep record of the person's name, email-id and user id during resgistration. The user id can be used later by the person to successfully login.
{
	char firstname[50];
	char lastname[20];
	char email[40];
	char username[50];

} u;

struct customer_details // stores values of details from the customer whose flight seat is being booked
{
	char FirstName[50];
	char LastName[50];
	int seat_number;
	int age;
	int price;
	char Num[11];
};

char FlightID[INT_MAX]; // All the arrays to store the flight details from the file, to perform the various operations on
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
void intro() // function which has 4 subfunctions under it - user sign up, user login, admin login and exit
{
	int i, j; // i and j are integer variables

check: // indicator to come back to this portion of the code while executing later functions under void intro
	printf("WELCOME TO VISTARA AIR");
	printf("1. User Sign Up"); // the user can select 4 options displayed on the screen. Selecting 1 will lead to user registration for creating valid user ID required for flight booking.
	printf("2. User Login");   // selecting 2 will help the user with existing valid user ID to login to the reservation system for booking
	printf("3. Admin Login");  // the admin will have unique ID and password. Selecting 3 will onky enable the admin to login and modify flight timing and availability of flights.
	printf("4. Exit\n ");	   // finally select 4 to exit the flight reseravtion system

	printf("  Enter Your Choice [1-4] = "); // the user will be asked to enter any one of the 4 choices displayed on the screen

	scanf("%d", &i); // the choice of the user will be scanned from the console

	if (i == 1)
	{
		Register();
		printf("Press 0 to go Back to Main Page");
		printf("Press 1 to Exit\n");
		printf(" Enter Your Choice [0-1]= ");
		scanf("%d", &j); // after registration and successful login the user can either choose to exit or go back to the main page
		if (j == 0)		 // selcting 0 will take the user back to the main page
		{
			goto check;
		}
		else if (j == 1) // selcting 1 will help the user to exit the flight reseravtion system
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
		scanf("%d", &j); // after successful login the user can either choose to exit or go back to the main page
		if (j == 0)
		{

			goto check;
		}
		else if (j == 1)
		{
			exit(0);
		}
	}
	else if (i == 3) // if the user gives an input of 3 then he/she will be directed to the admin page
	{
		admin();
		printf("Press any key to continue\n");
		printf("Press 0 to go Back to Main Page");
		printf("Press 1 to Exit\n");
		printf(" Enter Your Choice [0-1]= "); // after successful login the admin can either choose to exit or go back to the main page
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
		// screen cleared
		exit(0);
	}
}

void Register() // function for user registration
{
	char user[50];
	int s;	  // integer variable s is defined
	FILE *fp; // to read or write in the file fp a pointer (*) is required. FILE is some kind of structure that holds information about the file in C.
	if (fp = fopen("login.txt", "r"))
	{					  // to check whether fp file exists or not. If the file exists then it will direct to credentials part of the code to check whether the user ID already exists in the file fp or not.
		fclose(fp);		  // fclose is used to close the file fp
		goto credentials; // credentials is an indicator
	}
	else
	{ // if the file does not exist then a file will open in the write mode to enter the user details
		struct login a;
		fp = fopen("login.txt", "w"); // opens a file named login.txt in writing mode
		printf(" Enter the user account details ");
		printf("Enter first name: "); // user's name, email id and username will be asked to enter
		scanf("%s", a.firstname);
		printf("Enter last name: ");
		scanf("%s", a.lastname);
		printf("Enter email id: ");
		scanf("%s", a.email);
		printf("Enter username: ");
		scanf("%s", a.username); // the user name and email id will be taken by the system but the username will first be screened against the existing list of usernames to avoid duplication of the any user ID. The user ID should be unique for every user.

		fwrite(&a, sizeof(a), 1, fp); // writes the information in the file fp
		fclose(fp);
		goto next; // next is another indicator
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

	s = 0; // initialising s=0
	while (!feof(fp))

	{
		fread(&b, sizeof(b), 1, fp);	   // check whether the user ID/username already exists in the login.txt file or not
		if (strcmp(user, b.username) == 0) // strcmp function is used to compare between two string: the entered user ID against a list of existing user IDs in the file login.txt
		{
			s += 1; // if the entered user ID matches against an existing username then 1 will be added to s for every iteration.
		}
	} // if there is no match between the existing username in the list and the one entered by the user then s will adopt a value of 0.

	if (s > 0) // thus s>0 implies there is a match and hence the user should register with a different user ID

	{
		printf("User ID already exists"); // if s>0 then the username already exists; if s=0 then the username will be accepted as a new user ID
		printf("Enter a different User ID");
		printf("Press any key to continue");
		goto credentials;
	}
	else
	{
		fclose(fp);
		printf("Re-enter User name: "); // if there is no match the user will be asked to re-enter the username
		scanf("%s", a.username);

		fp = fopen("login.txt", "a"); // login.txt is now opened in append mode since everytime a new person registers, his/her personal information will be added to the file, to be accesssed later for login.
		fwrite(&a, sizeof(a), 1, fp); // the details recorded in struct login will be now appended to the file fp
		fclose(fp);					  // file is closed
	}
next:
	// used for clearing the screen of the console

	printf("Your Username is the unique UserID\n");
	printf("Press any key to login with new UserID\n");
	printf("Press any key to continue\n");
	Login(); // directly continue to the login page after registration
}

void Login() // function for the user to log-in with valid user ID to continue flight booking
{
	char username[50];
	int sum = 0;

	FILE *fp; // fp file will be pointed to open
	if (fp = fopen("login.txt", "r"))
	{ // to check whether fp file exists or not. If the file exists then it will direct to credentials part of the code to check whether the user ID already exists in the file fp or not.
		fclose(fp);
		goto login;
	}
	else
	{
		printf("No user ID has been registered in the file. Sign-up first to Continue");
		printf("Press any key to go back and Sign-up first");
		intro();
	}

login:							  // indicator
	fp = fopen("login.txt", "r"); // fp file wil now be opened in the reading mode

	struct login a;

	printf("Enter valid UserID: "); // the user has to enter valid User ID that he/she had registered with
	scanf("%s", &username);			// scanning the username given as an input from the user

	while (!feof(fp)) // feof means the fp file will be read till the end

	{
		fread(&a, sizeof(a), 1, fp);
		if (strcmp(username, a.username) == 0) //  strcmp function used for comparing two strings- the User ID taken as an input from the console and separately checking it against all the User IDs in the file fp. if the input matches the user ID in the file fp then strcmp will give 0
		{
			sum += 1; // sum is integer variable with initial value 0. For a match, 1 will be added to sum variable and its value will be updated. Fora mismatch the sum will take 0 which was its initial value
			strcpy(u.username, a.username);
			strcpy(u.firstname, a.firstname);
			strcpy(u.email, a.email);
			strcpy(u.lastname, a.lastname);
		}
	}
	if (sum > 0) // thus sum>0 if the input matches the user ID in the file

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

//***************************************ADMIN MODULE***************************************//

void admin() // the admin cannot register using the user regstration module. the admin has unique ID and password to exercise its power in the reservation system
{
	char username[50];
	char password[20];
adminuser: // indicator
	printf(" Sign in to the admin account ");
	printf("Enter Valid Admin ID: "); // valid admin id is vistara
	scanf("%s", &username);
	printf("Enter Valid Password: "); // valid password is iiserk
	scanf("%s", &password);
	if (strcmp(username, "vistara") == 0) // strcmp is used to compare the input string and "vistara"
	{
		printf("Admin ID is Valid"); // if the valid admin ID is enterd the strcmp function will give 0 and the user ID will be accepted
		printf("Press any key to continue");
	}
	else
	{
		printf("Invalid Admin ID");									 // for a mismatch this will be printed on the screen
		printf("Press any key to go back and enter valid Admin ID"); // if invalid user ID is displayed on the screen the user will be allowed to go back and enter the valid admin ID to continue
		goto adminuser;												 // indicator to go back and enter the admin ID again
	}
	if (strcmp(password, "iiserk") == 0) // strcmp is used to compare the input string and "iiserk"
	{
		printf("Password is Valid"); // if the valid password is enterd the strcmp function will give 0 and the password will be accepted
		printf("Press any key to continue");
	}
	else
	{
		printf("Invalid Password");									 // for a mismatch this will be printed on the screen
		printf("Press any key to go back and enter valid Password"); // if the user enters invalid password he will be directed to go back and enter valid admin details to continue
		goto adminuser;												 // indicator to go back and enter the admin ID and password again
	}
	if (strcmp(username, "vistara") == 0 && strcmp(password, "iiserk") == 0) // only by entering the valid admin ID and password the admin log in will be allowed.
	{
		printf("Welcome! Successful Admin Login");
		printf("Press any key to continue");
		admin_intro();
	}
}

void add() // This function adds new flight details into the internal database when admin opts for it.
{
	char a[100], b[100], c[100], d[100], e[100], f[100]; // 6 char variables are declared.

	printf("  Enter the Flight details "); // asks the user to enter the details of the new flight.

	printf("Flight ID: "); // asks for the FlightID (the same happens for every other information about the fight)
	scanf("%s", a);		   // scans the input from the console (the same happens for every other information about the flight)
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
	push_back_FlightID(FlightID, a);	   // the new char variable value corresponding to the Flight ID is inserted at the end of the vector and the container size is increased by 1.
	push_back_Destination(Destination, b); //(same as above for all the other details of the flight)
	push_back_Origin(Origin, c);
	push_back_Time(Time, d);
	push_back_seats(seats, e);
	push_back_date(date, f);
	total = sizeof(FlightID) / sizeof(FlightID[0]);
	update(); // calls the update function to update the text file.
	printf("Details have been successfully entered! Press enter to continue");
	// waits and reads a single character from the console
}

int search() // search function presents a search menu that allows to view the desired flights.
{
	int n = total; // gives the value of the total number of flights in the database.
	char word[100];
	int k = 0, t; // required variables declared.

backagain:									   // clears the output screen.
	printf("Welcome to the free search menu"); // prints the welcome message

	printf("1. Search by Flight ID"); // desplays the options on the screen.
	printf("2. Search by Destination");
	printf("3. Search by Orgin");
	printf("4. Search by Date and Time");
	printf("5. Skip Search.");
	printf("  Enter Your Choice [1-5] = ");

	scanf("%d", &t); // the option chosen is scanned from the console and stored in the t variable.

	if (t == 1) // Search by flight ID
	{
		int count = 0, line_count = 0, dd; // count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page)
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); // It prints the title to the relevant data
		printf("Enter a valid Flight ID: ");
		scanf("%s", &word);			// the flight ID of the required flight data is stored in word.
		int pos = 10;				// the pos variable gives the y coordinate for the gotoxy function.
		for (int i = 0; i < n; i++) // this loop runs over the total number of flights.
		{

			if (word == FlightID[i]) // if the word variable becomes equal to a flight ID, then the details of those flights are printed.
			{
				printf("%s\t", date[i]); // prints the flight details for that flight.
				printf("%s\t", FlightID[i]);
				printf("%s\t", Destination[i]);
				printf("%s\t", Origin[i]);
				printf("%s\t", Time[i]);
				printf("%s\t", seats[i]);
				count += 1;		 // the number of available relevant flights is increased by 1.
				line_count += 1; // updates the count of the number of lines displayed.
			}

			if (line_count == 11) // To show the flights page wise(11 lines in a page)
			{
				printf("Press 1 to see more or press 0 to exit the menu ");
				scanf("%d", &dd); // takes the input into dd variable.
				if (dd == 1)
				{
					printf("Available flights");				 // prints this in the new screen
					printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); // The title for the new screen is printed.
					pos = 10;									 // the y coordinate is updated to the beginning like in the first page.
					line_count = 0;								 // line_count is set to 0 to further count it for this new page of data.
				}
				else
				{
					goto backagain; // exits the menu and goes back to the beginning of the search menu.
				}
			}
		}
		if (count == 0) // in case we get no results for the relevant flights, ie, when coun is 0;
		{
			printf("No such flight exists."); // it prints that there are no relevant flights.
			goto backagain;					  // goes back to the beginning of the seach menu.
		}
		printf("Press any key to continue.");
	}

	else if (t == 2) // To search by destination
	{
		int count = 0, line_count = 0, dd; // count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page)
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); // It prints the title to the relevant data
		printf("Enter a valid Destination: ");		 // the Destination of the required flight data is stored in word.
		scanf("%s", &word);
		int pos = 10;
		for (int i = 0; i < n; i++) // this loop runs over the total number of flights.
		{

			if (word == Destination[i]) // if the destination of a flight becomes equal to the word entered.
			{

				printf("%s\t", date[i]); // the relevant flight data is printed on the screen.
				printf("%s\t", FlightID[i]);
				printf("%s\t", Destination[i]);
				printf("%s\t", Origin[i]);
				printf("%s\t", Time[i]);
				printf("%s\t", seats[i]);
				count += 1;		 // the count variable is increased by 1.
				line_count += 1; // the line count is also updated.
			}
			if (line_count == 11) // once the page is filled, it asks if more data has to be displayed. If the answer is yes, it does so. Else, it goes to the beginning of the search menu.
			{
				printf("Press 1 to see more or press 0 to exit the menu ");
				scanf("%d", &dd); // the choice is updated in dd.
				if (dd == 1)	  // when more flight details has to be displayed;
				{
					// the screen is cleared.
					printf("Available flights");
					printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); // prints the title for the data in this page.
					pos = 10;									 // the y coordinate is again set to 10, like in the start of the first page.
					line_count = 0;								 // line count is set to 0.
				}
				else
				{
					goto backagain; // goes to the beginning of the search menu.
				}
			}
		}
		if (count == 0) // if theres no relevant data
		{
			printf("No such flight exists."); // prints that theres no data
			goto backagain;					  // goes back to the beginning of the search menu.
		}
		printf("Press any key to continue.");
	}

	else if (t == 3) // To search by origin
	{
		int count = 0, line_count = 0, dd; // count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page)
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Enter a valid Origin: "); // the Origin of the required flight data is stored in word.
		scanf("%s", &word);
		int pos = 10;

		for (int i = 0; i < n; i++) // this loop runs over the total number of flights.
		{

			if (word == Origin[i]) // when the origin of a flight becomes equal to the word entered.
			{
				printf("%s\t", date[i]);
				printf("%s\t", FlightID[i]);
				printf("%s\t", Destination[i]);
				printf("%s\t", Origin[i]);
				printf("%s\t", Time[i]);
				printf("%s\t", seats[i]);
				printf("\n");
				count += 1;		 // count variable is updated.
				line_count += 1; // the no of lines in the output is also updated.
			}
			if (line_count == 11) // when the page is filled;
			{
				printf("Press 1 to see more or press 0 to exit the menu ");
				scanf("%d", &dd); // the choice is updated in dd.
				if (dd == 1)	  // when more details are required;
				{
					printf("Available flights");
					printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
					pos = 10;
					line_count = 0; // the line count is set to 0 to further print the output on this page.
				}
				else
				{
					goto backagain; // when no more output is required, it goes to the beginning of the search menu.
				}
			}
		}
		if (count == 0) // when theres no relevant data;
		{
			printf("No such flight exists.");
			goto backagain; // goes to the beginning of the search menu.
		}
		printf("Press any key to continue.");
	}

	else if (t == 4) // To search by date and time
	{
		int count = 0, g, line_count = 0, dd; // count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page). g and dd stores the choice by the user.
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Enter a date from Nov'20 to Dec'20 (DD/MM/YYYY): "); // the data of the required flight data is stored in word.
		scanf("%s", &word);											 // scans the input and stores in word.
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Press 1 to search for a specific time or 0 to list all flights: ");
		scanf("%d", &g); // scans the choice given and stores in g.
		int pos = 10;
		if (g != 1) // To print all flights for a date
		{

			for (int i = 0; i < n; i++) // this loop runs over the total number of flights.
			{

				if (word == date[i]) // when date of the flight is equal to the word entered;
				{
					printf("%s\t", date[i]); // relevant data is printed on the screen.
					printf("%s\t", FlightID[i]);
					printf("%s\t", Destination[i]);
					printf("%s\t", Origin[i]);
					printf("%s\t", Time[i]);
					printf("%s\t", seats[i]);
					count += 1;		 // count variable is updated.
					line_count += 1; // the line count is updated each time a relevant data is encountered.
				}
				if (line_count == 11) // when the output page is filled;
				{
					printf("Press 1 to see more or press 0 to exit the menu ");
					scanf("%d", &dd);
					if (dd == 1) // when more data is required;
					{
						printf("Available flights");
						printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
						pos = 10; // position variable and line count are set to the values as in the first page.
						line_count = 0;
					}
					else
					{
						goto backagain; // goes to the beginning of the search menu.
					}
				}
			}
			if (count == 0) // when theres no relevant data;
			{
				printf("No such flight exists."); // prints it
				goto backagain;					  // goes to the beginning of the search menu.
			}
			printf("Press any key to continue.");
		}

		else // Particular date and time
		{
			char times[100];
			printf("Available flights");
			printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
			printf("Enter time in 24 hours format: ");
			scanf("%s", &times); // the time entered is stored in times.
			count = 0;
			pos = 10;
			for (int i = 0; i < n; i++) // runs through the list of all the flights.
			{

				if (word == date[i] && times == Time[i]) // when both the date and the time of the flights match to the ones entered, the same process is repeated.
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

	else if (t == 5) // To exit free search
	{
		return 0;
	}
	else // when the option entered is not relevant.
	{
		printf("Available flights");
		printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
		printf("Wrong option pressed!");
		goto backagain; // goes to the beginning of the search menu.
	}
}

void deleteone() // the function to delete a flight detail of a chosen Flight ID and date
{
	search(); // the search function is called.
	printf("  Enter the flight details to be deleted ");

	char ID[20], dates[10]; // Two char variable are declared, which will hold the Flight ID and the date of the flight whose details have to be deleted.
	int recognised = -1;	// A marker variable whose value tells us if the flight of the given ID exists.
	if (total == 0)			// If the file is empty, there's no data to delete.
	{
		printf("You've no data to delete!'");
	}
	else // If the file is not empty;
	{
		printf("Flight ID: ");
		scanf("%s", ID); // the flight ID entered is stored in ID variable.
		printf("Date of the flight(DD/MM/YYYY): ");
		scanf("%s", dates); // the date entered is stored in dates.

		for (int i = 0; i < total; i++) // this loop runs through the total number of flights in the database.
		{

			if (strcmp(FlightID[i], ID) == 0 && strcmp(date[i], dates) == 0) // when the flight ID and the date entered match with one of the entries in the database;
			{
				FlightID[i] = "NA"; // the flight details associated with this flight is deleted.
				Destination[i] = "NA";
				Origin[i] = "NA";
				Time[i] = "NA";
				seats[i] = "NA";
				date[i] = "NA";
				recognised += 1; // the marker variable is set to 0.
			}
		}

		if (recognised == -1) // When there are no matching entries for the flight IDs: we print it!
		{
			printf("Sorry, there are no flights with the given Flight ID!");
		}
		else // when theres a matching entry;
		{
			total = sizeof(FlightID) / sizeof(FlightID[0]); // the size of the FlightID vector is stored in total.
			update();										// the update function is called.
			printf("The data has been deleted!");
		}
	}
}

void edit() // the function to edit a flight detail of a given flight ID and date.
{
	search(); // the search function is called.
	printf("  Enter the Flight details to be edited ");

	char ID[20], dat[10]; // two char variables are declared.
	int recognisedD = -1; // A variable taht stores the index value of the entry that has to be edited.
	int j;				  // a variable to store a choice entered.
	if (total == 0)		  // If the file is empty, there's no data to edit.
	{
		printf("You've no data to modify!'");
	}
	else // If the file is not empty;
	{
		printf("Flight ID: ");
		scanf("%s", ID); // scans and stores the flight ID entered into ID variable.
		printf("Date of the flight(DD/MM/YYYY): ");
		scanf("%s", dat); // scans and stores the date entered into the dat variable.

		for (int i = 0; i < total; i++) // runs through the total number of flights.
		{
			if (FlightID[i] == ID && date[i] == dat) // when both the flight ID and the date of an entry match with those entered;
			{
				recognisedD = i; // the index variable of that entry is stored into recognised.
			}
		}

		if (recognisedD != -1) // when there is a relevant entry;
		{
			// clears the screen.
			printf("What would you like to modify?");
			printf("1. Flight ID");
			printf("2. Destination");
			printf("3. Orgin");
			printf("4. Date");
			printf("5. Time");
			printf("6. Seats");
			printf("  Enter Your Choice [1-6] = ");
			scanf("%d", &j); // the choice is stored in j.

			if (j == 1) // if the flight ID has to be modified
			{
				char temp[20]; // a temp variable of character datatype is declared.
				printf(" Edit flight detail ");
				printf("Enter the modified Flight ID: ");
				scanf("%s", temp);			  // temp stores the new flight ID.
				FlightID[recognisedD] = temp; // this new flight ID is dumped into the index of the Flight ID that has to be modified.
			}

			if (j == 2) // if the destination has to be modified
			{
				char temp[20]; // a temp variable of character datatype is declared.
				printf(" Edit flight detail ");
				printf("Enter the modified Destination: ");
				scanf("%s", temp);				 // the entry is scanned and stored in the temp variable
				Destination[recognisedD] = temp; // this new destination is dumped into the index of the flight to be modified.
			}

			if (j == 3) // if the origin has to be modified
			{
				char temp[20]; // a char variable called temp is declared.
				printf(" Edit flight detail ");
				printf("Enter the modified Origin: ");
				scanf("%s", temp);			// the new origin is stored in temp.
				Origin[recognisedD] = temp; // this new origin is dumped into the index corresponding to the flight entry to be modified.
			}
			if (j == 4) // if the date has to be modified
			{
				char temp[10]; // a char variable called temp is declared.
				printf(" Edit flight detail ");
				printf("Enter the modified Date(DD/MM/YYYY): ");
				scanf("%s", temp);		  // the new date is stored in temp.
				date[recognisedD] = temp; // this new date entered is dumped into the index corresponding to the flight entry to be modified.
			}
			if (j == 5) // if the time has to be modified
			{
				char temp[6]; // a char variable temp is declared.
				printf(" Edit flight detail ");
				printf("Enter the modified Time(24 hours) ");
				scanf("%s", temp);		  // the new, modified time is stored in temp.
				Time[recognisedD] = temp; // the new time entered is dumped into the index corresponding to the flight entry to be modified.
			}
			if (j == 6) // if the no of seats has to be modified
			{
				char temp[10];
				printf(" Edit flight detail ");
				printf("Enter the modified seats: ");
				scanf("%s", temp);		   // the modifies no of seats is stored in temp.
				seats[recognisedD] = temp; // the new no of seats is dumped into the index corresponding to the flight entry to be modified.
			}
			update(); // updates the file containing flight details
			printf("The details have been successfully modified!");
		}
	}

	if (recognisedD == -1) // the recognisedD variable has not been modified. It serves as a marker, indicating there are no relevant entry. We print it.
	{
		printf("Sorry, there are no flights with the given Flight ID!");
	}
}

void admin_intro() // the function that presents the list of operations for the admin and directs him to these options.
{
	int a, b; // two choice variables of int datatype declared.

back_admin: // an identifier that brings us back to this part of the code from some other part of the code or function.
	printf("Welcome vistara! :)");
	printf("Kindly choose what change you'd like to make to the database.");

	printf("1. Add flights");
	printf("2. Delete flights");
	printf("3. Edit flight details");
	printf("4. Logout");

	printf("  Enter Your Choice [1-4] = ");

	scanf("%d", &a); // scans the choice and stores into a.
					 // clears the screen.

	if (a == 1) // To add a flight
	{
		add(); // calls the add function

		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.\n");
		printf("  Enter Your Choice [0-1] = "); // redirects the admin further to choose between going back to the main page or to exit.
		scanf("%d", &b);						// scans the choice to continue or exit into b.

		if (b == 0) // if the admin chooses to go back, we go to that part of the code again, for which we use the goto command.
		{
			goto back_admin;
		}
		else if (b == 1) // we exit if the admin chooses so.
		{
			exit(0);
		}
	}

	if (a == 2) // To delete a flight
	{
		deleteone(); // calls the deleteone function.
		printf("Press any key to continue!");
		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.\n");
		printf("  Enter Your Choice [0-1] = "); // redirects the admin further to choose between going back to the main page or to exit.

		scanf("%d", &b); // scans the choice to continue or exit into b.

		if (b == 0) // if the admin chooses to go back, we go to that part of the code again, for which we use the goto command.
		{
			goto back_admin;
		}
		else if (b == 1) // we exit if the admin chooses so.
		{
			exit(0);
		}
	}

	if (a == 3) // To edit a flight
	{
		edit(); // calls the edit function.
		printf("Press any key to continue!");
		printf("Press 0 to go back to the main page.");
		printf("Press 1 to Exit.");
		printf("  Enter Your Choice [0-1] = "); // redirects the admin further to choose between going back to the main page or to exit.

		scanf("%d", &b); // scans the choice to continue or exit into b.

		if (b == 0) // if the admin chooses to go back, we go to that part of the code again, for which we use the goto command.
		{
			goto back_admin;
		}
		else if (b == 1) // we exit if the admin chooses so
		{
			exit(0);
		}
	}

	if (a == 4) // To logout.
	{
		intro(); // The intro function is called.
	}

	else // if any choice other than 1-4 is entered, we print: Invalid Choice!
	{
		printf("Invalid Choice! Try again.");
		goto back_admin; // goes to the beginning of the admin intro.
	}
}

void flight_data() // reads flight data from the file
{

	FILE *ptr = fopen("Test.txt", "r");

	char a[100], b[100], c[100], d[100], e[100], f[100];
	while (fscanf(ptr, "%s %s %s %s %s %s", a, b, c, d, e, f) == 6)
	{
		push_back_FlightID(FlightID, a);	   // the new char variable value corresponding to the Flight ID is inserted at the end of the vector and the container size is increased by 1.
		push_back_Destination(Destination, b); //(same as above for all the other details of the flight)
		push_back_Origin(Origin, c);
		push_back_Time(Time, d);
		push_back_seats(seats, e);
		push_back_date(date, f);
	}
	fclose(ptr);
	total = sizeof(FlightID) / sizeof(FlightID[0]);
}

//******************************************************************************************************************//

int ticket(int i, struct customer_details d[], int *plan) // Input value from customer about their details
{
	int k, t, counter = 0;
	printf("Age: "); // Asks for age from user
	scanf("%d", &d[i].age);
	if (d[i].age <= 2)
	{
		printf("Ticket price is %d\n", infant);
		d[i].price = infant; // the pricing based on age is stored in the global struct customer_details d[]
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

	printf("First Name: "); // the details taken are stored in global struct customer_details d[] to be used to print for the ticket
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
		if (plan[t] == k) // If the seat number selected is a valid seat, the counter is given a value of 1, if not then counter remains as 0
		{
			counter = 1;
		}
	}
	if (counter == 1)
	{
		d[i].seat_number = k;
		printf("%d", d[i].seat_number); // Only if counter value==1 then the seat number is stored
	}
	else
	{
		printf("    Invalid seat number. Please fill again"); // Else the following statement is shown and a valid seat number is requested
		goto seatsetting;
	}
	return d[i].seat_number;
}

void PrintTicket(struct customer_details p) // Prints out ticket on screen and as a text file
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

int *randomfunc(int n) // randomizes the flight seating pattern for each flight
{
	int i, k = 0;
	bool arr[100] = {0}; // array which stores boolean values
	static int random[100] = {0};
	time_t t;
	srand((unsigned)time(&t));
	for (i = 0; i < n; ++i)
	{
		int r = rand() % 61;   // random number generated between 0-60
		if (!arr[r] && r != 0) // condition to check for repitition and to exclude 0
		{
			random[k] = r;
			k++;
		}
		else
		{
			i--;
		}
		arr[r] = 1; // boolean value updated from 0 to 1
	}
	return random; // returns the seating chart
}

void seating(int n, int random[]) // prints the seating chart for each flight
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

void TicketFunc(int n, int TicketNumber, int *plan) // Main function for Taking, Storing and Printing Ticket details
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

// Calculates the Index of the day from 0 to 6 i.e. If the given date of the given month appears on a Sunday(0), Monday(1), Tuesday(2), etc.
int dayNumber(int day, int month, int year) // Function required to print the calendar
{

	static int t[] = {0, 3, 2, 5, 0, 3,
					  5, 1, 4, 6, 2, 4}; // set of indices for a particular date
	year -= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

/* Function that returns the name of the
 month for the given month Number
 January - 0, February - 1 and so on */

char getMonthName(int monthNumber) // Function required to print the calendar
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

void printCalendar(int year) // Function that prints the calendar for the given year
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

		// Print the current month name
		printf("\n      ------------%s-------------\n  ",
			   getMonthName(i));

		// Print the columns
		printf("   Sun   Mon  Tue  Wed  Thu  Fri  Sat\n  ");

		// Print appropriate spaces
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

void display() // Function To display a calendar and the flights for the chosen date.
{
	printCalendar(2020); // prints calendar
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

		if (dt == date[i]) // displays the available flights for the entered date
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

void user() // Function to Display all the options available to User which are: View Calendar, Free search, Book a flight
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
	flight_data(); // function to read the flight data from Test.txt file
	intro();
	return 0;
}
