#include <cstdio>

int main(void) {
	char* str; // ������ ���� str ����
	int size = 1000;
	str = new char[size]; // ������ new�� ����Ͽ� ������ ������ 1���� �迭�� �������� �Ҵ�
	if (str == NULL)
		printf("Insufficient memory available\n");
	else {
		printf("Allocated 1000 bytes\n");
		printf("%d\n", str); // ������ ������ �Ҵ�� 1���� �迭�� �޸� �ּ� ���
		printf("%d\n", &str); // ������ ������ �޸� �ּ� ���
		
		delete[] str; // ������ delete�� ����Ͽ� �Ҵ�Ǿ��� �޸� �ݳ�
		
		printf("Memory freed\n");
		printf("%d\n", str);  // '33059'�� ������ �ּҰ� ��µ�. 
							  // �޸𸮰� �ݳ��� �� ������ ������ ����Ű�� ��ü�� �ʱ�ȭ �Ǵ� �ּҰ� ���� ������ ����.
		printf("%d\n", &str); // 12��� ������ �ּҰ� ��µ�.
	}
}