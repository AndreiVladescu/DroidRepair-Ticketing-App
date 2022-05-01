#pragma once
#include "ITicket.h"

class Ticket :
	public ITicket
{
protected:
	int _id;
	int _client_id;
	int _technician_id;

	string _category;
	string _problem;
	string _solution;
	string _client_email;
public:
	Ticket();
	~Ticket();
#pragma region Setters
	void setCategory(string category) override;
	void setProblem(string problem) override;
	void setSolution(string solution) override;
	void setID(int id);
	void setClientID(int cid) override;
	void setTechnicianID(int tid) override;
	void setClientEmail(string email);
#pragma endregion
#pragma region Getters
	string getCategory() override;
	string getProblem() override;
	string getSolution() override;
	string getClientEmail();
	int getID() override;
	int getClientID() override;
	int getTechnicianID() override;

#pragma endregion
};

