#include "eg1_ArrayStack.cpp"

bool checkMatching(const char* filename) {
	/*
	FILE* fp = fopen(filename, "r"); // FILE 타입 데이터의 포인터 fp
	if (fp == NULL)
		error("Error: 파일이 존재하지 않습니다.\n");
	*/
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, filename, "r"); // fp에 filename의 주소를 저장하고, 함수 작동 결과 반환
	if (err != 0)
		error("Error: 파일이 존재하지 않습니다.\n");

	int nLine = 1; // 읽은 라인 수
	int nChar = 0; // 읽은 문자 수
	ArrayStack<char> paStack; // paStack: parentheses stack
	char ch, prev;
	bool isString = false; // 작은 따옴표
	bool isChar = false; // 큰 따옴표
	bool isAnnotation = false;
	bool isStarAnnotation = false;

	while ((ch = getc(fp)) != EOF) { // getc(&file): 파일에서 문자 하나를 읽어오는 함수, EOF: End Of File
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
					printf("Error: 닫는 괄호가 여는 괄호 없이 등장 (라인: %d, 문자: %d)\n", nLine, nChar);
					fclose(fp);
					return false;
				}
				prev = paStack.pop();
				if ((prev == '(' && ch != ')') ||
					(prev == '{' && ch != '}') ||
					(prev == '[' && ch != ']')) {
					printf("Error: 괄호 불일치 (라인: %d, 문자: %d)\n", nLine, nChar);
					fclose(fp);
					return false;
				}
			}
		}
	}

	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename);
	if (!paStack.isEmpty()) {
		printf("Error: 문제 발견(라인수: %d, 문자수: %d)\n\n", nLine, nChar);
		paStack.display();
	}
	else
		printf("OK: 괄호 닫기 정상(라인수: %d, 문자수: %d)\n\n", nLine, nChar);
	return paStack.isEmpty();
}

int main() {
	checkMatching(R"(C:\Users\Chungsu\source\repos\dev-cs351\study-data-structure\Chapter3_StackAndQueue\Chapter3_StackAndQueue\eg1_ArrayStack.cpp)");
	checkMatching(R"(C:\Users\Chungsu\source\repos\dev-cs351\study-data-structure\Chapter3_StackAndQueue\Chapter3_StackAndQueue\eg3_Parentheses.cpp)");

	return 0;
}
