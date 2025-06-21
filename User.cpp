#include "User.hpp"
#include "Task.hpp"
#include <iostream>

int User::id_counter = 0;

User::User() 
	: m_id{++id_counter}
	, is_logged{false}
{}

User::User(const std::string& name, const std::string& passwd)
	: m_id{++id_counter}
	, m_name{name}
	, m_passwd{passwd}
	, is_logged{true}
{}

User::User(const User& other)
	: m_id{other.m_id}
	, m_name{other.m_name}
	, m_passwd{other.m_passwd}
	, is_logged{other.is_logged}
{
	for(size_t i = 0; i < other.m_tasks.size(); ++i){
		m_tasks.push_back(new Task(*other.m_tasks[i]));
	}
}

User& User::operator=(const User& rhs){
	if(this == &rhs){
		return *this;
	}
	for(size_t i = 0; i < m_tasks.size(); ++i){
		delete m_tasks[i];	
	}
	m_id = rhs.m_id;
	m_name = rhs.m_name;
	m_passwd = rhs.m_passwd;
	is_logged = rhs.is_logged;

	m_tasks.clear();

	for(size_t i = 0; i < m_tasks.size(); ++i){
		m_tasks.push_back(new Task(*rhs.m_tasks[i]));
	}

	return *this;
}

User::User(User&& other) noexcept
	: m_id{other.m_id}
	, m_name{std::move(other.m_name)}
	, m_passwd{std::move(other.m_passwd)}
	, m_tasks{std::move(other.m_tasks)}
	, is_logged{other.is_logged}
{
	other.m_tasks.clear();
}

User& User::operator=(User&& rhs) noexcept{
	if(this == &rhs){
		return *this;
	}

    for(size_t i = 0; i < m_tasks.size(); ++i){
        delete m_tasks[i];
    }

	m_tasks.clear();

	m_id = rhs.m_id;
	m_name = std::move(rhs.m_name);
	m_passwd = std::move(rhs.m_passwd);
	m_tasks = std::move(rhs.m_tasks);
	is_logged = rhs.is_logged;

	rhs.m_tasks.clear();

	return *this;
}


User::~User(){
	m_tasks.clear();
}

int User::get_id(){
	return m_id;
} 


void User::add_task(Task* add){
	m_tasks.push_back(add);	
}


void User::delete_task(const int task_id){
	for(auto it = m_tasks.begin(); it != m_tasks.end(); ++it){
		if((*it)->get_task_id() == task_id){
			m_tasks.erase(it);
			return;
		}
	} 
	std::cout<<"Task not found !\n";
}


void User::list_task(){
	for(size_t i = 0; i < m_tasks.size(); ++i){
		std::cout<<"\n -Task "<< i+1<<"-"<<std::endl;
		m_tasks[i]->display_info();
	}
}

Task* User::search_task(const int id){
	for(size_t i = 0; i < m_tasks.size(); ++i){
		if(m_tasks[i]->get_task_id() == id){
			return m_tasks[i];
		}
	}
	return nullptr;
}

void User::login(const std::string& passwd){
	if(passwd == m_passwd){
		is_logged = true;
		std::cout<<"You are logged in\n";
	}
	else{
		std::cout<<"Incorrect password!\n";
	}
}

void User::logout(){
	is_logged = false;
}

void User::edit_task(const int task_id){
	for(Task* t : m_tasks){
		if(t->get_task_id() == task_id){
			t->edit();
			return;
		}
	}
    std::cout << "No task found with ID " << task_id << '\n';
}

std::string User::get_name(){
	return m_name;
}