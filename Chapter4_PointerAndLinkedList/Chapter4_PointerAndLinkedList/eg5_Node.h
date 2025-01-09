#include "eg5_Student.h"

class Node : public Student {
	Node* link; // 다음 노드를 가르킬 포인터 변수
public:
	Node( int id=0, const char* name="아무개") // 노드는 id, name를 멤버 변수로 가짐
		: Student(id, name) { link = NULL; } // 해당 멤버 변수를 가지는 Student 객체로 이루어져 있다.
	~Node(void) {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};