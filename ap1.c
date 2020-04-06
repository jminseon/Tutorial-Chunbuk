#include <stdio.h>
#include <stdlib.h>

void main()
{
	int list[5]; //list배열 선언
	int *plist[5] = { NULL, }; //포인터배열 NULL로 초기화

	plist[0] = (int*)malloc(sizeof(int)); //int크기만큼 동적 메모리 할당

	list[0] = 1; //list의 0번째 인덱스 1로 초기화
	list[1] = 100; //list의 1번째 인덱스 100으로 초기화

	*plist[0] = 200; //*plist의 0번째 인덱스 200으로 초기화

	printf("value of list[0] = %d\n", list[0]); //list[0]의 값 1
	printf("address of list[0] = %p\n", &list[0]); //list[0]의 주소
	printf("value of list = %p\n", list); //list의 값 = list[0]의 값 :1
	printf("address of list (&list) = %p\n", &list); //list의 주소 = list[0]의 주소

	printf("------------------------------\n\n");
	printf("value of list[1] = %d\n", list[1]); //list[1]의 값 : 100
	printf("address of list[1] = %p\n", &list[1]); //list[1]의 주소 : list[0]의 주소값 +4
	printf("value of *(list+1) = %d\n", *(list + 1)); //list에 +1한 곳의 값 = list[1]의 값 : 100
	printf("address of list (&list) = %p\n", list + 1); //list+1의 주소 = list[1]의 주소

	printf("------------------------------\n\n");
	printf("value of *plist[0] = %d\n", *plist[0]); //*plist[0]의 값 : 200
	printf("&plist[0] = %p\n", &plist[0]); //배열의 첫번째 인덱스 주소값 = 배열의 주소값
	printf("&plist = %p\n", &plist); //&plist : 배열의 주소값
	printf("plist = %p\n", plist); //배열이름 = 배열의 주소값
	printf("plist[0] = %p\n", plist[0]); //plist[0] : 배열의 주소값
	printf("plist[1] = %p\n", plist[1]); //NULL값
	printf("plist[2] = %p\n", plist[2]); //NULL값
	printf("plist[3] = %p\n", plist[3]); //NULL값
	printf("plist[4] = %p\n", plist[4]); //NULL값

	free(plist[0]); //malloc 해제 동적메모리 할당 해제

    printf("\n[----- [전민선] [2019038083] -----]\n");

}