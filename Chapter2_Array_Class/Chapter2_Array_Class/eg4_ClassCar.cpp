#include <cstdio>
#include <cstring> // ���ڿ� ó�� �Լ� ����. 

class Car {
protected: 
	int speed;
	char name[80];
public:
	int gear;

	Car(int s, const char* n, int g) : // const char*: ���ڿ� ������ ������ �� ����.
		speed(s), gear(g) {
		strcpy_s(name, n); // ��� ���ڿ��� ũ�⸦ �μ��� �޴� strcpy, ���� �����÷ο츦 �����Ѵ�.
	}
	~Car() {}
	
	void changeGear(int g = 4) {
		gear = g;
	}

	void speedUp() {
		speed += 5;
	}

	void display() {
		printf("[%s] : ���=%d�� �ӵ�=%dkmph\n", name, gear, speed);
	}

	void whereAmI() { printf("��ü �ּ� = %p\n", this); } // �������� ���� �����ڴ� %p, 16����
};

class SportsCar : public Car
{
public:
	bool bTurbo;
	void setTurbo(bool bTur) { bTurbo = bTur; }
	void speedUp() {
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};
/*
int main() {
	Car mycar(10, "my car", 5);
	mycar.display();
	mycar.whereAmI();
}
*/