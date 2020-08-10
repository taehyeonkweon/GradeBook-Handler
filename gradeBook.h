#pragma once
#pragma once	//to avoid multiple inclusion


#include <string.h>

class gradeBook		//class for gradebook
{
public:
	gradeBook() { vacant = true; }			//Constructor 
	char * getsName() { return sName; }	//get name
	char * getID() { return sIDno; }	//get ID
	char * getsEmail() { return sEmail; }	//get email
	int * getmarks() { return sMarks; }	//get marks
	bool getvacant() { return vacant; }

	void setName(const char * name) { strcpy_s(sName, name); }   //set name
	void setID(const char * id) { strcpy_s(sIDno, id); }			// set ID
	void setEmail(char * semail) { strcpy_s(sEmail, semail); }	// set email
	void setmarks(int mk1, int mk2, int mk3) { sMarks[0] = mk1; sMarks[1] = mk2; sMarks[2] = mk3; }		//set marks
	void setvacant(bool vac) { vacant = vac; }

private:
	char sEmail[100], sName[80], sIDno[20];		//array of characters; char *sEmail, *sName, *sIDno; Keep the studentID from students
	int sMarks[3];	//number of marks; Keep the marks from students
	bool vacant;	// When record is used, it is false. When record is empty, it is true
};					


class gradeBookHandle		//Class for grade book handler
{
public:
	gradeBookHandle(const char * name, int num); //Constructor set number of elements to zero
	~gradeBookHandle();	//destrector
	int findRecord1(const char *id);	//find a student id from the list. -1 means not found
	int findRecord2(const char *studentname);	//find a student name from the list. -1 means not found
	int findRecord3(const char *semail);	//find a student email from the list. -1 means not found
	int addRecord(const char * studentname, const char *id, char *semail, int mk1, int mk2, int mk3); //Adds record 
	int showRecord(char *studentname, char *id, char *mail, int *pmk1, int *pmk2, int *pmk3, int arrIndex);	//Show record; Task 4
	void writeFile() const;	//

private:
	char userName[80];	//Store username that can manage Record objects; max 80charactors
	int recordNum;	//number of records is kept
	gradeBook * pRecordArr;	//the point pointing to the array in heap is kept
};



