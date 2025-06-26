#include <gtest/gtest.h>
#include "User.hpp"
#include "Task.hpp"


TEST(UserInput, UserInfo){
    std::string name = "Unknown";
    std::string passwd {"123"};

    User u{name, passwd};

    EXPECT_EQ(u.get_name(), name);

}

TEST(Tasks, TaskId){
    Task t1{};
    Task t2{};

    EXPECT_EQ(t2.get_task_id(), 2);
}