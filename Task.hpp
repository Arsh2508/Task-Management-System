#include <string>

#ifndef TASK_HPP
#define TASK_HPP
	enum class Prio{LOW, MID, HIGH, URGENT};
	enum class Status{NOT_STARTED, IN_PROGRESS, COMPLETED};


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
	std::string m_deadline;
	std::string m_category;

	Prio m_prio;
	Status m_status;

};


#endif
