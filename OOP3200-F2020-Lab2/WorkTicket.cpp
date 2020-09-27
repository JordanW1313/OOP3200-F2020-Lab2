#include "WorkTicket.h"
#include <iostream>
#include <sstream>
#include "MyConsoleInput.h"

// Class definition section.

// constructor for WorkTicket
WorkTicket::WorkTicket(int ticket_num, std::string ticket_id, std::string ticket_date, std::string ticket_description)
{
    SetWorkTicketNumber(ticket_num);
    SetClientID(ticket_id);
    SetWorkTicketDate(ticket_date);
    SetIssueDescription(ticket_description);
}

// Copy constructor implementation.
WorkTicket::WorkTicket(const WorkTicket& ticket2) 
{
    SetWorkTicketNumber(ticket2.GetTicketNumber());
    SetClientID(ticket2.GetClientID());
    SetWorkTicketDate(ticket2.GetTicketDate());
    SetIssueDescription(ticket2.GetIssueDescription());

    std::cout << "\nA WorkTicket object was COPIED.\n";
}
WorkTicket::~WorkTicket() // Default destructor.
= default;

WorkTicket::operator std::string() const
{
    std::string output;
    std::stringstream strOut;

    strOut << "Work Ticket # " << GetTicketNumber() << " - " << GetClientID() << " (" << GetTicketDate() << "): " << GetIssueDescription() << std::endl;
    output = strOut.str();

    return output;

}

// Operator checks if WorkTicket obj is the same as the other WorkTicket obj.
bool WorkTicket::operator!=(const WorkTicket& otherWorkTicket) const
{
    if (GetTicketNumber() == otherWorkTicket.GetTicketNumber())
    {
        return false;
    }
    else if (GetClientID() == otherWorkTicket.GetClientID())
    {
        return false;
    }
    else if (GetTicketDate() == otherWorkTicket.GetTicketDate())
    {
        return false;
    }
    else if(GetIssueDescription() == otherWorkTicket.GetIssueDescription())
    {
        return false;
    }
    else 
    {
        return true;
    }        
}

bool WorkTicket::operator==(WorkTicket& otherWorkTicket) const
{
    if (GetTicketNumber() != otherWorkTicket.GetTicketNumber())
    {
        return false;
    }
    else if (GetClientID() != otherWorkTicket.GetClientID())
    {
        return false;
    }
    else if (GetTicketDate() != otherWorkTicket.GetTicketDate())
    {
        return false;
    }
    else if (GetIssueDescription() != otherWorkTicket.GetIssueDescription())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void WorkTicket::operator=(WorkTicket& otherWorkTicket)
{
    workTicketNumber = otherWorkTicket.GetTicketNumber();
    clientID = otherWorkTicket.GetClientID();
    workTicketDate = otherWorkTicket.GetClientID();
    issueDescription = otherWorkTicket.GetIssueDescription();

    std::cout << "\nWorkTicket object was ASSIGNED.\n" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket)
{
    out << "Ticket Number: " << ticket.GetTicketNumber() << std::endl;
    out << "----------------------" << std::endl;
    out << "Client ID: " << ticket.GetClientID() << std::endl;
    out << "Ticket Date: " << ticket.GetTicketDate() << std::endl;
    out << "Issue Description: " << ticket.GetIssueDescription() << std::endl << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, WorkTicket& ticket)
{
    int newTicketNumber;
    std::string newClientID;
    std::string newTicketDay;
    std::string newTicketMonth;
    std::string newTicketYear;
    std::stringstream strOut;
    std::string newDateString;
    std::string newIssueDescription;
    bool isValid = false;

    std::cout << "Enter the work ticket number: ";
    newTicketNumber = ConsoleInput::ReadInteger(1, 9999999);

    if (newTicketNumber)
    {
        std::cout << "Enter the work ticket Client ID: ";
        in >> newClientID;

        while(isValid == false)
        {
            if (newClientID.length() > 1)
            {
                std::cout << "Enter the work ticket Month: ";
                newTicketMonth = std::to_string(ConsoleInput::ReadInteger(1, 31));

                std::cout << "Enter the work ticket Day: ";
                newTicketDay = std::to_string(ConsoleInput::ReadInteger(1, 12));

                std::cout << "Enter the work ticket Year: ";
                newTicketYear = std::to_string(ConsoleInput::ReadInteger(2000, 2099));

                strOut << newTicketMonth << "/" << newTicketDay << "/" << newTicketYear;

                newDateString = strOut.str();

                std::cout << "Enter the issue description: ";
                std::cout << std::endl;
                std::getline(std::cin, newIssueDescription);

                while (isValid == false)
                {                    
                    if (newIssueDescription.length() > 0) // The description string is at least one character long.
                    {
                        isValid = true;

                        ticket.SetWorkTicketNumber(newTicketNumber);
                        ticket.SetClientID(newClientID);
                        ticket.SetWorkTicketDate(newDateString);
                        ticket.SetIssueDescription(newIssueDescription);
                    }
                    else
                    {
                        std::cout << "Issue Description must be greater than one character try again. ";
                        std::cout << std::endl;
                        std::getline(std::cin, newIssueDescription);
                        isValid = false;
                    }
                }
            }
            else
            {
                std::cout << "Client ID must be greater than one character" << std::endl;
                in.ignore();
                in >> newClientID;
            }
        }
    }
    return in;
}

/// <summary>
/// Displays the object's attributes to the user.
/// </summary>
/// <param name="myTicket"></param>
void WorkTicket::ShowWorkTicket(const WorkTicket& myTicket)
{
    std::cout << "Ticket Number: " << myTicket.GetTicketNumber() << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Client ID: " << myTicket.GetClientID() << std::endl;
    std::cout << "Ticket Date: " << myTicket.GetTicketDate() << std::endl;
    std::cout << "Issue Description: " << myTicket.GetIssueDescription() << std::endl << std::endl;
}

///////// Getters for WorkTicket class ////////////////

/// <summary>
/// retrieves work ticket number attribute value from a work ticket object
/// </summary>
/// <returns></returns>
int WorkTicket::GetTicketNumber() const
{
    return workTicketNumber;
}

/// <summary>
/// retrieves client id attribute value from a work ticket object
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetClientID() const 
{
    return clientID;
}

/// <summary>
/// retrieves work ticket date attribute value from a work ticket object
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetTicketDate() const
{
    return workTicketDate;
}

/// <summary>
/// retrieves issue description attribute value from a work ticket object
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetIssueDescription() const
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


    bool validTicket = true; // validTicket returns true if all inputs are valid.
    bool isValid = false;

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
        while (isValid == false)
        {
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

                std::cout << "Enter the issue description:" << std::endl;
                std::getline(std::cin, description);
                while (isValid == false)
                {
                    if (description.length() > 0) // The description string is at least one character long.
                    {
                        issueDescription = description;
                        isValid = true;
                    }
                    else
                    {
                        
                        std::cout << "Issue Description must be greater than one character try again: " << std::endl;
                        std::getline(std::cin, description);
                    }
                }
        }
        else
        {
            std::cout << "Client ID must be greater than one character try again: ";
            std::cin >> iD;
            validTicket = false;
        }
    }
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << "The Work ticket number cannot be less than 0.";
        validTicket = false;
    }

    if (validTicket == true)
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