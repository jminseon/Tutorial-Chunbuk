#include<stdio.h>
#include<stdlib.h>

// 필요한 헤더파일 추가 

//링크
typedef struct Node {
	int key;
	struct Node* link;
} listNode;

//데이터
typedef struct Head {
	struct Node* first;
}headNode;


headNode* initialize(headNode* h); //노드만들기
int freeList(headNode* h); //동적할당해제

//삽입 관련 함수들
int insertFirst(headNode* h, int key); //처음삽입
int insertNode(headNode* h, int key); //중간삽입
int insertLast(headNode* h, int key); //마지막삽입

//삭제 관련 함수들
int deleteFirst(headNode* h); //처음삭제
int deleteNode(headNode* h, int key); //중간삭제
int deleteLast(headNode* h); //마지막삭제

int invertList(headNode* h); //순서뒤집기
void printList(headNode* h); //리스트 출력 함수

int main()
{
	char command; //명령입력용 지역변수
	int key; //데이터 입력을 위한 지역변수
	headNode* headnode = NULL;

	do {
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //명령 입력

		switch (command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P': //command가 p나 P일 경우 출력
			printList(headnode);
			break;
		case 'i': case 'I': //command가 i나 I일 경우 중간삽입
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D': //command가 d나 D일 경우 중간삭제
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N': //command가 n이나 N일 경우 마지막삽입
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E': //command가 d나 D일 경우 마지막삭제
			deleteLast(headnode);
			break;
		case 'f': case 'F': //command가 f나 F일 경우 처음삽입
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T': //command가 t나 T일 경우 처음삭제
			deleteFirst(headnode);
			break;
		case 'r': case 'R': //command가 r이나 R일 경우 뒤집기
			invertList(headnode);
			break;
		case 'q': case 'Q': //command가 q나 Q일 경우 동적할당해제
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	// headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 
	if (h != NULL)
		freeList(h);

	// headNode에 대한 메모리를 할당하여 리턴 
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h) {
	// h와 연결된 listNode 메모리 해제
	// headNode도 해제되어야 함.
	 
	listNode* p = h->first;

	listNode* prev = NULL;
	while (p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}


//list 처음에 key에 대한 노드하나를 추가
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


//리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 
int insertNode(headNode* h, int key) {

	listNode* node5 = (listNode*)malloc(sizeof(listNode));
	listNode* temp;
	listNode*prev; 
	node5->key = key;
	temp = h->first;
	prev = NULL;

	while (temp != NULL)
	{
		if (node5->key > temp->key)
		{
			prev = temp;
			temp = temp->link;
		}
		else
			break;
	}

	if (prev == NULL){
		node5->key = key;
		node5->link = h->first;
	}
	else{
		node5->link = temp;
		prev->link = node5;
	}

	return 0;
}

//list에 key에 대한 노드하나를 추가
int insertLast(headNode* h, int key) {

	listNode* node3 = (listNode*)malloc(sizeof(listNode)); //노드를 동적할당으로 생성
	listNode* node2;

	node3->key = key;
	node2 = h->first;

	if (node2 != NULL) {
		while (1) {

			node2 = node2->link;

			if (node2->link == NULL)
				break;
		}
	}

	node2->link = node3;
	node3->link = NULL;

	return 0;
}


// list의 첫번째 노드 삭제 - 수정
int deleteFirst(headNode* h) {
	
	listNode* del;
	
	del = h->first;
	h->first = h->first->link;
	free(del);

	return 0;
}

//list에서 key에 대한 노드 삭제
int deleteNode(headNode* h, int key) {

	headNode* temp;
	temp->first = h->first;

	while (temp->first != NULL) {

		if (temp->first->key == key) {

			// 노드를 지우는 코드
			temp = temp->first;

			return 0;
		}
		temp->first = temp->first->link;
	}
	free(temp);

	return 0;

}

//list의 마지막 노드 삭제
int deleteLast(headNode* h) {

	listNode* previous;//이전
	listNode* current;//현재

	previous = h->first;
	current = h->first->link;

	if (current->link != NULL)
	{
		previous = current;
		current = current->link;
	}
	previous->link = NULL;
	free(current); //동적할당 해제

	return 0;
}


//리스트의 링크를 역순으로 재 배치
int invertList(headNode* h) {

	listNode* h2;
	listNode* h3;
	listNode* h4;

	h2 = h->first;
	h3 = NULL;
	h4 = NULL;

	//노드의 연결을 반대로 바꾸기
	while (h2 != NULL){
		h4 = h3;
		h3 = h2;
		h2 = h2->link;
		h3->link = h4;
	}
	h->first = h3;

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
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}