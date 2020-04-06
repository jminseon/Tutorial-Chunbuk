#include <stdio.h>

void print1 (int *ptr, int rows); //print1 함수 선언

int main()
{
    int one[]={0,1,2,3,4}; //one배열 01234로 초기화 5크기의 배열

    printf("one = %p\n", one); //배열의 이름 = 배열의 주소
    printf("&one = %p\n", &one); //배열의 주소
    printf("&one[0] = %p\n", &one[0]); //배열의 첫번째 인덱스 주소 = 배열의 주소 
    printf("\n");

    print1(&one[0], 5); //print1 함수 호출 one[0]의 주소값과 5를 넘김

    printf("\n[----- [전민선] [2019038083] ----]\n");

    return 0;
}

void print1(int *ptr, int rows)
{//print out a one-dimensional array using a pointer
    int i;
    printf("Address \t Contents\n");

    for (i=0; i<rows; i++) //i=0부터 row-1까지 반복 = 5-1까지 반복
        printf("%p \t %5d\n", ptr+i, *(ptr+i)); //주소는 one의 주소에서 4씩 증가하고 값은 01234로 바뀜
    printf("\n");
}