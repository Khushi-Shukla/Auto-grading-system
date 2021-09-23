#include <iostream>
#include<fstream>
#include <iomanip>
#include <sstream> 
#include"Student.h"
#include"Course.h"
#include"Theory.h"
#include"Lab.h"
using namespace std;

void read_information() {

    //to read the file
    ifstream fin;

    // Open an existing file
    fin.open("STUDENT.csv");
    
    string line, word;
    while (fin.good()) {
        
        //seperating the lines at commas (,)
        getline(fin, line, ',');

        //breaking the line in words
        stringstream s(line);
        
        //displaying each word

        while (getline(s, word, ',')) {
            cout << left << setw(17) << word;  //setw() is used to set width
        }
        
    }
    
    cout << "\n";
    cout << "The data may appear a little distorted due to less space. Check out Student.csv file to see the details clearly\n";

}

void read_result() {
   
    //to read the file
    ifstream fin;

    // Open an existing file
    fin.open("Result.csv");
    
    string line, word;
    while (fin.good()) {
        //seperating the lines at commas (,)
        getline(fin, line, ',');

        //breaking the line in words
        stringstream s(line);
       
        //displaying each word
        while (getline(s, word, ',')) {
            cout<<left << setw(20) << word;
        }
    
    }
    cout << "\n";
    cout << "The data may appear a little distorted due to less space. Check out Student.csv file to see the details clearly\n";
 
}

int main()
{
   
    Student* s;
    int t, isTrue=0;
    std::cout << "Enter total students: ";
    cin >> t;
    s = new Student[t];


    //storing in the csv file writing in the file. if the file is not present, a new one of the given names are created
    ofstream fout1("STUDENT.csv");
    ofstream fout2("Result.csv");

    //writing the headers of the csv file
    fout1 << "Roll,Name,CourseCode,CourseName,Credit,Lab-Insem-marks,Lab-Endsem-Marks,Lab-Result,Theory-Insem-Marks,Theory-Endsem-Marks,Theory-Result,FinalResult";
    fout2 << "Roll,Name,Result";



    for (int i = 0; i < t; i++) {
        //storing the values by calling a member function
        s[i].details();


        //accessing all the values to store in csv file
        int roll = s[i].getRoll();
        string name = s[i].getName();
        int totalCourse = s[i].getTotalCourses();
        string* result = s[i].getResult();
        Course* course = s[i].courseInfo();
        Lab* lab = s[i].labInfo();
        Theory* theory = s[i].theoryInfo();

        fout1 << "\n" << roll << "," << name << ",";
        fout2 << "\n" << roll << "," << name << ",";

        // to check if a student has passed all the exams
        bool isPass = true;

        for (int j = 0; j < totalCourse; j++) {
        
            //writing in the csv file
            if (result[j] == "FAIL")
                isPass = false; //if student fails in any one subject then they fail the exam as a whole
            
            if (j != 0)
                fout1 << "\n,,";
            fout1 << course[j].getCourseCode() << "," << course[j].getCourseName() << "," << course[j].getCredit() << "," << lab[j].getInsemMarks()
                << "," << lab[j].getEndSemMarks() << "," << lab[j].getResult() << "," << theory[j].getInsemMarks() << ","
                << theory[j].getEndSemMarks() << "," << theory[j].getResult() << "," << result[j];
        }

        //checking if student is  pass or not
        if (isPass)
            fout2 << "PASS"; 
        else
            fout2 << "FAIL";
        
    }
    //end of the loop

    fout1.close(); //close the file student.csv
    fout2.close(); //close the file result.csv


    for (int i = 0; i < t; i++)
        s[i].showDetails(); //display the result along with the details


    //display statement
    std::cout << "\nThe information has been saved in the student.csv file\nThe result of the students is saved in Result.csv file\n";
   
    //a loop so that user can see both the reult and the details of the student as required
    while (1) {
        std::cout << "Press 1 to view the course wise result\nPress 2 to view the overall result of each student.\nPress 3 to view the full information.\nPress 0 to break\n----";
        cin >> isTrue;
        cout << "\n";

        if (isTrue == 0) {
            break;
        }
        if (isTrue == 1) {
            for (int i = 0; i < t; i++) {
                s[i].showCourseResult();
                cout << "\n";
            }
        }
        else if (isTrue == 2) {
            read_result();
            cout << "\n";
        }
        else if (isTrue == 3) {
            read_information();
            cout << "\n";
        }
    
        else {
            cout << "Wrong option! Try again\n";
        }
    }
    return 0;
}

