#include<stdio.h>
#include<stdlib.h>
/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;


//* �Լ� ����Ʈ *
int initialize(listNode** h);
int freeList(listNode* h); //�̰�
int insertLast(listNode* h, int key); //�̰�
int deleteLast(listNode* h); //�̰�
int insertFirst(listNode* h, int key); //�̰�
int deleteFirst(listNode* h); //�̰�
int invertList(listNode* h); //�̰�

int insertNode(listNode* h, int key); //�̰�
int deleteNode(listNode* h, int key); //�̰�

void printList(listNode* h);


int main()
{
	char command;
	int key;
	listNode* headnode = NULL;
	initialize(&headnode);

	printf("\n====== [ 2019038083 ] [ ���μ� ] ======\n\n");


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

	//* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� *
	if (*h != NULL)
		freeList(*h);

	// headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� 
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}


//�ϼ�
//* �޸� ���� *
int freeList(listNode* h) {

	listNode* p = h->rlink;

	listNode* prev = NULL;

	while (p != h) { //p�� h�� �ƴҶ�����
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


//�ϼ�
//list�� �������� key�� ���� ����ϳ��� �߰�
int insertLast(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key���� node���ٰ� �ְ�
	node->llink = NULL; //node�� llink�� rlink�� NULL�� ����
	node->rlink = NULL;

	if (h->rlink == h) //h->rlink�� h��
	{
		h->rlink = node;
		node->llink = h;
		h->llink = node;
		node->rlink = h;

		return 0;
	}

	listNode* n = h->rlink;

	while (n->rlink != h) { //n�� ������ ��������
		n = n->rlink;
	}

	n->rlink = node; //node�� ���� n->rlink�� ����
	node->llink = n; //n�� ���� node->llink�� ����
	node->rlink = h; //n->rlink�� h�� ����
	h->llink = node;

	return 1;
}


//�ϼ�
// list�� ������ ��� ����
int deleteLast(listNode* h) {

	if (h->rlink == h) //h->rlink==h�� ����� ����
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink; //h->first�� ���� n�� �ְ�
	listNode* trail = NULL; //trail�� NULL��

	if (n->rlink == h) { //n->rlink�� h�� ����������� ��
		h->rlink = h;
		h->llink = h;
		n->rlink = NULL;
		n->llink = NULL;
		free(n);
		return 0;
	}

	while (n->rlink != h) { //n->rlink�� h�� �ƴϸ�
		trail = n; //trail�� n�̶� �Ȱ����ϰ�
		n = n->rlink; //n->rlink�� �������̵�
	}
	//n�� �ǳ� trail�� �ǳ����� ��ĭ ���� ��

	trail->rlink = h;
	h->llink = trail;
	n->llink = NULL;
	n->rlink = NULL;
	free(n);

	return 1;
}


//�ϼ�
//list ó���� key�� ���� ����ϳ��� �߰�
int insertFirst(listNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //Ű�� �ְ�

	if (h->rlink == h)
	{
		node->llink = h; //h�� node->llink�� ��
		h->rlink = node;
		node->rlink = h;
		h->llink = node;
		return 0;
	}
	else
	{
		node->rlink = h->rlink; //node�� rlink�� h�� rlink
		node->llink = h; //node�� llink�� h
		h->rlink = node;
		node->rlink->llink = node;
	}

	return 1;
}

//�ϼ�
// list�� ù��° ��� ����
int deleteFirst(listNode* h) {

	if (h->rlink == h)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;

	h->rlink = n->rlink; //n->rlink�� h->rlink->llink�� �ְ�
	n->rlink->llink = h; //n->llink�� h->llink->rlink�� �ְ� free n
	free(n);

	return 1;

}


//����Ʈ�� ��ũ�� �������� �� ��ġ
int invertList(listNode* h) {

	listNode *n = h->rlink;
	listNode *next1 = n->rlink;

	if (h->rlink == h) { //����Ʈ�� ���������
		printf("nothing to invert...\n");
		return 0;
	}
	else if (n->rlink == h) { //�ϳ���������
		return 0;
	}
	else if (next1->rlink == h) { //�ΰ��� ������
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

	h->rlink = h->llink; //h���� �������ְ�
	h->llink = n;

	while (n != h) { //�ݺ��ؼ� ������ �ű��

		n->rlink = pre;
		n->llink = next;

		pre = n;
		n = next;
		next = next->rlink;
	}
	return 0;


}


//* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� *
int insertNode(listNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key; //key ���� �ְ� �����ʿ��� �� NULL
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

	while (n != h) { //n�� h�� �ƴҵ���
		if (n->key >= key) { //n�� ���� �Է¹��� Ű������ ũ�ų� �������
			n->llink->rlink = node;
			node->rlink = n;
			node->llink = n->llink;
			n->llink = node;
			return 0;
		}
		n = n->rlink;
	}
	//n�� h�� ������ �ѹ��� �ٵ��Ŵϱ� �׳ɵڿ��ٿ�
	node->rlink = h;
	node->llink = h->llink;
	h->llink->rlink = node;
	h->llink = node;

	return 0;
}


//�ϼ�
//list���� key�� ���� ��� ����
int deleteNode(listNode* h, int key) {

	if (h->rlink == h)
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;

	while (n != h) { //n�� ���� �ƴҶ����� �ݺ�
		if (n->key == key) { //Ű���� ������

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