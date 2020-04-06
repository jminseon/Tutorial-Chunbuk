#include <stdio.h>

#define MAX_SIZE 100 //100�� MAX_SIZE�� ����

float sum(float [], int); //sum�Լ�����
float input[MAX_SIZE], answer; //float�� �迭�� ���� ����
int i;

void main(void)
{
    for(i=0; i<MAX_SIZE; i++) //�ݺ��� i�� 0���� 99���� 100��
        input[i] = i; //�ε����� �� ����

    /* for checking call by reference */
    printf("address of input = %p\n", input); //input�� �ּ� ��� = ù��° �ε����� �ּ� ���
    

    answer = sum(input, MAX_SIZE); //sum�Լ� ȣ�� -> answer�� ����
    printf("The sum is : %f\n", answer); //answer�� ��� = sum�Լ��� tempsum��

    printf("\n[----- [���μ�] [2019038083] -----]\n");
}

float sum(float list[], int n) //sum�Լ�
{
    
    printf("value of list = %p\n", list); //list�� �� ��� = input�� �ּ�
    printf("address of list = %p\n\n", &list); //list�� �ּ� ���

    int i; //�ݺ����� ���� ����
    float tempsum = 0; //������� ������ ����

    for(i=0; i<n; i++) //i�� 0���� n-1���� = MAX_SIZE-1���� = 100-1����
        tempsum += list[i]; //list[i]�� ���� tempsum�� ���� ����

    return tempsum; //�ݺ����� ���� ���� tempsum�� �� ���� = 0���� 99���� ���� ��
}