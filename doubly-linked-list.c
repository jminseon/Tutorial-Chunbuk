#include<stdio.h>
#include<stdlib.h>
 //* 필요한 헤더파일 추가 if necessary *


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

//* 함수 리스트 *

//* note: initialize는 이중포인터를 매개변수로 받음
//		 singly-linked-list의 initialize와 차이점을 이해 할것 *
int initialize(headNode** h);

//* note: freeList는 싱글포인터를 매개변수로 받음
//		- initialize와 왜 다른지 이해 할것
//		 - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 *
int freeList(headNode* h);

int insertNode(headNode* h, int key);//* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int insertLast(headNode* h, int key); //list 마지막에 key에 대한 노드하나를 추가
int insertFirst(headNode* h, int key); //list 처음에 key에 대한 노드하나를 추가
int deleteNode(headNode* h, int key); //list에서 key에 해당하는 노드 삭제
int deleteLast(headNode* h); //list의 마지막 노드 삭제
int deleteFirst(headNode* h); //list의 첫번째 노드 삭제
int invertList(headNode* h); //리스트의 링크를 역순으로 재 배치

void printList(headNode* h);


int main()
{
	char command; //명령을 입력받을 변수
	int key;
	headNode* headnode = NULL;

	do {
		printf("\n ====== [ 2019038083 ] [ 전민선 ] ====== \n");
		
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z': //command가 z/Z이면 생성함수 호출
			initialize(&headnode);
			break;
		case 'p': case 'P': //command가 p/P이면 출력함수 호출
			printList(headnode);
			break;
		case 'i': case 'I': //command가 i/I이면 큰값 앞 삽입함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D': //command가 d/D이면 삭제함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N': //command가 n/N이면 마지막 생성함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E': //command가 e/E이면 마지막 삭제함수 호출
			deleteLast(headnode);
			break;
		case 'f': case 'F': //command가 f/F이면 처음 생성함수 호출
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T': //command가 t/T이면 처음 삭제함수 호출
			deleteFirst(headnode);
			break;
		case 'r': case 'R': //command가 r/R이면 재배치함수 호출
			invertList(headnode);
			break;
		case 'q': case 'Q': //command가 q/Q이면 해제함수 호출
			freeList(headnode);
			break;
		default: //command가 위의 것들이 아니면 문구 출력
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) {

	if (*h != NULL)
		freeList(*h);
	
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;

	return 1;
}


int freeList(headNode* h) {

	listNode* p = h->first;

	listNode* prev = NULL;

	while (p != NULL) {
		prev = p;
		p = p->llink;
		p = prev->rlink;
		free(prev);
	}
	free(h);

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while (p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}



// * list에 key에 대한 노드하나를 추가
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key값을 node에다가 넣고
	node->llink = NULL; //node의 llink와 rlink를 NULL로 만듬
	node->rlink = NULL;

	if (h->first == NULL) //h->first가 NULL이면 node의 값을 넣고 리턴0
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first;
	while (n->rlink != NULL) {
		n = n->rlink;
	}
	n->rlink = node; //node의 값을 n->rlink에 넣음
	node->llink = n; //n의 값을 node->llink에 넣음
	node->rlink = NULL; //n->rlink는 NULL로 만듬 마지막꺼니까

	return 0;
}



// * list의 마지막 노드 삭제
int deleteLast(headNode* h) {

	if (h->first == NULL) //h->first==NULL이면 지울게 없다
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //h->first의 값을 n에 넣고
	listNode* trail = NULL; //trail은 NULL로

	if (n->rlink == NULL) { //n->rlink가 널이면 마지막꺼라는 뜻이니까 그냥free
		h->first = NULL;
		free(n);
		return 0;
	}

	while (n->rlink != NULL) { //n->rlink가 널이아니면
		trail = n; //trail도 n이랑 똑같이하고
		n = n->rlink; //n->rlink를 끊어버림
	}

	trail->rlink = NULL; //trail->rlink는 NULL로 하고 free해서 지움
	free(n);

	return 0;
}



//list 처음에 key에 대한 노드하나를 추가
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //키값 넣고

	node->rlink = h->first; //h->first를 node->rlink에 연결
	node->llink = NULL;
	h->first = node; //node값을 h->first로 넣으면 처음에 추가

	return 0;
}


//list의 첫번째 노드 삭제
int deleteFirst(headNode* h) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first;

	h->first = n->rlink; //n->rlink를 h->first에 넣고 free n
	free(n);

	return 0;
}


//리스트의 링크를 역순으로 재 배치
int invertList(headNode* h) {

	if (h->first == NULL) {
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;
	listNode *trail = NULL;
	listNode *middle = NULL;

	while (n != NULL) { //오른쪽으로 움직여가면서 바꿈
		trail = middle;
		middle = n;
		n = n->rlink;
		middle->rlink = trail;
		middle->llink = n;
	}

	h->first = middle;

	return 0;
}


//* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 *
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key 값을 넣고 오른쪽왼쪽 다 널
	node->llink = NULL;
	node->rlink = NULL;

	if (h->first == NULL)
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = h->first;

	while (n != NULL) {
		if (n->key >= key) { //크거나 같을경우
			if (n == h->first) {//같을경우
				h->first = node;
				node->rlink = n;
				node->llink = NULL;
			}
			else {//클경우
				node->rlink = n;
				node->rlink->llink = node;
				trail->rlink = node;
				node->llink = trail;
			}
			return 0;
		}
		//작을경우
		trail = n;
		n = n->rlink;
	}

	trail->llink = node;
	trail->rlink = node;

	return 0;
}


// list에서 key에 대한 노드 삭제
int deleteNode(headNode* h, int key) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = NULL;

	while (n != NULL) { //n이 널이 아닐때까지 반복
		if (n->key == key) { //키값이 같으면
			if (n == h->first) { //h->first와 n이 같으면
				h->first = n->rlink;
				h->first->llink = n->llink;
			}
			else {
				trail->rlink = n->rlink;
				trail->llink = n->llink;
			}
			free(n);
			return 0;
		}

		trail = n;
		n = n->rlink;
	}

	printf("cannot find the node for key = %d\n", key);

	return 1;
}