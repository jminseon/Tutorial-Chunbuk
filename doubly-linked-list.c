#include<stdio.h>
#include<stdlib.h>
 //* �ʿ��� ������� �߰� if necessary *


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

//* �Լ� ����Ʈ *

//* note: initialize�� ���������͸� �Ű������� ����
//		 singly-linked-list�� initialize�� �������� ���� �Ұ� *
int initialize(headNode** h);

//* note: freeList�� �̱������͸� �Ű������� ����
//		- initialize�� �� �ٸ��� ���� �Ұ�
//		 - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� *
int freeList(headNode* h);

int insertNode(headNode* h, int key);//* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ����
int insertLast(headNode* h, int key); //list �������� key�� ���� ����ϳ��� �߰�
int insertFirst(headNode* h, int key); //list ó���� key�� ���� ����ϳ��� �߰�
int deleteNode(headNode* h, int key); //list���� key�� �ش��ϴ� ��� ����
int deleteLast(headNode* h); //list�� ������ ��� ����
int deleteFirst(headNode* h); //list�� ù��° ��� ����
int invertList(headNode* h); //����Ʈ�� ��ũ�� �������� �� ��ġ

void printList(headNode* h);


int main()
{
	char command; //����� �Է¹��� ����
	int key;
	headNode* headnode = NULL;

	do {
		printf("\n ====== [ 2019038083 ] [ ���μ� ] ====== \n");
		
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
		case 'z': case 'Z': //command�� z/Z�̸� �����Լ� ȣ��
			initialize(&headnode);
			break;
		case 'p': case 'P': //command�� p/P�̸� ����Լ� ȣ��
			printList(headnode);
			break;
		case 'i': case 'I': //command�� i/I�̸� ū�� �� �����Լ� ȣ��
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D': //command�� d/D�̸� �����Լ� ȣ��
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N': //command�� n/N�̸� ������ �����Լ� ȣ��
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E': //command�� e/E�̸� ������ �����Լ� ȣ��
			deleteLast(headnode);
			break;
		case 'f': case 'F': //command�� f/F�̸� ó�� �����Լ� ȣ��
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T': //command�� t/T�̸� ó�� �����Լ� ȣ��
			deleteFirst(headnode);
			break;
		case 'r': case 'R': //command�� r/R�̸� ���ġ�Լ� ȣ��
			invertList(headnode);
			break;
		case 'q': case 'Q': //command�� q/Q�̸� �����Լ� ȣ��
			freeList(headnode);
			break;
		default: //command�� ���� �͵��� �ƴϸ� ���� ���
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



// * list�� key�� ���� ����ϳ��� �߰�
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key���� node���ٰ� �ְ�
	node->llink = NULL; //node�� llink�� rlink�� NULL�� ����
	node->rlink = NULL;

	if (h->first == NULL) //h->first�� NULL�̸� node�� ���� �ְ� ����0
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first;
	while (n->rlink != NULL) {
		n = n->rlink;
	}
	n->rlink = node; //node�� ���� n->rlink�� ����
	node->llink = n; //n�� ���� node->llink�� ����
	node->rlink = NULL; //n->rlink�� NULL�� ���� ���������ϱ�

	return 0;
}



// * list�� ������ ��� ����
int deleteLast(headNode* h) {

	if (h->first == NULL) //h->first==NULL�̸� ����� ����
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //h->first�� ���� n�� �ְ�
	listNode* trail = NULL; //trail�� NULL��

	if (n->rlink == NULL) { //n->rlink�� ���̸� ����������� ���̴ϱ� �׳�free
		h->first = NULL;
		free(n);
		return 0;
	}

	while (n->rlink != NULL) { //n->rlink�� ���̾ƴϸ�
		trail = n; //trail�� n�̶� �Ȱ����ϰ�
		n = n->rlink; //n->rlink�� �������
	}

	trail->rlink = NULL; //trail->rlink�� NULL�� �ϰ� free�ؼ� ����
	free(n);

	return 0;
}



//list ó���� key�� ���� ����ϳ��� �߰�
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //Ű�� �ְ�

	node->rlink = h->first; //h->first�� node->rlink�� ����
	node->llink = NULL;
	h->first = node; //node���� h->first�� ������ ó���� �߰�

	return 0;
}


//list�� ù��° ��� ����
int deleteFirst(headNode* h) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first;

	h->first = n->rlink; //n->rlink�� h->first�� �ְ� free n
	free(n);

	return 0;
}


//����Ʈ�� ��ũ�� �������� �� ��ġ
int invertList(headNode* h) {

	if (h->first == NULL) {
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;
	listNode *trail = NULL;
	listNode *middle = NULL;

	while (n != NULL) { //���������� ���������鼭 �ٲ�
		trail = middle;
		middle = n;
		n = n->rlink;
		middle->rlink = trail;
		middle->llink = n;
	}

	h->first = middle;

	return 0;
}


//* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� *
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key ���� �ְ� �����ʿ��� �� ��
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
		if (n->key >= key) { //ũ�ų� �������
			if (n == h->first) {//�������
				h->first = node;
				node->rlink = n;
				node->llink = NULL;
			}
			else {//Ŭ���
				node->rlink = n;
				node->rlink->llink = node;
				trail->rlink = node;
				node->llink = trail;
			}
			return 0;
		}
		//�������
		trail = n;
		n = n->rlink;
	}

	trail->llink = node;
	trail->rlink = node;

	return 0;
}


// list���� key�� ���� ��� ����
int deleteNode(headNode* h, int key) {

	if (h->first == NULL)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;
	listNode* trail = NULL;

	while (n != NULL) { //n�� ���� �ƴҶ����� �ݺ�
		if (n->key == key) { //Ű���� ������
			if (n == h->first) { //h->first�� n�� ������
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