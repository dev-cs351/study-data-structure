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
	Student(int i = 0, const char* n = "�ƹ���") {
		set(i, n);
	}
	~Student() {}
	void set(int i, const char* n) {
		id = i;
		strcpy_s(name, n);
	}
	void display() {
		printf("�й�: %d, �̸�:%-10s", id, name);
	}
};