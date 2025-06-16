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

	User(User&&) noexcept;
	User& operator=(User&&) noexcept;

	~User();

	void add_task(const Task&);
	void delete_task(const std::string&);
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
