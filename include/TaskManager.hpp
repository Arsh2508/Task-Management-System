#include <vector>
#include "User.hpp"
#include "Task.hpp"

#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

class TaskManager{
public:
	TaskManager() = default;

	TaskManager(const TaskManager&);
	TaskManager& operator=(TaskManager);

	TaskManager(TaskManager&&)noexcept;
	TaskManager& operator=(TaskManager&&)noexcept;

	~TaskManager();

	int register_user();
	int login();
	void logout(const int);
	 
	void add_task(const int);
	void delete_task(const int, const int);
	void edit_task(const int, const int);
	void display_task(const int);
	void display_all_tasks();
	void display_all_users();

	
private:
	std::vector<User*> m_users;
	std::vector<Task*> m_all_tasks;
	User* find_user(const int) const;
	void Swap(TaskManager&) noexcept; 
};

#endif
