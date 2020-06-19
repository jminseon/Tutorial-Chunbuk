#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 20

typedef struct Vertex
{
	int num; 
	struct Vertex* link; 
}Vertex;

typedef struct VertexHead 
{
	struct Vertex* head;
}VertexHead;

typedef struct Graph
{
	VertexHead* vlist;
}Graph;

Graph* createGraph(Graph* G); // �׷��� �ʱ�ȭ
int destoryGraph(Graph* G); // �׷��� ��� �޸𸮸� ����
int insertVertex(Graph* G, int num); // ���� ����
int deleteVertex(Graph* G, int num); // ���� ����
int insertEdge(Graph* G, int u, int v); // ���� �߰�
int deleteEdge(Graph* G, int u, int v); // ���� ����
void depthFS();
void breadthFS();
int printGraph(Graph* G); // �׷��� ����, ���� ���

int vflag[MAX_VERTEX] = { 0 }; // ������ ����������� ���θ� �Ǵ��ϴ� �迭

int main()
{
	char command; // ��ɾ� ���� ���� 
	int u, v, num, key;
	Graph* Graph = NULL;

	do {
		printf("========================================================\n"); // �޴� ���
		printf("                     ������ �׷���                        \n");
		printf("========================================================\n");
		printf(" createGraph   = z           Print         = p \n");
		printf(" Insert Vertex = i           Delete Vertex = d \n");
		printf(" Insert Edge   = n           Delete Edge   = e \n");
		printf(" depthFS       = f           breadthFS     = b \n");
		printf(" destoryGraph  = t           Quit          = q \n");
		printf("========================================================\n");

		printf("Command = ");
		scanf_s(" %c", &command); // ��ɾ� �Է�

		switch (command)
		{
		case 'z': case 'Z':
			Graph = createGraph(Graph);
			break;

		case 'p': case 'P':
			printGraph(Graph); 
			break;

		case 'i': case 'I':
			printf("Insert Vertex Number = ");
			scanf_s("%d", &num); // key�� �Է�
			insertVertex(Graph, num); // ���� �׷����� ����
			break;

		case 'd': case 'D':
			printf("Delete Vertex Number = ");
			scanf_s("%d", &num);
			deleteVertex(Graph, num); // ���� ����
			break;

		case 'n': case 'N': 
			printf("Input Edge u,v = "); // ���� ���
			scanf_s("%d %d", &u, &v); 
			insertEdge(Graph, u, v);
			break;

		case 'e': case 'E': 
			printf("Delete Edge u,v = ");
			scanf_s("%d %d", &u, &v);
			deleteEdge(Graph, u, v);
			break;

		case 'f': case 'F':
			printf("Your Key = "); 
			scanf("%d", &key); 
			depthFS(); 
			break;

		case 'b': case 'B':
			breadthFS();
			break;

		case 't': case 'T': 
			destoryGraph(Graph); // �׷��� �Ҵ� �޸� ����
			break;

		case 'q': case 'Q': 
			destoryGraph(Graph);
			break;

		default: 
			printf("\n ========== Concentration! =========== \n"); //���� ���
			break;
		}
	} while (command != 'q' && command != 'Q'); //�ݺ��� ����

	return 1;
}

Graph* createGraph(Graph* G) // �׷���  ���� ����
{
	Graph* g = (VertexHead*)malloc(sizeof(VertexHead) * MAX_VERTEX);

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		g[i].vlist = NULL; // �ε����� NULL�� �ʱ�ȭ
		vflag[i] = 0; // vflag�� �ش� �ε������� 0���� �����Ѵ�
	}

	return g; // ������ g ����
}

int destoryGraph(Graph* G) //�޸𸮸� ����
{
	VertexHead* p = NULL;
	Vertex* temp = NULL;
	Vertex* prev = NULL;

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		if (vflag[i] == 1) // ���� i���� ���� ������ �����Ǿ��ִٸ�
		{
			
		}
	}
	free(G); //�޸� ����


	return 0;
}

int insertVertex(Graph* G, int num) // �׷����� ������ �����ϴ� �Լ�
{
	VertexHead* head = (VertexHead*)malloc(sizeof(VertexHead)); // ����� ������ ����
	head->head = NULL; // head����� �� NULL�� �ʱ�ȭ

	if (vflag[num] == 1) // �Է¹��� NUM�� ���� ������ �����ϸ�, 
		printf("�̹� �ش� Vertex�� �����մϴ�.\n"); // ���� ���

	else // �Է¹��� NUM�� ���� ������ �׷����� ���ٸ�
	{
		
	}

	return 0; 
}

int deleteVertex(Graph* G, int num) // ���� ����
{
	
}

int insertEdge(Graph* G, int u, int v) // ������ �����ϴ� �Լ�
{
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex)); // ���Ḯ��Ʈ�� ������ vertex ����
	Vertex* temp = NULL; // ������ ����ų ������ �����
	Vertex* prev = NULL; // ������ ����ų ������ ����


	if (vflag[u] == 1 && vflag[v] == 1) // ���� u�� v�� ������ �� �� �����Ѵٸ� 
	{
		temp = G[u].vlist->head; 
		prev = G[u].vlist->head;
		vertex->num = v; // vertex�� ����Ű�� ����� num���� v�� ����

		if (temp == NULL) // ������ �����Ǿ����� ������
		{
			G[u].vlist->head = vertex;
			vertex->link = NULL;
		}

		else if (temp != NULL) // ������ ���� �Ǿ��ִٸ�
		{
			while (temp != NULL) // temp�� NULL�� �ٸ��� ��� �ݺ�
			{
				
			}
		}

		if (temp == NULL) //������ �����Ǿ����� ������
		{
			G[v].vlist->head = vertex; // G[v]�迭�� ����忡 vertex�� �ּ� ����
			vertex->link = NULL; 
		}

		else if (temp != NULL) // ���� ������ ���� �Ǿ��ִٸ�
		{
			
		}

	}
	else
		printf("���� ���� �ȵ�. vertex�� ���� ������ �ֽʽÿ�.\n"); // vflag[u],vflag[v]�� ���� 1�� �ƴ϶�� ������ ���� �����϶�� ���� ���

	return 0; // �Լ� ����
}

int deleteEdge(Graph* G, int u, int v) // ���� ����
{
	
}

int printGraph(Graph* G) 
{
	VertexHead* p = NULL;
	Vertex* temp;

	for (int i = 0; i < MAX_VERTEX; i++) // 0���� 19���� ��� �ݺ�
	{
		if (vflag[i] == 1) // ���� i���� ���� ������ �����Ѵٸ�
		{
			temp = G[i].vlist->head;
			printf("\n\t���� %d�� ���� ����Ʈ", i);

			while (temp != NULL) // temp�� NULL�� ���������� �ݺ�
			{
				printf(" -> [%d]", temp->num); // temp->num �� ���
				temp = temp->link;
			}
		}
	}
	return 0;
}