# GradeBook
This is a course project for PolyU ENG2002.

It is an object-oriented console application designed to manage student grade books with an integrated login system. It allows users to build and maintain a database of students' names, emails, ID numbers, and marks, providing the functionality to display and update this data.

## Key Features:
### Login System

- **User Authentication**: Upon launching the applicatoin, users are required to log in. The system verifies the username and password against a file (`Password_Database.txt`) that stores registered credentials.
  - **New User Registration**: If the username is not found, the system prompts the user to create an account by setting a password, which is stored for future logins.
  - **Password Verification**: If the username exists, the user must provide the correct password. Failure to provide the correct password in three consecutive attempts will terminate the session.

### Managing Student Records
- **Creating Records**: After logging in, the user is prompted to specify how many student records they wish to create. The user must provide:
  - Student's name
  - Student's ID number
  - Email address
  - Marks for three quizzes
- The data is stored until all allocated slots are filled. If the user attempts to exceed the pre-specified number of records, an error message is displayed, and the record is not saved.

### Searching the Database
- **Search Functionality**: Once records are entered, the user can search the database using the "Show Record" option. Records can be searched using one of the following criteria:
  - Student's ID number
  - Student's name
  - Email address  
- If a match is found, the corresponding record is displayed. If not, the user is notified that no mathcing record was found.

### Data Persistence
- Saving Data: Upon logging out, the application generates two files:
  - `Password_Database.txt`: Stores usernames and passwords for future logins.
  - `GradeBook.csv`: Contains the student records, including names, IDs, emails, and quiz marks, for all students entered during the session.
