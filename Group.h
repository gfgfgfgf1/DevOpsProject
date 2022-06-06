// Copyright 2021 Bulatov D.
#ifndef GROUP_H_1
#define GROUP_H_

#include <string>
#include <vector>
#include "Student.h"

class Student;
class Group {
 private:
  std::string title;
  std::string spec;
  Student* head;

 public:
  std::vector<Student> students;
  Group(std::string title, std::string spec);
  std::string getTitle();
  std::string getSpec();
  void addStudent(const Student& student);
  Student& getStudent(int id);
  Student& getStudent(std::string fio);
  void chooseHead();
  Student* getHead();
  double getAverageMark();
  void removeStudent(int id);
  std::vector<Student> getStudents();
};
#endif  // GROUP_H_
