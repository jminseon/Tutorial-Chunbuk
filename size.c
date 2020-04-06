#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int **x; //이중포인터변수

    printf("sizeof(x) = %ld\n", sizeof(x)); //*x의 주소를 저장하기 때문에 4
    printf("sizeof(*x) = %ld\n", sizeof(*x)); //**x의 주소를 저장하기 때문에 4
    printf("sizeof(**x) = %ld\n", sizeof(**x)); //값을 저장하기 때문에 4 int형
    //vscode에서는 32비트여서 4바이트로 출력되고, 리눅스에서는 64비트여서 8바이트로 출력됨
   printf("\n[----- [전민선] [2019038083] -----]\n");
    return 0;
}