#include <stdio.h>

void print1 (int *ptr, int rows); //print1 �Լ� ����

int main()
{
    int one[]={0,1,2,3,4}; //one�迭 01234�� �ʱ�ȭ 5ũ���� �迭

    printf("one = %p\n", one); //�迭�� �̸� = �迭�� �ּ�
    printf("&one = %p\n", &one); //�迭�� �ּ�
    printf("&one[0] = %p\n", &one[0]); //�迭�� ù��° �ε��� �ּ� = �迭�� �ּ� 
    printf("\n");

    print1(&one[0], 5); //print1 �Լ� ȣ�� one[0]�� �ּҰ��� 5�� �ѱ�

    printf("\n[----- [���μ�] [2019038083] ----]\n");

    return 0;
}

void print1(int *ptr, int rows)
{//print out a one-dimensional array using a pointer
    int i;
    printf("Address \t Contents\n");

    for (i=0; i<rows; i++) //i=0���� row-1���� �ݺ� = 5-1���� �ݺ�
        printf("%p \t %5d\n", ptr+i, *(ptr+i)); //�ּҴ� one�� �ּҿ��� 4�� �����ϰ� ���� 01234�� �ٲ�
    printf("\n");
}