#include <string>
#include <iostream>

#ifndef TASK_HPP
#define TASK_HPP
	enum class Prio{LOW, MID, HIGH, URGENT};
	enum class Status{NOT_STARTED, IN_PROGRESS, COMPLETED};
	
	struct Date{
		int year;
		int month;
		int day;

		void input(){
			do{
				std::cout<<"Enter year: ";
				std::cin>>year;
			}while(year < 2020 || year > 2050);

			do{
				std::cout<<"Enter month: ";
				std::cin>>month;
			}while(month < 1 || month > 12);

			do{
				std::cout<<"Enter day: ";
				std::cin>>day;
			}while(day < 1 || day > 31);
		}

		friend std::ostream& operator<<(std::ostream& os, const Date& dat){
			os<<dat.year<<"-"<<dat.month<<"-"<<dat.day;
			return os;
		}

	};

class Task{
public:
	Task();

	Task(const Task&);
	Task& operator=(const Task&);

	Task(Task&&) noexcept;
	Task& operator=(Task&&) noexcept;

	~Task();

	void edit();
	void set_status(Status);
	void set_prio(Prio);
	void display_info();
	const std::string& get_task_id() const;

private:
	std::string m_task_id;
	std::string m_uid;
	std::string m_title;
	std::string m_description;
	Date m_deadline;
	std::string m_category;

	Prio m_prio;
	Status m_status;

};


#endif
