#include "TaskManager.hpp"
#include "Task.hpp"
#include "User.hpp"

TaskManager::TaskManager(){}

TaskManager::TaskManager(const TaskManager& other)
{
	for(User* t : other.m_users){
		m_users.push_back(new User(*t)); 
	}

	for(Task* t : other.m_all_tasks){
		m_all_tasks.push_back(new Task(*t)); 
	}
}

TaskManager& TaskManager::operator=(const TaskManager& rhs){
	if(this == &rhs){
		return *this;
	}
	
	for(User* t : m_users){
		delete t;
	}
	for(Task* t : m_all_tasks){
		delete t;
	}

	for(User* t : rhs.m_users){
		m_users.push_back(new User(*t));
	}
	for(Task* t : rhs.m_all_tasks){
		m_all_tasks.push_back(new Task(*t));
	}
	return *this;
}

TaskManager::TaskManager(TaskManager&& other) noexcept
	: m_users{std::move(other.m_users)}
	, m_all_tasks{std::move(other.m_all_tasks)}
{
	other.m_all_tasks.clear();
	other.m_users.clear();
}

TaskManager& TaskManager::operator=(TaskManager&& rhs) noexcept{
	if(this == &rhs){
		return *this;
	}

	m_users = std::move(rhs.m_users);
	m_all_tasks = std::move(rhs.m_all_tasks);

	rhs.m_all_tasks.clear();
	rhs.m_users.clear();

	return *this;
}

TaskManager::~TaskManager(){
	for(User* t : m_users){
		delete t;
	}

	for(Task* t : m_all_tasks){
		delete t;
	}
}


