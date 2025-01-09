#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_STRING = 100;

class Student
{
private:
	int id;
	char name[MAX_STRING];
public:
	Student(int i = 0, const char* n = "아무개") {
		set(i, n);
	}
	~Student() {}
	void set(int i, const char* n) {
		id = i;
		strcpy_s(name, n);
	}
	void display() {
		printf("학번: %d, 이름:%-10s", id, name);
	}
};