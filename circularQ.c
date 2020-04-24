#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 4 //����ť������ �ִ�ũ�⸦ 4�� ����

typedef char element; //char���� ���� element
typedef struct {
	element queue[MAX_QUEUE_SIZE]; //ť�迭
	int front, rear; //����Ʈ, ����
}QueueType; //����ü ��Ī QueueType


QueueType *createQueue(); //����ü ������ ť���� �Լ�
int isEmpty(QueueType *cQ); //ť�� ������� Ȯ���ϴ� �Լ�
int isFull(QueueType *cQ); //ť�� ��á���� Ȯ���ϴ� �Լ�
void enQueue(QueueType *cQ, element item); //�߰��ϴ� �Լ�
void deQueue(QueueType *cQ, element* item); //�����ϴ� �Լ�
void printQ(QueueType *cQ); //����ϴ� �Լ�
void debugQ(QueueType *cQ); //������ϴ� �Լ�

element getElement(); //char��/ ������ ��� �Լ�


int main(void)
{
	QueueType *cQ = createQueue(); //ť �����ؼ� ����ü �����Ϳ� ����
	element data; //char�� ���� data ����

	char command; //char�� �������� ����Է¿�

	printf("\n====== [���μ�] [2019038083] ======\n");

	do { //do while��
		printf("\n\n\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command �� �Է�

		switch (command) {
		case 'i': case 'I': //command�� i�� I�� ���� �޴� �Լ��� ���� �Լ� ����
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D': //command�� d�� D�� ���� �Լ� ����
			deQueue(cQ, &data);
			break;
		case 'p': case 'P': //command�� p�� P�� ����Ʈ �Լ� ����
			printQ(cQ);
			break;
		case 'b': case 'B': //command�� b�� B�� ����� �Լ� ����
			debugQ(cQ);
			break;
		case 'q': case 'Q': //comand�� q�� Q�� ����
			break;
		default: //���� �͵��� ���� �� �ƴϸ� �������
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q'); //command�� q�� Q�� �ƴ� ������

	return 1;
}


QueueType *createQueue() //����ť ���� �Լ�
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType)); //�����Ҵ�
	cQ->front = 0; //���� = 0���� �ʱ�ȭ
	cQ->rear = 0; //�� = 0���� �ʱ�ȭ
	return cQ; //������ ����
}

element getElement() //���� ���� �Է� �Լ�
{
	element item; //char�� item����
	printf("Input element = ");
	scanf(" %c", &item); //���� �� �Է��ϰ�
	return item; //�� ���� ����
}


int isEmpty(QueueType *cQ)
{
	if (cQ->front == cQ->rear){ //���۰� ���� ������ �������
	    printf("\n====== Empty ======\n");
		return -1; //��������� -1�� ����
	}
}


int isFull(QueueType *cQ)
{
	if ((cQ->front) == (cQ->rear + 1) % MAX_QUEUE_SIZE){ //���� �ִ������-1�� ������ ����
	    printf("\n====== Full ======\n");
		return -1; //������ -1�� ����
	}
}


void enQueue(QueueType *cQ, element item)
{
	if (isFull(cQ) != -1){ //-1�� �ƴϸ�
		cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
		cQ->queue[cQ->rear] = item;//item�� ���� ����ť�� �����ؼ� �����ؾ���
	}
}


void deQueue(QueueType *cQ, element *item)
{
	if (isEmpty(cQ) != -1){ //-1�� �ƴϸ�
		cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
		cQ->queue[cQ->front-1] = '-'; //�����ڸ��� - �� �ֱ�
	}
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE; //first = front
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE; //last = rear

	printf("Circular Queue : [");

	i = first;
	while (i != last) { //i�� ���� rear�� �ƴ� ����
		printf("%3c", cQ->queue[i]); //����ť�������
		i = (i + 1) % MAX_QUEUE_SIZE; //i����
	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{
	printf("\n---DEBUG\n");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) //�ݺ���
	{
		if (i == cQ->front) { //i�� ���̶� front�� ���� ������ �� ��ġ�� �˷���
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]); //i��° �ε����� �� �� ���

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); //front�� rear�� ���� �� �� �ְ� ���
}