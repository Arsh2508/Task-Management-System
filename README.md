📝 Task Management System
This project is a console-based Task Management System built in C++ using Object-Oriented Programming (OOP) principles. It allows users to register, log in, and manage personal tasks with priorities, deadlines, categories, and status tracking.

The system is modular, extensible, and includes unit tests with Google Test.

📦 Features
🧑‍💼 User Management
• Register, log in, and log out securely with credentials.
• Unique ID assigned to each user.

🗂️ Task Handling
• Add, edit, delete, and view tasks.
• Each task includes:
  🔹 Title
  🔹 Description
  🔹 Category
  🔹 Deadline
  🔹 Priority (LOW, MID, HIGH, URGENT)
  🔹 Status (NOT_STARTED, IN_PROGRESS, COMPLETED)

📋 Task Overview
• View all tasks (admin style) or only personal tasks.
• Display tasks grouped by user.

✅ Unit Testing
• Modular code tested with Google Test framework.

🗃️ Project Structure
```
.
├── include/           # Header files (.hpp)
├── src/               # Source files (.cpp)
├── googletests/       # Google Test files
├── build/             # Build directory (Makefile, bin/, obj/)
│   ├── bin/           # Output executables
│   └── obj/           # Compiled object files
└── README.md
```

🔧 Build & Run Instructions
From the root folder, enter the build/ directory:

🔨 Build the Application
cd build
make
▶️ Run the Application
./bin/TaskManagement

🧪 Running Tests
📥 Google Test Setup
To run unit tests, install Google Test.

Official GitHub:
👉 https://github.com/google/googletest

🔧 Ubuntu/Debian Users
sudo apt install libgtest-dev cmake
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib

🧪 Run the Tests
make test
./bin/TaskManagementTest
