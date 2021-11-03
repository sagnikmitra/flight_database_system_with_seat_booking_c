              
/* * * * * * * * * * * * * * * * * * * * * BHARAT AIR FLIGHT BOOKING SYSTEM  * * * * * * * * * * * * * * * * * * * * * * * *\
*																															*
*											     Group 13																	*
*											Yeshma Ibrahim(16MS123)															*
*										Dhanashree Sandeep Somani(17MS087)													*
*											Estuti Shukla (16MS068)															*
*											Nilanjana Nandi(16MS190) 														*
*										Vadlamannati Vijaya Arunima(16MS004)												*
*																															*	
*						An interactive flight booking system with two modes available. 										*
*						 																									*
*						1. Admin Mode (User ID - kripa, Password- iiserk)													*
*						2. User Mode																						*
*																															*
*	The admin mode allows the airline personnel to edit/delete/add flights to the flight database stored in Test.txt file.  *
*	The user mode is for searching and booking flights. The user first needs to create an account with a unique user ID.    *
*	The credentials of each user are stored in login.txt file. After the booking has been made, the final boarding pass is  *
*	saved in boarding.txt file.																							*					
*																															* 
* * * * * * * * * * * * * * * * * * * * * BHARAT AIR FLIGHT BOOKING SYSTEM  * * * * * * * * * * * * * * * * * * * * * * * * */

//including required header files

#include<stdio.h>
#include<conio.h>
#include<bits.h>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h> 
#include<windows.h>
#include<time.h>


// defining the functions

void intro(); 						                                // function for the introduction page with the small animation, logo and the 4 subfunctions under it- user sign up, user login, admin login and exit 
void Register(); 					                                // function for user registration
void Login(); 						                                // function for user login
void admin();						                                // function for admin login 
void box(int a,int b,int c,int d); 	                                // box function with double line box for the main text
void box1(int a,int b,int c,int d);	                                // box function with single line box for the sub text
void gotoxy(short x, short y); 		                                // function used for moving the cursor to particular coordinates of the screen
void delay(int milliseconds); 		                                // function to suspend the execution of the program/particular statement for a given time in milliseconds
void logo() ;                  		                                // function that displays the logo of our airlines
void anime();                  		                                // function that displays the animation of the airline
void add(); 						                                //function that appends flight details to the internal database.
void deleteone(); 					                                //function that deletes flight details from an internal database.
void edit(); 						                                //function that edits or modifies flight details.
void admin_intro();					                                // function to display admin page
void flight_data();					                                // To input the Flight details to arrays, perform the edit/add/delete/search function
int search(); 						                                // free search function
void user();						                                //function to display user menu page
void update(); 						                                //to update the file with all the changed details after the edit/add/delete function
int * randomfunc (int n);			                                //function to return flight seating pattern with available seats
void seating(int n, int random[]);	                                //prints the seating pattern for each booking for a flight
int ticket (int i, struct customer_details d[], int * plan);        //collects data from customer about their details and stores it
void PrintTicket(struct customer_details p);                        //prints the ticket for each individual
void TicketFunc(int n, int TicketNumber, int * plan);               //calls the ticket and PrintTicket function based on the total number of tickets to be booked and runs a loop for it


int total,flight_book=-1; 				//global variable where total stores the number of flights, flight_book stores the flight that the user books
int infant=1000,child=2200,adult=3000;	//global variable for prices of each seat based on age

// struct is an user defined data type available in C that allows to combine data items of different kinds. Structures are used to represent a record.


struct login							// This login structure will keep record of the person's name, email-id and user id during resgistration. The user id can be used later by the person to successfully login. 
{
	char firstname[50]; 
	char lastname[20];
	char email[40];
	char username[50];
	
}u;


struct customer_details 				//stores values of details from the customer whose flight seat is being booked
{
	char FirstName[50];
	char LastName[50];
	int seat_number;
	int age;
	int price;
	char Num[11];
};

using namespace std;

vector<string> FlightID;			 // All the arrays to store the flight details from the file, to perform the various operations on
vector<string> Destination;
vector<string> Origin;
vector<string> Time;
vector<string> seats;
vector<string> date;

void ShowCursor(bool show) 				// defining the function for hiding or showing the cursor. 
{
    HANDLE hConsoleOutput; 
    CONSOLE_CURSOR_INFO structCursorInfo;
    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
    structCursorInfo.bVisible = show;
    SetConsoleCursorInfo( hConsoleOutput,
    &structCursorInfo );
}
	
void anime()    						// fucntion for the display of the small animation
{ 
 int speed1=90;                  		
 									   // starting animation
 ShowCursor(false);             		// hide cursor during animation
 system("CLS");                 		// clear screen
 printf("\n**       ");
 printf("\n* ****** ");
 printf("\n*       *");
 printf("\n******** ");
 printf("\n   * *   ");
 printf("\n   **    ");
 delay(speed1);                 	 // delay the execution of next function by 90 millisecond stored in integer variable speed1
 system("CLS");
 printf("\n  **       ");
 printf("\n  * ****** ");
 printf("\n  *       *");
 printf("\n  ******** ");
 printf("\n     * *   ");                  // printing the starting animation of Bharat Air
 printf("\n     **    ");                     
 delay(speed1);
 system("CLS");
 printf("\n    **       ");
 printf("\n    * ****** ");
 printf("\n    *       *");
 printf("\n    ******** ");
 printf("\n       * *   ");
 printf("\n       **    ");
 delay(speed1);
 system("CLS");
 printf("\n      **       ");
 printf("\n      * ****** ");
 printf("\n      *       *");
 printf("\n      ******** ");
 printf("\n         * *   ");
 printf("\n         **    ");
 delay(speed1);
 system("CLS");
 printf("\n        **       ");
 printf("\n        * ****** ");
 printf("\n        *       *");
 printf("\n        ******** ");
 printf("\n           * *   ");
 printf("\n           **    ");
 delay(speed1);
 system("CLS");
 printf("\n          **       ");
 printf("\n          * ****** ");
 printf("\n          *       *");
 printf("\n          ******** ");
 printf("\n             * *   ");
 printf("\n             **    ");
 delay(speed1);
 system("CLS");
 printf("\n            **       ");
 printf("\n            * ****** ");
 printf("\n            *       *");
 printf("\n            ******** ");
 printf("\n               * *   ");
 printf("\n               **    ");
 delay(speed1);
 system("CLS");
 printf("\n              **       ");
 printf("\n              * ****** ");
 printf("\n              *       *");
 printf("\n              ******** ");
 printf("\n                 * *   ");
 printf("\n                 **    ");
 delay(speed1);
 system("CLS");
 printf("\n                **       ");
 printf("\n                * ****** ");
 printf("\n                *       *");
 printf("\n                ******** ");
 printf("\n                   * *   ");
 printf("\n                   **    ");
 delay(speed1);
 system("CLS");
 printf("\n                  **       ");
 printf("\n                  * ****** ");
 printf("\n                  *       *");
 printf("\n                  ******** ");
 printf("\n                     * *   ");
 printf("\n                     **    ");
 delay(speed1);
 system("CLS");
 printf("\n                    **       ");
 printf("\n                    * ****** ");
 printf("\n                    *       *");
 printf("\n                    ******** ");
 printf("\n                       * *   ");
 printf("\n                       **    ");
 delay(speed1);
 system("CLS");
 printf("\n                      **       ");
 printf("\n                      * ****** ");
 printf("\n                      *       *");
 printf("\n                      ******** ");
 printf("\n                         * *   ");
 printf("\n                         **    ");
 delay(speed1);
 system("CLS");
 printf("\n                        **       ");
 printf("\n                        * ****** ");
 printf("\n                        *       *");
 printf("\n                        ******** ");
 printf("\n                           * *   ");
 printf("\n                           **    ");
 delay(speed1);
 system("CLS");
 printf("\n                          **       ");
 printf("\n                          * ****** ");
 printf("\n                          *       *");
 printf("\n                          ******** ");
 printf("\n                             * *   ");
 printf("\n                             **    ");
 delay(speed1);
 system("CLS");
 printf("\n                            **       ");
 printf("\n                            * ****** ");
 printf("\n                            *       *");
 printf("\n                            ******** ");
 printf("\n                               * *   ");
 printf("\n                               **    ");
 delay(speed1);
 system("CLS");
 printf("\n                              **       ");
 printf("\n                              * ****** ");
 printf("\n                              *       *");
 printf("\n                              ******** ");
 printf("\n                                 * *   ");
 printf("\n                                 **    ");
 delay(speed1);
 system("CLS");
 printf("\n                               **       ");
 printf("\n                               * ****** ");
 printf("\n                               *       *");
 printf("\n                               ******** ");
 printf("\n                                  * *   ");
 printf("\n                                  **    ");
 delay(speed1);
 system("CLS");
 printf("\n                                 **       ");
 printf("\n                                 * ****** ");
 printf("\n                                 *       *");
 printf("\n                                 ******** ");
 printf("\n                                    * *   ");
 printf("\n                                    **    ");
 delay(speed1);
 system("CLS");
 printf("\n                                   **       ");
 printf("\n                                   * ****** ");
 printf("\n                                   *       *");
 printf("\n                                   ******** ");
 printf("\n                                      * *   ");
 printf("\n                                      **    ");
 delay(speed1);
 system("CLS");
 printf("\n                                     **       ");
 printf("\n                                     * ****** ");
 printf("\n                                     *       *");
 printf("\n                                     ******** ");
 printf("\n                                        * *   ");
 printf("\n                                        **    ");
 delay(speed1+50);
 system("CLS");
 
}   

void logo()             //printing the logo of our airlines "Bharat Air"
{
 ShowCursor(false);	    //hide cursor when the logo is shown
 printf("\n      *******                                                      ");
 printf("\n       *      *                                                    ");
 printf("\n        *       *                                                  ");
 printf("\n      ***        *************************************************       ");
 printf("\n       *                                ___                     *****    ");
 printf("\n        *       |  ) |__|  /\\  |  )  /\\  |                      ******   ");
 printf("\n         *      |  ) |  | /  \\ |  \\ /  \\ |     /\\  | |  )           *  ");
 printf("\n          *                                   /  \\ | |  \\           *  ");
 printf("\n           *****      *************           **************************    ");
 printf("\n              *      *           *          *                      ");  
 printf("\n             *     *            *         *                        ");
 printf("\n            *******            *        *                          ");
 printf("\n                              *       *                            ");
 printf("\n                             *      *                              ");
 printf("\n                            *******                                ");   
 delay(3000);
 system("CLS");
 }  

void intro()                   		// function which has 4 subfunctions under it - user sign up, user login, admin login and exit 
{	
	int i,j;                   		// i and j are integer variables
	
	check:                     		// indicator to come back to this portion of the code while executing later functions under void intro
	gotoxy (32,4);	
	printf("WELCOME TO BHARAT AIR");            
	box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,12);
 	printf("1. User Sign Up");            // the user can select 4 options displayed on the screen. Selecting 1 will lead to user registration for creating valid user ID required for flight booking.
 	delay(150);
 	gotoxy(48,12);
 	printf("2. User Login");             // selecting 2 will help the user with existing valid user ID to login to the reservation system for booking
	delay(150);
 	gotoxy(16,15);
 	printf("3. Admin Login");         // the admin will have unique ID and password. Selecting 3 will onky enable the admin to login and modify flight timing and availability of flights.
 	delay(150);
 	gotoxy(48,15);
 	printf("4. Exit\n ");         // finally select 4 to exit the flight reseravtion system
	
	box(10,22,81,24);
 	delay(150);
 	gotoxy(11,23);
 
 	printf("  Enter Your Choice [1-4] = ");    //the user will be asked to enter any one of the 4 choices displayed on the screen
		
	scanf("%d", &i);    					// the choice of the user will be scanned from the console
	
if (i==1)
{	
	system("CLS");       					 // if the user gives an input of 1 then he/she will be directed to the registration page
	Register();
	getch();
	system("CLS");
	box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,9);
	printf("Press 0 to go Back to Main Page");            
	gotoxy (16,11);
	printf("Press 1 to Exit\n");
	box(10,22,80,24);
 	delay(150);                                       
 	gotoxy(11,23);
 	printf(" Enter Your Choice [0-1]= ");
	scanf("%d", &j);                   // after registration and successful login the user can either choose to exit or go back to the main page
	if(j==0)                           // selcting 0 will take the user back to the main page 
	{
		system ("CLS");
		goto check;
	}
	else if(j==1)             			// selcting 1 will help the user to exit the flight reseravtion system
	{
		exit(0);
	}
}

	if (i==2)
	{
	system("CLS");                  //  if the user gives an input of 2 then he/she will be directed to the login page
	Login();
	gotoxy(10,14);
	system("CLS");
	box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,9);
	printf("Press 0 to go Back to Main Page");
	gotoxy (16,11);
	printf("Press 1 to Exit\n");
	box(10,22,80,24);
 	delay(150);
 	gotoxy(11,23);
 	printf(" Enter Your Choice [0-1]= ");
	scanf("%d",&j);                        // after successful login the user can either choose to exit or go back to the main page
	if(j==0)
	{
	system ("CLS");
	goto check;
	}
	else if(j==1)
	{
	exit(0);}
 	}
	else if(i==3)                      // if the user gives an input of 3 then he/she will be directed to the admin page
	{
	system("CLS");                      
 	admin();
 	gotoxy(10,18);
 	printf("Press any key to continue\n");
	gotoxy(10,20);
 	
	getch();
	system("CLS");
	box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,9);
	printf("Press 0 to go Back to Main Page");
	gotoxy (16,11);
	printf("Press 1 to Exit\n");
	box(10,22,80,24);
 	delay(150);
 	gotoxy(11,23);
 	printf(" Enter Your Choice [0-1]= ");                // after successful login the admin can either choose to exit or go back to the main page
	scanf("%d", &j);
	if(j==0)
	{
	system ("CLS");
	goto check;
	}
	else if(j==1)
	{
	exit(0);
	}
	}
	if (i==4)
	{
	system("CLS");        // screen cleared
	anime();              // after the exit from the reservation system the small animation displayed in the beginning as well as the logo our airlines will be displayed
	logo();
	exit(0);
	}
	
}

//here we declare the gotoxy function used to move the cursor to different coordinates in the screen as defined by the user//

void gotoxy(short x, short y)                                                         
{
 COORD pos ={x,y};                                        // x,y are the coordinates on the console which are declared in the variable pos
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);             // the cursor is moved to the pos coordinates
}
void box(int a,int b,int c,int d)      					// defining box function where a,b,c,d will take the 4 coordinates of the corners of the box
{	
	int i,j;
	for(i=a;i<c;i++)
	{
		gotoxy(i,b);printf("\xcd");                                      
		gotoxy(i,d);printf("\xcd");
	}
	for(j=b;j<d;j++)
	{
		gotoxy(a,j);printf("\xba");
		gotoxy(c,j);printf("\xba");
	}
		gotoxy(a,b);printf("\xc9");
		gotoxy(c,b);printf("\xbb");
		gotoxy(a,d);printf("\xc8");
		gotoxy(c,d);printf("\xbc");
}
void box1(int a,int b,int c,int d)        // defining the second type of box function with single outline
{
	int i,j;
	for(i=a;i<c;i++)
	{
		gotoxy(i,b);printf("%c",196);              
		gotoxy(i,d);printf("%c",196);
	}
	for(j=b;j<d;j++)
	{
		gotoxy(a,j);printf("%c",179);
		gotoxy(c,j);printf("%c",179);
	}
		gotoxy(a,b);printf("%c",218);
		gotoxy(c,b);printf("%c",191);
		gotoxy(a,d);printf("%c",192);
		gotoxy(c,d);printf("%c",217);
}
void delay(int milliseconds)                      // defining the delay function to delay(in milliseconds) the execution of the succeeding lines of code 
 {
   long pause;
   clock_t now,then;                             // clock_t clock() is a function defined in C that returns the number of clock ticks elapsed since the program was launched.

   pause = milliseconds*(CLOCKS_PER_SEC/1000);
   now = then = clock();
   while( (now-then) < pause )
    now = clock();
 }


void Register() 								// function for user registration
{	
	char user[50];        
	int s;                							// integer variable s is defined
	FILE *fp;  										//to read or write in the file fp a pointer (*) is required. FILE is some kind of structure that holds information about the file in C.
	if (fp = fopen("login.txt", "r")) 
	{         									   //to check whether fp file exists or not. If the file exists then it will direct to credentials part of the code to check whether the user ID already exists in the file fp or not.
    	fclose(fp);          					   // fclose is used to close the file fp
		goto credentials;   						//credentials is an indicator
    } 
	else 
	{                     							// if the file does not exist then a file will open in the write mode to enter the user details
   	struct login a;
   	fp=fopen("login.txt","w");       				  // opens a file named login.txt in writing mode
    box(7,2,73,22);
	gotoxy(27,2);
	printf(" Enter the user account details ");           
	gotoxy(10,6);
	printf("Enter first name: ");        				 // user's name, email id and username will be asked to enter
	gotoxy(59,6);
	box1(48,5,70,7);
	gotoxy(50,6);
	scanf("%s",a.firstname);
	gotoxy (10,9);
	printf("Enter last name: ");
	gotoxy(59,9);
	box1(48,8,70,10);
	gotoxy(50,9);
	scanf("%s",a.lastname);
	gotoxy(10,12);
	printf("Enter email id: ");
	gotoxy(59,12);
	box1(48,11,70,13);
	gotoxy(50,12);
	scanf("%s",a.email);
	gotoxy(10,15);
	printf("Enter username: ");
	gotoxy(59,15);
	box1(48,14,70,16);
	gotoxy(50,15);
	scanf("%s",a.username);        					// the user name and email id will be taken by the system but the username will first be screened against the existing list of usernames to avoid duplication of the any user ID. The user ID should be unique for every user.

	fwrite(&a ,sizeof(a),1,fp);        			 	 // writes the information in the file fp
	fclose(fp);
	goto next;                      				// next is another indicator
    }
	credentials:               						 // indicator to come back to this part of the code
	fp=fopen("login.txt","r"); 							//  login.txt is opened in read mode to check whether the given userID already exists or not
	struct login a,b ;
	box(7,2,73,22);
	gotoxy(27,2);
	printf(" Enter the user account details ");
	gotoxy(10,6);
	printf("Enter first name: ");
	gotoxy(59,6);
	box1(48,5,70,7);
	gotoxy(50,6);
	scanf("%s",a.firstname);
	gotoxy (10,9);
	printf("Enter last name: ");
	gotoxy(59,9);
	box1(48,8,70,10);
	gotoxy(50,9);
	scanf("%s",a.lastname);
	gotoxy(10,12);
	printf("Enter email id: ");
	gotoxy(59,12);
	box1(48,11,70,13);
	gotoxy(50,12);
	scanf("%s",a.email);
	gotoxy(10,15);
	printf("Enter username: ");
	gotoxy(59,15);
	box1(48,14,70,16);
	gotoxy(50,15);
	scanf("%s",&user);

	s=0;                      					// initialising s=0
	while(!feof(fp))

	{
		fread(&b ,sizeof(b),1,fp);             // check whether the user ID/username already exists in the login.txt file or not
		if(strcmp(user, b.username)==0)        // strcmp function is used to compare between two string: the entered user ID against a list of existing user IDs in the file login.txt
		{
			s+=1;                            // if the entered user ID matches against an existing username then 1 will be added to s for every iteration.    
		}
	}                                     // if there is no match between the existing username in the list and the one entered by the user then s will adopt a value of 0.

	if (s>0)                    // thus s>0 implies there is a match and hence the user should register with a different user ID

	{	
		gotoxy(10,17);
	
		printf("User ID already exists");     // if s>0 then the username already exists; if s=0 then the username will be accepted as a new user ID
		gotoxy(10,18);
	
		printf("Enter a different User ID");      
		gotoxy(10,19);
	 
		printf("Press any key to continue");
		getch();
		system("CLS");
		goto credentials;
	}
else 
{
	fclose(fp);
	
	gotoxy(10,18);
	 
	printf("Re-enter User name: "); // if there is no match the user will be asked to re-enter the username 
	gotoxy(59,18);
	box1(48,17,70,19);
	gotoxy(50,18);
	      
	scanf("%s",a.username);
	system("CLS");
	fp=fopen("login.txt","a");  // login.txt is now opened in append mode since everytime a new person registers, his/her personal information will be added to the file, to be accesssed later for login.
	fwrite(&a ,sizeof(a),1,fp);   // the details recorded in struct login will be now appended to the file fp
	fclose(fp);                   // file is closed
}
	next:
	system("CLS");                // used for clearing the screen of the console
	   
	box(7,2,73,22);
	                      // indicator to come back to this portion of the code
	gotoxy (10,10);
	printf("Your Username is the unique UserID\n");
	gotoxy(10,11);
	printf("Press any key to login with new UserID\n");
	gotoxy(10,12);
	printf("Press any key to continue\n");
	getch();                       // getch function is used to read a character input
	system("CLS");                // used for clearing the screen of the console
	Login();                      // directly continue to the login page after registration
	
}

void Login()               // function for the user to log-in with valid user ID to continue flight booking 
{ 	
	char username[50];
	int sum=0;          

	FILE *fp;                    // fp file will be pointed to open
	if (fp = fopen("login.txt", "r")) {           //to check whether fp file exists or not. If the file exists then it will direct to credentials part of the code to check whether the user ID already exists in the file fp or not.
    fclose(fp);
	goto login;}
	else{ 
	box(7,2,80,22);
	gotoxy (10,14);
	printf("No user ID has been registered in the file. Sign-up first to Continue");
	gotoxy(10,16);                                                             // if the file login.txt is empty or does not exist the user has to sign up first.
	printf("Press any key to go back and Sign-up first");
	getch();
	system("CLS");
	intro();}
	
	login:                            // indicator
	fp=fopen("login.txt","r");            // fp file wil now be opened in the reading mode 

	struct login a;                      
	
	box(7,2,73,22);
	gotoxy(10,6);
	printf("Enter valid UserID: ");     // the user has to enter valid User ID that he/she had registered with 
	gotoxy(59,6);
	box1(48,5,70,7);
	gotoxy(50,6);
	scanf("%s",&username);              // scanning the username given as an input from the user

	while(!feof(fp))                   // feof means the fp file will be read till the end

	{
		fread(&a ,sizeof(a),1,fp); 
		if(strcmp(username, a.username)==0)      //  strcmp function used for comparing two strings- the User ID taken as an input from the console and separately checking it against all the User IDs in the file fp. if the input matches the user ID in the file fp then strcmp will give 0 
		{	
		sum+=1;                                 // sum is integer variable with initial value 0. For a match, 1 will be added to sum variable and its value will be updated. Fora mismatch the sum will take 0 which was its initial value
		strcpy(u.username,a.username);
		strcpy(u.firstname,a.firstname);
		strcpy(u.email,a.email);	
		strcpy(u.lastname,a.lastname);                            
	
		}                                 
	
	}
if (sum>0)                          // thus sum>0 if the input matches the user ID in the file

	{	
	gotoxy(10,10);
	printf("Welcome! Successful User Login \n");
	gotoxy (10,14);
	printf("Press any key to continue");
	getch();
	system("CLS");
	user();
	}

else if (sum==0)
{	
	gotoxy(10,10); 
	printf ("Enter valid UserID"); 
	gotoxy (10,11);
	printf("User Login Unsuccessful! Press any key to continue.");
	getch();
}

fclose(fp);

}


//***************************************ADMIN MODULE***************************************//
	
void admin()            				// the admin cannot register using the user regstration module. the admin has unique ID and password to exercise its power in the reservation system
{
	char username[50];                   
	char password[20];
	adminuser:               			// indicator
	box(7,2,73,26);
	gotoxy(27,2);
	printf(" Sign in to the admin account ");
    gotoxy(10,6);
	printf("Enter Valid Admin ID: ");   // valid admin id is kripa
	gotoxy(59,6);
	box1(48,5,70,7);
	gotoxy(50,6);
	scanf("%s",&username);
	gotoxy (10,9);
	printf("Enter Valid Password: ");   // valid password is iiserk
	gotoxy(59,9);
	box1(48,8,70,10);
	gotoxy(50,9);
	scanf("%s",&password);
	if (strcmp(username, "kripa")==0)  	// strcmp is used to compare the input string and "kripa"
	{gotoxy(10,12);
	printf("Admin ID is Valid");    	 // if the valid admin ID is enterd the strcmp function will give 0 and the user ID will be accepted
	gotoxy(10,14);
	printf("Press any key to continue");
	getch();
	}
	else
	{gotoxy (10,12);
	printf("Invalid Admin ID");       // for a mismatch this will be printed on the screen
	gotoxy(10,14);
	printf("Press any key to go back and enter valid Admin ID"); // if invalid user ID is displayed on the screen the user will be allowed to go back and enter the valid admin ID to continue
	getch();
	system("CLS");
	goto adminuser;  					// indicator to go back and enter the admin ID again
	}
	if(strcmp(password, "iiserk")==0)   // strcmp is used to compare the input string and "iiserk"
	{gotoxy (10,16);
	printf("Password is Valid");   // if the valid password is enterd the strcmp function will give 0 and the password will be accepted
	gotoxy(10,18);
	printf("Press any key to continue");
	getch();
	
	}
	else
	{gotoxy(10,16);
	printf("Invalid Password");										 // for a mismatch this will be printed on the screen
	gotoxy(10,18);
	printf("Press any key to go back and enter valid Password");  // if the user enters invalid password he will be directed to go back and enter valid admin details to continue
	getch();
	system("CLS");
	goto adminuser; 												// indicator to go back and enter the admin ID and password again
	}
	if (strcmp(username, "kripa")==0 && strcmp(password, "iiserk")==0)   // only by entering the valid admin ID and password the admin log in will be allowed.
	{ gotoxy(10,20);
	printf("Welcome! Successful Admin Login");
	getch();
	gotoxy (10,22);
	printf("Press any key to continue");
	getch();
	system("CLS");
	admin_intro();
	}
}


void add()												 //This function adds new flight details into the internal database when admin opts for it.
{   
	char a[100],b[100],c[100],d[100],e[100],f[100];  //6 char variables are declared.
    
	box(7,2,73,22); //
    gotoxy(27,2);
	printf("  Enter the Flight details "); 			//asks the user to enter the details of the new flight.
     
	gotoxy(10,4);									 //the gotoxy function locates the text cursor to the position (x,y) given as arguments to it.
	printf("Flight ID: "); 							//asks for the FlightID (the same happens for every other information about the fight)
	gotoxy(59,4);
	box1(48,3,70,5); 
	gotoxy(50,4);
	scanf("%s",a); 									//scans the input from the console (the same happens for every other information about the flight)
 	gotoxy (10,7);
	printf("Destination: ");
	gotoxy(59,7);
	box1(48,6,70,8);
	gotoxy(50,7);
	scanf("%s",b);
    gotoxy(10,10);
	printf("Origin: ");
	gotoxy(59,10);
	box1(48,9,70,11);
	gotoxy(50,10);
	scanf("%s",c);
	gotoxy(10,13);
	printf("Date of Departure(DD/MM/YYYY): ");
	gotoxy(59,13);
	box1(48,12,70,14);
	gotoxy(50,13);
	scanf("%s",f);
 	gotoxy(10,16);
	printf("Time of Departure(xxxx hrs): ");
	gotoxy(59,16);
	box1(48,15,70,17);
	gotoxy(50,16);
	scanf("%s",d);
 	gotoxy(10,19);
	printf("Number of seats available ");
	gotoxy(59,19);
	box1(48,18,70,20);
	gotoxy(50,19);
	scanf("%s",e);
    box(7,22,73,24);
    delay(150);
 	gotoxy(9,23);
	FlightID.push_back(a); 								//the new char variable value corresponding to the Flight ID is inserted at the end of the vector and the container size is increased by 1. 
	Destination.push_back(b); 							//(same as above for all the other details of the flight)
	Origin.push_back(c); 
	Time.push_back(d); 
	seats.push_back(e);
	date.push_back(f);  
    total=FlightID.size();
    update(); 											//calls the update function to update the text file.
	printf("Details have been successfully entered! Press enter to continue");
 	getch(); 											//waits and reads a single character from the console
      
}

int search() 											//search function presents a search menu that allows to view the desired flights.
{ 
	int n=total; 										//gives the value of the total number of flights in the database.
	char word[100]; int k=0, t; 						//required variables declared.
	backagain: 											// Search function will return to this after viewing the flights
	system("CLS"); 										//clears the output screen.
	box(10,6,80,21);                  
	delay(150); 										//suspends the execution of the program for a partiular amount of time (time as arguments in milliseconds).
	gotoxy(16,7);										 //places the text cursor at (x,y)
	printf("Welcome to the free search menu"); 			//prints the welcome message
	gotoxy(16,12);
 	
	printf("1. Search by Flight ID"); 					//desplays the options on the screen.
	delay(150);
	gotoxy(48,12);
	printf("2. Search by Destination");
	delay(150);
	gotoxy(16,15);
	printf("3. Search by Orgin");
	delay(150);
	gotoxy(48,15);
	printf("4. Search by Date and Time");
	delay(150);
	gotoxy(16,18);
	printf("5. Skip Search.");
	
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);

	printf("  Enter Your Choice [1-5] = ");
		
	scanf("%d", &t);									 //the option chosen is scanned from the console and stored in the t variable.
	system("CLS");
	
if(t==1) //Search by flight ID
{	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	
	int count=0,line_count=0,dd; 						//count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page)
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");		 //It prints the title to the relevant data
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	printf("Enter a valid Flight ID: ");
	scanf("%s",&word); 									//the flight ID of the required flight data is stored in word.
	int pos=10; 										//the pos variable gives the y coordinate for the gotoxy function.
	for (int i=0;i<n;i++) 								//this loop runs over the total number of flights.
	{
    
		if(word==FlightID[i]) 							//if the word variable becomes equal to a flight ID, then the details of those flights are printed.
		{	gotoxy(16,pos++);  							//the y coordinate for the cursor is updated each time (that is, prints each flight's detail in a new line).
			printf("%s\t",date[i].c_str()); 			//prints the flight details for that flight.
			printf("%s\t",FlightID[i].c_str());
			printf("%s\t",Destination[i].c_str());
			printf("%s\t",Origin[i].c_str());
			printf("%s\t",Time[i].c_str());
			printf("%s\t",seats[i].c_str());
			count+=1; 									//the number of available relevant flights is increased by 1.
			line_count+=1;								 //updates the count of the number of lines displayed.
		}
		
		if(line_count==11) 								//To show the flights page wise(11 lines in a page)
		{	
			box(9.99,22,81,24);
			delay(150);
			gotoxy(10,23);
			printf("Press 1 to see more or press 0 to exit the menu ");
			scanf("%d",&dd); 							//takes the input into dd variable.
			if(dd==1)
			{	
				system("CLS"); 							//clears the screen.
				box(10,6,80,21);                 
				delay(150);
				gotoxy(35,6);
				printf("Available flights"); 				//prints this in the new screen
				gotoxy(16,8);
				printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); //The title for the new screen is printed.
				box(9.99,22,81,24);
				delay(150);
				gotoxy(10,23);
				pos=10; 									//the y coordinate is updated to the beginning like in the first page.
				line_count=0;								//line_count is set to 0 to further count it for this new page of data.
			}
			else 
			{
				goto backagain; 							//exits the menu and goes back to the beginning of the search menu.
			}
		}
	
	}
	if(count==0) 											//in case we get no results for the relevant flights, ie, when coun is 0;
	{	gotoxy(16,pos++); 									//the cursor is set at this position
			
		printf("No such flight exists.");					 //it prints that there are no relevant flights.
		delay(800);
		goto backagain;	 									//goes back to the beginning of the seach menu.
	}
	gotoxy(16,19);
	
	printf("Press any key to continue."); 
	getch();
	}

else if(t==2) 												//To search by destination
{	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	
	int count=0,line_count=0,dd;							 //count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page)
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");			 //It prints the title to the relevant data
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	
	printf("Enter a valid Destination: ");					 //the Destination of the required flight data is stored in word.
	scanf("%s",&word);
	int pos=10;
	for (int i=0;i<n;i++) 									//this loop runs over the total number of flights.
	{
    
		if(word==Destination[i])							 //if the destination of a flight becomes equal to the word entered.
		{	gotoxy(16,pos++);								 //the y coordinate is updated. that is, skips to a new line for every new relevant flight.
			
			printf("%s\t",date[i].c_str());					 //the relevant flight data is printed on the screen.
			printf("%s\t",FlightID[i].c_str());
			printf("%s\t",Destination[i].c_str());
			printf("%s\t",Origin[i].c_str());
			printf("%s\t",Time[i].c_str());
			printf("%s\t",seats[i].c_str());
			count+=1; 										//the count variable is increased by 1.
			line_count+=1; 									//the line count is also updated.
		}
		if(line_count==11) 									//once the page is filled, it asks if more data has to be displayed. If the answer is yes, it does so. Else, it goes to the beginning of the search menu.
		{	box(9.99,22,81,24);
			delay(150);
			gotoxy(10,23);
			printf("Press 1 to see more or press 0 to exit the menu ");
			scanf("%d",&dd); 								//the choice is updated in dd.
			if(dd==1) 										//when more flight details has to be displayed;
			{	system("CLS"); 								//the screen is cleared.
				box(10,6,80,21);                  
				delay(150);
				gotoxy(35,6);								 //the position of the cursor is set.
				printf("Available flights");
				gotoxy(16,8);
				printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); //prints the title for the data in this page.
				box(9.99,22,81,24);
				delay(150);
				gotoxy(10,23);
				pos=10; 									//the y coordinate is again set to 10, like in the start of the first page.
				line_count=0;								//line count is set to 0.
			}
			else
			{
				goto backagain; 							//goes to the beginning of the search menu.
			}
	
	}
	
}
	if(count==0)											 //if theres no relevant data
	{ 	gotoxy(16,pos++); 
			
		printf("No such flight exists.");					//prints that theres no data
		delay(800);
		goto backagain;										//goes back to the beginning of the search menu.
	}
	gotoxy(16,19);
	
	printf("Press any key to continue.");
	getch();
	
}

else if(t==3) //To search by origin
{   box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	
	int count=0,line_count=0,dd; 							//count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page)
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	
	
	printf("Enter a valid Origin: "); 						//the Origin of the required flight data is stored in word.
	scanf("%s",&word);
	int pos=10;
	
	for (int i=0;i<n;i++) 									//this loop runs over the total number of flights.
	{
    
		if(word==Origin[i]) 								//when the origin of a flight becomes equal to the word entered.
		{	gotoxy(16,pos++);								 //each time a new flight is entered, the y coordinate is updated

			printf("%s\t",date[i].c_str());
			printf("%s\t",FlightID[i].c_str());
			printf("%s\t",Destination[i].c_str());
			printf("%s\t",Origin[i].c_str());
			printf("%s\t",Time[i].c_str());
			printf("%s\t",seats[i].c_str());
			printf("\n");
			count+=1;										 //count variable is updated.
			line_count+=1; 									//the no of lines in the output is also updated.
		}
	if(line_count==11)										 //when the page is filled;
		{	box(9.99,22,81,24);
			delay(150);
			gotoxy(10,23);
			printf("Press 1 to see more or press 0 to exit the menu "); 
			scanf("%d",&dd);								 //the choice is updated in dd.
			if(dd==1) 										//when more details are required;
			{	system("CLS");								 //screen is cleared.
				box(10,6,80,21);                  
				delay(150);
				gotoxy(35,6);
				printf("Available flights");
				gotoxy(16,8);
				printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
				box(9.99,22,81,24);
				delay(150);
				gotoxy(10,23);
				pos=10;
				line_count=0;								 //the line count is set to 0 to further print the output on this page.
			}
			else
			{
				goto backagain; 							//when no more output is required, it goes to the beginning of the search menu.
			}
	
	}
}
	if(count==0) 											//when theres no relevant data;
	{	gotoxy(16,pos++);
			
		printf("No such flight exists.");
		delay(800);
		goto backagain;										//goes to the beginning of the search menu.
	}
	gotoxy(16,19);
	printf("Press any key to continue.");
	getch();
	
}


else if(t==4) 												//To search by date and time
{	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	
	int count=0,g,line_count=0,dd; 								//count:To check the number of available flights; line_count:To keep a check on the number of lines displayed(to fit in a page). g and dd stores the choice by the user.
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats"); 
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	printf("Enter a date from Nov'20 to Dec'20 (DD/MM/YYYY): ");	 //the data of the required flight data is stored in word.
	scanf("%s",&word); 												//scans the input and stores in word.
	system("CLS"); 													//clears the screen.
	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	
	printf("Press 1 to search for a specific time or 0 to list all flights: "); 
	scanf("%d",&g); 														//scans the choice given and stores in g.
	int pos=10;
	if(g!=1) 																//To print all flights for a date
	{
	
	for (int i=0;i<n;i++) //this loop runs over the total number of flights.
	{
    
		if(word==date[i]) 													//when date of the flight is equal to the word entered;
		{	gotoxy(16,pos++); 												//the y coordinate is updated each time.
			
			printf("%s\t",date[i].c_str()); 								//relevant data is printed on the screen.
			printf("%s\t",FlightID[i].c_str());
			printf("%s\t",Destination[i].c_str());
			printf("%s\t",Origin[i].c_str());
			printf("%s\t",Time[i].c_str());
			printf("%s\t",seats[i].c_str());
			count+=1; 														//count variable is updated.
			line_count+=1;													 //the line count is updated each time a relevant data is encountered.
		}
		if(line_count==11) 													//when the output page is filled;
		{	box(9.99,22,81,24);
			delay(150);
			gotoxy(10,23);
			printf("Press 1 to see more or press 0 to exit the menu ");
			scanf("%d",&dd);
			if(dd==1) 														//when more data is required;
			{	system("CLS");												 //clears the screen.
				box(10,6,80,21);                  
				delay(150);
				gotoxy(35,6);
				printf("Available flights");
				gotoxy(16,8);
				printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
				box(9.99,22,81,24);
				delay(150);
				gotoxy(10,23);
				pos=10; 													//position variable and line count are set to the values as in the first page.
				line_count=0;	
			}
			else
			{
				goto backagain;												 //goes to the beginning of the search menu.
			}
	
	}
	
	}
	if(count==0) 															//when theres no relevant data;
	{	gotoxy(16,pos++);
			
		printf("No such flight exists."); 									//prints it
		delay(800); 
		goto backagain; 													//goes to the beginning of the search menu.	
	}
	gotoxy(16,19);
	printf("Press any key to continue.");
	getch();

	}
	
	else																	 //Particular date and time
	{
	char times[100];
	system("CLS");
	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	
	printf("Enter time in 24 hours format: ");
	scanf("%s",&times); 													//the time entered is stored in times.
	count=0;
	pos=10;
	for (int i=0;i<n;i++) 													//runs through the list of all the flights.
	{
    	
		if(word==date[i] && times==Time[i]) 								//when both the date and the time of the flights match to the ones entered, the same process is repeated.
		{	gotoxy(16,pos++);
			
			printf("%s\t",date[i].c_str());
			printf("%s\t",FlightID[i].c_str());
			printf("%s\t",Destination[i].c_str());
			printf("%s\t",Origin[i].c_str());
			printf("%s\t",Time[i].c_str());
			printf("%s\t",seats[i].c_str());
			printf("\n");
			count+=1;
			line_count+=1;
		}
		if(line_count==11)
		{	box(9.99,22,81,24);
			delay(150);
			gotoxy(10,23);
			printf("Press 1 to see more or press 0 to exit the menu ");
			scanf("%d",&dd);
			if(dd==1)
			{	system("CLS");
				box(10,6,80,21);                  
				delay(150);
				gotoxy(35,6);
				printf("Available flights");
				gotoxy(16,8);
				printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
				box(9.99,22,81,24);
				delay(150);
				gotoxy(10,23);
				pos=10;
				line_count=0;	
			}
			else
			{
				goto backagain;
			}
	
	}
	
	}
	if(count==0)
	{	gotoxy(16,pos++);
			
		printf("No such flight exists.");
		delay(800);
		goto backagain;	
	}
	gotoxy(16,19);
	printf("Press any key to continue.");
	getch();
	
	}
}

else if(t==5)																		 //To exit free search
{
return 0;
}
else																				 //when the option entered is not relevant.
{	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);
	
	printf("Wrong option pressed!"); 
	delay(800);
	goto backagain; 																	//goes to the beginning of the search menu.
}

}




void deleteone()																		 //the function to delete a flight detail of a chosen Flight ID and date
{  
	search(); 																			//the search function is called.
	system("CLS");																		 //clears the screen.
	box(7,2,73,22);
    gotoxy(23,2);
	printf("  Enter the flight details to be deleted "); 
     
	
   char ID[20],dates[10];																 //Two char variable are declared, which will hold the Flight ID and the date of the flight whose details have to be deleted.
   int recognised = -1;																	 //A marker variable whose value tells us if the flight of the given ID exists.
   if (total == 0) 																			//If the file is empty, there's no data to delete.
     {
	 gotoxy(10,4);

	 printf("You've no data to delete!'");
	 
     }
   else 																					//If the file is not empty;
   {
    gotoxy(10,4);
	printf("Flight ID: "); 
	gotoxy(59,4);
	box1(48,3,70,5);
	gotoxy(50,4);
	scanf("%s",ID); 																		//the flight ID entered is stored in ID variable.
 	gotoxy (10,7);
	printf("Date of the flight(DD/MM/YYYY): "); 
	gotoxy(59,7);
	box1(48,6,70,8);
	gotoxy(50,7);
	scanf("%s",dates); 																			//the date entered is stored in dates.
    
   
    for (int i=0;i<total;i++) 																	//this loop runs through the total number of flights in the database.
	{
    
		if(strcmp(FlightID[i].c_str(),ID)==0 && strcmp(date[i].c_str(),dates)==0) 				//when the flight ID and the date entered match with one of the entries in the database;
		{
			FlightID[i].clear(); 																//the flight details associated with this flight is deleted.
			Destination[i].clear(); 
			Origin[i].clear(); 
			Time[i].clear(); 
	 		seats[i].clear();
			date[i].clear(); 
			recognised+=1; 																		//the marker variable is set to 0.
		}
	}
	   
    if (recognised == -1) 																		//When there are no matching entries for the flight IDs: we print it!
    {
	gotoxy (10,10);
	
	printf("Sorry, there are no flights with the given Flight ID!");
	gotoxy(10,11);
	}
	else 																						//when theres a matching entry;
	{
	total=FlightID.size(); 																		//the size of the FlightID vector is stored in total.
	update();																					 //the update function is called.
	gotoxy (10,10);
	
	printf("The data has been deleted!");
	gotoxy(10,11);
	}
   }
}


void edit() 																				//the function to edit a flight detail of a given flight ID and date.
{
    search(); 																				//the search function is called.
   	system("CLS");																			 //the screen is cleared.
	box(7,2,73,22);
    gotoxy(23,2);
	printf("  Enter the Flight details to be edited ");

   char ID[20],dat[10]; 																	//two char variables are declared.
   int recognisedD = -1; 																	//A variable taht stores the index value of the entry that has to be edited.
   int j; 																					//a variable to store a choice entered.
   if (total == 0) 																			//If the file is empty, there's no data to edit.
   {
   gotoxy(10,4);

   printf("You've no data to modify!'");
    }
   else																							 //If the file is not empty;
   {gotoxy(10,4);
	printf("Flight ID: "); 
	gotoxy(59,4);
	box1(48,3,70,5);
	gotoxy(50,4);
	scanf("%s",ID); 																			//scans and stores the flight ID entered into ID variable.
 	gotoxy (10,7);
	printf("Date of the flight(DD/MM/YYYY): ");
	gotoxy(59,7);
	box1(48,6,70,8);
	gotoxy(50,7);
	scanf("%s",dat);																			 //scans and stores the date entered into the dat variable.
    
    for (int i=0;i<total;i++)																	 //runs through the total number of flights.
	{if(FlightID[i]==ID && date[i]==dat) 														//when both the flight ID and the date of an entry match with those entered;
		{
			recognisedD = i; 																	//the index variable of that entry is stored into recognised.
		}
	}
    
	if (recognisedD != -1) 																		//when there is a relevant entry;
	{
	system("CLS");																				 //clears the screen.
	box(10,6,80,21);                  
	delay(150);
	gotoxy(16,7);
	printf("What would you like to modify?");
	gotoxy(16,12);
 	
	printf("1. Flight ID");
	delay(150);
	gotoxy(48,12);
	printf("2. Destination");
	delay(150);
	gotoxy(16,15);
	printf("3. Orgin");
	delay(150);
	gotoxy(48,15);
	printf("4. Date");
	delay(150);
	gotoxy(16,18);
	printf("5. Time");
	delay(150);
	gotoxy(48,18);
	printf("6. Seats");
	
	box(9.99,22,81,24);
	delay(150);
	gotoxy(10,23);

	printf("  Enter Your Choice [1-6] = ");
		
	scanf("%d", &j); 																			//the choice is stored in j.
	system("CLS");
	
	if (j == 1) 																				//if the flight ID has to be modified
       {
	    char temp[20]; 																			//a temp variable of character datatype is declared.
        
        box(7,2,73,22);
		gotoxy(27,2); 																			//the coordinates of the cursor is set to the (x,y), the arguments of gotoxy.
		printf(" Edit flight detail ");
		gotoxy(10,6);
		printf("Enter the modified Flight ID: ");
		gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
		scanf("%s",temp); 																		//temp stores the new flight ID.
	   	FlightID[recognisedD]=temp;																 //this new flight ID is dumped into the index of the Flight ID that has to be modified.
	   }
	   
	   if (j == 2) 																				//if the destination has to be modified
	   {
	   	char temp[20]; 																			//a temp variable of character datatype is declared.
	   	box(7,2,73,22);
		gotoxy(27,2);
		printf(" Edit flight detail ");
    	gotoxy(10,6);
		printf("Enter the modified Destination: ");
        gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
	    scanf("%s",temp); 																		//the entry is scanned and stored in the temp variable
        Destination[recognisedD]=temp; 															//this new destination is dumped into the index of the flight to be modified.
	   }
	   
	   if (j == 3)																				 //if the origin has to be modified
	   {
	    char temp[20]; 																			//a char variable called temp is declared.
	    box(7,2,73,22);
		gotoxy(27,2);
		printf(" Edit flight detail ");
		gotoxy(10,6);
		printf("Enter the modified Origin: ");
        gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
		scanf("%s",temp); 																		//the new origin is stored in temp.
        Origin[recognisedD]=temp;																 //this new origin is dumped into the index corresponding to the flight entry to be modified.
	   }
	   if (j == 4) 																					//if the date has to be modified
	   {
	   	char temp[10]; 																				//a char variable called temp is declared.
	    box(7,2,73,22);
		gotoxy(27,2);
		printf(" Edit flight detail ");
    	gotoxy(10,6);
		printf("Enter the modified Date(DD/MM/YYYY): ");
        gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
		scanf("%s",temp);																			 //the new date is stored in temp.
        date[recognisedD]=temp; 																	//this new date entered is dumped into the index corresponding to the flight entry to be modified.
	   }
	   if (j == 5) 																					//if the time has to be modified
	   {
	   	char temp[6]; 																				//a char variable temp is declared.
	   	box(7,2,73,22);
		gotoxy(27,2);
		printf(" Edit flight detail ");
    	gotoxy(10,6);
		printf("Enter the modified Time(24 hours) ");
        gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
 		scanf("%s",temp);																			 //the new, modified time is stored in temp.
        Time[recognisedD]=temp;																		 //the new time entered is dumped into the index corresponding to the flight entry to be modified.
	   }
	   if (j == 6) 																					//if the no of seats has to be modified
		{
	   	char temp[10];
	    box(7,2,73,22);
		gotoxy(27,2);
		printf(" Edit flight detail ");
		gotoxy(10,6);
		printf("Enter the modified seats: ");
        gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
		scanf("%s",temp); 																		//the modifies no of seats is stored in temp.
        seats[recognisedD]=temp; 																//the new no of seats is dumped into the index corresponding to the flight entry to be modified.
	   }
	   update();																				//updates the file containing flight details
	   gotoxy(10,10);
       printf("The details have been successfully modified!");
       gotoxy(10,11);
       delay(800);
	 }
	 
    }
  
   if (recognisedD == -1) 																			//the recognisedD variable has not been modified. It serves as a marker, indicating there are no relevant entry. We print it.
   {
   gotoxy (10,10);
	
   printf("Sorry, there are no flights with the given Flight ID!");
   gotoxy(10,11);
   }
   
}



void admin_intro() 																					//the function that presents the list of operations for the admin and directs him to these options.
{
	int a,b; 																						//two choice variables of int datatype declared.
    
    
	back_admin:																						 //an identifier that brings us back to this part of the code from some other part of the code or function.
	system("CLS"); 																					//clears the screen.
	
	
    box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,7);
 	
	printf("Welcome Kripa! :)");
	gotoxy(16,9);
 	
	printf("Kindly choose what change you'd like to make to the database.");
    
	gotoxy(16,12);
 	printf("1. Add flights");
 	delay(150);
 	gotoxy(48,12);
 	printf("2. Delete flights");
	delay(150);
 	gotoxy(16,15);
 	printf("3. Edit flight details");
 	delay(150);
 	gotoxy(48,15);
 	printf("4. Logout");

	box(9.99,22,81,24);
 	delay(150);
 	gotoxy(10,23);
 
 	printf("  Enter Your Choice [1-4] = ");
		
	
	scanf("%d",&a);																					 //scans the choice and stores into a.
    system("CLS"); 																					//clears the screen.
 	  
    if (a==1)																						//To add a flight
     {
	  add(); 																						//calls the add function
      system("CLS"); 
      box(10,6,80,21);                  
	  delay(150);
 	  gotoxy(16,9);
      printf("Press 0 to go back to the main page.");
	  gotoxy(16,11);
      
	  printf("Press 1 to Exit.\n");
	  box(9.99,22,81,24);
      delay(150);
 	  gotoxy(10,23);
	  printf("  Enter Your Choice [0-1] = "); 													//redirects the admin further to choose between going back to the main page or to exit.
 
      scanf("%d",&b); 																			//scans the choice to continue or exit into b.
      	
      if (b==0) 																				//if the admin chooses to go back, we go to that part of the code again, for which we use the goto command.
      {
	   goto back_admin; 
	  }
	  else if (b==1) 																			//we exit if the admin chooses so.
	  {
	   exit(0);
	  }
    }
    
    if (a==2)																					//To delete a flight
    {
	 deleteone(); 																				//calls the deleteone function.
     printf("Press any key to continue!");
      getch(); 
      system("CLS"); 																			//clears the screen.
      box(10,6,80,21);                  
	  delay(150);
 	  gotoxy(16,9);
      printf("Press 0 to go back to the main page.");
	  gotoxy(16,10);
      
	  printf("Press 1 to Exit.\n");
	  box(9.99,22,81,24);
      delay(150);
 	  gotoxy(10,23);
	  printf("  Enter Your Choice [0-1] = "); 														//redirects the admin further to choose between going back to the main page or to exit.
      
	  scanf("%d",&b);																				 //scans the choice to continue or exit into b.
      
	  if (b==0) 																					//if the admin chooses to go back, we go to that part of the code again, for which we use the goto command.
      {
	   goto back_admin;
	  }
	  else if (b==1) 																				//we exit if the admin chooses so.
	  {
	   exit(0);
	  }
    }
    
    if (a==3)																						//To edit a flight
    {
	 edit(); 																						//calls the edit function.
     printf("Press any key to continue!");
      getch(); 
      system("CLS"); 
      box(10,6,80,21);                  
	  delay(150);
 	  gotoxy(16,9);
      printf("Press 0 to go back to the main page.");
	  gotoxy(16,10);
      
	  printf("Press 1 to Exit.");
	  box(9.99,22,81,24);
      delay(150);
 	  gotoxy(10,23);
	  printf("  Enter Your Choice [0-1] = ");														//redirects the admin further to choose between going back to the main page or to exit.
      
	  scanf("%d",&b); 																				//scans the choice to continue or exit into b.
      
	  if (b==0) 																					//if the admin chooses to go back, we go to that part of the code again, for which we use the goto command.
      {
	   goto back_admin;
	  }
	  else if (b==1)																				 //we exit if the admin chooses so
	  {
	   exit(0);
	  }
    }
	
    if (a==4) 																						//To logout.
    {
	 intro(); 																						//The intro function is called.
	}
	
	else 																							//if any choice other than 1-4 is entered, we print: Invalid Choice!
	{
	system("CLS"); 																					//redirects the admin further to choose between going back to the main page or to exit.
    box(10,6,80,21);                  
    delay(150);
	box(9.99,22,81,24);
    delay(150);
 	gotoxy(10,23);
	
    printf("Invalid Choice! Try again.");
	delay(800);
	goto back_admin; 																				//goes to the beginning of the admin intro.
	}
	
}


void flight_data()  																				//reads flight data from the file
{ 
	
    FILE* ptr = fopen("Test.txt","r"); 
    
    
    char a[100],b[100],c[100],d[100],e[100],f[100]; 
    while (fscanf(ptr,"%s %s %s %s %s %s",a,b,c,d,e,f)==6) 
     {
		FlightID.push_back(a); 
		Destination.push_back(b); 
		Origin.push_back(c); 
		Time.push_back(d); 
	 	seats.push_back(e);
		date.push_back(f);  
    }
    fclose(ptr);
    total=FlightID.size();
	
}


//******************************************************************************************************************//


int ticket (int i, struct customer_details d[], int * plan)           //Input value from customer about their details
{
	int k, t, counter=0;
	gotoxy(48,3);
	printf("Age: ");                                                  //Asks for age from user                    
	box1(48,4,70,6);
	gotoxy(50,5);
	scanf("%d", &d[i].age);
	if (d[i].age<=2)                                                  
	{
	gotoxy(48,7);
	printf("Ticket price is %d\n",infant);
	d[i].price=infant;                                                //the pricing based on age is stored in the global struct customer_details d[]
	}
	else if (d[i].age>2 && d[i].age <18)
	{	gotoxy(48,7);
		 
	printf("Ticket price is %d\n",child);                             
	d[i].price=child;
	}
	else
	{	gotoxy(48,7);
	 
	printf("Ticket price is %d\n",adult);                             
	d[i].price=adult;
	}
			
	gotoxy(48,8);
	printf("First Name: ");                                           //the details taken are stored in global struct customer_details d[] to be used to print for the ticket
	box1(48,9,70,11);
	gotoxy(50,10);
	scanf("%s", d[i].FirstName);
	
	gotoxy(48,12);
	printf("Last Name: ");
	box1(48,13,70,15);
	gotoxy(50,14);
	scanf("%s", d[i].LastName);
	
	gotoxy(48,16);
	printf("Phone number: ");
	box1(48,17,70,19);
	gotoxy(50,18);
	scanf("%s", d[i].Num);
	
	seatsetting:
    gotoxy(48,20);
	printf("Seat number");
	box1(48,21,70,23);
	gotoxy(50,22);
	scanf("%d", &k);
	

		for(t=0; t<100; t++)
	{
		if (plan[t]==k)                                               //If the seat number selected is a valid seat, the counter is given a value of 1, if not then counter remains as 0
		{
			counter=1;
		}
	}
	if (counter==1)
	{
		d[i].seat_number=k;
		printf("%d", d[i].seat_number);                               //Only if counter value==1 then the seat number is stored
	}
	else
	{
		printf("    Invalid seat number. Please fill again");         //Else the following statement is shown and a valid seat number is requested
		goto seatsetting;
	}
	return d[i].seat_number;
}

void PrintTicket (struct customer_details p)       										//Prints out ticket on screen and as a text file
{
	FILE *fptr;
	fptr = fopen("boarding.txt", "a");
	int i=0,j;
	

	printf("  ====================================================================================\n");
	fprintf(fptr, "  ====================================================================================\n");
	for (i=0; i<2; i++)
	{
		for(j=0; j<i;)
		{
			if (j/2==0)
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
	printf("                               Flight ID          %s                                   \n\n", FlightID[flight_book].c_str());
	printf(" ||                                                                                  ||\n");
	printf("                                 Name           %s %s                                  \n\n", p.FirstName, p.LastName);
	printf(" ||                                                                                  ||\n");
	printf("                                 Price            Rs. %d/-                             \n\n", p.price);
	printf(" ||                                                                                  ||\n");
	printf("                          To:%s                 From:%s                                 \n\n", Origin[flight_book].c_str(), Destination[flight_book].c_str());
	printf(" ||                                                                                  ||\n");
	printf("                          Date:%s             Time:%s                                 \n\n", date[flight_book].c_str(), Time[flight_book].c_str());
	printf(" ||                                                                                  ||\n");
	printf("                               Seat Number        %d                                   \n\n", p.seat_number);
	printf(" ||                                                                                  ||\n");
	printf("                                Gate Number       2A                                   \n\n");
	
	fprintf(fptr, "                               Flight ID          %s                                   \n\n",FlightID[flight_book].c_str());
	fprintf(fptr, " ||                                                                                  ||\n");
	fprintf(fptr, "                                 Name           %s %s                                  \n\n", p.FirstName, p.LastName);
	fprintf(fptr, " ||                                                                                  ||\n");
	fprintf(fptr, "                                 Price             Rs. %d /-                                   \n\n",p.price);
	fprintf(fptr, " ||                                                                                  ||\n");
	fprintf(fptr, "                          To:%s                 From:%s                                  \n\n",Origin[flight_book].c_str(),Destination[flight_book].c_str());
	fprintf(fptr," ||                                                                                  ||\n");
	fprintf(fptr,"                          Date:%s             Time:%s                                 \n\n", date[flight_book].c_str(), Time[flight_book].c_str());
	fprintf(fptr, " ||                                                                                  ||\n");
	fprintf(fptr, "                               Seat Number        %d                                   \n\n",p.seat_number);
	fprintf(fptr, " ||                                                                                  ||\n");
	fprintf(fptr, "                                Gate Number       2A                                   \n\n");
	
	for (i=0; i<2; i++)
	{
		for(j=0; j<i; j++)
		{
			if (j/2==0)
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

int * randomfunc (int n)                                  							//randomizes the flight seating pattern for each flight
{
	int i, k=0;
	bool arr[100]={0};																//array which stores boolean values
	static int random[100]={0};
	time_t t;
	srand((unsigned)time(&t));
	for (i=0; i<n; ++i)
	{
		int r=rand()%61;                                                        //random number generated between 0-60
		if (!arr[r] && r!=0)                                                    //condition to check for repitition and to exclude 0
		{
			random[k]=r;
			k++;
		}
		else
		{
			i--;
		}
		arr[r]=1;                                                               //boolean value updated from 0 to 1
	}
	return random;                                                              //returns the seating chart
}

void seating(int n, int random[])                         						//prints the seating chart for each flight
{
	int i,o,j,pos=5;
	system("CLS");
	box(2,2,73,24);
			 
	gotoxy(3,6);
 	printf("  Seating Chart\n\n");
 	
 	printf("   x--------xx--------x\n   ");
	for( o=1;o<=60;o++)
	{	printf("|");
		int counter=0;
		for(j=0;j<n;j++)
		{
			if(random[j] == o)
  			{
    			counter+=1;
  			}
		}
		if(counter==0)
		{
  			if(o%6==0 )
  			{
    			printf("xx|\n   ");
  			}
  			else if(o%3==0 && o%6!=0)
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
  			if(o%6==0 && o/10==0)
  			{
    			printf("0%d|\n   ",o);
  			}
  			else if(o%3==0 && o%6!=0 && o/10==0)
  			{
     			printf("0%d|",o);
  			}
  			else if(o%3==0 && o%6!=0 && o/10!=0)
  			{
     			printf("%d|",o);
  			}
  			else if(o%6==0 && o/10!=0)
  			{
    			printf("%d|\n   ",o);
  			}
  			else if(o%3!=0 && o%6!=0 && o/10==0)
  			{
    			printf("0%d",o);
  			}
  			else
  			{
    			printf("%d",o);
  			}
		}

	}
	printf("x--------xx--------x\n\n");
	gotoxy(4,21);
 	
	printf(" xx--> unavailable seats.\n\n");
}

void TicketFunc (int n, int TicketNumber, int * plan)    							//Main function for Taking, Storing and Printing Ticket details
{
	int age,i,j,q,n1=n,b,sum=0;
	struct customer_details d[TicketNumber];
			
		for (i=0; i < TicketNumber; i++)
		{	system("CLS");
		 	box(2,2,73,24);
			seating(n1,plan);
	        gotoxy(35,2);
			printf("For Ticket %d:", i+1);
			j=ticket(i,d,plan);
			for(q=0;q<100;q++)
			{
				if(plan[q]==j)
				{
					plan[q]=0;
					--n1;
				}
			}
			system("CLS");
		}
	char str[10];
	itoa(n-TicketNumber,str,10);
	seats[flight_book]=str;
	update();
	for(i=0; i<TicketNumber; i++)
	{
		PrintTicket(d[i]);
		sum+=d[i].price;
	}
	printf("\n\t\t\t\t Total price: Rs. %d\n\n",sum);
	
	printf("Press 0 to go back to the user page.\n");
	printf("Press 1 to go the main page.\n");
	printf("Press 2 to Exit.\n");
	scanf("%d",&b);
	switch(b){
		case 0: system("CLS");user(); break;
		case 1: system("CLS");intro(); break;
		case 2: system("CLS");exit(0); break;}
	
}


// Calculates the Index of the day from 0 to 6 i.e. If the given date of the given month appears on a Sunday(0), Monday(1), Tuesday(2), etc.
int dayNumber(int day, int month, int year) 									//Function required to print the calendar
{ 
  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };										 //set of indices for a particular date 
    year -= month < 3; 
    return (year + year / 4 
			- year / 100 
            + year / 400 
            + t[month - 1] + day) % 7; 
} 

/* Function that returns the name of the 
 month for the given month Number 
 January - 0, February - 1 and so on */ 

string getMonthName(int monthNumber) 											//Function required to print the calendar
{ 
    string month; 
  
    switch (monthNumber) { 
    case 0: 
        month = "January"; 
        break; 
    case 1: 
        month = "February"; 
        break; 
    case 2: 
        month = "March"; 
        break; 
    case 3: 
        month = "April"; 
        break; 
    case 4: 
        month = "May"; 
        break; 
    case 5: 
        month = "June"; 
        break; 
    case 6: 
        month = "July"; 
        break; 
    case 7: 
        month = "August"; 
        break; 
    case 8: 
        month = "September"; 
        break; 
    case 9: 
        month = "October"; 
        break; 
    case 10: 
        month = "November"; 
        break; 
    case 11: 
        month = "December"; 
        break; 
    } 
    return month; 
} 

void printCalendar(int year) 														//Function that prints the calendar for the given year
{ 
	system("CLS");
	box(2,2,40,31);                  
	delay(150);
 	gotoxy(9,7);
 	
    printf("     \tCalendar - %d\n", year); 
    gotoxy(9,10);
 	
	int days; 
  
    // Index of the day from 0 to 6 i.e. If the 1st of the month appears on a Sunday(0), Monday(1), Tuesday(2), etc.
    int current = dayNumber(1, 11, year); 
  
    /* i for Iterate through months 
     j for Iterate through days of the month - i.
     Change i according to the months we want to display. 
	 the code is written for November and December. */
    for (int i = 10; i < 12; i++) 
	{ 
        if(i==10)
		{
		days=30;
		}
		else
		{
		days=31;
		}
  
        // Print the current month name 
        printf("\n      ------------%s-------------\n  ", 
               getMonthName(i).c_str()); 
  
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

void display() 															//Function To display a calendar and the flights for the chosen date.
{
	printCalendar(2020); 												//prints calendar
	gotoxy(10,28);
	char dt[50];
	printf("Choose a date(DD/MM/YYYY): ");
	gotoxy(15,30);
	
	scanf("%s", dt);
	int n=total;
	system("CLS");
	box(10,6,80,21);                  
	delay(150);
	gotoxy(35,6);
	int count=0;
	printf("Available flights");
	gotoxy(16,8);
	printf("Date\t\tID\tTo\tFrom\tTime\tSeats");
	gotoxy(16,9);
	int pos=10;
	 for (int i=0;i<n;i++)
	{
    
		if(dt==date[i])														//displays the available flights for the entered date
		{	gotoxy(16,pos++);
			
			printf("%s\t",date[i].c_str());
			printf("%s\t",FlightID[i].c_str());
			printf("%s\t",Destination[i].c_str());
			printf("%s\t",Origin[i].c_str());
			printf("%s\t",Time[i].c_str());
			printf("%s\t",seats[i].c_str());
			count+=1;
		}
	
	}
	if(count==0)
	{	gotoxy(16,pos++);
			
		printf("No such flight exists.");
		delay(800);
		}
	gotoxy(16,19);
	printf("Press any key to continue.");
	getch();
	}
	
void user() 																	//Function to Display all the options available to User which are: View Calendar, Free search, Book a flight
{   int TicketNumber,i,j,b;
	char ID[20],dates[10]; 
    check:
    system("CLS");
	box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,7);
 	printf("Welcome %s %s\n",u.firstname,u.lastname);
 	gotoxy(16,12);
 	
 	printf("1. View calendar");
 	delay(150);
 	gotoxy(48,12);
 	printf("2. Free Search");
	delay(150);
 	gotoxy(16,15);
 	printf("3. Book the flight");
 	delay(150);
 	gotoxy(48,15);
 	printf("4. Logout");

	box(9.99,22,81,24);
 	delay(150);
 	gotoxy(10,23);
 
 	printf("  Enter Your Choice [1-4] = ");
		
	scanf("%d", &i);

    system("CLS"); 																		//this entry redirects the admin to further add details
    
	
	if (i==1)
	{
	display();
	system("CLS"); 																		//redirects the user further to choose between going back to the main page or to exit.
    box(10,6,80,21);                  
	delay(150);
 	gotoxy(16,9);
    printf("Press 0 to go back to the main page.");
	gotoxy(16,11);
      
	printf("Press 1 to Exit.\n");
	box(9.99,22,81,24);
    delay(150);
 	gotoxy(10,23);
	printf("  Enter Your Choice [0-1] = ");
 
    scanf("%d",&b);
    if (b==0)																		 //if the user chooses to go back, we go to that part of the code again, for which we use the goto command.
    {
	   goto check;
	}
	else if (b==1)																	 //we exit if the user chooses so.
	{
	   exit(0);
	}
	}
	else if (i==2)
	{
	  search();
	  system("CLS");																 //redirects the user further to choose between going back to the main page or to exit.
      box(10,6,80,21);                  
	  delay(150);
 	  gotoxy(16,9);
      printf("Press 0 to go back to the main page.");
	  gotoxy(16,11);
      
	  printf("Press 1 to Exit.\n");
	  box(9.99,22,81,24);
      delay(150);
 	  gotoxy(10,23);
	  printf("  Enter Your Choice [0-1] = ");
 
      scanf("%d",&b);
      if (b==0) 																		//if the user chooses to go back, we go to that part of the code again, for which we use the goto command.
      {
	   goto check;
	  }
	  else if (b==1) 																	//we exit if the user chooses so.
	  {
	   exit(0);
	  }
   	  }
   	  
   	  else if(i==3)
   	  {		 
    	if (total == 0) 																//Checks If there are flights available to book.
     	{
     		system("CLS"); 
     	 	box(10,6,80,21);                  
	  		delay(150);
 	  		gotoxy(16,9);
      		printf("There are no flights available!'");
	     	gotoxy(16,11);
			delay(800);
			intro();
      
		 }	
		 
   		else{
   		box(7,2,73,22);
		gotoxy(27,2);
		printf(" Book the flight ");
    
		gotoxy(10,6);
		printf("Enter the date(DD/MM/YYYY): ");
		gotoxy(59,6);
		box1(48,5,70,7);
		gotoxy(50,6);
		scanf("%s",dates);
		gotoxy (10,9);
		printf("Enter flight ID: ");
		gotoxy(59,9);
		box1(48,8,70,10);
		gotoxy(50,9);
		scanf("%s",ID);
		
    	for (int i=0;i<total;i++)
		{
    
		if(strcmp(FlightID[i].c_str(),ID)==0 && strcmp(date[i].c_str(),dates)==0)
		{
			flight_book=i;
		}
		}
	   
   		 if (flight_book == -1) 														//When there are no matching entries for the flight IDs
   		 {	
   		 	gotoxy(10,12);
		    printf("Sorry, there is no such flight that you are looking for!");
			gotoxy(10,13);
			printf("Try again.");
			delay(900);
	        goto check; 
	
			}
		else {  
		int n=atoi(seats[flight_book].c_str());
	
		int * plan=randomfunc(n);
		check2:
		gotoxy(10,12);
		
		printf("The number of available seats are %d",n);
		gotoxy(10,16);
		
		printf("Number of seats you wish to book: ");
		gotoxy(59,16);
		box1(48,15,70,17);
		gotoxy(50,16);
		scanf("%d", &TicketNumber);
		if(TicketNumber<=n)
		{
		TicketFunc(n, TicketNumber, plan);
		}
		else
		{
		gotoxy(10,18);
		
		printf("Not enough seats available. Type another number!");
		delay(900);
		goto check2;
		
		
		}
		}
  		 }
		}
	else if(i==4)
	{
	intro();	
	}
	else
	{
	system("CLS"); 
    box(10,6,80,21);                  
    delay(150);
	box(9.99,22,81,24);
    delay(150);
 	gotoxy(10,23);
	
    printf("Invalid Choice! Try again.");
	delay(800);
	goto check; 
	}
}

void update()																		 //Updates the file after any of the information has been changed.
{
	FILE *temp;
   	temp=fopen("Test.txt","w");
   	for(int i=0;i<total;i++)
   	{
   		const char* a=FlightID[i].c_str();
   		const char* b=Destination[i].c_str();
   		const char* c=Origin[i].c_str();
   		const char* d=Time[i].c_str();
   		const char* e=seats[i].c_str();
   		const char* f=date[i].c_str();
   		fprintf(temp,"%s %s %s %s %s %s\n",a,b,c,d,e,f);
	}
	fclose(temp);
	
}


int main()

{
	anime();													//function to call the animation
	logo();														//function to call the logo
	flight_data();												//function to read the flight data from Test.txt file
    intro();
	return 0;	

}
