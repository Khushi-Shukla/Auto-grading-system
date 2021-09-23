#include <iomanip>
#include"Course.h"
#include"Lab.h"
#include"Theory.h"
using namespace std;

#pragma once
class Student {
	std::string name, *result;
	int roll, totalCourses;
	Course* course;
	Theory* theorySub;
	Lab* labSub;
public:
	Student() {
		name = "";
		result = {};
		roll = 0;
		totalCourses = 0;
		course = new Course[0];
		theorySub = new Theory[0];
		labSub = new Lab[0];
	}
	void details() {
		
		cout << "\nEnter the student's name: ";
		cin.ignore(); //  to ignore or clear one or more characters from the input buffer. we need to clear the input buffer, otherwise it will occupy the buffer of previous variable. By pressing the “Enter” key after the first input, as the buffer of previous variable has space to hold new data, the program skips the following input of container.
		getline(cin,name); //to accept name with spaces

		cout << "\nEnter roll number of the student(only integer value): ";
		cin >> roll;
		
		cout << "\nEnter total courses enrolled: ";
		cin >> totalCourses;
		
		//declaring size of the data members 
		result = new std::string[totalCourses]; 
		course = new Course[totalCourses];
		labSub = new Lab[totalCourses];
		theorySub = new Theory[totalCourses];

		for (int i = 0; i < totalCourses; i++) {
			std::string cname; //temporary variables
			int insemLab, endsemLab, insemTheory, endsemTheory, credit; //temporary variables

			//taking user input
			cout << "\n\tEnter course name " << i + 1 << ": ";
			cin.ignore(); //  to ignore or clear one or more characters from the input buffer. we need to clear the input buffer, otherwise it will occupy the buffer of previous variable. By pressing the “Enter” key after the first input, as the buffer of previous variable has space to hold new data, the program skips the following input of container.
			getline(cin, cname); //to accept name with spaces

			cout << "\n\tEnter credit of " << cname << " : ";
			cin >> credit;
			cout << "\n\tLAB:\n";
			cout << "\n\t\tEnter insem marks obtained in " << cname << " lab : ";
			cin >> insemLab;
			cout << "\n\t\tEnter endsem marks obtained in " << cname << " lab : ";
			cin >> endsemLab;

			cout << "\n\tTHEORY:\n";
			cout << "\n\t\tEnter insem marks obtained in " << cname << " theory : ";
			cin >> insemTheory;
			cout << "\n\t\tEnter endsem marks obtained in " << cname << " theory : ";
			cin >> endsemTheory;

			//storing the course detail
			course[i] = Course(cname, credit);

			
			//storing the lab detials
			labSub[i] = Lab(insemLab, endsemLab, cname, credit);

			//storing the theory details
			theorySub[i] = Theory(insemTheory, endsemTheory, cname, credit);

			//calculating lab result
			labSub[i].calcResult();

			//calculating theory result
			theorySub[i].calcResult();

			//if the students has passed in both lab and theory only then their result is declared as PASS else the result is saved as FAIL.
			if (labSub[i].getResult() == "PASS" && theorySub[i].getResult() == "PASS") {
				this->result[i] = "PASS";
			}
			else
				this->result[i] = "FAIL";

			
		}
	}

	//display every detail of the students and courses taken by them
	void showDetails() {
		cout << "\nRoll: " << roll << " Name: " << name << "\n" << "Courses enrolled: ";
		for (int i = 0; i < totalCourses; i++) {
			cout << "\n\t" << i + 1 << ")";
			course[i].viewCourseDeets();
			labSub[i].viewResult();
			theorySub[i].viewResult();
			cout << "\nCOURSE RESULT : " << this->result[i] << "\n";

		}
	}

	//to show course result
	void showCourseResult() {
		cout <<"\n"<< setw(15)<<"Roll"<<setw(25)<<"Name"<<setw(20)<<"Course name"<<setw(20)<<"Result\n------------------------------------------------------------\n";
		cout << setw(15)<<roll << setw(25) << name << setw(20);
		for (int i = 0; i < totalCourses; i++) {
			if(i>0)
				cout << setw(42);
			cout << course[i].getCourseName()<< setw(20) << this->result[i];
			cout << "\n";
		}
		cout << "------------------------------------------------------\n";
	}


//	void showCourseResult() {
		//cout << "\nRoll: " << roll << " Name: " << name << "\n";
		//cout << "Course name" << setw(29) << "Result\n";
	//	for (int i = 0; i < totalCourses; i++) {
			//cout << "\n" << i + 1 << ")";
			//cout << course[i].getCourseName() << setw(34) << this->result[i];
			//cout << "\n";
		//}
		//cout << "\n";
	//}

	//getter function for the courses taken by student
	Course* courseInfo() {
		return course;
	}

	//getter function for the theory courses taken by student
	Lab* labInfo() {
		return labSub;
	}

	//getter function for the lab courses taken by student
	Theory* theoryInfo() {
		return theorySub;
	}


	//getter function for the result
	std::string* getResult() {
		return result;
	}

	//getter function for the student's roll
	int getRoll() {
		return roll;
	}

	//getter function for the student's name
	std::string getName() {
		return name;
	}


	//getter function for the total number of courses
	int getTotalCourses() {
		return totalCourses;
	}

};