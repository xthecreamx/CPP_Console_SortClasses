/*
DAVIS KIEU
ASSIGNMENT #3
DESCRIPTION: A project that involves sorting a set of classes by section number. This project revolves around enabling the user to select different 
sorting methods to sort the classes by section number.
*/

#include"Course.h"
#include"Selection.h"
#include"Bubble.h"
#include"Insertion.h"
#include"Heap.h"
#include"Quick.h"
#include"Merge.h"
#include<sstream>
#include<fstream>
#include<string>

using namespace std;

char selection();
void printValues(Course[], int);
int loadValues(Course[],string);
ostream& operator<<(ostream&, const Course&);

const string FILE_NAME = "classes.txt";
const int MAX_VALUES = 10;

int main()
{
	//I left array as a collection of Course object values , but a array of Course object pointers wouldve resulted in more efficent sorts
	Course * values = new Course[MAX_VALUES];

	int elements = loadValues(values, FILE_NAME);

	do
	{
		Course copy[MAX_VALUES];

		for (int index = 0; index < elements; index++)
			copy[index] = values[index];

		switch (selection())
		{
		case 'a': {}
		case 'A':
		{
			SelectionSort<Course>(copy, elements);
			printValues(copy, elements);
			break; 
		}
		case 'b': {}
		case 'B':
		{
			BubbleSort<Course>(copy, elements);
			printValues(copy, elements);
			break; 
		}
		case 'c': {}
		case 'C':
		{
			InsertionSort(copy, elements);
			printValues(copy, elements);
			break; 
		}
		case 'd': {}
		case 'D':
		{
			HeapSort<Course>(copy, elements);
			printValues(copy, elements);
			break; 
		}
		case 'e': {}
		case 'E':
		{
			QuickSort<Course>(copy, 0, elements - 1);
			printValues(copy, elements);
			break; 
		}
		case 'f': {}
		case 'F':
		{
			MergeSort<Course>(copy, 0, elements - 1);
			printValues(copy,elements);
			break;
		}
		case 'g': {}
		case 'G':
			return 0;
		default:
			cout << "Invalid Input." << endl;
		}

	} while (1);
}

ostream& operator<<(ostream& out, const Course& course)
{
	out << "Course # " << course.courseNum << " Section # " << course.sectionNum << endl;
	return out;
}

int loadValues(Course values[],string fileName)
{
	ifstream input(fileName);
	string line;

	int section, course, index = 0;

	if (input.is_open())
	{
		while (!input.eof() && index != MAX_VALUES)
		{
			getline(input,line);
			stringstream ss(line);

			ss >> course >> section;
			values[index++] = *(new Course(course, section));
		}
	}

	input.close();
	return index;
}
char selection()
{
	char choice;

	cout << "---- SORTING METHODS ----" << endl;
	cout << "A.Selection\n"
		<< "B.Bubble\n"
		<< "C.Insertion\n"
		<< "D.Heap\n"
		<< "E.Quick\n"
		<< "F.Merge\n"
		<< "G.Exit\n";
	
	cin.get(choice);
	cin.ignore();

	system("cls");

	return choice;
}
void printValues(Course values[],int max)
{
	for (int index = 0; index < max; index++)
		cout << values[index];
}
