#pragma once
#include "IUser.h"
class User :
	public IUser
{
protected:
	int _id;
	int _role;

	string _email;
public:

	User();
	~User();

#pragma region Setters
	void setID(int id) override;
	void setRole(int role) override;
	void setEmail(string email) override;
#pragma endregion

#pragma region Getters
	int getID() override;
	int getRole() override;
	string getEmail() override;
#pragma endregion
};

