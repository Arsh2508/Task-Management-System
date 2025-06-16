#include "User.hpp"
#include "Task.hpp"
#include <iostream>

User::User() : is_logged{false}
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

	m_id = rhs.m_id;
	m_name = rhs.m_name;
	m_passwd = rhs.m_passwd;
	is_logged = rhs.is_logged;

	for(size_t i = 0; i < m_tasks.size(); ++i){
		delete m_tasks[i];	
	}

	m_tasks.clear();

	for(size_t i = 0; i < m_tasks.size(); ++i){
		m_tasks.push_back(new Task(*rhs.m_tasks[i]));
	}

	return *this;
}

User::User(User&& other) noexcept
	: m_id{std::move(other.m_id)}
	, m_name{std::move(other.m_name)}
	, m_passwd{std::move(other.m_passwd)}
	, m_tasks{std::move(other.m_tasks)}
	, is_logged{other.is_logged}
{
}

User& User::operator=(User&& rhs) noexcept{
	if(this == &rhs){
		return *this;
	}

    for(size_t i = 0; i < m_tasks.size(); ++i){
        delete m_tasks[i];
    }

	m_tasks.clear();

	m_id = std::move(rhs.m_id);
	m_name = std::move(rhs.m_name);
	m_passwd = std::move(rhs.m_passwd);
	m_tasks = std::move(rhs.m_tasks);
	is_logged = rhs.is_logged;

	return *this;
}


User::~User(){
	for(size_t i = 0; i < m_tasks.size(); ++i){
		delete m_tasks[i];
	}
}


void User::add_task(const Task& add){
	m_tasks.push_back(new Task(add))	
}












