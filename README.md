# Tutorial-Chunbuk
for the Tutorial

#include <stdio.h>

int main(void)
{
    char charType; //char형 변수 charType 선언
    int integerType; //int형 변수 integerType 선언
    float floatType; //float형 변수 floatType 선언
    double doubleType; //double형 변수 doubleType 선언

     //변수 크기 출력 자료형에 따라 변수의 크기가 결정됨 (변수의 크기 = 자료형의 크기)
    printf("Size of char : %ld bytes\n", sizeof(charType)); //1바이트
    printf("Size of int : %ld bytes\n", sizeof(integerType)); //4바이트
    printf("Size of float : %ld bytes\n", sizeof(floatType)); //4바이트
    printf("Size of double : %ld bytes\n", sizeof(doubleType)); //8바이트
    
    printf("------------------------------\n");

     //자료형 크기 출력
    printf("Size of char : %ld bytes\n", sizeof(char)); //1바이트
    printf("Size of int : %ld bytes\n", sizeof(int)); //4바이트
    printf("Size of float : %ld bytes\n", sizeof(float)); //4바이트
    printf("Size of double : %ld bytes\n", sizeof(double)); //8바이트
    
    printf("------------------------------\n");

    //포인터 자료형 크기 출력 모두 4바이트(32비트)
    printf("Size of char* : %ld bytes\n", sizeof(char*));
    printf("Size of int* : %ld bytes\n", sizeof(int*));
    printf("Size of float* : %ld bytes\n", sizeof(float*));
    printf("Size of double* : %ld bytes\n", sizeof(double*));
    
    printf("\n[---- [전민선] [2019038083] ----]\n");

    return 0;
}





-------------------------------------------------------------------------------






#include <stdio.h>

int main(void)
{
    int i; //int형 변수 i
    int *ptr; //int형 포인터 변수 ptr
    int **dptr; //int형 이중포인터 변수 dptr
    i = 1234; //i=1234로 초기화
    
    printf("[checking values before ptr = &i] \n"); //ptr=&i 하기 전 결과확인
    printf("value of i == %d\n", i); //i의 값 출력 1234
    printf("address of i == %p\n", &i); //i의 주소값 출력 
    printf("value of ptr == %p\n", ptr); //ptr의 값 출력 
    printf("address of ptr == %p\n", &ptr); //ptr의 주소값 출력 
    
    ptr = &i; /* ptr is now holding the address of i */    //ptr을 i의 주소값으로 초기화
    
    printf("\n[checking values after ptr = &i] \n"); //ptr=&i 한 후 결과확인
    printf("value of i == %d\n", i); //i의 값 출력 1234
    printf("address of i == %p\n", &i); //i의 주소값 출력 
    printf("value of ptr == %p\n", ptr); //ptr의 값 출력 = i의 주소값 출력 
    printf("address of ptr == %p\n", &ptr); //ptr의 주소값 출력 
    printf("value of *ptr == %d\n", *ptr); //ptr포인터의 값 출력 = i의 값 출력 1234

    dptr = &ptr; /* dptr is now holding the address of ptr */
    //dptr을 ptr의 주소값으로 초기화 -> i의 주소값으로 초기화

    printf("\n[checking values after dptr = &ptr] \n"); //dptr = &ptr 한 후 결과확인
    printf("value of i == %d\n", i); //i의 값 출력 1234
    printf("address of i == %p\n", &i); //i의 주소값 출력 
    printf("value of ptr == %p\n", ptr); //ptr의 값 출력 = i의 주소값 출력 
    printf("address of ptr == %p\n", &ptr); //ptr의 주소값 출력 
    printf("value of *ptr == %d\n", *ptr); //ptr포인터의 값 출력 = i의 값 출력 1234
    printf("value of dptr == %p\n", dptr); //dptr의 값 출력 = ptr의 주소값 출력 
    printf("address of dptr == %p\n", &dptr); //dptr의 주소값 출력 
    printf("value of *dptr == %p\n", *dptr); //dptr포인터의 값 출력 = ptr의 값 출력 = i의 주소값 출력 
    printf("value of **dptr == %d\n", **dptr); //이중포인터로 i의 값에 접근 1234

    *ptr = 7777; /* changing the value of *ptr */    //포인터변수 ptr의 값을 7777로 바꿈

    printf("\n[after *ptr = 7777] \n"); //*ptr = 7777 한 후 결과 확인
    printf("value of i == %d\n", i); //i의 값 출력 7777 *ptr이 메모리주소에 접근해서 값을 바꿈
    printf("value of *ptr == %d\n", *ptr); //*ptr출력
    printf("value of **dptr == %d\n", **dptr); //*dptr이 *ptr을 가리키고 i의 값 출력

    **dptr = 8888; /* changing the value of **dptr */    //역참조 두번으로 i의 메모리주소값에 접근함

    printf("\n[after **dptr = 8888] \n"); //**dptr = 8888 한 후 결과 확인
    printf("value of i == %d\n", i); //i의 값 출력 8888 *dptr이 메모리주소에 접근해서 값을 바꿈
    printf("value of *ptr == %d\n", *ptr); //*ptr의 값 출력
    printf("value of **dptr == %d\n", **dptr); //**dptr의 값 출력
    
    printf("\n[---- [전민선] [2019038083] ----]\n");

    return 0;
}
