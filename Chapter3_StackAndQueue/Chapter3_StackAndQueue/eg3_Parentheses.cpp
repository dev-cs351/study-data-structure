#include "eg1_ArrayStack.cpp"

bool checkMatching(const char* filename) {
	/*
	FILE* fp = fopen(filename, "r"); // FILE Ÿ�� �������� ������ fp
	if (fp == NULL)
		error("Error: ������ �������� �ʽ��ϴ�.\n");
	*/
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, filename, "r"); // fp�� filename�� �ּҸ� �����ϰ�, �Լ� �۵� ��� ��ȯ
	if (err != 0)
		error("Error: ������ �������� �ʽ��ϴ�.\n");

	int nLine = 1; // ���� ���� ��
	int nChar = 0; // ���� ���� ��
	ArrayStack<char> paStack; // paStack: parentheses stack
	char ch, prev;
	bool isString = false; // ���� ����ǥ
	bool isChar = false; // ū ����ǥ
	bool isAnnotation = false;
	bool isStarAnnotation = false;

	while ((ch = getc(fp)) != EOF) { // getc(&file): ���Ͽ��� ���� �ϳ��� �о���� �Լ�, EOF: End Of File
		if (ch == '\n') nLine++;
		nChar++;

		if (ch == '\\') {
			char nextCh = getc(fp);
			if (nextCh == '\'' || nextCh == '\"' || nextCh == '\\')
				continue;
			else
				ungetc(nextCh, fp);
		}

		if (ch == '\'' && !isChar && !isAnnotation && !isStarAnnotation) {
			isString = !isString;
			continue;
		}
		if (ch == '\"' && !isString && !isAnnotation && !isStarAnnotation) {
			isChar = !isChar;
			continue;
		}

		if (isAnnotation) {
			if (ch == '\n') 
				isAnnotation = false; 
			continue;  
		}

		if (isStarAnnotation) {
			char nextCh = getc(fp);
			if (ch == '*' && nextCh == '/') {
				isStarAnnotation = false;
				continue;
			}
			else
				ungetc(nextCh, fp);
		}

		if (ch == '/') {
			char nextCh = getc(fp);
			if (nextCh == '/') {
				isAnnotation = true;
				continue;
			}
			else
				ungetc(nextCh, fp);
		}

		if (ch == '/') {
			char nextCh = getc(fp);
			if (nextCh == '*') {
				isStarAnnotation = true;
				continue;
			}
			else
				ungetc(nextCh, fp);
		}

		if (!isString && !isChar && !isAnnotation && !isStarAnnotation) {
			if (ch == '(' || ch == '{' || ch == '[')
				paStack.push(ch);
			else if (ch == ')' || ch == '}' || ch == ']') {
				if (paStack.isEmpty()) {
					printf("Error: �ݴ� ��ȣ�� ���� ��ȣ ���� ���� (����: %d, ����: %d)\n", nLine, nChar);
					fclose(fp);
					return false;
				}
				prev = paStack.pop();
				if ((prev == '(' && ch != ')') ||
					(prev == '{' && ch != '}') ||
					(prev == '[' && ch != ']')) {
					printf("Error: ��ȣ ����ġ (����: %d, ����: %d)\n", nLine, nChar);
					fclose(fp);
					return false;
				}
			}
		}
	}

	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if (!paStack.isEmpty()) {
		printf("Error: ���� �߰�(���μ�: %d, ���ڼ�: %d)\n\n", nLine, nChar);
		paStack.display();
	}
	else
		printf("OK: ��ȣ �ݱ� ����(���μ�: %d, ���ڼ�: %d)\n\n", nLine, nChar);
	return paStack.isEmpty();
}

int main() {
	checkMatching(R"(C:\Users\Chungsu\source\repos\dev-cs351\study-data-structure\Chapter3_StackAndQueue\Chapter3_StackAndQueue\eg1_ArrayStack.cpp)");
	checkMatching(R"(C:\Users\Chungsu\source\repos\dev-cs351\study-data-structure\Chapter3_StackAndQueue\Chapter3_StackAndQueue\eg3_Parentheses.cpp)");

	return 0;
}
