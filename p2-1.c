#include <stdio.h>

#define MAX_SIZE 100 //100을 MAX_SIZE로 정의

float sum(float [], int); //sum함수선언
float input[MAX_SIZE], answer; //float형 배열과 변수 선언
int i;

void main(void)
{
    for(i=0; i<MAX_SIZE; i++) //반복문 i가 0부터 99까지 100번
        input[i] = i; //인덱스에 값 저장

    /* for checking call by reference */
    printf("address of input = %p\n", input); //input의 주소 출력 = 첫번째 인덱스의 주소 출력
    

    answer = sum(input, MAX_SIZE); //sum함수 호출 -> answer에 저장
    printf("The sum is : %f\n", answer); //answer값 출력 = sum함수의 tempsum값

    printf("\n[----- [전민선] [2019038083] -----]\n");
}

float sum(float list[], int n) //sum함수
{
    
    printf("value of list = %p\n", list); //list의 값 출력 = input의 주소
    printf("address of list = %p\n\n", &list); //list의 주소 출력

    int i; //반복문을 위한 변수
    float tempsum = 0; //결과값을 저장할 변수

    for(i=0; i<n; i++) //i가 0부터 n-1까지 = MAX_SIZE-1까지 = 100-1까지
        tempsum += list[i]; //list[i]의 값을 tempsum의 값에 저장

    return tempsum; //반복문이 끝난 다음 tempsum의 값 리턴 = 0부터 99까지 더한 값
}