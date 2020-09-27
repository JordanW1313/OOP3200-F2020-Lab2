/****************************************************************
* Name: Jordan Wriker & Ahmed Rizvi
* Date: 27th September, 2020
* Course: OOP-3200
* File: OOP3200-F2020-Lab2
* Purpose: The purpose of this iteration of lab 1 is to implement operator
*          overloads in the WorkTicket class. This includes a copy constructor,
*          a conversion operator, overloaded operator==, operator=, operator>>,
*          and operator<<.
*
******************************************************************/

#include <iostream>
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()
#include "WorkTicket.h"
#include <string>
#include <stdexcept>		// out_of_range
#include <sstream>
#include <vector>


int main()
{
	// Adding some objects into the vector for testing purposes.
    WorkTicket ticket0 = (WorkTicket(1, "100698429", "1/1/2021", 
        "Desc for ticket 1"));
    WorkTicket ticket1 = (WorkTicket(2, "100441592", "2/2/2002",
        "Desc for ticket 2"));
	
    // Change size to desirable number of total WorkTicket objects.
    int numOfObjects = 3;
    std::vector<WorkTicket> ticketVector;
    ticketVector.reserve(numOfObjects); // Used to preallocate memory for the pre-existing objects.
    ticketVector.push_back(ticket0);
    ticketVector.push_back(ticket1);

    std::cout << std::endl;
   
    // Prompts the user to create the specified number of tickets.
    for (int vectorSize = 2; vectorSize < numOfObjects; vectorSize++)
    {
        WorkTicket newTicket;
        newTicket.WorkTicket::SetWorkTicket();
        ticketVector.push_back(newTicket);
        std::cout << std::endl;
    }

    
    // Displays all the attributes of each WorkTicket obj stored in the ticket vector.
    for (int vectorIndex = 0; vectorIndex < numOfObjects; vectorIndex++)
    {
        WorkTicket::ShowWorkTicket(ticketVector[vectorIndex]);
    }

    WorkTicket testTicket(1200, "ABC123", "1/2/2020",
        "test description");

    ticketVector[2] = testTicket; //Demo for = overload

    WorkTicket::ShowWorkTicket(ticketVector[2]); //Shows above ticket's new values

    std::string s = ticketVector[0]; //Demo for conversion operator

    std::cout << s << std::endl; //Displays converted work ticket string

    std::cin >> ticketVector[2]; //Demo for >> overload

    std::cout << std::endl;

    std::cout << ticketVector[2]; //Demo for << overload

	// Demo for == overload
    bool equalCheck1, equalCheck2;
    equalCheck1 = (ticketVector[0] == ticketVector[1]);
    equalCheck2 = (ticketVector[0] == ticketVector[2]);

    std::cout << "Is Ticket #" << ticketVector[0].GetTicketNumber() <<
        " equal to Ticket #" << ticketVector[1].GetTicketNumber() << "?: " << equalCheck1 << std::endl;
    std::cout << "Is Ticket #" << ticketVector[0].GetTicketNumber() <<
        " equal to Ticket #" << ticketVector[2].GetTicketNumber() << "?: " << equalCheck2 << std::endl;
}

