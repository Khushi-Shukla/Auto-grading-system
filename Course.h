#include<string>
#pragma once
class Course {
	std::string courseName, code;
	int credit;
public:
	//default constructor defined so that no error or warning is generated
	Course() {
		credit = 0;
		courseName = "";
		int random = 0;
		code = "";
	}

	//parameterized constructor
	Course(std::string course_name, int credit_val) {
		this->credit = credit_val;
		courseName = course_name;
		int random = rand() % 900 + 100; //predefined function to generate random numbers between 100 to 999 i.e. 3 digit numbers
		code = courseName.substr(0, 3) + std::to_string(random); //the course code is assigned the first 3 letters of the course name and 3 random digits so that it is unique
	}


	//to show the details of the course taken by student
	void viewCourseDeets() {
		std::cout << "\n\tCourse code:" << code << "\n\tCourse name : " << courseName << "\n\tCredits : " << credit;
	}

	//getter function for credit
	int getCredit() {
		return credit;
	}

	//getter function for course name
	std::string getCourseName() {
		return courseName;
	}

	//getter function for course code
	std::string getCourseCode() {
		return code;
	}
};