# gradeBook
It is an object-oriented console application that can handle students’ grade books integrated with login system. It builds a database of the students’ names, emails, ID numbers, and marks; and displays and handles the database content.



Logging into the Application
* When a user wants to start it, the user needs to login the application with a username first, which will be checked with the content of a file that stores username-password pairs. If the username is new, the application will ask for a password from the user and store it into that file. If the username can be found in that file, the application will start only if the password is correct. The application will end if the user fails to provide the correct password in three consecutive trials. 

Adding Data to the Database system
* The program asks to enter the number of records that we want to create. We are asked to type in student name, number, email, and marks for three quizzes. The data is added until all vacant slots are used. If we tried to type more records than our original allocation, error message shows up and the record is not saved.

Searching for Data in the Database System
* After we are doing inputting the records for the students, we can search for saved records through the Show Record option. We can search the database for the records in three ways. The application can search for records by the students ID, Email Address, or their Name. We select one of them and enter the value. If it matches with the database, the data in the record is shown. If not, no data is to be shown.

After Logging out of the Application
* After the data has been recorded by the application, we can exit the application. As a result, we see that a Password_Database.txt and a GradeBook.csv file have been generated. The Password_Database.txt is generated when we make an account for the first time. The GradeBook.csv is generated after the user exits the menu. It stores all the student data (Name, ID, Email, Grades) that was entered by the user.
