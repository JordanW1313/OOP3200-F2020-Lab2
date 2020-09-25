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
#include <string>
#include <stdexcept>		// out_of_range
#include <sstream>


class WorkTicket
{
public:

    // Default constructor
    WorkTicket()
    {
        workTicketNumber = 0;
        clientID = "";
        workTicketDate = "1/1/2000";
        issueDescription = "";

    }

    // Parameterized constructor
    WorkTicket(int ticketNumber, std::string id, std::string ticketDate, std::string description) 
    {
        workTicketNumber = ticketNumber;
        clientID = id;
        workTicketDate = ticketDate;
        issueDescription = description;
    };

    /**** Accessors ****/
    static void ShowWorkTicket(WorkTicket);
    
    int GetTicketNumber();

    std::string GetClientID();

    std::string GetTicketDate();

    std::string GetIssueDescription();
    
    /*** Mutators ***/
    void SetWorkTicket();

    void SetWorkTicketNumber(int ticketNumber);

    void SetClientID(std::string iD);

    void SetWorkTicketDate(std::string ticketDate);

    void SetIssueDescription(std::string description);
    
private:
    // Declaring the parameters of the WorkTicket obj
    int workTicketNumber;
    std::string clientID;
    std::string workTicketDate;
    std::string issueDescription;
};

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

/// <summary>
/// Displays the object's attributes to the user.
/// </summary>
/// <param name="myTicket"></param>
void WorkTicket::ShowWorkTicket(WorkTicket myTicket)
{
    std::cout << "Ticket Number: " << myTicket.workTicketNumber << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Client ID:" << myTicket.clientID << std::endl;
    std::cout << "Ticket Date: " << myTicket.workTicketDate << std::endl;
    std::cout << "Issue Description: " << myTicket.issueDescription << std::endl << std::endl;
}

///////// Getters for WorkTicket class ////////////////

/// <summary>
/// retrieves work ticket number attribute value from a work ticket object
/// </summary>
/// <returns></returns>
int WorkTicket::GetTicketNumber()
{
    return workTicketNumber;
}

/// <summary>
/// retrieves client id attribute value from a work ticket object
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetClientID()
{
    return clientID;
}

/// <summary>
/// retrieves work ticket date attribute value from a work ticket object
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetTicketDate()
{
    return workTicketDate;
}

/// <summary>
/// retrieves issue description attribute value from a work ticket object
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetIssueDescription()
{
    return issueDescription;
}

//////////// Setters for WorkTicket class. ///////////////

/// <summary>
/// sets all attributes of work ticket object only it all input is valid
/// </summary>
void WorkTicket::SetWorkTicket(/*int ticketNumber, std::string iD, std::string ticketDate, std::string description*/)
{
    // Constants for minimum and maximum day/month/year that the user can enter.
    const int MIN_DAY = 1;
    const int MIN_MONTH = 1;
    const int MIN_YEAR = 2000;
    const int MAX_DAY = 31;
    const int MAX_MONTH = 12;
    const int MAX_YEAR = 2099;


    bool isValid = true; // isValid returns true if all inputs are valid.

    // Variables hold user input
    int ticketNumber;
    std::string iD;
    std::string description;
    std::stringstream strOut;
    int month;
    int day;
    int year;

    std::cout << "Enter the work ticket number: ";
    //std::cin >> ticketNumber;
    try
    {
        ticketNumber = ConsoleInput::ReadInteger(1, 999999); // Checks if the ticket number is an integer.

        std::cout << "Enter the client ID: ";
        std::cin >> iD;
        if (iD.length() > 1)
        {
            std::cout << "Enter the month: ";
            try
            {
                month = ConsoleInput::ReadInteger(MIN_MONTH, MAX_MONTH); // Month entered was within range.
            }
            catch (std::exception& ex) // Month entered was out of range.
            {
                std::cerr << ex.what() << "The month must be a whole number between 1 and 12.";
            }

            std::cout << "Enter the day: ";
            try
            {
                day = ConsoleInput::ReadInteger(MIN_DAY, MAX_DAY); // Day entered was within range.
            }
            catch (std::exception& ex) // Day entered was out of range.
            {
                std::cerr << ex.what() << "The day must be a whole number between 1 and 31.";
            }

            std::cout << "Enter the Year: ";
            try
            {
                year = ConsoleInput::ReadInteger(MIN_YEAR, MAX_YEAR); // Year entered was within range.
            }
            catch (std::exception& ex) // The year either does not fall in the range, or is not an integer.
            {
                std::cerr << ex.what() << "The year must be a whole number between 2000 and 2099.";
            }

            strOut << month << "/" << day << "/" << year;

            std::cout << "Enter the issue description" << std::endl;
            std::getline (std::cin,description);
            if (description.length() > 0) // The description string is at least one character long.
            {
                issueDescription = description;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "Issue Description must be greater than one character: ";
                isValid = false;
            }
        }
        else
        {
            std::cout << "Client ID must be greater than one character" << std::endl;
            isValid = false;
        }
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << "The Work ticket number cannot be less than 0.";
        isValid = false;
    }

    if (isValid == true)
    {
        std::cout << std::endl;
        SetWorkTicketNumber(ticketNumber);
        SetClientID(iD);
        SetWorkTicketDate(strOut.str());
        SetIssueDescription(description);
    }
}

/// <summary>
/// set the work ticket number attribute of work ticket object
/// </summary>
/// <param name="ticketNumber"></param>
void WorkTicket::SetWorkTicketNumber(int ticketNumber)
{    
    workTicketNumber = ticketNumber;    
}

/// <summary>
/// set the client id attribute of work ticket object
/// </summary>
/// <param name="iD"></param>
void WorkTicket::SetClientID(std::string iD)
{
    clientID = iD;
}

/// <summary>
/// set the work ticket date attribute of work ticket object
/// </summary>
/// <param name="ticketDate"></param>
void WorkTicket::SetWorkTicketDate(std::string ticketDate)
{
    workTicketDate = ticketDate;
}

/// <summary>
/// set the issue description attribute of work ticket object
/// </summary>
/// <param name="description"></param>
void WorkTicket::SetIssueDescription(std::string description)
{
    issueDescription = description;
}
