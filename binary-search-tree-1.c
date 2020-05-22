#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

//�ϼ��ؾ��� �Լ�
void inorderTraversal(Node* ptr);	  //* recursive inorder traversal 
void preorderTraversal(Node* ptr);    //* recursive preorder traversal
void postorderTraversal(Node* ptr);	  //* recursive postorder traversal 
int insert(Node* head, int key);  //* insert a node to the tree 
int deleteLeafNode(Node* head, int key);  //* delete the leaf node for the key 
Node* searchRecursive(Node* ptr, int key);  //* search the node for the key 
Node* searchIterative(Node* head, int key);  //* search the node for the key 
int freeBST(Node* head); //* free all memories allocated to the tree 

//�ʿ��ϸ� �Լ��߰�
//https://wkdtjsgur100.github.io/binary-search-tree/

int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	//* temp 

	printf("2019038083 ���μ�");

	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if (ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if (*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}


void inorderTraversal(Node* ptr) //������ȸ
{
	if (ptr == NULL)
		return;

	inorderTraversal(ptr->left);
	printf("%d", ptr->key);
	inorderTraversal(ptr->right);
}


void preorderTraversal(Node* ptr) //������ȸ
{
	if (ptr == NULL)
		return;
	
	printf("%d", ptr->key);
	preorderTraversal(ptr->left);
	preorderTraversal(ptr->right);
}


void postorderTraversal(Node* ptr) //������ȸ
{
	if (ptr == NULL)
		return;

	postorderTraversal(ptr->left);
	postorderTraversal(ptr->right);
	printf("%d", ptr->key);
}


int insert(Node* head, int key)
{
	struct node *new = malloc(sizeof(struct node));    // �� ��� ����
	
	new->key = key; //key�� �ְ�

	//���࿡ Ű���� ��� Ű������ ������ ���� �ƴϸ� ������
	if (key < head->key)
		head->left = new;
	else
		head->right = new;

	head = new; //��带 �ű�
}


int deleteLeafNode(Node* head, int key)
{
	Node* p;
	Node* new2;
	p = head;
	new2 = head->left;
	
	if (head == NULL)
		return NULL;

	if (head->key > key)
		head->left = deleteLeafNode(head->left, key);
	else if (head->key < key)
		head->right = deleteLeafNode(head->right, key);
	else if (head->key == key) {
		p->left = p;
		free(head);
	}

	return head;
}


Node* searchRecursive(Node* ptr, int key)
{
	while (ptr != NULL)
	{
		//ptr�� Ű�� Ű������ Ŭ ���
		if (ptr->key > key){      
			if (ptr->left != NULL) //ptr�� left�� ���� �ƴϸ�
				ptr = searchRecursive(ptr->left, key); //�ٽ� �θ���
			else
				return NULL;
		}

		else if (ptr->key < key){//ptr�� Ű�� Ű������ ���� ���
			if (ptr->right != NULL) //ptr�� right�� ���� �ƴϸ�
				ptr = searchRecursive(ptr->right, key); //�ٽ� �θ���
			else
				return NULL;
		}

		return ptr;
	}

	return NULL;
}


Node* searchIterative(Node* head, int key)
{
	while (head != NULL)
	{
		//head�� Ű�� Ű������ Ŭ ���
		if (head->key > key) {
			if (head->left != NULL) //head�� left�� ���� �ƴϸ�
				head = head->left;
			else
				return NULL;
		}

		else if (head->key < key) {//head�� Ű�� Ű������ ���� ���
			if (head->right != NULL) //head�� right�� ���� �ƴϸ�
				head = head->right;
			else
				return NULL;
		}

		else //�������
			return head;

		return head;
	}

	return NULL;
}


int freeBST(Node* head)
{
	free(head);
}