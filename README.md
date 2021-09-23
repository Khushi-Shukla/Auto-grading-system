# Auto-grading-system
Used a filesystem to import and export the students' details and result to/from the program. Two files are created. One file has all the details of every student and other file stores the result of the student.
Question Create a class called a Course. Course class will represent a subject taken up by a student. If the
student has five courses, then each course is represented by an object of the class Course. Each
course offered to the student is unique and can be separated by a course code. Along with this,
each course is signified by its name, in-semester mark, and end-semester mark. In addition to
these properties, a course is also assigned a credit. 
Using the course class discussed above, you will design another two types called Theory Course
and Laboratory course (inherit the class Course). A student is declared to pass a theory
course if the student secures at least 28 marks in the End semester examination and a total
of 40 marks if we add in-semester and end-semester marks together. Similarly, a student is
declared to pass a laboratory course if it obtains 35 marks in the end-Semester
examination with a total of 50 marks when combined the mark of In-semester and end-semester
marks.
In this project, you are going to define all the classes (Course, TheoryCourse, LaboratoryCourse)
with the details mentioned above. Along with this, you need to specify the member functions
whenever required. In addition, there will be a function common to both Theory and Laboratory
courses. That function will calculate the result of the student for that course depends on the
constraints mentioned above.
In this project, you also need to define a class called Student. This class will specify the student
details like name, roll number, and courses taken up by him/her (both theory and
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
