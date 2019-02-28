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
using namespace std;

void print(vector<Person> &employees);
void readData(vector<Person> &employees);
void writeData();
void printHighestPaid();
void separateAndSave();
void getCompanies(vector<Person> &employees,
  vector<string> &companyNames)

void separateAndSave()
{

}

void printHighestPaid()
{

}
void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
  for (int i = 0; i < employees.size(); i++)
  {
    companyNames.at(i) = employees.at(i).getCompanyName();
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
  printHighestPaid();
  separateAndSave();
  return 0;
}
