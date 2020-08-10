#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS 1	//for Visual Studio
#include <iostream>
#include <fstream>	//To create an ofstream object
#include <string>
#include "gradeBook.h"


using namespace std;	

bool menu(gradeBookHandle *, int);// Recurrent menu; gradeBookHandle object passed by reference
void getIDnMarks(char *, char *, char *, int *, int *, int *); //Get student name, student ID, email, and marks from user by reference
void Case_one(gradeBookHandle *);	//Case one in menu()
void Case_two(gradeBookHandle *, int);	//Case two in menu()

int main()
{
	string 	option, Name, password, inputName, inputPassword, registeredName, registeredPassword;
	int attemptcount = 0;
	while (1)
	{


		cout << "Enter Your Option (New_User  / Login /  Exit):  ";
		getline(cin, option);


		if (option == "Exit")
		{
			return 1;
		}
		if (option == "New_User")
		{

			ofstream fin("Password_Database.txt", ios::ate);
			if (!fin.is_open())
			{
				cout << "could not open file\n";
			}
			cout << "\n\n"
				<< "New Username: ";
			getline(cin, registeredName);
			cout << "New Password: ";
			getline(cin, registeredPassword);
			fin << registeredName;
			fin << '\n';
			fin << registeredPassword;
			fin << '\n';

			fin.close();
		}
		if (option == "Login")
		{
			ifstream f("Password_Database.txt");
			if (!f.is_open())
			{
				cout << "could not open file\n";
				return 0;
			}
			getline(f, Name, '\n');
			getline(f, password, '\n');
			f.close();


			while (1)
			{


				do {
					cout << "\n\n\n"
						<< "Enter Username: ";
					getline(cin, inputName);
					cout << "Enter Password: ";
					getline(cin, inputPassword);

					if (inputName == Name && inputPassword == password)
					{
						cout << "Login Successful\n\n" << "Welcome, " << inputName;
						char userName[80];
						int rec_num;
						cout << "\n\nWelcome to the Student Record Management System.\n\n";
						cout << "Please enter your Surname:  ";
						cin >> userName;
						cout << "\nHow many records do you want to create: ";
						cin >> rec_num;
						gradeBookHandle *User = new gradeBookHandle(userName, rec_num);
						bool exitflag = false;	//flag is bool
						while (exitflag == false)
							exitflag = menu(User, rec_num);
						User->writeFile();	//
						cout << "Goodbye " << userName << "!!!\n";
						delete User;
						return 0;
						break;
					}

					else {				// Ends if an user fails to provide correct answer within three trials 
						attemptcount++;
						cout << "incorrect username or password\n";

					}

				} while (attemptcount < 3);


				cout << "\nIncorrect 3 attempts\n\n";
				return 1;
			}
		}



		cout << "\n\\n\n";
	}
	return 1;
}
bool menu(gradeBookHandle *mUser, int numRec)	//main menu

{
	char choice;
	//menu
	cout << "\nStudent record management system:\n";
	cout << "1. Add Record\n";
	cout << "2. Show Record\n";
	cout << "3. Quit\n";
	cout << "Please enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		Case_one(mUser);
		break;
	case '2':
		Case_two(mUser, numRec);
		break;
	case '3':
		return true;
	default: cout << "\nInvalid input, please re-enter.\n\n";
	}
	return false;
}
//get Name, ID, email and marks from the user
void getIDnMarks(char *Name, char *ID, char * email, int *marks1, int *marks2, int *marks3) 
{

	cout << "Student Name:  ";
	cin >> Name;
	cout << "Student number:  ";
	cin >> ID;
	cout << "Enter Email: ";
	cin >> email;
	cout << "Enter no for first quiz:  ";
	cin >> *marks1;
	cout << "Enter no for second quiz:  ";
	cin >> *marks2;
	cout << "Enter no for third quiz:  ";
	cin >> *marks3;

}
void Case_one(gradeBookHandle *Usr)
{
	int marks1, marks2, marks3, ret_i; //stores integer returned by functions
	char StudID[20], sEmail[100], stdname[80];
	getIDnMarks(stdname, StudID, sEmail, &marks1, &marks2, &marks3); //passed by reference
	if (Usr->findRecord1(StudID) == -1) // record cannot be found
	{
		ret_i = Usr->addRecord(stdname, StudID, sEmail, marks1, marks2, marks3); //Add a new record
		if (ret_i == 0)
			cout << "\nThe record of " << StudID << " is created.\n\n";
		if (ret_i == -1)	//No empty slot to add
			cout << "\nNo empty record is found. Please free up a record to store the data.\n\n";
	}
	else
		cout << "\nThe record of " << StudID << " exists.\n\n";
}
void Case_two(gradeBookHandle *Usr, int recNum)
{
	int mks1, mks2, mks3; //For storing marks returned by reference
	char StudID[20], sEmail[100], sName[80]; //For storing StudentID, email and name returned by reference
	int i;
	cout << "How do you want to search student record: \n";
	cout << "[1]IDno" << "\t[2]Name" << "\t[3]Email\n";
	char choice;
	cin >> choice;
	switch (choice) {

	case '1':

		cout << "Enter student number: \n";
		cin >> StudID;
		i = Usr->findRecord1(StudID);
		if (i != -1) {//Check according to indices
			if (Usr->showRecord(sName, StudID, sEmail, &mks1, &mks2, &mks3, i) == 0) //shows result if not vacant
				cout << "\nStudent Name:  " << sName << "\nStudent ID:  " << StudID << "\nStudent Email:  " << sEmail << "\nMarks_1:  " << mks1 << "\nMarks_2:  "
				<< mks2 << "\nMarks_3:  " << mks3 << endl;
		}
		else { cout << "\nThe record of " << StudID << " is not found.\n\n"; }; break;

	case '2':

		cout << "Enter student name: \n";
		cin >> sName;
		i = Usr->findRecord2(sName);
		if (i != -1) {//Check according to indices
			if (Usr->showRecord(sName, StudID, sEmail, &mks1, &mks2, &mks3, i) == 0)//shows result if not vacant
				cout << "\nStudent Name:  " << sName << "\nStudent ID:  " << StudID << "\nStudent Email:  " << sEmail << "\nMarks_1:  " << mks1 << "\nMarks_2:  "
				<< mks2 << "\nMarks_3:  " << mks3 << endl;

		}
		else { cout << "\nThe record of " << sName << " is not found.\n\n"; }; break;

	case '3':
		cout << "Enter student email: \n";
		cin >> sEmail;

		i = Usr->findRecord3(sEmail);
		if (i != -1) {//Check according to indices
			if (Usr->showRecord(sName, StudID, sEmail, &mks1, &mks2, &mks3, i) == 0)//shows result if not vacant
				cout << "\nStudent Name:  " << sName << "\nStudent ID:  " << StudID << "\nStudent Email:  " << sEmail << "\nMarks_1:  " << mks1 << "\nMarks_2:  "
				<< mks2 << "\nMarks_3:  " << mks3 << endl;
		}
		else { cout << "\nThe record of " << sEmail << " is not found.\n\n"; }; break;

	}


}

