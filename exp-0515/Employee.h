#pragma once

#include <iostream>
#include <string>

using namespace std;

// Salary Level
enum SalaryLevel
{
	L0,
	L1,
	L2,
	L3,
	L4,
	L5
};

double const _basicSalary[6] = {5000., 10000., 15000., 20000., 25000., 30000.};

const double _leaveDeduction = 100.; // Per day

class Employee
{
protected:
	// Use string to store ID to prevent overflow of int like 2147483647
	string name, ID;
	SalaryLevel salaryLevel;
	double monthlySalary;

public:
	Employee(string name, string ID, SalaryLevel salaryLevel) : name(name), ID(ID), salaryLevel(salaryLevel) {}

	virtual double pay(int leaveDays) { return 0; }
};

class Technician : virtual public Employee
{
protected:
	const double addHrAllnRate = 10.;
	double additionalHr, workingHr, researchProg;

public:
	Technician(string name, string ID, SalaryLevel salaryLevel, double additionalHr, double workingHr, double researchProg) : Employee(name, ID, salaryLevel), additionalHr(additionalHr), workingHr(workingHr), researchProg(researchProg) {}

	double pay(int leaveDays) override
	{
		double basicSalary = _basicSalary[salaryLevel];
		double performanceSalary = additionalHr * workingHr * researchProg;
		monthlySalary = basicSalary + performanceSalary - leaveDays * _leaveDeduction;
		return monthlySalary;
	}
};

class Salesman : virtual public Employee
{
protected:
	double monthlySales, bonusRate;

public:
	Salesman(string name, string ID, SalaryLevel salaryLevel, double monthlySales, double bonusRate) : Employee(name, ID, salaryLevel), monthlySales(monthlySales), bonusRate(bonusRate) {}

	double pay(int leaveDays) override
	{
		double basicSalary = _basicSalary[salaryLevel];
		double performanceSalary = monthlySales * bonusRate;
		monthlySalary = basicSalary + performanceSalary - leaveDays * _leaveDeduction;
		return monthlySalary;
	}
};

class Manager : virtual public Employee
{
protected:
	double fixedBonus, managerPerf;

public:
	Manager(string name, string ID, SalaryLevel salaryLevel, double fixedBonus, double managerPerf) : Employee(name, ID, salaryLevel), fixedBonus(fixedBonus), managerPerf(managerPerf) {}

	double pay(int leaveDays) override
	{
		double basicSalary = _basicSalary[salaryLevel];
		double performanceSalary = fixedBonus * managerPerf;
		monthlySalary = basicSalary + performanceSalary - leaveDays * _leaveDeduction;
		return monthlySalary;
	}
};

class DevManager : public Technician, public Manager
{
public:
	DevManager(string name, string ID, SalaryLevel salaryLevel, double additionalHr, double workingHr, double researchProg, double fixedBonus, double managerPerf) : Employee(name, ID, salaryLevel), Technician(name, ID, salaryLevel, additionalHr, workingHr, researchProg), Manager(name, ID, salaryLevel, fixedBonus, managerPerf) {}

	double pay(int leaveDays) override
	{
		// Use Technician::pay() and Manager::pay() to calculate the performance salary
		double basicSalary = _basicSalary[salaryLevel];
		double performanceSalary = (Technician::pay(leaveDays) + Manager::pay(leaveDays) - 2 * basicSalary) / 2.;
		monthlySalary = basicSalary + performanceSalary - leaveDays * _leaveDeduction;
		return monthlySalary;
	}
};

class SalesManager : public Salesman, public Manager
{
public:
	SalesManager(string name, string ID, SalaryLevel salaryLevel, double monthlySales, double bonusRate, double fixedBonus, double managerPerf) : Employee(name, ID, salaryLevel), Salesman(name, ID, salaryLevel, monthlySales, bonusRate), Manager(name, ID, salaryLevel, fixedBonus, managerPerf) {}

	double pay(int leaveDays) override
	{
		double basicSalary = _basicSalary[salaryLevel];
		double performanceSalary = (Salesman::pay(leaveDays) + Manager::pay(leaveDays) - 2 * basicSalary) / 2.;
		monthlySalary = basicSalary + performanceSalary - leaveDays * _leaveDeduction;
		return monthlySalary;
	}
};