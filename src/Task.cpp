#include "Task.hpp"
#include "Date.hpp"
#include <iostream>
#include <limits>

int Task::id_counter = 0;

Task::Task()
	: m_task_id{++id_counter}
	, m_uid{0}
	, m_prio{Prio::LOW}
	, m_status{Status::NOT_STARTED}
{}

Task::Task(int uid, const std::string& title, const std::string& description, Date& deadline, const std::string& category)
	: m_task_id{++id_counter}
	, m_uid{uid}
	, m_title{title}
	, m_description{description}
	, m_deadline{deadline}
	, m_category{category}
{
}

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
	: m_task_id {other.m_task_id}
    , m_uid {other.m_uid}
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
	m_task_id = rhs.m_task_id;
	m_uid = rhs.m_uid;
	m_title = std::move(rhs.m_title);
	m_description = std::move(rhs.m_description);
	m_deadline = std::move(rhs.m_deadline);
	m_category = std::move(rhs.m_category);
	m_prio = rhs.m_prio;
	m_status = rhs.m_status;

	return *this;
}

Task::~Task() = default;

void Task::set_status(){
	std::cout<< "Swith status:\n1) NOT_STARTED\n2) IN_PROGRESS\n3) COMPLETED\n";
	int status = 0;
	while(!(std::cin>>status)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		std::cout<<"Invalid input! Enter integer [1-3]\n";
	}

	switch(status){
		case 1:
			m_status = Status::NOT_STARTED;
			break;
		case 2:
			m_status = Status::IN_PROGRESS;
			break;
	 	case 3:
			m_status = Status::COMPLETED;
			break;
		default:
			std::cout<<"Defaulting Status to NOT_STAETED\n";
			m_status = Status::NOT_STARTED;
			break;
	}
}

void Task::set_prio(){
	std::cout<< "Swith priority:\n1) LOW\n2) MID\n3) HIGH\n4) URGENT\n";
	int priority;
	while(!(std::cin>>priority)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		std::cout<<"Invalid input! Enter integer [1-4]\n";
	}

	switch(priority){
		case 1:
			m_prio = Prio::LOW;
			break;
		case 2:
			m_prio = Prio::MID;
			break;
		case 3:
			m_prio = Prio::HIGH;
			break;
		case 4:
			m_prio = Prio::URGENT;
			break;
		default:
			std::cout<<"Defalting priority to LOW: \n";
			m_prio = Prio::LOW;
			break;
	}
}

void Task::display_info(){
	std::cout<<"Task Id - "<<m_task_id;
	std::cout<<"\nUID - "<<m_uid;
	std::cout<<"\nTitle - "<<m_title;
	std::cout<<"\nDescription - "<<m_description;
	std::cout<<"\nDeadline - "<<m_deadline;
	std::cout<<"\nCategory - "<<m_category<<std::endl;
}

const int Task::get_task_id() const{
	return m_task_id;
} 


void Task::edit() {
	int choice;
	
	do{
		std::cout<<"What do you want to edit:"
			 	<<"\n1) Title\n2) Description\n3) Category\n"
			 	<<"4) Deadline\n5) Status\n6) Priority\n7) Exit\n";
		if(!(std::cin>>choice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Invalid input! Please enter a number.\n";
			continue;
		}
		std::cin.ignore();

		switch(choice){
			case(1):
				std::cout << "New title: "; 
				std::getline(std::cin, m_title);
				break;
			case(2):
			    std::cout << "New description: ";
				std::getline(std::cin, m_description);
				break;
			case(3):
				std::cout << "New category: "; 
				std::getline(std::cin, m_category);
				break;
			case(4):
				std::cout << "New deadline:\n";
				m_deadline.input();
				break;
			case(5):
				set_status();
				break;
			case(6):
				set_prio();
				break;
			case(7):
				std::cout<<"Exiting edit menu!\n";
				break;
			default:
				std::cout<< "Invalid input:\n";
				break;
		}   
	}while(choice != 7); 
}