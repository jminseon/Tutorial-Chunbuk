#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 4 //원형큐스택의 최대크기를 4로 고정

typedef char element; //char형의 별명 element
typedef struct {
	element queue[MAX_QUEUE_SIZE]; //큐배열
	int front, rear; //프런트, 리어
}QueueType; //구조체 별칭 QueueType


QueueType *createQueue(); //구조체 포인터 큐생성 함수
int isEmpty(QueueType *cQ); //큐가 비었는지 확인하는 함수
int isFull(QueueType *cQ); //큐가 꽉찼는지 확인하는 함수
void enQueue(QueueType *cQ, element item); //추가하는 함수
void deQueue(QueueType *cQ, element* item); //삭제하는 함수
void printQ(QueueType *cQ); //출력하는 함수
void debugQ(QueueType *cQ); //디버그하는 함수

element getElement(); //char형/ 성분을 얻는 함수


int main(void)
{
	QueueType *cQ = createQueue(); //큐 생성해서 구조체 포인터에 저장
	element data; //char형 변수 data 선언

	char command; //char형 지역변수 명령입력용

	printf("\n====== [전민선] [2019038083] ======\n");

	do { //do while문
		printf("\n\n\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command 값 입력

		switch (command) {
		case 'i': case 'I': //command가 i나 I면 성분 받는 함수와 삽입 함수 실행
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D': //command가 d나 D면 삭제 함수 실행
			deQueue(cQ, &data);
			break;
		case 'p': case 'P': //command가 p나 P면 프린트 함수 실행
			printQ(cQ);
			break;
		case 'b': case 'B': //command가 b나 B면 디버그 함수 실행
			debugQ(cQ);
			break;
		case 'q': case 'Q': //comand가 q나 Q면 종료
			break;
		default: //위에 것들이 전부 다 아니면 문구출력
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q'); //command가 q나 Q가 아닐 때까지

	return 1;
}


QueueType *createQueue() //원형큐 생성 함수
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType)); //동적할당
	cQ->front = 0; //시작 = 0으로 초기화
	cQ->rear = 0; //끝 = 0으로 초기화
	return cQ; //포인터 리턴
}

element getElement() //넣을 성분 입력 함수
{
	element item; //char형 item변수
	printf("Input element = ");
	scanf(" %c", &item); //성분 값 입력하고
	return item; //그 값을 리턴
}


int isEmpty(QueueType *cQ)
{
	if (cQ->front == cQ->rear){ //시작과 끝이 같으면 비어있음
	    printf("\n====== Empty ======\n");
		return -1; //비어있으면 -1을 리턴
	}
}


int isFull(QueueType *cQ)
{
	if ((cQ->front) == (cQ->rear + 1) % MAX_QUEUE_SIZE){ //끝이 최대사이즈-1과 같으면 꽉참
	    printf("\n====== Full ======\n");
		return -1; //꽉차면 -1을 리턴
	}
}


void enQueue(QueueType *cQ, element item)
{
	if (isFull(cQ) != -1){ //-1이 아니면
		cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
		cQ->queue[cQ->rear] = item;//item의 값을 원형큐에 접근해서 저장해야해
	}
}


void deQueue(QueueType *cQ, element *item)
{
	if (isEmpty(cQ) != -1){ //-1이 아니면
		cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
		cQ->queue[cQ->front-1] = '-'; //지운자리에 - 값 넣기
	}
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1) % MAX_QUEUE_SIZE; //first = front
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE; //last = rear

	printf("Circular Queue : [");

	i = first;
	while (i != last) { //i의 값이 rear이 아닐 동안
		printf("%3c", cQ->queue[i]); //원형큐성분출력
		i = (i + 1) % MAX_QUEUE_SIZE; //i증가
	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{
	printf("\n---DEBUG\n");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) //반복문
	{
		if (i == cQ->front) { //i의 값이랑 front의 값이 같으면 그 위치를 알려줌
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]); //i번째 인덱스와 그 값 출력

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); //front와 rear가 뭔지 알 수 있게 출력
}