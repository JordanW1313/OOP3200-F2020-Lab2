#pragma once
#include <string>
#ifndef _WORK_TICKET_
#define _WORK_TICKET_


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

#endif // defined (_WORK_TICKET_)
