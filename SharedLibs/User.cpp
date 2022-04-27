#include "User.h"

// Empty constructor
User::User()
{
	this->_id = -1;
	this->_role = -1;

	bool rb;
	rb = this->_email.empty();
}

// Default destructor
User::~User()
{
	this->_id = -1;
	this->_role = -1;

	bool rb;
	rb = this->_email.empty();
}

void User::setID(int id)
{
	this->_id = id;
}

void User::setRole(int role)
{
	this->_role = role;
}

void User::setEmail(string email)
{
	this->_email = email;
}

int User::getID()
{
	return this->_id;
}

int User::getRole()
{
	return this->_role;
}

string User::getEmail()
{
	return this->_email;
}
