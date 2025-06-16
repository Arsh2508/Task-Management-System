#include <iostream>
#include "User.hpp"
#include "Task.hpp"

int main()
{
	User obj;
	Task task;
	task.edit();
	obj.add_task(task);

	obj.list_task();

	return 0;
}
