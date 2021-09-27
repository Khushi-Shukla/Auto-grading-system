# Auto-grading-system
Used a filesystem to import and export the students' details and result to/from the program. Two files are created. One file has all the details of every student and other file stores the overall result of each student.

## 1. Question
Create a class called a Course. Course class will represent a subject taken up by a student. If the
student has five courses, then each course is represented by an object of the class Course. Each
course offered to the student is unique and can be separated by a course code. Along with this,
each course is signified by its name, in-semester mark, and end-semester mark. In addition to
these properties, a course is also assigned a credit. 
Using the course class discussed above, you will design another two types called Theory Course
and Laboratory course (inherit the class Course). A student is declared to pass a theory
course if the student secures at least 28 marks in the End semester examination and a total
of 40 marks if we add in-semester and end-semester marks together. Similarly, a student is
declared to pass a laboratory course if it obtains 35 marks in the end-Semester
examination with a total of 50 marks when combined the mark of In-semester and end-semester
marks.
In this project, you are going to define all the classes (Course, TheoryCourse, LaboratoryCourse)
with the details mentioned above. Along with this, you need to specify the member functions
whenever required. In addition, there will be a function common to both Theory and Laboratory
courses. That function will calculate the result of the student for that course depends on the
constraints mentioned above.
In this project, you also need to define a class called Student. This class will specify the student
details like name, roll number, and courses taken up by him/her (both theory and
laboratory courses).
In the main function, you should take input for as many students as you want. It should look like
as below code:

int main()
{
int n;
Sudent *std;
cout&lt;&lt;&quot;\n Enter Number of Student : &quot;;
cin&gt;&gt;n;
std = new Student[n];

for(size_t i; i&lt;n;i++)
std-&gt;details();
//Take the details of student, number of course (create as many course object needed for this
student)
for(size_t i; i&lt;n;i++) {
std-&gt;EndSemestermark(); // Enter all the end semester mark for the student;
std-&gt;InSemestermark(); // Enter all the end Semester mark for the student
}
for(size_t i; i&lt;n;i++) {
//Print result of each course whether Fail/Pass.
}
}

## 2. Approach
Seperate classes are created according to the question. The member functions are then called to do the required jobs. Member functions defined in different classes are-
  ### 2.1 Course Class
        a)	getCredit() - all the data members are private. So, the getter functions are defined to get the values.
        b)	getCourseName() - getter function of course name
        c)	getCourseCode() - getter function of course code
        d)	viewCourseDeets() – function that displays the details of the student  
  ### 2.2 Theory Class and Member Class
        a)	calcResult() - calculates whether the student has passed the theory or not using the condition mentioned in the question
        b)	getResult() - getter function for result
        c)	getInsemMarks() - getter function for in semester marks
        d)	getEndSemMarks() - getter function for end semester marks
        e)	viewResult() - to display the result
  ### 2.3 Student Class
        a)	details() – this function stores all the detail of the student. This will also save the result of the student for a particular course
        b)	showDetails()- to display every detail of the students and courses taken by them
        c)	showCourseResult() – to show the result of each course
        d)	courseInfo() - getter function for the courses taken by student
        e)	labInfo() - getter function for the theory courses taken by student
        f)	theoryInfo() - getter function for the lab courses taken by student
        g)	getResult() - getter function for the result
        h)	getRoll() - getter function for the student's roll
        i)	getName() - getter function for the student's name
        j)	getTotalCourses() - getter function for the total number of courses
        
## 3. Importing and Exporting the csv file
  ### 3.1 Writing in the files
In the main function 2 lines are written which creates 2 new files if they aren’t already created.
ofstream fout1("STUDENT.csv");
ofstream fout2("Result.csv");
The first file stores every detail of the student and the second file contains only the name, roll and result of the students. This gives the user an option to view either the whole detail which also has the result of students or just the result of students with their roll and name. Then the first row of these files are written i.e., the header is given which will specify the next fields.     
fout1 << "Roll,Name,CourseCode,CourseName,Credit,Lab-Insem-marks,Lab-Endsem-Marks,Lab-Result,Theory-Insem-Marks,Theory-Endsem-Marks,Theory-Result,FinalResult";
fout2 << "Roll,Name,Result";
To write the details in these files we have to access the data from the particular classes which have that data. Therefore, when the details of the students are being stored at the same time, those details are accessed using various getter functions and these details are written in the file. In Line 102 – line 109 of grading.cpp all the required information is accessed. Now, we have to keep in mind that the string *result of student class stores result for each course separately and user might need the final result. So the final result for every student whether they have passed or not is calculated. For this a Boolean value isPass is declared which is assigned false if any of the course result is fail. After the end of the loop if the isPass variable is true, it means the student has passed every course and hence their final result is written pass in the file otherwise it is Fail.
After all the writing is completed, these files are closed.
fout1.close(); 
fout2.close();

    
  ### 3.2 Reading from the files
There are two different files and to read from these files two different functions are created.
Read_information()

Ifstream: This data type represents the input file stream and is used to read information from files.
The outermost while loop runs until there is no error found in the stream: while (fin.good()) {
Perform reading }
Using getline(), file pointer and comma(,) as the delimiter, we read an entire row and store it in a string variable ‘line’: getline(fin, line, ','); 
The entire line is then separated into words using stringstream() function stringstream s(line);
Now, the inner loop iterate over each of these words and print them on the output screen
In this function the setw() function is used which specifies the minimum number of character positions a variable will consume.
Read_result()

This function reads the ‘result.csv’ file and have pretty much the same working as the above function. It is written as a separate function because of two reasons. First is to avoid any confusion and error for future editing of these functions and secondly the spacing needed in both function is not the same. The student.csv file contains 12 fields and result.csv contains 3 fields. So, the second file can have more spacing but if that is given in the first file the output may look very clumsy. Hence, two separate functions are declared.
The outermost while loop runs until there is no error found in the stream: while (fin.good()) {
Perform reading }
Using getline(), file pointer and comma(,) as the delimiter, we read an entire row and store it in a string variable ‘line’: getline(fin, line, ','); 
The entire line is then separated into words using stringstream() function stringstream s(line);
Now, the inner loop iterate over each of these words and print them on the output screen


## 4. Output
 #### 4.1 Output of the code after user's input looks like this-
![output of the code](https://github.com/Khushi-Shukla/Auto-grading-system/blob/main/output.png)

#### 4.2 The csv files after successful import of data will look like this- 
![csv files](https://github.com/Khushi-Shukla/Auto-grading-system/blob/main/csvfilesoutput.png)
