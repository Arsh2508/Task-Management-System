#include <iostream>
#include <limits>   
#include "TaskManager.hpp"  

int main() {
    TaskManager manager;

    int choice;
    int current_uid = -1;  

    do {
        std::cout << "\n=== Main Menu ===\n"
                  << "1) Register\n"
                  << "2) Login\n"
                  << "3) Logout\n"
                  << "4) Add Task\n"
                  << "5) Display My Tasks\n"
                  << "6) Edit a Task\n"
                  << "7) Delete a Task\n"
				  << "8) Display all tasks\n"
				  << "9) Display all users\n"
                  << "0) Exit\n"
                  << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                current_uid = manager.register_user();
                std::cout << "User registered with ID " << current_uid << ".\n";
                break;
            }
            case 2: {
                current_uid = manager.login();
                break;
            }
            case 3: {
                if (current_uid != -1) {
                    manager.logout(current_uid);
                    current_uid = -1;
                } else {
                    std::cout << "No user logged in!\n";
                }
                break;
            }
            case 4: {
                if (current_uid != -1) {
                    manager.add_task(current_uid); 
                } else {
                    std::cout << "Please log in first!\n";
                }
                break;
            }
            case 5: {
                if (current_uid != -1) {
                    manager.display_task(current_uid); 
                } else {
                    std::cout << "Please log in first!\n";
                }
                break;
            }
            case 6: {
                if (current_uid != -1) {
                    manager.display_task(current_uid);
                    int task_id;
                    std::cout << "Enter the ID of the task to edit: ";
                    std::cin >> task_id;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    manager.edit_task(current_uid, task_id);
                } else {
                    std::cout << "Please log in first!\n";
                }
                break;
            }
            case 7: {
                if (current_uid != -1) {
                    manager.display_task(current_uid); 
                    int task_id;
                    std::cout << "Enter the ID of the task to delete: ";
                    std::cin >> task_id;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    manager.delete_task(current_uid, task_id);
                } else {
                    std::cout << "Please log in first!\n";
                }
                break;
            }
			case 8:
				manager.display_all_tasks();
				break;
			case 9:
				manager.display_all_users();
				break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
