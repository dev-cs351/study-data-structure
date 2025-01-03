#include <cstdio>
#include <cstring> // 문자열 처리 함수 제공. 

class Car {
protected: 
	int speed;
	char name[80];
public:
	int gear;

	Car(int s, const char* n, int g) : // const char*: 문자열 내용을 변경할 수 없다.
		speed(s), gear(g) {
		strcpy_s(name, n); // 대상 문자열의 크기를 인수로 받는 strcpy, 버퍼 오버플로우를 방지한다.
	}
	~Car() {}
	
	void changeGear(int g = 4) {
		gear = g;
	}

	void speedUp() {
		speed += 5;
	}

	void display() {
		printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed);
	}

	void whereAmI() { printf("객체 주소 = %p\n", this); } // 포인터의 형식 지정자는 %p, 16진수
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