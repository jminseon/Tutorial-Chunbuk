#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

//* for stack *
#define MAX_STACK_SIZE      20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

//* for queue *
#define MAX_QUEUE_SIZE      20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

//�����ؾ��ϴ� / *�Լ� * /
void recursiveInorder(Node* ptr); //*��� �� ���� ��ȸ * /
void iterativeInorder(Node * ptr); // *�ݺ��� �� ���� ��ȸ * /
void levelOrder(Node * ptr); // *���� ���� ��ȸ * /
int insert(Node * head, int key); // *Ʈ���� ��带 ���� * /
int deleteNode(Node * head, int key); // *Ű�� ��带 �����մϴ� * /
int freeBST(Node* head); // *Ʈ���� �Ҵ� �� ��� �޸𸮸� ���� * /

// *�ʿ��� ��� �ڽ� ���� ���� �� �Լ��� �߰� �� �� �ֽ��ϴ� * /
void printStack();


int main()
{
	char command;
	int key;
	Node* head = NULL;

	printf("[---------- [���μ�] [2019038083] ----------]\n");

	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
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
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


int initializeBST(Node** h) {

	// *Ʈ���� ��� ���� ������ Ʈ������ �Ҵ� �� ��� ��带 ����
	if (*h != NULL)
		freeBST(*h);

	//* create a head node *
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;   //* root *
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}


//�̰Ŷ�
void recursiveInorder(Node* ptr)
{
	if (ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}


//224 �̰Ŷ�
void iterativeInorder(Node * node)
{
	int top = -1;

	for (; ; ) {
		for (; node; node = node->left)
			push(node);
		node = pop();
		if (!node)
			break;
		printf("%d", node->key);
		node = node->right;
	}
}


//225 �̰Ŷ�
void levelOrder(Node * ptr)
{
	int front = rear = 0;

	if (!ptr) return;
	enQueue(ptr);

	for (; ; ) {
		ptr = deQueue();
		if (ptr) {
			printf("%d", ptr->key);
			if (ptr->left)
				enQueue(ptr->left);
			if (ptr->right)
				enQueue(ptr->right);
		}
		else
			break;
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while (ptr != NULL) {

		/* if there is a node for the key, then just return */
		if (ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if (ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if (parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


//�̰Ŷ�
int deleteNode(Node* head, int key)
{
	Node* temp; //key���� ã�� ����
	Node* Rtemp; //���ﰪ�� �����ʿ��� ���� ū�� ã��
	Node* pre; //�θ��尡 ������ �ڳ�� ����� branch�� NULL�� �����ϱ� ����

	if (head != NULL)      //�ʱ�ȭ ���� ���� ����
	{
		temp = head->right;
		while (temp != NULL)
		{
			if (temp->key == key) //����
			{
				if (temp->left != NULL && temp->right != NULL)      //�ڳ��尡 �����ϴ� ���
				{
					Rtemp = temp->right;
					pre = temp;
					while (Rtemp->left != NULL)
					{                              //������ ����Ʈ������ ���� ū �� ã��
						pre = Rtemp;
						Rtemp = Rtemp->left;
					}
					temp->key = Rtemp->key;
					if (Rtemp == temp->right)      //���� ������ ����Ʈ������ ���� ū ���� ������ ����Ʈ���� ��Ʈ�� ���
						pre->right = Rtemp->right;
					else if (Rtemp->right == NULL)      //���� ū ���� ������ ����Ʈ���� �������� �ʴ� ���
						pre->left = NULL;
					else
						pre->left = Rtemp->right;      //���� ū ���� ������ ����Ʈ���� �����ϴ� ���
					free(Rtemp);
					return 1;
				}
			}
		}

		printf("\n Cannot find the node [%d]\n", key);      //��带 ã�� ������ ���
	}
	return 0;
}


void freeNode(Node* ptr)
{
	if (ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if (head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}


//����ؿ���
Node* pop()
{
	if (top != -1) //������ ������� ������
		return stack[top--];
	return NULL;
}

void push(Node* aNode)
{
	top++;
	stack[top] = aNode;
}


Node* deQueue()
{
	if (rear != front)
		return queue[++rear];
	return NULL;
}

void enQueue(Node* aNode)
{
	front = front + 1;
	queue[front] = aNode;
}


void printStack() {

}
