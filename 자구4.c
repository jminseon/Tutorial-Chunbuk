#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//사용할 함수 선언
int** create_matrix(int row, int col); //2차원배열 생성 함수 동적메모리할당
int free_matrix(int** matrix, int row, int col); //동적메모리해제
void print_matrix(int** matrix, int row, int col); //연산이 끝나면 결과값 출력
int fill_data(int **matrix, int row, int col); //0~19사이의 랜덤값으로 성분채우기
int transpose_matrix(int **matrix, int **matrix_t, int row, int col); //전치행렬 구하기
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col); //더하기
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col); //빼기
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col); //곱하기


int rowsize, colsize; //행과 열의 값을 입력받을 변수, 행렬의 크기 변수
int** A, B, T; //행렬 A, B, 전치행렬 T
int** add, sub, axt; // A+B  A-B  A*T 행렬
int a, b, t, Add, Sub, Axt; //함수가 정상작동했는지 알아보기위해 리턴한 값을 저장할 변수


//2차원배열 생성 함수
int** create_matrix(int row, int col)
{
	int** matrix;
	int i; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	//행렬을 만들기 위한 동적할당
	matrix = (int**)malloc(sizeof(int**) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int**)malloc(sizeof(int*) * col);
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	return matrix;
}


//동적메모리해제
int free_matrix(int** matrix, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		free(matrix[i]);
	}

	//반복문의 값이 행의크기만큼 작동했으면 정상작동했다고 판단하고 6을 리턴 아니면 -6리턴
	if (i == row)
		return 6;
	else
		return -6;
}


//연산이 끝나면 결과값 출력
void print_matrix(int** matrix, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d", matrix[i][j]);
			if (j == (col - 1)) //j의 값이 열보다 1작을 때 다음행으로 넘어가기 위해 \n출력
				printf("\n");
		}
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}
}


//0~19사이의 랜덤값으로 성분채우기
int fill_data(int **matrix, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix[i][j] = rand() % 20; //0~19 값을 랜덤으로 채움
		}
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}
	
	//반복문에서 i의 값이 row까지, j의 값이 col까지 갔으면 함수가 정상작동했다고 판단하고 1을 리턴 아니면 -1리턴
	if (i == row && j == col)
		return 1;
	else
		return -1;
}


//전치행렬구하기
int transpose_matrix(int **matrix, int **matrix_t, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	//전치행렬 T의 성분 값을 모두 0으로 초기화
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_t[i][j] = 0;
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_t[j][i] = matrix[i][j];
		}
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix_t == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//반복문에서 i의 값이 row까지, j의 값이 col까지 갔으면 함수가 정상작동했다고 판단하고 4리턴 아니면 -4리턴
	if (i == row && j == col)
		return 4;
	else
		return -4;
}


//더하기
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix_sum == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//반복문에서 i의 값이 row까지, j의 값이 col까지 갔으면 함수가 정상작동했다고 판단하고 2리턴 아니면 -2리턴
	if (i == row && j == col)
		return 2;
	else
		return -2;
}


//빼기
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
		}
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix_sub == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//반복문에서 i의 값이 row까지, j의 값이 col까지 갔으면 함수가 정상작동했다고 판단하고 3리턴 아니면 -3리턴
	if (i == row && j == col)
		return 3;
	else
		return -3;
}


//곱하기
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col)
{
	int i, j; //반복문을 위한 지역변수

	//행과 열의 값이 0보다 작으면 경고문을 출력하고 -1을 리턴하여 에러를 알 수 있게함
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_axt[i][j] = matrix_a[i][j] * matrix_t[i][j];
		}
	}

	//행렬이 비어있으면 경고문을 출력하고 -2를 리턴하여 에러를 알 수 있게 함
	if (matrix_axt == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//반복문에서 i의 값이 row까지, j의 값이 col까지 갔으면 함수가 정상작동했다고 판단하고 5리턴 아니면 -5리턴
	if (i == row && j == col)
		return 5;
	else
		return -5;
}


int main(void)
{
	//scanf를 사용하여 행과열의 값을 입력받는 부분
	printf("행의 크기 입력 : ");
	scanf("%d", &rowsize);
	printf("열의 크기 입력 : ");
	scanf("%d", &colsize);

	srand((unsigned)time(NULL)); //실행할때마다 성분에 다른 값을 채우기 위해 선언

	//행렬을 생성하기 위한 함수 호출
	A = create_matrix(rowsize, colsize); //행렬 A를 동적할당으로 생성
	B = create_matrix(rowsize, colsize); //행렬 B를 동적할당으로 생성
	T = create_matrix(rowsize, colsize); //행렬 T를 동적할당으로 생성
	add = create_matrix(rowsize, colsize); //행렬 add를 동적할당으로 생성
	sub = create_matrix(rowsize, colsize); //행렬 sub를 동적할당으로 생성
	axt = create_matrix(rowsize, colsize); //행렬 axt를 동적할당으로 생성

	//행렬을 채우기 위한 함수 호출
	a = fill_data(A, rowsize, colsize); //행렬 A의 성분을 랜덤값으로 채움
	b = fill_data(B, rowsize, colsize); //행렬 B의 성분을 랜덤값으로 채움
	printf("\n fill_data 함수 2번 (1:정상/-1:비정상) %3d %3d\n", a, b); //둘다 1이나오면 함수정상작동확인

	//AB 더하기 빼기
	Add = addition_matrix(A, B, add, rowsize, colsize); //A+B 구하기
	Sub = subtraction_matrix(A, B, sub, rowsize, colsize); //A-B 구하기
	printf("\n addition_matrix 함수 1번 (2:정상/-2:비정상) %3d\n", Add); //2가 나오면 함수정상작동확인
	printf("\n subtraction_matrix 함수 1번 (3:정상/-3:비정상) %3d\n", Sub); //3이 나오면 함수정상작동확인

	//전치행렬구하고 AT 곱하기
	t = transpose_matrix(A, T, rowsize, colsize); //전치행렬T 구하기
	Axt = multiply_matrix(A, T, axt, rowsize, colsize); //A*T구하기
	printf("\n transpose_matrix 함수 1번 (4:정상/-4:비정상) %3d\n", t); //4가 나오면 함수정상작동확인
	printf("\n multiply_matrix 함수 1번 (5:정상/-5:비정상) %3d\n", Axt); //5가 나오면 함수정상작동확인

	//결과값 프린트
	printf("\n\n행렬 A\n");  print_matrix(A, rowsize, colsize); //행렬 A 출력
	printf("\n\n행렬 B\n");  print_matrix(B, rowsize, colsize); //행렬 B 출력
	printf("\n\n행렬 T : A의 전치행렬\n");  print_matrix(T, rowsize, colsize); //A의 전치행렬 T 출력
	printf("\n\n행렬 add : A + B\n");  print_matrix(add, rowsize, colsize); //A+B 출력
	printf("\n\n행렬 sub : A - B\n");  print_matrix(sub, rowsize, colsize); //A-B 출력
	printf("\n\n행렬 axt : A * T\n");  print_matrix(axt, rowsize, colsize); //A*T 출력

	//동적할당 해제
	a = free_matrix(A, rowsize, colsize);
	b = free_matrix(B, rowsize, colsize);
	t = free_matrix(T, rowsize, colsize);
	Add = free_matrix(add, rowsize, colsize);
	Sub = free_matrix(sub, rowsize, colsize);
	Axt = free_matrix(axt, rowsize, colsize);

	//6이 6개 나오면 함수정상작동확인
	printf("\n free_matrix 함수 6번 (6:정상/-6:비정상) %3d %3d %3d %3d %3d %3d\n", a, b, t, Add, Sub, Axt);

	printf("\n[----- [전민선] [2019038083] -----]\n\n");

	system("pause");
	return 0;
}