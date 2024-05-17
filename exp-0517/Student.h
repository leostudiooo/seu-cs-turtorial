#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
protected:
	string name;
	unsigned int age;
	double basicCost;
	string studentType = "Student";

public:
	Student(string name = "", unsigned int age = 0, double basicCost = 0.) : name(name), age(age), basicCost(basicCost) {}
	virtual int calcCost() { return basicCost; }
	virtual void print()
	{
		cout << studentType << "\t" << name << "\t" << age << "\t" << calcCost() << endl;
	}
	virtual void writeFile(ofstream &ofs)
	{
		ofs << studentType << "\t" << name << "\t" << age << "\t" << calcCost() << endl;
		print();
	}
};

class HighSchoolStudent : public Student
{
protected:
	unsigned int booksNumber;
	double costPerBook;

public:
	HighSchoolStudent(string name, unsigned int age, double basicCost, unsigned int booksNumber = 0, double costPerBook = 0.) : Student(name, age, basicCost), booksNumber(booksNumber), costPerBook(costPerBook)
	{
		studentType = "HighSchoolStudent";
	}

	int calcCost() override
	{
		return basicCost + booksNumber * costPerBook;
	}

	void print() override
	{
		cout << studentType << "\t" << name << "\t" << age << "\t" << basicCost << "\t" << booksNumber << "\t" << costPerBook << "\t" << calcCost() << endl;
	}

	void writeFile(ofstream &ofs) override
	{
		ofs << studentType << "\t" << name << "\t" << age << "\t" << basicCost << "\t" << booksNumber << "\t" << costPerBook << "\t" << calcCost() << endl;
		print();
	}
};

class CollegeStudent : public Student
{
protected:
	double credits;
	double costPerCredit = 0;

public:
	CollegeStudent(string name, unsigned int age, double basicCost, double credits = 0., double costPerCredit = 0.) : Student(name, age, basicCost), credits(credits), costPerCredit(costPerCredit)
	{
		studentType = "CollegeStudent";
	}

	int calcCost() override
	{
		return basicCost + credits * costPerCredit;
	}

	void print() override
	{
		cout << studentType << "\t" << name << "\t" << age << "\t" << basicCost << "\t" << credits << "\t" << costPerCredit << "\t" << calcCost() << endl;
	}

	void writeFile(ofstream &ofs) override
	{
		ofs << studentType << "\t" << name << "\t" << age << "\t" << basicCost << "\t" << credits << "\t" << costPerCredit << "\t" << calcCost() << endl;
		print();
	}
};

class StudentArray
{
	vector<Student *> list;

public:
	StudentArray(const string);
	~StudentArray();

	// Sort the students by their cost
	void sort();

	void append(Student *student);

	void save(const string fileName) const;

	void print() const;
};

StudentArray::StudentArray(const string fileName)
{
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// Temporary variables
	string studentType;
	string name;
	unsigned int age;
	double basicCost;
	unsigned int booksNumber;
	double costPerBook;
	double credits;
	double costPerCredit;

	while (ifs >> studentType)
	{
		if (studentType == "Student")
		{
			ifs >> name >> age >> basicCost;
			list.push_back(new Student(name, age, basicCost));
		}
		else if (studentType == "HighSchoolStudent")
		{
			ifs >> name >> age >> basicCost >> booksNumber >> costPerBook;
			list.push_back(new HighSchoolStudent(name, age, basicCost, booksNumber, costPerBook));
		}
		else if (studentType == "CollegeStudent")
		{
			ifs >> name >> age >> basicCost >> credits >> costPerCredit;
			list.push_back(new CollegeStudent(name, age, basicCost, credits, costPerCredit));
		}
	}
}

StudentArray::~StudentArray()
{
	for (auto student : list)
	{
		delete student;
	}
}

void StudentArray::sort()
{
	int last = list.size() - 1;
	// Map students to their costs
	vector<pair<double, Student*>> cost_stu;
	for (auto student : list)
	{
		cost_stu.push_back(make_pair(student->calcCost(), student));
	}

	// Sort the students by their costs
	std::sort(cost_stu.begin(), cost_stu.end());

	// Overwrite the list with the sorted students, backwards to create descending order
	for (int i = 0; i <= last; i++)
	{
		list[i] = cost_stu[last - i].second;
	}
}

void StudentArray::append(Student *student)
{
	list.push_back(student);
}

void StudentArray::save(const string fileName) const
{
	ofstream ofs;
	ofs.open(fileName, ios::out);
	for (auto student : list)
	{
		student->writeFile(ofs);
	}
	ofs.close();
}

void StudentArray::print() const
{
	for (auto student : list)
	{
		student->print();
	}
}

