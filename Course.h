#ifndef COURSE_DEFINED
#define COURSE_DEFINED

#include<iostream>

using namespace std;

class Course
{
private:
	int courseNum;
	int sectionNum;
public:
	Course() { courseNum = sectionNum = 0; }
	Course(const Course& other) { this->courseNum = other.courseNum; this->sectionNum = other.sectionNum; }
	Course(int course, int section) { courseNum = course; sectionNum = section; }
	Course& operator=(const Course& other)
	{
		if (this != &other)
		{
			courseNum = other.courseNum;
			sectionNum = other.sectionNum;
		}
		return *this;
	}
	bool operator<(const Course& other) { return this->sectionNum < other.sectionNum; }
	bool operator<=(const Course& other) { return this->sectionNum <= other.sectionNum; }
	bool operator>(const Course& other) { return this->sectionNum > other.sectionNum; }
	bool operator>=(const Course& other) { return this->sectionNum >= other.sectionNum; }
	bool operator==(const Course& other) { return this->sectionNum == other.sectionNum; }
	bool operator!=(const Course& other) { return this->sectionNum != other.sectionNum; }
	friend ostream& operator<<(ostream&, const Course&);
};
#endif