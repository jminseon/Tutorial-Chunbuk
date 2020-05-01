#include<stdio.h>
#include<stdlib.h>

// �ʿ��� ������� �߰� 

//��ũ
typedef struct Node {
	int key;
	struct Node* link;
} listNode;

//������
typedef struct Head {
	struct Node* first;
}headNode;


headNode* initialize(headNode* h); //��常���
int freeList(headNode* h); //�����Ҵ�����

//���� ���� �Լ���
int insertFirst(headNode* h, int key); //ó������
int insertNode(headNode* h, int key); //�߰�����
int insertLast(headNode* h, int key); //����������

//���� ���� �Լ���
int deleteFirst(headNode* h); //ó������
int deleteNode(headNode* h, int key); //�߰�����
int deleteLast(headNode* h); //����������

int invertList(headNode* h); //����������
void printList(headNode* h); //����Ʈ ��� �Լ�

int main()
{
	char command; //����Է¿� ��������
	int key; //������ �Է��� ���� ��������
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
		scanf(" %c", &command); //��� �Է�

		switch (command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P': //command�� p�� P�� ��� ���
			printList(headnode);
			break;
		case 'i': case 'I': //command�� i�� I�� ��� �߰�����
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D': //command�� d�� D�� ��� �߰�����
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N': //command�� n�̳� N�� ��� ����������
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E': //command�� d�� D�� ��� ����������
			deleteLast(headnode);
			break;
		case 'f': case 'F': //command�� f�� F�� ��� ó������
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T': //command�� t�� T�� ��� ó������
			deleteFirst(headnode);
			break;
		case 'r': case 'R': //command�� r�̳� R�� ��� ������
			invertList(headnode);
			break;
		case 'q': case 'Q': //command�� q�� Q�� ��� �����Ҵ�����
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

	// headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� 
	if (h != NULL)
		freeList(h);

	// headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� 
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h) {
	// h�� ����� listNode �޸� ����
	// headNode�� �����Ǿ�� ��.
	 
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


//list ó���� key�� ���� ����ϳ��� �߰�
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


//����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� 
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

//list�� key�� ���� ����ϳ��� �߰�
int insertLast(headNode* h, int key) {

	listNode* node3 = (listNode*)malloc(sizeof(listNode)); //��带 �����Ҵ����� ����
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


// list�� ù��° ��� ���� - ����
int deleteFirst(headNode* h) {
	
	listNode* del;
	
	del = h->first;
	h->first = h->first->link;
	free(del);

	return 0;
}

//list���� key�� ���� ��� ����
int deleteNode(headNode* h, int key) {

	headNode* temp;
	temp->first = h->first;

	while (temp->first != NULL) {

		if (temp->first->key == key) {

			// ��带 ����� �ڵ�
			temp = temp->first;

			return 0;
		}
		temp->first = temp->first->link;
	}
	free(temp);

	return 0;

}

//list�� ������ ��� ����
int deleteLast(headNode* h) {

	listNode* previous;//����
	listNode* current;//����

	previous = h->first;
	current = h->first->link;

	if (current->link != NULL)
	{
		previous = current;
		current = current->link;
	}
	previous->link = NULL;
	free(current); //�����Ҵ� ����

	return 0;
}


//����Ʈ�� ��ũ�� �������� �� ��ġ
int invertList(headNode* h) {

	listNode* h2;
	listNode* h3;
	listNode* h4;

	h2 = h->first;
	h3 = NULL;
	h4 = NULL;

	//����� ������ �ݴ�� �ٲٱ�
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