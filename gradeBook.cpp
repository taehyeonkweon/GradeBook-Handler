#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>	
#include <fstream>	//To create an ofstream object
#include "gradeBook.h"


using namespace std;
//Implementatin of Gradebook Handle Class
gradeBookHandle::gradeBookHandle(const char * name, int num)	//constructor

{
	strcpy(userName, name);	//save userName;
	recordNum = num;
	pRecordArr = new gradeBook[num];
}
gradeBookHandle::~gradeBookHandle()		//destructor
{
	delete[] pRecordArr;	//All record objects in the heap are deleted
	cout << "Destructor of RecordManager object runs." << endl;
}
int gradeBookHandle::findRecord1(const char *id)	//find a student id from the list. -1 means not found

{
	for (int i = 0; i < recordNum; i++)
	{
		if ((strcmp(id, pRecordArr[i].getID()) == 0))	// return i if current record is not used and the ID does not match the given ID
			return i;



	}
	return -1;
}
int gradeBookHandle::findRecord2(const char *studentname)	//find a student name from the list. -1 means not found

{
	for (int i = 0; i < recordNum; i++)
	{
		if ((strcmp(studentname, pRecordArr[i].getsName()) == 0))// return i if current record is not used and the Student name does not match the given name
			return i;
	}
	return -1;
}
int gradeBookHandle::findRecord3(const char *semail)	//find a student email from the list, -1 means not found.

{
	for (int i = 0; i < recordNum; i++)
	{
		if ((strcmp(semail, pRecordArr[i].getsEmail()) == 0))// return i if current record is not used and the email does not match the given email
			return i;
	}
	return -1;
}
int gradeBookHandle::addRecord(const char *studentname, const char *id, char *sEmail, int mk1, int mk2, int mk3)	//Add a student name, email, ID to the list
{
	int i;
	if (findRecord1(id) != -1 || findRecord2(studentname) != -1 || findRecord3(sEmail) != -1) //found used record
	{
		for (i = 0; i < recordNum; i++)
			if (strcmp(id, pRecordArr[i].getID()) == 0)		//Look for used record, then mark is updated
			{
				pRecordArr[i].setmarks(mk1, mk2, mk3);

				return 1;	//three marks are updated
			}
	}
	else    // used record is not found
		for (i = 0; i < recordNum; i++)	// vacant slot may exist even though record does not exist
			if (pRecordArr[i].getvacant())	//fill in ID name, ID, email, and marks; vacant changed to false
			{
				pRecordArr[i].setName(studentname);	
				pRecordArr[i].setID(id);
				pRecordArr[i].setEmail(sEmail);
				pRecordArr[i].setmarks(mk1, mk2, mk3);

				pRecordArr[i].setvacant(false);
				return 0;	//leave after filling in
			}
	return -1;	// no empty record object could be found
}
int gradeBookHandle::showRecord(char *studentname, char *id, char *sEmail, int *pmk1, int *pmk2, int *pmk3, int arrIndex)	//Shows a record from the list

{

	if (pRecordArr[arrIndex].getvacant())
		return -1;	//return -1 if the requested record is vacant
	else  //studentname, ID, email and marks are put to reference *studentname, *id, *semail and *pmk1 *pmk2 *pmk3
	{	  
		strcpy(studentname, pRecordArr[arrIndex].getsName());
		strcpy(id, pRecordArr[arrIndex].getID());
		strcpy(sEmail, pRecordArr[arrIndex].getsEmail());
		*pmk1 = pRecordArr[arrIndex].getmarks()[0];
		*pmk2 = pRecordArr[arrIndex].getmarks()[1];
		*pmk3 = pRecordArr[arrIndex].getmarks()[2];
		return 0;
	}
}
void gradeBookHandle::writeFile() const
{
	ofstream fout("GPBook.csv");	//creating ofstream object with the filename as GPBook
	for (int i = 0; i < recordNum; i++)	//Get student name, ID, email, and three points on the file
	{
		fout << pRecordArr[i].getsName() << ","
			<< pRecordArr[i].getID() << ","
			<< pRecordArr[i].getsEmail() << ","
			<< pRecordArr[i].getmarks()[0] << ","
			<< pRecordArr[i].getmarks()[1] << ","
			<< pRecordArr[i].getmarks()[2] << "," << endl;
	}
	fout.close();	//close the file

}