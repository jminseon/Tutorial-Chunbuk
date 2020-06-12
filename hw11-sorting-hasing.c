#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE            13    /* prime number */
#define MAX_HASH_TABLE_SIZE     MAX_ARRAY_SIZE
//둘 다 사이즈를 13으로 설정

 /* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);


int main()
{
	char command;
	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;

	srand(time(NULL));

	printf("-------- [ 2019038083 ] [ 전민선 ] --------\n\n");

	do {
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		//메뉴선택 switch문
		switch (command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);

			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;

		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


//배열 초기선언부분
int initialize(int** a)
{
	int *temp = NULL;

	/* array가 NULL인 경우 메모리 할당 */
	if (*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	}
	else
		temp = *a;

	/* 랜덤값을 배열의 값으로 저장 */
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0;
}


//배열해제
int freeArray(int *a)
{
	if (a != NULL)
		free(a);
	return 0;
}


//배열출력
void printArray(int *a)
{
	if (a == NULL) { //a가 NULL이면 nothing to print. 출력
		printf("nothing to print.\n");
		return;
	}

	//a가 NULL이 아니면 for문으로 인덱스 출력
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("a[%02d] ", i);
	printf("\n");

	//출력된 인덱스 밑에 인덱스 값 출력
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]);
	printf("\n");
}


//선택정렬
int selectionSort(int *a)
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);


	//0부터 MAX_ARRAY_SIZE-1까지 반복문
	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		minindex = i; //minindex를 i라고 하고
		min = a[i]; //i번째 인덱스 값을 min에 넣음

		//i+1부터 MAX_ARRAY_SIZE-1까지 반복문을 통해서 작은 값 찾기
		for (j = i + 1; j < MAX_ARRAY_SIZE; j++)
		{
			// min = a[i]의 값보다 a[j]의 값이 작으면
			if (min > a[j])
			{
				min = a[j];  //min을 a[j]로 바꾸고
				minindex = j;  //minindex에도 j를 넣음
			}
		}

		a[minindex] = a[i];
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}


//삽입정렬
int insertionSort(int *a)
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//i=1부터 MAX_ARRAY_SIZE-1까지
	for (i = 1; i < MAX_ARRAY_SIZE; i++)
	{
		t = a[i];
		j = i;

		//a[j - 1]이 t보다 크고 j가 0보다 크면
		while (a[j - 1] > t && j > 0)
		{
			a[j] = a[j - 1];  //a[j - 1]을 a[j]에 넣고 
			j--;  //j는 -1을 함
		}
		a[j] = t; //t값을 a[j]에 넣음
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}


//버블정렬
int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//i=0부터 MAX_ARRAY_SIZE-1까지
	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		//j=0부터 MAX_ARRAY_SIZE-i-1까지
		for (j = 0; j < MAX_ARRAY_SIZE-i; j++)
		{
			//a[j-1]이 a[j]보다 크면
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];  //t에 a[j-1]저장하고
				a[j - 1] = a[j]; //a[j-1]에는 a[j]저장하고
				a[j] = t; //a[j]에는 t저장해서 바꿈
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

//쉘정렬
int shellSort(int *a)
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//MAX_ARRAY_SIZE / 2한 값에서 시작, h가 0보다 클때까지, h는 /2씩
	for (h = MAX_ARRAY_SIZE / 2; h > 0; h /= 2)
	{
		//i는0부터 h-1까지
		for (i = 0; i < h; i++)
		{
			for (j = i + h; j < MAX_ARRAY_SIZE; j += h)
			{
				v = a[j]; //v에는 a[j] 값을
				k = j; //k에는 j값을 넣고

				//k가 h-1보다 크고 a[k-h]가 v보다 크면
				while (k > h - 1 && a[k - h] > v)
				{
					a[k] = a[k - h]; //a[k]에 a[k-h]값을 넣고
					k -= h; //k에는 k-h값을 넣음
				}
				a[k] = v; //a[k]에는 v값을 넣음
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

//퀵정렬
int quickSort(int *a, int n)
{
	int v, t;
	int i, j;

	if (n > 1) //n이 1보다 클때
	{
		v = a[n - 1];
		i = -1;
		j = n - 1;

		while (1)
		{
			while (a[++i] < v);
			while (a[--j] > v);

			if (i >= j) break;
			//a[i]값과 a[j]값을 바꾸는 부분
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}

		//a[i]의 값과 a[n-1]의 값을 바꾸는 부분
		t = a[i];
		a[i] = a[n - 1];
		a[n - 1] = t;

		//퀵정렬다시호출
		quickSort(a, i);
		quickSort(a + i + 1, n - i - 1);
	}


	return 0;
}

int hashCode(int key) {
	return key % MAX_HASH_TABLE_SIZE; //key를 13으로 나눠서 리턴
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL;

	/* hash table이 NULL인 경우 메모리 할당 */
	if (*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	}
	else {
		hashtable = *ht;    /* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}

	for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1;
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key);
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/

		//hashtable[hashcode]가 -1이면 hashtable[hashcode]에 key 값 저장
		if (hashtable[hashcode] == -1){
			hashtable[hashcode] = key;
		}

		//hashtable[hashcode]가 -1이 아니면
		else {

			//index에 hashcode를 넣고
			index = hashcode;

			//hashtable[index]가 -1이 아닌동안 반복
			while (hashtable[index] != -1)
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key;
		}
	}

	return 0;
}

//검색
int search(int *ht, int key)
{
	int index = hashCode(key); //index에 hashCode(key)넣음

	//ht[index]와 key값이 같으면 index리턴
	if (ht[index] == key)
		return index;

	//ht[++index]가 key값이랑 다르면
	while (ht[++index] != key)
	{
		index = index % MAX_HASH_TABLE_SIZE; //index에 index % 13을 넣음
	}
	return index;
}