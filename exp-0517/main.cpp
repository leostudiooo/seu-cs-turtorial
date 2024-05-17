#include "Student.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define READ

using namespace std;

int main()
{

#ifdef WRITE
	// Test: 1 Student, 2 HighSchoolStudent(s), 3 CollegeStudent(s)
	vector<Student *> students;
	students.push_back(new Student("Alice", 15, 1000.));
	students.push_back(new HighSchoolStudent("Bob", 17, 2000., 5, 100.));
	students.push_back(new HighSchoolStudent("Charlie", 16, 3000., 6, 200.));
	students.push_back(new CollegeStudent("David", 21, 6000, 21.5, 200.));
	students.push_back(new CollegeStudent("Eve", 22, 7000, 22.5, 300.));
	students.push_back(new CollegeStudent("Frank", 20, 6500, 20., 250.));

	// Write to file
	ofstream ofs;
	ofs.open("students.txt", ios::out);
	for (auto student : students)
	{
		student->writeFile(ofs);
	}
	ofs.close();

	// Cleanup
	for (auto student : students)
	{
		delete student;
	}
#endif

#ifdef READ
	// Read from file
	StudentArray studentArray("students.txt");
	studentArray.sort();
	studentArray.print();
#endif

	return 0;
}

/*
Output:
CollegeStudent	Eve	22	7000	22.5	300	13750
CollegeStudent	Frank	20	6500	20	250	11500
CollegeStudent	David	21	6000	21.5	200	10300
HighSchoolStudent	Charlie	16	3000	6	200	4200
HighSchoolStudent	Bob	17	2000	5	100	2500
Student	Alice	15	1000
*/