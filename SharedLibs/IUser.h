#pragma once

#include <iostream>

using namespace std;

class IUser
{
public:

#pragma region Setters
	virtual void setID(int id) = 0;
	virtual void setRole(int role) = 0;
	virtual void setEmail(string email) = 0;
#pragma endregion

#pragma region Getters
	virtual int getID() = 0;
	virtual int getRole() = 0;
	virtual string getEmail() = 0;
#pragma endregion

};