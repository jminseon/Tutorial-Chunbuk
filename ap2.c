#include <stdio.h>
#include <stdlib.h>

void main()
{
	int list[5];
	int *plist[5];

	list[0] = 10;
	list[1] = 11;

	plist[0] = (int*)malloc(sizeof(int)); //intũ���� ���� �޸� �Ҵ�

	printf("list[0] \t= %d\n", list[0]); //list[0]�� �� 10
	printf("address of list \t = %p\n", &list[0]); //list[0]�� �ּҰ�
	printf("address of list + 0 \t = %p\n", list+0); //list���� 0��ŭ ���������� �ּ� = list�� �ּ�
	printf("address of list + 1 \t = %p\n", list+1); //list���� 1��ŭ ���������� �ּ� = list�� �ּ�+4
	printf("address of list + 2 \t = %p\n", list+2); //list���� 2��ŭ ���������� �ּ� = list�� �ּ�+8
	printf("address of list + 3 \t = %p\n", list+3); //list���� 3��ŭ ���������� �ּ� = list�� �ּ�+12
	printf("address of list + 4 \t = %p\n", list+4); //list���� 4��ŭ ���������� �ּ� = list�� �ּ�+16
	printf("address of list[4] \t = %p\n", &list[4]); //list[4]�� �ּ� = list���� 4��ŭ ���������� �ּ�

    printf("\n[----- [���μ�] [2019038083] -----]\n");

	free(plist[0]); //���� �޸� ����
}
