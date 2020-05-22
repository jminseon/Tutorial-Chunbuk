#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

//완성해야할 함수
void inorderTraversal(Node* ptr);	  //* recursive inorder traversal 
void preorderTraversal(Node* ptr);    //* recursive preorder traversal
void postorderTraversal(Node* ptr);	  //* recursive postorder traversal 
int insert(Node* head, int key);  //* insert a node to the tree 
int deleteLeafNode(Node* head, int key);  //* delete the leaf node for the key 
Node* searchRecursive(Node* ptr, int key);  //* search the node for the key 
Node* searchIterative(Node* head, int key);  //* search the node for the key 
int freeBST(Node* head); //* free all memories allocated to the tree 

//필요하면 함수추가
//https://wkdtjsgur100.github.io/binary-search-tree/

int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	//* temp 

	printf("2019038083 전민선");

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


void inorderTraversal(Node* ptr) //중위순회
{
	if (ptr == NULL)
		return;

	inorderTraversal(ptr->left);
	printf("%d", ptr->key);
	inorderTraversal(ptr->right);
}


void preorderTraversal(Node* ptr) //전위순회
{
	if (ptr == NULL)
		return;
	
	printf("%d", ptr->key);
	preorderTraversal(ptr->left);
	preorderTraversal(ptr->right);
}


void postorderTraversal(Node* ptr) //후위순회
{
	if (ptr == NULL)
		return;

	postorderTraversal(ptr->left);
	postorderTraversal(ptr->right);
	printf("%d", ptr->key);
}


int insert(Node* head, int key)
{
	struct node *new = malloc(sizeof(struct node));    // 새 노드 생성
	
	new->key = key; //key값 넣고

	//만약에 키값이 헤드 키값보다 작으면 왼쪽 아니면 오른쪽
	if (key < head->key)
		head->left = new;
	else
		head->right = new;

	head = new; //헤드를 옮김
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
		//ptr의 키가 키값보다 클 경우
		if (ptr->key > key){      
			if (ptr->left != NULL) //ptr의 left가 널이 아니면
				ptr = searchRecursive(ptr->left, key); //다시 부르고
			else
				return NULL;
		}

		else if (ptr->key < key){//ptr의 키가 키값보다 작을 경우
			if (ptr->right != NULL) //ptr의 right가 널이 아니면
				ptr = searchRecursive(ptr->right, key); //다시 부르고
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
		//head의 키가 키값보다 클 경우
		if (head->key > key) {
			if (head->left != NULL) //head의 left가 널이 아니면
				head = head->left;
			else
				return NULL;
		}

		else if (head->key < key) {//head의 키가 키값보다 작을 경우
			if (head->right != NULL) //head의 right가 널이 아니면
				head = head->right;
			else
				return NULL;
		}

		else //같을경우
			return head;

		return head;
	}

	return NULL;
}


int freeBST(Node* head)
{
	free(head);
}