#include "WorkTicket.h"
#include <iostream>
#include <sstream>
#include "MyConsoleInput.h"

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
            std::getline(std::cin, description);
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
