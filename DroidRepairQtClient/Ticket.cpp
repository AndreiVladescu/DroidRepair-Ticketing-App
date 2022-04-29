#include "Ticket.h"

// Empty ticket type
Ticket::Ticket()
{
	_id = -1;
	_client_id = -1;
	_technician_id = -1;

	bool rb;
	rb = _category.empty();
	rb = _solution.empty();
	rb = _problem.empty();
}

// Default destructor, empties things
Ticket::~Ticket()
{
	_id = -1;
	_client_id = -1;
	_technician_id = -1;

	bool rb;
	rb = _category.empty();
	rb = _solution.empty();
	rb = _problem.empty();
}

void Ticket::setCategory(string category)
{
	_category = category;
}

void Ticket::setProblem(string problem)
{
	_problem = problem;
}

void Ticket::setSolution(string solution)
{
	_solution = solution;
}

void Ticket::setID(int id)
{
	_id = id;
}

void Ticket::setClientID(int cid)
{
	_client_id = cid;
}

void Ticket::setTechnicianID(int tid)
{
	_technician_id = tid;
}

string Ticket::getCategory()
{
	return this->_category;
}

string Ticket::getProblem()
{
	return this->_problem;
}

string Ticket::getSolution()
{
	return this->_solution;
}

int Ticket::getID()
{
	return this->_id;
}

int Ticket::getClientID()
{
	return this->_client_id;
}

int Ticket::getTechnicianID()
{
	return this->_technician_id;
}

