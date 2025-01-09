#include "eg5_Student.h"

class Node : public Student {
	Node* link; // ���� ��带 ����ų ������ ����
public:
	Node( int id=0, const char* name="�ƹ���") // ���� id, name�� ��� ������ ����
		: Student(id, name) { link = NULL; } // �ش� ��� ������ ������ Student ��ü�� �̷���� �ִ�.
	~Node(void) {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};