#include <vector>
#include "User.hpp"
#include "Task.hpp"

#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

class TaskManager{
public:
	TaskManager();

	TaskManager(const TaskManager&);
	TaskManager& operator=(TaskManager);

	TaskManager(TaskManager&&)noexcept;
	TaskManager& operator=(TaskManager&&)noexcept;

	~TaskManager();

	void register_user();
	void login();
	void logout();
	 
	void add_task(const int);
	void delete_task(const int);
	void edit_task(const int);
	void display_task(const int);

	void Swap(TaskManager&) noexcept; 

private:
	std::vector<User*> m_users;
	std::vector<Task*> m_all_tasks;
	User* find_user(const int) const;
};

#endif
