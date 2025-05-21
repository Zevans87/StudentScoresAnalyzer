//Zachery Evans
//04/18/2023
//COSC-1337
//Programming Assignment 3
#include "SuperArray.h"
#include <iostream>
#include <fstream>
using namespace std;

enum Course { COSC1336, COSC1136, COSC1337, COSC1137, COSC3331, COSC3333, COSC3317 };

//Function Prototype
string enumToString(Course);

int main()
{
	//Variables and Vectors
	const int SIZE = 10;
	int iArraySize, maxAverage, maxScore, curve, userIndex;
	int* courseArray = nullptr;
	SuperArray courseRecords[SIZE];  //Task I
	SuperArray newRecord;
	string courseName;
	Course num;
	Course targetCourse = COSC1137;

	//Opening File
	ifstream infile;
	infile.open("scores.txt");

	cout << "------------------------------ Task II ------------------------------" << endl;
	//Populating Array
	for (int i = 0; i < SIZE; i++)
	{
		if (infile >> iArraySize)
		{
			courseRecords[i].setNumElement(iArraySize);
			courseArray = new int[iArraySize];
			for (int j = 0; j < iArraySize; j++)
			{
				infile >> courseArray[j];
			}
			courseRecords[i].makeCopy(courseArray, iArraySize);
			delete[] courseArray;
			courseArray = nullptr;
		}
		else break;
	}
	//Displaying Array
	for (int i = 0; i < SIZE; i++)
	{
		courseRecords[i].displayAllArray();
	}
	
	cout << endl << "------------------------------ Task III ------------------------------" << endl;
	newRecord.fillRandom(60, 100, 13);
	cout << "The content of the new single object: " << endl;
	newRecord.displayAllArray();
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (courseRecords[i].getAnElement(0) == 0)
		{
			courseRecords[i].makeCopy(newRecord.getArray(), 13);
		}
	}
	cout << "The content of the populated section of the object array: " << endl;
	for (int i = 0; i < 6; i++)
	{
		courseRecords[i].displayPopulatedSection();
	}

	cout << endl << "------------------------------ Task IV ------------------------------" << endl;
	maxAverage = courseRecords[0].getAverage();
	num = static_cast<Course>(0);
	courseName = enumToString(num);
	for (int i = 1; i < SIZE; i++)
	{
		if (courseRecords[i].getAverage() > maxAverage)
		{
			maxAverage = courseRecords[i].getAverage();
			num = static_cast<Course>(i);
			courseName = enumToString(num);
		}
	}
	if (newRecord.getAverage() > maxAverage)
	{
		maxAverage = newRecord.getAverage();
		num = static_cast<Course>(6);
		courseName = enumToString(num);
	}
	cout << courseName << "is the course with the max average of " << maxAverage << "." << endl;

	cout << endl << "------------------------------ Task V ------------------------------" << endl;
	courseName = enumToString(targetCourse);
	cout << "The scores for " << courseName << "course before the curve:" << endl;
	courseRecords[targetCourse].displayPopulatedSection();
	maxScore = courseRecords[targetCourse].getMax();
	curve = (100 - maxScore);
	for (int i = 0; i < courseRecords[targetCourse].getNumElement(); i++)
	{
		courseRecords[targetCourse].insertAtIndex(i, (courseRecords[targetCourse].getAnElement(i) + curve));
	}
	cout << endl;
	cout << "The scores for " << courseName << "course after the curve:" << endl;
	courseRecords[targetCourse].displayPopulatedSection();

	cout << endl << "------------------------------ Task VI ------------------------------" << endl;
	targetCourse = COSC3331;
	courseName = enumToString(targetCourse);
	cout << "The scores for " << courseName << "after adding the new student: " << endl;
	courseRecords[targetCourse].insertAtIndex(courseRecords[targetCourse].getNumElement(), 83);
	courseRecords[targetCourse].displayPopulatedSection();
	
	cout << endl << "------------------------------ Task VII ------------------------------" << endl;
	targetCourse = COSC1336;
	courseName = enumToString(targetCourse);
	cout << "Score Modification for " << courseName << ":" << endl;
	cout << "Please enter a value in the range: 0-11: ";
	cin >> userIndex;
	courseRecords[targetCourse].insertAtIndex(userIndex, (courseRecords[targetCourse].getAnElement(userIndex) + 4));
	cout << "The scores for " << targetCourse << "course after modification:" << endl;
	courseRecords[targetCourse].displayPopulatedSection();
	cout << "The number of scores for " << targetCourse << "is: " << courseRecords[targetCourse].getNumElement();

	cout << endl << "------------------------------ Task VIII ------------------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		targetCourse = static_cast<Course>(i);
		courseName = enumToString(targetCourse);
		cout << courseName << ":          ";
		courseRecords[i].displayPopulatedSection();
	}
	targetCourse = COSC3317;
	courseName = enumToString(targetCourse);
	cout << courseName << ":          ";
	newRecord.displayPopulatedSection();

	return 0;
}

//Function Definition
string enumToString(Course x)
{
	string course;

	switch (x)
	{
	case COSC1336: course = "COSC1336 ";
		break;
	case COSC1136: course = "COSC1136 ";
		break;
	case COSC1337: course = "COSC1337 ";
		break;
	case COSC1137: course = "COSC1137 ";
		break;
	case COSC3331: course = "COSC3331 ";
		break;
	case COSC3333: course = "COSC3333 ";
		break;
	case COSC3317: course = "COSC3317 ";
		break;
	}

	return course;
}