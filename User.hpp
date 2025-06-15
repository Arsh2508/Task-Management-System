#include <string>
#include <vector>
#include "Task.hpp"

#ifndef USER_HPP
#define USER_HPP

class User{
public:
	User();

	User(const User&);
	User& operator=(const User&);

	User(User&&);
	User& operator=(User&&);

	~User();

	void add_task();
	void delete_task();
	void edit_task();
	void list_task();
	Task& search_task();

	void login();
	void logout();

private:
	std::string m_id;
	std::string m_name;
	std::string m_passwd;
	std::vector<Task*> m_tasks;
	bool is_logged;
};


#endif
