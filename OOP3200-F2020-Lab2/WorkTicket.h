#pragma once
#include <string>
#ifndef _WORK_TICKET_
#define _WORK_TICKET_

// Class declaration section.
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

    /* copy constructor */
    WorkTicket(const WorkTicket& ticket2);
    ~WorkTicket(); // Destructor which does memory cleanup.
	
    /* conversion operator */
    operator std::string() const;

    /* Is not equal to overload */
    bool operator!=(const WorkTicket& otherWorkTicket) const;

    /* Equal to overload */
    bool operator==(WorkTicket& otherWorkTicket) const;

    /* Assignment operator*/
    void operator=(WorkTicket& otherWorkTicket);

    /* output operator */
    friend std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket);

    /* input operator */
    friend std::istream& operator>>(std::istream& in, WorkTicket& ticket);

    /**** Accessors ****/
    static void ShowWorkTicket(const WorkTicket&);

    int GetTicketNumber() const;

    std::string GetClientID() const;

    std::string GetTicketDate() const;

    std::string GetIssueDescription() const;

    /*** Mutators ***/
    void SetWorkTicket();

    void SetWorkTicketNumber(int ticketNumber);

    void SetClientID(std::string iD);

    void SetWorkTicketDate(std::string ticketDate);

    void SetIssueDescription(std::string description);

private:
    // Data members for a Work Ticket obj's parameters.
    int workTicketNumber{};
    std::string clientID;
    std::string workTicketDate;
    std::string issueDescription;
};

#endif // defined (_WORK_TICKET_)
