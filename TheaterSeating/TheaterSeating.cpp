//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121																//
//																									//
//	Type of Assignment:	Assignment	  	 															//
//	Problem Number:	4		 																		//
//	Section Number	700		 																		//
//	Author:	Adam Stahly																				//
//	Due Date: 5/4/2023		 																		//
//	File Name:				TheaterSeating.cpp														//
//																									//
//	Purpose of Program:																				//
//			Assign 6 rows of 8 seats to customers and display prices					    		//
//																									//
//																									//
//	Algorithm:																						//
//    1.Ask customers which seat type they want.			                                       	//
//        2.Display if a seat is available.                                                         //
//        3.Display price of rows.                                                                  //
//        4.Repeat until program is terminated or all seats are full.     							//		
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//constant variables
const int SEAT_IN_ROW = 8, ROWS=6;
//function definition
void displayMenu();
void displaySeats(char seats[ROWS][SEAT_IN_ROW]);
void displayPrices(double prices[]);
void showTotal(double total);
void getTicket(char seats[ROWS][SEAT_IN_ROW],double prices[],double &total,int &tickets);
int main()
{
    //declare variables
    char seats[ROWS][SEAT_IN_ROW];
    double prices[ROWS];
    int choice,tickets=0;
    double total = 0;
    for (int i = 0; i < ROWS; i++) // Declare and initialize the seats array to ("#")
    {
        for (int j = 0; j < SEAT_IN_ROW; j++)
        {
            seats[i][j] = '#';
        }
    }
    for (int i=0; i < ROWS; i++) // Declare and initialize the prices array
    {
        cout << "Please enter ticket price for Row " << i + 1 << " in USD: ";
        cin >> prices[i];
    }
    do {
        displayMenu(); //Call menu function
        cin >> choice; //Get input from user
        switch (choice) {          // Switch statement to handle user's choice
        case 1:
            displaySeats(seats);
            break;
        case 2:
            displayPrices(prices);
            break;
        case 3:
            showTotal(total);
            break;
        case 4:
            getTicket(seats,prices,total,tickets);
            break;
        case 5:
            break;
        default:
            cout << "Invalid Input";
        }
        } while (choice != 5);
        return 0;
}

void displayMenu()  // Function to display the menu
{
    cout << "\nC++ Theatre\n\n";
    cout << "1. View Available Seats";
    cout << "\n2. View Seating Prices";
    cout << "\n3. View Ticket Sales";
    cout << "\n4. Purchase a Ticket";
    cout << "\n5. Exit the Program";
    cout << "\nEnter your choice(1-5): ";
}
void displaySeats(char seats[ROWS][SEAT_IN_ROW]) // Function to display the seating chart
{
    cout << "Seats\n";
    cout << "       12345678";
    for (int i=0; i < ROWS; i++)
    {
        cout << "\nRow " << i + 1 << ": ";
        for (int j=0; j < SEAT_IN_ROW;j++)
        {
            if (seats[i][j]=='#')
                cout << "#";
            else
                cout << "*";
        }
    }
    cout << "\n\nLegend: * = Sold" <<
                    "\n        # = Available\n";
}
void displayPrices(double prices[]) // Function to display the prices of rows
{
    cout << "\nPrices:\n\n";
    for (int i=0; i < ROWS; i++)
    {
        cout << "Row " << i + 1 << ": $" << fixed << setprecision(2) << prices[i];
        cout << "\n";
    }
}
void showTotal(double total) // Function to display the total ticket sales
{
    cout << "\nTotal Sales to Date:  $"  << fixed << setprecision(2) << total;
    cout << "\n";
}
void getTicket(char seats[ROWS][SEAT_IN_ROW],double prices[], double &total, int &tickets) //Function to sell tickets
{
    char option; //declare variables
    int row, seat;
    if (tickets == ROWS * SEAT_IN_ROW) // Check if all seats have been sold
    {
        cout << "Sold Out! Tickets can no longer be purchased.\n";
        exit(0); // Exit the program
    }
    cout << "\nC++ Theatre\n";  // Prompt user if they want to view the chart of available seats
    cout << "Ticket Purchase Opportunity\n\n";
    cout << "Do you wish to view the chart of available seats before making your selections (y/n)? ";
    cin >> option;
    if (option == 'y' || option == 'Y') // Display the chart of available seats if requested
    {
        displaySeats(seats);
    }
    cout << "Please enter desired row number (1-6): "; // Prompt user to enter desired row and seat numbers
    cin >> row;
    cout << "Please enter desired seat number(1-8): ";
    cin >> seat;
    if (seats[row-1][seat-1] == '*') // Check if the selected seat is already occupied
    {
        cout << "Seat Occupied. Please try again." << endl;
    }
    else if (row - 1 >= ROWS || row - 1 < 0) // Check if the selected row number is invalid
    {
        cout << "Row does not exist. Please try again.\n";
    }
    else if (seat - 1 >= SEAT_IN_ROW || seat - 1 < 0) // Check if the selected seat number is invalid
    {
        cout << "Seat does not exist. Please try again.\n";
    }
    else
    {
        cout << "Purchase confirmed"; // Confirm the purchase 
        seats[row-1][seat-1] = '*';
        tickets++; //Update seat status
        total += prices[row - 1];
        cout << "\n\nWould you like to purchase another seat(y/n)? "; // Ask user if they want to purchase another seat
        cin >> option;
        if (option == 'y' || option == 'Y')
            getTicket(seats,prices,total,tickets); //Repeat function
        else // Display the total number of tickets purchased and the total price
        {
            cout << "\nYou have purchased a total of " << tickets << " tickets for a total price of $"  << fixed << setprecision(2) << total;
        }
    }
}
