#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int **x; //���������ͺ���

    printf("sizeof(x) = %ld\n", sizeof(x)); //*x�� �ּҸ� �����ϱ� ������ 4
    printf("sizeof(*x) = %ld\n", sizeof(*x)); //**x�� �ּҸ� �����ϱ� ������ 4
    printf("sizeof(**x) = %ld\n", sizeof(**x)); //���� �����ϱ� ������ 4 int��
    //vscode������ 32��Ʈ���� 4����Ʈ�� ��µǰ�, ������������ 64��Ʈ���� 8����Ʈ�� ��µ�
   printf("\n[----- [���μ�] [2019038083] -----]\n");
    return 0;
}