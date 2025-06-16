#include "Task.hpp"
#include <iostream>

Task::Task()
	: m_prio{Prio::LOW}
	, m_status{Status::NOT_STARTED}
{}

Task::Task(const Task& other) 
	: m_task_id{other.m_task_id}
	, m_uid{other.m_uid}
	, m_title{other.m_title}
	, m_description{other.m_description}
	, m_deadline{other.m_deadline}
	, m_category{other.m_category}
	, m_prio{other.m_prio}
	, m_status{other.m_status}
{
	
}

Task& Task::operator=(const Task& rhs){
	if(this == &rhs){
		return *this;
	}
	m_task_id = rhs.m_task_id;
	m_uid = rhs.m_uid;
	m_title = rhs.m_title;
	m_description = rhs.m_description;
	m_deadline = rhs.m_deadline;
	m_category = rhs.m_category;
	m_prio = rhs.m_prio;
	m_status = rhs.m_status;

	return *this;

}

Task::Task(Task&& other) noexcept 
	: m_task_id {std::move(other.m_task_id)}
    , m_uid {std::move(other.m_uid)}
    , m_title {std::move(other.m_title)}
    , m_description {std::move(other.m_description)}
    , m_deadline {std::move(other.m_deadline)}
    , m_category {std::move(other.m_category)}
    , m_prio {other.m_prio}
    , m_status {other.m_status}

{}

Task& Task::operator=(Task&& rhs) noexcept{
	if(this == &rhs){
		return *this;
	}
	m_task_id = std::move(rhs.m_task_id);
	m_uid = std::move(rhs.m_uid);
	m_title = std::move(rhs.m_title);
	m_description = std::move(rhs.m_description);
	m_deadline = std::move(rhs.m_deadline);
	m_category = std::move(rhs.m_category);
	m_prio = rhs.m_prio;
	m_status = rhs.m_status;

	return *this;
}

Task::~Task() = default;

void Task::set_status(Status st){
	m_status = st;
}

void Task::set_prio(Prio p){
	m_prio = p;
}

void Task::display_info(){
	std::cout<<"Task Id - "<<m_task_id;
	std::cout<<"\nUID - "<<m_uid;
	std::cout<<"\nTitle - "<<m_title;
	std::cout<<"\nDescription - "<<m_description;
	std::cout<<"\nDeadline - "<<m_deadline;
	std::cout<<"\nCategory - "<<m_category<<std::endl;
}

const std::string& Task::get_task_id() const{
	return m_task_id;
} 


void Task::edit(){
	std::cout<<"Enter Task ID: ";
	std::getline(std::cin, m_task_id);

	std::cout<<"Enter UID: ";
	std::getline(std::cin, m_uid);

	std::cout<<"Enter Title: ";
	std::getline(std::cin, m_title);

	std::cout<<"Enter Description: ";
	std::getline(std::cin, m_description);

	std::cout<<"Enter Deadline: ";
	m_deadline.input();
	
	std::cin.ignore();

	std::cout<<"Enter Category: ";
	std::getline(std::cin, m_category);

	int choice = 0;
	std::cout<<"Enter Priority (1-LOW, 2-MID, 3-HIGH, 4-URGENT): ";
	std::cin>>choice;

	switch(choice){
		case 1: set_prio(Prio::LOW);
				break;
		case 2:	set_prio(Prio::MID);
				break;
		case 3: set_prio(Prio::HIGH);
				break;
		case 4: set_prio(Prio::URGENT);
				break;
		default:
			std::cout<<"Invalid input, defaulting priority to LOW\n";
			set_prio(Prio::LOW);
			break;
	}

	std::cout<<"Enter Status: (1-NOT_STARTED, 2-IN_PROGRESS, 3-COMPLETED): ";
	std::cin>>choice;

    switch(choice){
        case 1: set_status(Status::NOT_STARTED);
                break;
        case 2: set_status(Status::IN_PROGRESS);
                break;
        case 3: set_status(Status::COMPLETED);
                break;
        default:
            std::cout<<"Invalid input, defaulting to NOT_STARTED\n";
            set_status(Status::NOT_STARTED);
            break;
   } 
}












