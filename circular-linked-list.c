#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;


//* 함수 리스트 *
int initialize(listNode** h);
int freeList(listNode* h); //이거
int insertLast(listNode* h, int key); //이거
int deleteLast(listNode* h); //이거
int insertFirst(listNode* h, int key); //이거
int deleteFirst(listNode* h); //이거
int invertList(listNode* h); //이거

int insertNode(listNode* h, int key); //이거
int deleteNode(listNode* h, int key); //이거

void printList(listNode* h);


int main()
{
	char command;
	int key;
	listNode* headnode = NULL;
	initialize(&headnode);

	printf("\n====== [ 2019038083 ] [ 전민선 ] ======\n\n");


	do {
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


int initialize(listNode** h) {

	//* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 *
	if (*h != NULL)
		freeList(*h);

	// headNode에 대한 메모리를 할당하여 리턴 
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}


//완성
//* 메모리 해제 *
int freeList(listNode* h) {

	listNode* p = h->rlink;

	listNode* prev = NULL;

	while (p != h) { //p가 h가 아닐때동안
		free(prev);
		prev = p;
	}
	free(h);

	return 0;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while (p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while (p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}


//완성
//list의 마지막에 key에 대한 노드하나를 추가
int insertLast(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key값을 node에다가 넣고
	node->llink = NULL; //node의 llink와 rlink를 NULL로 만듬
	node->rlink = NULL;

	if (h->rlink == h) //h->rlink가 h면
	{
		h->rlink = node;
		node->llink = h;
		h->llink = node;
		node->rlink = h;

		return 0;
	}

	listNode* n = h->rlink;

	while (n->rlink != h) { //n을 끝으로 보내는중
		n = n->rlink;
	}

	n->rlink = node; //node의 값을 n->rlink에 넣음
	node->llink = n; //n의 값을 node->llink에 넣음
	node->rlink = h; //n->rlink는 h에 연결
	h->llink = node;

	return 1;
}


//완성
// list의 마지막 노드 삭제
int deleteLast(listNode* h) {

	if (h->rlink == h) //h->rlink==h면 지울게 없다
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink; //h->first의 값을 n에 넣고
	listNode* trail = NULL; //trail은 NULL로

	if (n->rlink == h) { //n->rlink가 h면 마지막꺼라는 뜻
		h->rlink = h;
		h->llink = h;
		n->rlink = NULL;
		n->llink = NULL;
		free(n);
		return 0;
	}

	while (n->rlink != h) { //n->rlink가 h가 아니면
		trail = n; //trail을 n이랑 똑같이하고
		n = n->rlink; //n->rlink를 끝으로이동
	}
	//n이 맨끝 trail은 맨끝보다 한칸 앞이 됨

	trail->rlink = h;
	h->llink = trail;
	n->llink = NULL;
	n->rlink = NULL;
	free(n);

	return 1;
}


//완성
//list 처음에 key에 대한 노드하나를 추가
int insertFirst(listNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //키값 넣고

	if (h->rlink == h)
	{
		node->llink = h; //h를 node->llink로 함
		h->rlink = node;
		node->rlink = h;
		h->llink = node;
		return 0;
	}
	else
	{
		node->rlink = h->rlink; //node의 rlink는 h의 rlink
		node->llink = h; //node의 llink는 h
		h->rlink = node;
		node->rlink->llink = node;
	}

	return 1;
}

//완성
// list의 첫번째 노드 삭제
int deleteFirst(listNode* h) {

	if (h->rlink == h)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;

	h->rlink = n->rlink; //n->rlink를 h->rlink->llink에 넣고
	n->rlink->llink = h; //n->llink는 h->llink->rlink에 넣고 free n
	free(n);

	return 1;

}


//리스트의 링크를 역순으로 재 배치
int invertList(listNode* h) {

	listNode *n = h->rlink;
	listNode *next1 = n->rlink;

	if (h->rlink == h) { //리스트가 비어잇을때
		printf("nothing to invert...\n");
		return 0;
	}
	else if (n->rlink == h) { //하나만있을때
		return 0;
	}
	else if (next1->rlink == h) { //두개만 잇을때
		n->rlink = h;
		n->llink = next1;
		next1->rlink = n;
		next1->llink = h;
		h->rlink = next1;
		h->llink = n;
		return 0;
	}

	listNode *next = n->rlink;
	listNode *pre = n->llink;

	h->rlink = h->llink; //h먼저 뒤집어주고
	h->llink = n;

	while (n != h) { //반복해서 뒤집고 옮기고

		n->rlink = pre;
		n->llink = next;

		pre = n;
		n = next;
		next = next->rlink;
	}
	return 0;


}


//* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 *
int insertNode(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key 값을 넣고 오른쪽왼쪽 다 NULL
	node->llink = NULL;
	node->rlink = NULL;

	if (h->rlink == h)
	{
		h->rlink = node;
		node->llink = h;
		h->llink = node;
		node->rlink = h;
		return 0;
	}

	listNode* n = h->rlink;

	while (n != h) { //n이 h가 아닐동안
		if (n->key >= key) { //n의 값이 입력받은 키값보다 크거나 같을경우
			n->llink->rlink = node;
			node->rlink = n;
			node->llink = n->llink;
			n->llink = node;
			return 0;
		}
		n = n->rlink;
	}
	//n이 h랑 같으면 한바퀴 다돈거니까 그냥뒤에붙여
	node->rlink = h;
	node->llink = h->llink;
	h->llink->rlink = node;
	h->llink = node;

	return 0;
}


//완성
//list에서 key에 대한 노드 삭제
int deleteNode(listNode* h, int key) {

	if (h->rlink == h)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;

	while (n != h) { //n이 널이 아닐때까지 반복
		if (n->key == key) { //키값이 같으면

			n->llink->rlink = n->rlink;
			n->rlink->llink = n->llink;

			free(n);
			return 0;
		}
		n = n->rlink;
	}

	printf("cannot find the node for key = %d\n", key);

	return 1;
}