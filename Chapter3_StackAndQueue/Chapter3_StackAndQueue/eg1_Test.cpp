#include "eg1_ArrayStack.cpp"

int main() {
	ArrayStack<int> testStack; // ArrayStack testStack;
	for (int i = 1; i < 10; i++)
		testStack.push(i);
	testStack.display();
	testStack.pop();
	testStack.pop();
	testStack.display();

	return 0;
}
