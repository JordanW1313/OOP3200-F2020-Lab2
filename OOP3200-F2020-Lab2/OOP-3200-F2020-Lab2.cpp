/****************************************************************
* Name: Jordan Wriker & Ahmed Rizvi
* Date: 18th September, 2020
* Course: OOP-3200
* File: OOP3200-F2020-Lab1
* Purpose: The purpose of this program is to implement object oriented concepts to keep
*          track of Work Tickets. Each Work Ticket is created as an object, and upon the
*          launch of the program, the user is prompted to create their own Work Ticket
*          object. The program then outputs all the Work Tickets, stored in an array, and 
*          their attributes.
*
******************************************************************/

#include <iostream>
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()
#include "WorkTicket.h"
#include <string>
#include <stdexcept>		// out_of_range
#include <sstream>


int main()
{
    // Array holds WorkTicket objs. Can change the array size if more tickets are needed.
    WorkTicket ticketArray [3];

    // Creating the first two ticket objs in ticketArray.
    ticketArray[0] = WorkTicket(1, "100698449", "1/1/2001", "This is the description for the very first work ticket in the array.");
    ticketArray[1] = WorkTicket(2, "100441592", "2/2/2002", "This is the description for the very second work ticket in the array.");
    

    // Prompts the user to create tickets for the remaining number of empty indices of the ticket array. User must alter number of loops to indicate number of array elements.
    for (int ticketIndex = 2; ticketIndex <= 2; ticketIndex++)
    {
        ticketArray[ticketIndex].WorkTicket::SetWorkTicket();
        std::cout << std::endl;
    }

    // Displays all the attributes of each WorkTicket obj stored in the ticket array.
    for (int ticketIndex = 0; ticketIndex <= 2; ticketIndex++)
    {
        ticketArray[ticketIndex].WorkTicket::ShowWorkTicket(ticketArray[ticketIndex]);
        std::cout << std::endl;
    }
}

