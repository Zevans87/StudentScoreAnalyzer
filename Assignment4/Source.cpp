/*Zachery Evans
11/21/2022
COSC-1336
Assignment4*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void menu();
char letterGrade(int);
int minScore(int, int, int);
int averageScore(int, int, int);
string topStudent(string, int);
void continuousProgressList(string);
int gradeCount(string, char, int);

int main()
{
	menu();
	return 0;
}

void menu()
{
	ifstream infile;
	int menuOption,
		theScore1,
		theScore2,
		theScore3,
		average,
		minimum,
		testNumber,
		userTest,
		studentCount;
	string fileName = "studentData.txt",
		   theName,
		   highScore;
	char theLetter,
		 userLetter;
	


	do
	{
		cout << "1." << "\t" << "List the students and their average scores in letter grades." << endl;
		cout << "2." << "\t" << "List the students who made all A's: their names along with their 3 scores." << endl;
		cout << "3." << "\t" << "List the name of the student who has made the highest score on a certain test." << endl;
		cout << "4." << "\t" << "List the students with continuous progress on their test scores." << endl;
		cout << "5." << "\t" << "The number of students who made a certain grade on a certain test:" << endl;
		cout << "6." << "\t" << "Exit." << endl;
		cout << "Please choose an option: ";
		cin >> menuOption;
		switch (menuOption)
		{
		case 1: 
			infile.open("studentData.txt");
			cout << "Name" << "\t" << "Scores" << endl;
			while (infile >> theName)
			{
				infile >> theScore1 >> theScore2 >> theScore3;
				average = averageScore(theScore1, theScore2, theScore3);
				theLetter = letterGrade(average);
				cout << theName << "\t" << theLetter << endl;
			}
			infile.close();
			break;
		case 2:
			infile.open("studentData.txt");
			cout << "Name" << "\t" << "Scores" << endl;
			while (infile >> theName)
			{
				infile >> theScore1 >> theScore2 >> theScore3;
				minimum = minScore(theScore1, theScore2, theScore3);
				if (minimum >= 90)
					cout << theName << "\t" << theScore1 << " " << theScore2 << " " << theScore3 << endl;
			}
			infile.close();
			break;
		case 3:
			cout << "Please enter the test number (1-3): ";
			cin >> testNumber;
			highScore = topStudent(fileName, testNumber);
			cout << "The student with the highest score for test " << testNumber << ": " << highScore << endl;
			break;
		case 4: 
			continuousProgressList(fileName);
			break;
		case 5:
			cout << "Please enter the letter grade: ";
			cin >> userLetter;
			cout << "Please enter the test number (1-3): ";
			cin >> userTest;
			studentCount = gradeCount(fileName, userLetter, userTest);
			cout << "The count of students making grade of " << userLetter << " on test #" << userTest << ": " << studentCount << endl;
			break;
		case 6: cout << "Goodbye!" << endl;
			break;
		default: cout << "Please choose a correct menu option." << endl;
		}
	} while (menuOption != 6);
}

char letterGrade(int average)
{
	char letter;
	if (average >= 90)
		letter = 'A';
	else if ((average >= 80) && (average < 90))
		letter = 'B';
	else if ((average >= 70) && (average < 80))
		letter = 'C';
	else if (average < 70)
		letter = 'F';
	return letter;
}

int minScore(int theScore1, int theScore2, int theScore3)
{
	int min = theScore1;
	if (theScore2 < min)
		min = theScore2;
	if (theScore3 < min)
		min = theScore3;
	return min;
}

int averageScore(int theScore1, int theScore2, int theScore3)
{
	int	theAverage;
	theAverage = (theScore1 + theScore2 + theScore3) / 3;
	return theAverage;
}

string topStudent(string fileName, int testNumber)
{
	string name,
		   maxName;
	int score1,
		score2,
		score3,
		maxTest1,
		maxTest2,
		maxTest3;
	ifstream infile(fileName);
	 
	
	switch (testNumber)
	{
	case 1:
		infile >> maxName >> maxTest1 >> maxTest2 >> maxTest3;
		while (infile >> name)
		{
			infile >> score1 >> score2 >> score3;
			if (maxTest1 < score1)
			{
				maxName = name;
				maxTest1 = score1;
				maxTest2 = score2;
				maxTest3 = score3;
			}
		}
		break;
	case 2:
		infile >> maxName >> maxTest1 >> maxTest2 >> maxTest3;
		while (infile >> name)
		{
			infile >> score1 >> score2 >> score3;
			if (score2 > maxTest2)
			{
				maxName = name;
				maxTest1 = score1;
				maxTest2 = score2;
				maxTest3 = score3;
			}
		}
		break;
	case 3:
		infile >> maxName >> maxTest1 >> maxTest2 >> maxTest3;
		while (infile >> name)
		{
			infile >> score1 >> score2 >> score3;
			if (score3 > maxTest3)
			{
				maxName = name;
				maxTest1 = score1;
				maxTest2 = score2;
				maxTest3 = score3;
			}
		}
		break;
	}
	infile.close();
	return maxName;
}

void continuousProgressList(string fileName)
{
	string name;
	int score1,
		score2,
		score3;
	bool flag = false;
	ifstream infile(fileName);
	while (infile >> name)
	{
		infile >> score1 >> score2 >> score3;
		if ((score1 < score2) && (score2 < score3))
		{
			flag = true;
			cout << name << endl;
		}
	}
	if (flag == false)
		cout << "Sorry, no such student is found in this file." << endl;
	infile.close();
}

int gradeCount(string fileName, char userLetter, int userTest)
{
	string name;
	int score1,
		score2,
		score3,
		counter = 0;
	char letter;
	ifstream infile(fileName);
	switch (userTest)
	{
	case 1:
		while (infile >> name)
		{
			infile >> score1 >> score2 >> score3;
			letter = letterGrade(score1);
			if (letter == userLetter)
				counter++;
		}
		break;
	case 2:
		while (infile >> name)
		{
			infile >> score1 >> score2 >> score3;
			letter = letterGrade(score2);
			if (letter == userLetter)
				counter++;
		}
		break;
	case 3:
		while (infile >> name)
		{
			infile >> score1 >> score2 >> score3;
			letter = letterGrade(score3);
			if (letter == userLetter)
				counter++;
		}
		break;
	}
	infile.close();
	return counter;
}
	
