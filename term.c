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

Graph* createGraph(Graph* G); // 그래프 초기화
int destoryGraph(Graph* G); // 그래프 모든 메모리를 해제
int insertVertex(Graph* G, int num); // 정점 삽입
int deleteVertex(Graph* G, int num); // 정점 제거
int insertEdge(Graph* G, int u, int v); // 간선 추가
int deleteEdge(Graph* G, int u, int v); // 간선 제거
void depthFS();
void breadthFS();
int printGraph(Graph* G); // 그래프 정점, 간선 출력

int vflag[MAX_VERTEX] = { 0 }; // 정점이 만들어졌는지 여부를 판단하는 배열

int main()
{
	char command; // 명령어 지역 변수 
	int u, v, num, key;
	Graph* Graph = NULL;

	do {
		printf("========================================================\n"); // 메뉴 출력
		printf("                     무방향 그래프                        \n");
		printf("========================================================\n");
		printf(" createGraph   = z           Print         = p \n");
		printf(" Insert Vertex = i           Delete Vertex = d \n");
		printf(" Insert Edge   = n           Delete Edge   = e \n");
		printf(" depthFS       = f           breadthFS     = b \n");
		printf(" destoryGraph  = t           Quit          = q \n");
		printf("========================================================\n");

		printf("Command = ");
		scanf_s(" %c", &command); // 명령어 입력

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
			scanf_s("%d", &num); // key값 입력
			insertVertex(Graph, num); // 정점 그래프에 삽입
			break;

		case 'd': case 'D':
			printf("Delete Vertex Number = ");
			scanf_s("%d", &num);
			deleteVertex(Graph, num); // 정점 삭제
			break;

		case 'n': case 'N': 
			printf("Input Edge u,v = "); // 문구 출력
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
			destoryGraph(Graph); // 그래프 할당 메모리 해제
			break;

		case 'q': case 'Q': 
			destoryGraph(Graph);
			break;

		default: 
			printf("\n ========== Concentration! =========== \n"); //문구 출력
			break;
		}
	} while (command != 'q' && command != 'Q'); //반복문 종료

	return 1;
}

Graph* createGraph(Graph* G) // 그래프  새로 생성
{
	Graph* g = (VertexHead*)malloc(sizeof(VertexHead) * MAX_VERTEX);

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		g[i].vlist = NULL; // 인덱스값 NULL로 초기화
		vflag[i] = 0; // vflag의 해당 인덱스에도 0값을 대입한다
	}

	return g; // 포인터 g 리턴
}

int destoryGraph(Graph* G) //메모리를 해제
{
	VertexHead* p = NULL;
	Vertex* temp = NULL;
	Vertex* prev = NULL;

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		if (vflag[i] == 1) // 만약 i값을 가진 정점이 생성되어있다면
		{
			
		}
	}
	free(G); //메모리 해제


	return 0;
}

int insertVertex(Graph* G, int num) // 그래프에 정점을 삽입하는 함수
{
	VertexHead* head = (VertexHead*)malloc(sizeof(VertexHead)); // 헤드노드 포인터 변수
	head->head = NULL; // head노드의 값 NULL로 초기화

	if (vflag[num] == 1) // 입력받은 NUM을 가진 정점이 존재하면, 
		printf("이미 해당 Vertex가 존재합니다.\n"); // 문구 출력

	else // 입력받은 NUM을 가진 정점이 그래프에 없다면
	{
		
	}

	return 0; 
}

int deleteVertex(Graph* G, int num) // 정점 삭제
{
	
}

int insertEdge(Graph* G, int u, int v) // 간선을 생성하는 함수
{
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex)); // 연결리스트에 연결할 vertex 변수
	Vertex* temp = NULL; // 정점을 가리킬 포인터 ㅂ녀수
	Vertex* prev = NULL; // 정점을 가리킬 포인터 변수


	if (vflag[u] == 1 && vflag[v] == 1) // 만약 u와 v의 정점이 둘 다 존재한다면 
	{
		temp = G[u].vlist->head; 
		prev = G[u].vlist->head;
		vertex->num = v; // vertex가 가리키는 노드의 num값에 v를 대입

		if (temp == NULL) // 간선이 생성되어있지 않으면
		{
			G[u].vlist->head = vertex;
			vertex->link = NULL;
		}

		else if (temp != NULL) // 간선이 생성 되어있다면
		{
			while (temp != NULL) // temp가 NULL과 다르면 계속 반복
			{
				
			}
		}

		if (temp == NULL) //간선이 생성되어있지 않으면
		{
			G[v].vlist->head = vertex; // G[v]배열의 헤드노드에 vertex의 주소 대입
			vertex->link = NULL; 
		}

		else if (temp != NULL) // 만약 간선이 생성 되어있다면
		{
			
		}

	}
	else
		printf("정점 생성 안됨. vertex를 먼저 생성해 주십시오.\n"); // vflag[u],vflag[v]의 값이 1이 아니라면 정점을 먼저 생성하라는 문구 출력

	return 0; // 함수 종료
}

int deleteEdge(Graph* G, int u, int v) // 간선 삭제
{
	
}

int printGraph(Graph* G) 
{
	VertexHead* p = NULL;
	Vertex* temp;

	for (int i = 0; i < MAX_VERTEX; i++) // 0부터 19까지 계속 반복
	{
		if (vflag[i] == 1) // 만약 i값을 가진 정점이 존재한다면
		{
			temp = G[i].vlist->head;
			printf("\n\t정점 %d의 인접 리스트", i);

			while (temp != NULL) // temp랑 NULL이 같지않으면 반복
			{
				printf(" -> [%d]", temp->num); // temp->num 값 출력
				temp = temp->link;
			}
		}
	}
	return 0;
}