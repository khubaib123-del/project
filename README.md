# School Management System (C++)

This project is a simple **School Management System** written in **C++**.  
It allows managing students and teachers data and finding the top student.

## Features

- Input and store data for students and teachers
- Calculate student marks and average
- Find the top student
- Uses dynamic memory allocation
- Implements Object-Oriented Programming concepts: Classes, Inheritance, Encapsulation

## Classes

1. **Person** (Base class)
   - Common attributes: `name`, `age`
   - Functions: `setData()`, `display()`

2. **Student** (Derived class)
   - Attributes: `rollNo`, `marks[5]`
   - Functions: `setStudentData()`, `displayStudent()`, `getAverage()`

3. **Teacher** (Derived class)
   - Attributes: `subject`, `salary`
   - Functions: `setTeacherData()`, `displayTeacher()`


g++ main.cpp -o SchoolManagement

