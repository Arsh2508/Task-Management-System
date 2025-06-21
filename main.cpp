#include <iostream>
#include "User.hpp"
#include "Task.hpp"

int main()
{
	User obj;
	Task *task = new Task;
	task->edit();
	
	obj.add_task(std::move(*task));
	task->set_status();
	obj.list_task();
	


	return 0;
}
