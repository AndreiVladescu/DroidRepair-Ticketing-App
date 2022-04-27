#pragma once
#include <iostream>

using namespace std;

class ITicket
{
public:

#pragma region Setters
	virtual void setCategory(string category) = 0;
	virtual void setProblem(string problem) = 0;
	virtual void setSolution(string solution) = 0;
	virtual void setID(int id) = 0;
	virtual void setClientID(int cid) = 0;
	virtual void setTechnicianID(int tid) = 0;
#pragma endregion

#pragma region Getters
	virtual string getCategory() = 0;
	virtual string getProblem() = 0;
	virtual string getSolution() = 0;
	virtual int getID() = 0;
	virtual int getClientID() = 0;
	virtual int getTechnicianID() = 0;
#pragma endregion

};

