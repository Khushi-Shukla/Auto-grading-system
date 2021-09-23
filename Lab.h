#include"Course.h"
#pragma once
class Lab : public Course {
	int insemMarks, endsemMarks;
	std::string result;
public:

	//default constructor defined so that no error or warning is generated
	Lab() {
		insemMarks = 0;
		endsemMarks = 0;
		result = "";
	}

	//parameterized constructor
	Lab(int insem_marks, int endsem_marks, std::string course_name, int credit_val): Course(course_name, credit_val) {
		insemMarks = insem_marks;
		endsemMarks = endsem_marks;
		result = "NIL";
	}


	//calculates whether the student has passed the theory or not using the condition mentioned in the question
	void calcResult() {
		if (endsemMarks >= 35 && (endsemMarks + insemMarks >= 50))
			this->result="PASS";
		else
			this->result="FAIL";
	}

	//getter function for result
	std::string getResult() {
		return result;
	}

	//to display the result
	void viewResult() {
		std::cout << "\n\tLAB:\n" << "\t\tInsem Marks : " << insemMarks << "\n\t\tEndsem Marks : " << endsemMarks<<"\n\t\tResult : "<<result ;
	}

	//getter function for insem marks
	int getInsemMarks() {
		return insemMarks;
	}

	//getter function for end sem marks
	int getEndSemMarks() {
		return endsemMarks;
	}
}; 