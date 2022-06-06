// Copyright 2021
#include <gtest/gtest.h>

#include <string>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

TEST(StudentTest, Test1) {
  Student st("Ivan Ivanov", 20);
  EXPECT_EQ("Ivan Ivanov", st.getFio());
}

TEST(StudentTest, Test2) {
  Student st("Ivanov Ivan", 1);
  Group gr("first group", "spec 1");
  st.addToGroup(&gr);
  EXPECT_EQ("first group", st.getGroupTitle());
}

TEST(StudentTest, Test3) {
  Student st("Ivan Ivanov", 1);
  std::vector<int> marks = {3, 2, 4, 2, 4};
  st.setMarks(marks);
  EXPECT_EQ(3, st.getAverageMark());
}

TEST(GroupTest, Test4) {
  Group gr("1", "2");
  Student st1("g", 1);
  Student st2("f", 2);
  std::vector<int> marks1 = {5, 4, 4, 6, 6};
  std::vector<int> marks2 = {5, 4, 5, 6};
  st1.setMarks(marks1);
  st2.setMarks(marks2);
  gr.addStudent(st1);
  gr.addStudent(st2);
  EXPECT_EQ(5, gr.getAverageMark());
}

TEST(GroupTest, Test5) {
  Group gr("1", "2");
  Student st1("g", 1);
  gr.addStudent(st1);
  gr.chooseHead();
  auto str = gr.getHead()->getFio();
  EXPECT_EQ("g", str);
}

TEST(GroupTest, Test6) {
  Group gr("1", "2");
  Student st1("g", 1);
  gr.addStudent(st1);
  gr.removeStudent(st1.getId());
  EXPECT_EQ(0, gr.getStudents().size());
}

TEST(DeanaryTest, Test7) {
  Deanary dr;
  Group gr1("1", "2");
  Group gr2("3", "4");
  dr.addGroup(gr1);
  dr.addGroup(gr2);
  EXPECT_EQ("1", dr.getGroups()[0].getTitle());
}

TEST(DeanaryTest, Test8) {
  Deanary dr;
  Group gr1("1", "2");
  Group gr2("3", "4");
  Student st1("g", 1);
  dr.addGroup(gr1);
  dr.addGroup(gr2);
  dr.addStudent(st1);
  dr.moveStudent(st1.getFio(), gr1.getTitle());
  EXPECT_EQ("g", dr.getGroups()[0].getStudents()[0].getFio());
}

TEST(GroupTest, Test9) {
  Group gr("one", "two");
  EXPECT_EQ("one", gr.getTitle());
}

TEST(GroupTest, Test10) {
  Group gr("1", "2");
  Student st("Ivan", 1);
  gr.addStudent(st);
  EXPECT_EQ("Ivan", gr.getStudent(1).getFio());
}
