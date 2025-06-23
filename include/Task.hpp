#include <string>
#include <iostream>
#include "Date.hpp"

#ifndef TASK_HPP
#define TASK_HPP
	enum class Prio{LOW, MID, HIGH, URGENT};
	enum class Status{NOT_STARTED, IN_PROGRESS, COMPLETED};

class Task{
public:
	Task();
	Task(int, const std::string&, const std::string&, Date&, const std::string&);

	Task(const Task&);
	Task& operator=(const Task&);

	Task(Task&&) noexcept;
	Task& operator=(Task&&) noexcept;

	~Task();

	void edit();
	void set_status();
	void set_prio();
	void display_info();
	const int get_task_id() const;

private:
	static int id_counter;
	static int uid_counter;

	int m_task_id;
	int m_uid;
	std::string m_title;
	std::string m_description;
	Date m_deadline;
	std::string m_category;

	Prio m_prio;
	Status m_status;

};


#endif