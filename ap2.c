#include <stdio.h>
#include <stdlib.h>

void main()
{
	int list[5];
	int *plist[5];

	list[0] = 10;
	list[1] = 11;

	plist[0] = (int*)malloc(sizeof(int)); //int크기의 동적 메모리 할당

	printf("list[0] \t= %d\n", list[0]); //list[0]의 값 10
	printf("address of list \t = %p\n", &list[0]); //list[0]의 주소값
	printf("address of list + 0 \t = %p\n", list+0); //list에서 0만큼 떨어진곳의 주소 = list의 주소
	printf("address of list + 1 \t = %p\n", list+1); //list에서 1만큼 떨어진곳의 주소 = list의 주소+4
	printf("address of list + 2 \t = %p\n", list+2); //list에서 2만큼 떨어진곳의 주소 = list의 주소+8
	printf("address of list + 3 \t = %p\n", list+3); //list에서 3만큼 떨어진곳의 주소 = list의 주소+12
	printf("address of list + 4 \t = %p\n", list+4); //list에서 4만큼 떨어진곳의 주소 = list의 주소+16
	printf("address of list[4] \t = %p\n", &list[4]); //list[4]의 주소 = list에서 4만큼 떨어진곳의 주소

    printf("\n[----- [전민선] [2019038083] -----]\n");

	free(plist[0]); //동적 메모리 해제
}
