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

int TaskManager::register_user(){
	std::string name, password;
	std::cout<<"Enter name: ";
	std::cin>>name;
	std::cout<<"Enter passowrd: ";
	std::cin>>password;

	User* new_user = new User(name, password);
	m_users.push_back(new_user);

	return new_user->get_id();
}

User* TaskManager::find_user(const int uid) const{
	for(User* u : m_users){
		if(u->get_id() == uid){
			return u;
		}
	}
	return nullptr;
}

int TaskManager::login(){
	int uid;
	std::string password;

	std::cout<<"Enter User ID: ";
	std::cin>>uid;
	std::cout<<"Enter password: ";
	std::cin>>password;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	User* u = find_user(uid);
	if(u){
		u->login(password);
		return u->get_id();
	}else{
		std::cout << "No user found with ID " << uid << '\n';
		return -1;
	}
	
}

void TaskManager::logout(int uid){
	User* u = find_user(uid);
	if(u){
		u->logout();
	}
	else{
		std::cout << "No user found with ID " << uid << '\n';
	}
}

void TaskManager::add_task(const int uid){
	
	User* u = find_user(uid);
	if(!u){
		std::cout<<"No user found with ID"<<uid<<"!\n";
		return;
	}
	
	std::string title, description, category;	
	Date deadline;
		
	std::cout << "Enter title: ";
	std::getline(std::cin, title);
    std::cout << "Enter description: ";
    std::getline(std::cin, description);
    deadline.input();
    std::cout << "Enter category: ";
    std::getline(std::cin, category);
						
	Task* new_task = new Task(uid, title, description, deadline, category);
	new_task->set_prio();
	new_task->set_status();

	u->add_task(new_task);
	m_all_tasks.push_back(new_task);
}

void TaskManager::delete_task(const int uid, const int task_id){
	User* u = find_user(uid);
	if(!u){
		std::cout<<"User not found with ID"<<uid<<"!\n";
		return;
	}
	u->delete_task(task_id);

	for(auto it = m_all_tasks.begin(); it != m_all_tasks.end(); ++it){
		if((*it)->get_task_id() == task_id){
			delete *it;
			m_all_tasks.erase(it);
            std::cout << "Task with ID " << task_id << " deleted successfully.\n";
			return;
		}
	}
}

void TaskManager::edit_task(const int uid, const int task_id){
	User* u = find_user(uid);
	if(!u) {
		std::cout<<"User not found with ID"<<uid<<"!\n";
		return;
	}
	u->edit_task(task_id);
}

void TaskManager::display_task(const int uid){
	User* u = find_user(uid);
	if(!u){
		std::cout<<"User not found with ID"<<uid<<"!\n";
		return;
	}
	u->list_task();
}

void TaskManager::display_all_tasks(){
	if(m_all_tasks.empty()){
		std::cout<<"There is no tasks yet!\n";
		return;
	}
	for(Task* t : m_all_tasks){
		std::cout<<"---------------------------------\n";
		t->display_info();
	}
}

void TaskManager::display_all_users(){
	if(m_users.empty()){
		std::cout<<"No users registred yet!\n";
	}

	for(User* u : m_users){
		std::cout<< "----------------------------\n";
		std::cout<<"  User ID - "<<u->get_id()<<"\n  Username - "<<u->get_name()<<"\n";
	}
}