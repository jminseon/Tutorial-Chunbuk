#include <stdio.h>

struct student { //student ����ü
	char lastName[13]; //13����Ʈ
	int studentId; //4����Ʈ
	short grade; //2����Ʈ
}; //����ü�� ũ�� 19����Ʈ

int main()
{
	struct student pst; //typedef�� ��� struct �����

	printf("size of student = %d\n", sizeof(struct student));
	//student ����ü�� ũ�� ��� 24�� ���� �е��� �ϱ� ����!
	//lastName[13]-> [16] + studentId[4] + grade[2] -> [4] = [24]
	printf("size of int = %ld\n", sizeof(int)); //int�� ũ�� 4
	printf("size of short = %ld\n", sizeof(short)); //short�� ũ�� 2

    printf("\n[----- [���μ�] [2019038083] -----]\n");
	return 0;
}