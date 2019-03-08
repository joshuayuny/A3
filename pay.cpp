#include <iostream>
#include <fstream>
#include <cstdlib>
#include "person.cpp"
#include "person.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void print(vector<Person> &employees);
void readData(vector<Person> &employees);
void printHighestPaid(vector<Person> &employees);
void separateAndSave(vector<Person> &employees, vector<string> &companyNames);
void getCompanies(vector<Person> &employees, vector<string> &companyNames);

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
  ofstream output;
  // string name;
  for (int i = 0; i < companyNames.size(); i++)
  {
    float total = 0;
    //name = companyNames.at(i) + ".txt";
    output.open(companyNames.at(i) + ".txt");
    for (int z = 0; z < employees.size(); z++)
    {
      if (companyNames.at(i) == employees.at(z).getCompanyName())
      {
        output << setw(16) << left << employees.at(z).getFirstName();
        output << setw(16) << left << employees.at(z).getLastName();
        output << setw(16) << left << employees.at(z).getEmployeeId();
        output << setw(16) << left << employees.at(z).getCompanyName();
        output << "$" << setw(16) << left << fixed << setprecision(2) << employees.at(z).totalPay() << endl;
        total = total + employees.at(z).totalPay();
      }
    }
    output << "Total: $" << fixed << setprecision(2) << total;
    output.close();
  }
}

void printHighestPaid(vector<Person> &employees)
{
  int number;
  float number1;
  int i = 0;
  while(i < employees.size())
  {
    if (number1 < employees.at(i).totalPay())
    {
      number1 = employees.at(i).totalPay();
      number = i;
    }
    i++;
  }
  cout << "Highest Paid: " << employees.at(number).fullName() << endl;
  cout << "Employee ID: " << employees.at(number).getEmployeeId() << endl;
  cout << "Employer: " << employees.at(number).getCompanyName() << endl;
  cout << "Total Pay: $" << fixed << setprecision(2) << employees.at(number).totalPay() << endl;
}
void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
  for (int i = 0; i < employees.size(); i++)
  {
    int z=0;
    if (companyNames.empty())
    {
      companyNames.push_back(employees.at(i).getCompanyName());
    }
    for (int x = 0; x < companyNames.size(); x++)
    {
      if (employees.at(i).getCompanyName() == companyNames.at(x))
      {
        z++;
      }
    }
    if(z == 0)
    {
      companyNames.push_back(employees.at(i).getCompanyName());
    }
  }
}


void readData(vector<Person> &employees)
{
  string firstName;
  string lastName;
  int    employeeID;
  string companyName;
  float  hoursWorked;
  float  payRate;
  ifstream input;
  input.open("input.txt");

  while(input>>firstName>>lastName>>employeeID>>companyName>>hoursWorked>>payRate)
  {
    Person p;
    p.setFirstName(firstName);
    p.setLastName(lastName);
    p.setEmployeeId(employeeID);
    p.setCompanyName(companyName);
    p.setHoursWorked(hoursWorked);
    p.setPayRate(payRate);
    employees.push_back(p);
  }
  for (int i = 0; i < employees.size(); i++)
  {
    cout << employees.at(i).fullName()<<endl;
  }
  input.close();
}

int main()
{
  vector<Person> employees;
  vector<string> companyNames;
  readData(employees);
  getCompanies(employees, companyNames);
  printHighestPaid(employees);
  separateAndSave(employees, companyNames);
  return 0;
}
