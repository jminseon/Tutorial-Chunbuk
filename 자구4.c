#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//����� �Լ� ����
int** create_matrix(int row, int col); //2�����迭 ���� �Լ� �����޸��Ҵ�
int free_matrix(int** matrix, int row, int col); //�����޸�����
void print_matrix(int** matrix, int row, int col); //������ ������ ����� ���
int fill_data(int **matrix, int row, int col); //0~19������ ���������� ����ä���
int transpose_matrix(int **matrix, int **matrix_t, int row, int col); //��ġ��� ���ϱ�
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col); //���ϱ�
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col); //����
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col); //���ϱ�


int rowsize, colsize; //��� ���� ���� �Է¹��� ����, ����� ũ�� ����
int** A, B, T; //��� A, B, ��ġ��� T
int** add, sub, axt; // A+B  A-B  A*T ���
int a, b, t, Add, Sub, Axt; //�Լ��� �����۵��ߴ��� �˾ƺ������� ������ ���� ������ ����


//2�����迭 ���� �Լ�
int** create_matrix(int row, int col)
{
	int** matrix;
	int i; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	//����� ����� ���� �����Ҵ�
	matrix = (int**)malloc(sizeof(int**) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int**)malloc(sizeof(int*) * col);
	}

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	return matrix;
}


//�����޸�����
int free_matrix(int** matrix, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		free(matrix[i]);
	}

	//�ݺ����� ���� ����ũ�⸸ŭ �۵������� �����۵��ߴٰ� �Ǵ��ϰ� 6�� ���� �ƴϸ� -6����
	if (i == row)
		return 6;
	else
		return -6;
}


//������ ������ ����� ���
void print_matrix(int** matrix, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d", matrix[i][j]);
			if (j == (col - 1)) //j�� ���� ������ 1���� �� ���������� �Ѿ�� ���� \n���
				printf("\n");
		}
	}

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}
}


//0~19������ ���������� ����ä���
int fill_data(int **matrix, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix[i][j] = rand() % 20; //0~19 ���� �������� ä��
		}
	}

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}
	
	//�ݺ������� i�� ���� row����, j�� ���� col���� ������ �Լ��� �����۵��ߴٰ� �Ǵ��ϰ� 1�� ���� �ƴϸ� -1����
	if (i == row && j == col)
		return 1;
	else
		return -1;
}


//��ġ��ı��ϱ�
int transpose_matrix(int **matrix, int **matrix_t, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	//��ġ��� T�� ���� ���� ��� 0���� �ʱ�ȭ
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

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix_t == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//�ݺ������� i�� ���� row����, j�� ���� col���� ������ �Լ��� �����۵��ߴٰ� �Ǵ��ϰ� 4���� �ƴϸ� -4����
	if (i == row && j == col)
		return 4;
	else
		return -4;
}


//���ϱ�
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix_sum == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//�ݺ������� i�� ���� row����, j�� ���� col���� ������ �Լ��� �����۵��ߴٰ� �Ǵ��ϰ� 2���� �ƴϸ� -2����
	if (i == row && j == col)
		return 2;
	else
		return -2;
}


//����
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
		}
	}

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix_sub == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//�ݺ������� i�� ���� row����, j�� ���� col���� ������ �Լ��� �����۵��ߴٰ� �Ǵ��ϰ� 3���� �ƴϸ� -3����
	if (i == row && j == col)
		return 3;
	else
		return -3;
}


//���ϱ�
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col)
{
	int i, j; //�ݺ����� ���� ��������

	//��� ���� ���� 0���� ������ ����� ����ϰ� -1�� �����Ͽ� ������ �� �� �ְ���
	if (row <= 0 || col <= 0) {
		printf("Check the sizes of row and col!\n");
		return -1;
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix_axt[i][j] = matrix_a[i][j] * matrix_t[i][j];
		}
	}

	//����� ��������� ����� ����ϰ� -2�� �����Ͽ� ������ �� �� �ְ� ��
	if (matrix_axt == NULL) {
		printf("Check the matrix!\n");
		return -2;
	}

	//�ݺ������� i�� ���� row����, j�� ���� col���� ������ �Լ��� �����۵��ߴٰ� �Ǵ��ϰ� 5���� �ƴϸ� -5����
	if (i == row && j == col)
		return 5;
	else
		return -5;
}


int main(void)
{
	//scanf�� ����Ͽ� ������� ���� �Է¹޴� �κ�
	printf("���� ũ�� �Է� : ");
	scanf("%d", &rowsize);
	printf("���� ũ�� �Է� : ");
	scanf("%d", &colsize);

	srand((unsigned)time(NULL)); //�����Ҷ����� ���п� �ٸ� ���� ä��� ���� ����

	//����� �����ϱ� ���� �Լ� ȣ��
	A = create_matrix(rowsize, colsize); //��� A�� �����Ҵ����� ����
	B = create_matrix(rowsize, colsize); //��� B�� �����Ҵ����� ����
	T = create_matrix(rowsize, colsize); //��� T�� �����Ҵ����� ����
	add = create_matrix(rowsize, colsize); //��� add�� �����Ҵ����� ����
	sub = create_matrix(rowsize, colsize); //��� sub�� �����Ҵ����� ����
	axt = create_matrix(rowsize, colsize); //��� axt�� �����Ҵ����� ����

	//����� ä��� ���� �Լ� ȣ��
	a = fill_data(A, rowsize, colsize); //��� A�� ������ ���������� ä��
	b = fill_data(B, rowsize, colsize); //��� B�� ������ ���������� ä��
	printf("\n fill_data �Լ� 2�� (1:����/-1:������) %3d %3d\n", a, b); //�Ѵ� 1�̳����� �Լ������۵�Ȯ��

	//AB ���ϱ� ����
	Add = addition_matrix(A, B, add, rowsize, colsize); //A+B ���ϱ�
	Sub = subtraction_matrix(A, B, sub, rowsize, colsize); //A-B ���ϱ�
	printf("\n addition_matrix �Լ� 1�� (2:����/-2:������) %3d\n", Add); //2�� ������ �Լ������۵�Ȯ��
	printf("\n subtraction_matrix �Լ� 1�� (3:����/-3:������) %3d\n", Sub); //3�� ������ �Լ������۵�Ȯ��

	//��ġ��ı��ϰ� AT ���ϱ�
	t = transpose_matrix(A, T, rowsize, colsize); //��ġ���T ���ϱ�
	Axt = multiply_matrix(A, T, axt, rowsize, colsize); //A*T���ϱ�
	printf("\n transpose_matrix �Լ� 1�� (4:����/-4:������) %3d\n", t); //4�� ������ �Լ������۵�Ȯ��
	printf("\n multiply_matrix �Լ� 1�� (5:����/-5:������) %3d\n", Axt); //5�� ������ �Լ������۵�Ȯ��

	//����� ����Ʈ
	printf("\n\n��� A\n");  print_matrix(A, rowsize, colsize); //��� A ���
	printf("\n\n��� B\n");  print_matrix(B, rowsize, colsize); //��� B ���
	printf("\n\n��� T : A�� ��ġ���\n");  print_matrix(T, rowsize, colsize); //A�� ��ġ��� T ���
	printf("\n\n��� add : A + B\n");  print_matrix(add, rowsize, colsize); //A+B ���
	printf("\n\n��� sub : A - B\n");  print_matrix(sub, rowsize, colsize); //A-B ���
	printf("\n\n��� axt : A * T\n");  print_matrix(axt, rowsize, colsize); //A*T ���

	//�����Ҵ� ����
	a = free_matrix(A, rowsize, colsize);
	b = free_matrix(B, rowsize, colsize);
	t = free_matrix(T, rowsize, colsize);
	Add = free_matrix(add, rowsize, colsize);
	Sub = free_matrix(sub, rowsize, colsize);
	Axt = free_matrix(axt, rowsize, colsize);

	//6�� 6�� ������ �Լ������۵�Ȯ��
	printf("\n free_matrix �Լ� 6�� (6:����/-6:������) %3d %3d %3d %3d %3d %3d\n", a, b, t, Add, Sub, Axt);

	printf("\n[----- [���μ�] [2019038083] -----]\n\n");

	system("pause");
	return 0;
}