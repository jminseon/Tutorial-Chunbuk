#include <stdio.h>
#include <stdlib.h>

void main()
{
	int list[5]; //list�迭 ����
	int *plist[5] = { NULL, }; //�����͹迭 NULL�� �ʱ�ȭ

	plist[0] = (int*)malloc(sizeof(int)); //intũ�⸸ŭ ���� �޸� �Ҵ�

	list[0] = 1; //list�� 0��° �ε��� 1�� �ʱ�ȭ
	list[1] = 100; //list�� 1��° �ε��� 100���� �ʱ�ȭ

	*plist[0] = 200; //*plist�� 0��° �ε��� 200���� �ʱ�ȭ

	printf("value of list[0] = %d\n", list[0]); //list[0]�� �� 1
	printf("address of list[0] = %p\n", &list[0]); //list[0]�� �ּ�
	printf("value of list = %p\n", list); //list�� �� = list[0]�� �� :1
	printf("address of list (&list) = %p\n", &list); //list�� �ּ� = list[0]�� �ּ�

	printf("------------------------------\n\n");
	printf("value of list[1] = %d\n", list[1]); //list[1]�� �� : 100
	printf("address of list[1] = %p\n", &list[1]); //list[1]�� �ּ� : list[0]�� �ּҰ� +4
	printf("value of *(list+1) = %d\n", *(list + 1)); //list�� +1�� ���� �� = list[1]�� �� : 100
	printf("address of list (&list) = %p\n", list + 1); //list+1�� �ּ� = list[1]�� �ּ�

	printf("------------------------------\n\n");
	printf("value of *plist[0] = %d\n", *plist[0]); //*plist[0]�� �� : 200
	printf("&plist[0] = %p\n", &plist[0]); //�迭�� ù��° �ε��� �ּҰ� = �迭�� �ּҰ�
	printf("&plist = %p\n", &plist); //&plist : �迭�� �ּҰ�
	printf("plist = %p\n", plist); //�迭�̸� = �迭�� �ּҰ�
	printf("plist[0] = %p\n", plist[0]); //plist[0] : �迭�� �ּҰ�
	printf("plist[1] = %p\n", plist[1]); //NULL��
	printf("plist[2] = %p\n", plist[2]); //NULL��
	printf("plist[3] = %p\n", plist[3]); //NULL��
	printf("plist[4] = %p\n", plist[4]); //NULL��

	free(plist[0]); //malloc ���� �����޸� �Ҵ� ����

    printf("\n[----- [���μ�] [2019038083] -----]\n");

}