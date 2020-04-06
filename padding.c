#include <stdio.h>

struct student { //student 구조체
	char lastName[13]; //13바이트
	int studentId; //4바이트
	short grade; //2바이트
}; //구조체의 크기 19바이트

int main()
{
	struct student pst; //typedef가 없어서 struct 써야함

	printf("size of student = %d\n", sizeof(struct student));
	//student 구조체의 크기 출력 24가 나옴 패딩을 하기 때문!
	//lastName[13]-> [16] + studentId[4] + grade[2] -> [4] = [24]
	printf("size of int = %ld\n", sizeof(int)); //int의 크기 4
	printf("size of short = %ld\n", sizeof(short)); //short의 크기 2

    printf("\n[----- [전민선] [2019038083] -----]\n");
	return 0;
}