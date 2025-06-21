#include <iostream>
#include "TaskManager.hpp"
#include "Task.hpp"
#include "User.hpp"

TaskManager::TaskManager() = default;

TaskManager::TaskManager(const TaskManager& other)
{
	for(User* t : other.m_users){
		m_users.push_back(new User(*t)); 
	}

	for(Task* t : other.m_all_tasks){
		m_all_tasks.push_back(new Task(*t)); 
	}
}

void TaskManager::Swap(TaskManager& rhs) noexcept{
	std::swap(m_users, rhs.m_users);
	std::swap(m_all_tasks, rhs.m_all_tasks);
}

TaskManager& TaskManager::operator=(TaskManager rhs){	//using copy and swap idiom 
	Swap(rhs);
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

void TaskManager::register_user(){
	std::string name, password;
	std::cout<<"Enter name: ";
	std::cin>>name;
	std::cout<<"Enter passowrd: ";
	std::cin>>password;

	m_users.emplace_back(new User(name, password));

}

User* TaskManager::find_user(const int uid) const{
	for(User* u : m_users){
		if(u->get_id() == uid){
			return u;
		}
	}
	return nullptr;
}

void TaskManager::login(){
	int uid;
	std::string password;

	std::cout<<"Enter User ID: ";
	std::cin>>uid;
	
	User* u = find_user(uid);
	if(u){
		u->login(password);
	}else{
		std::cout << "No user found with ID " << uid << '\n';
	}
}

void TaskManager::logout(){
	int uid;
	std::cout<<"Enter User ID to logout: ";
	std::cin>>uid;
	User* u = find_user(uid);
	if(u){
		u->logout();
	}
	else{
		std::cout << "No user found with ID " << uid << '\n';
	}
}

void TaskManager::add_task(const int uid){
	for(User* u : m_users){
		if(u->get_id() == uid){
			std::string title, description, category;	
			Date deadline;

			std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            deadline.input();
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
			
			
			u->add_task(Task(uid, title, description, deadline, category));
			m_all_tasks.emplace_back(new Task(uid, title, description, deadline, category));
		}
	}
}


