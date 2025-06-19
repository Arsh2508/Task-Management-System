#include <vector>
#include "User.hpp"
#include "Task.hpp"

#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

class TaskManager{
public:
	TaskManager();

	TaskManager(const TaskManager&);
	TaskManager& operator=(const TaskManager&);

	TaskManager(TaskManager&&)noexcept;
	TaskManager& operator=(TaskManager&&)noexcept;

	~TaskManager();

	void register_user();
	void login();
	void logout();
	 
	void add_task();
	void delete_task();
	void edit_task();
	void display_task();

private:
	std::vector<User*> m_users;
	std::vector<Task*> m_all_tasks;
};

#endif
