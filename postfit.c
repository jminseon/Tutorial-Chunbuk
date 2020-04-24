#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stack.h>

#define MAX_STACK_SIZE 10 //������ ũ�� 10���� ����
#define MAX_EXPRESSION_SIZE 20

// stack ������ �켱����, lparen = 0 ���� ����
typedef enum {
	lparen = 0,   //     (    ���� ��ȣ = 0
	rparen = 9,   //     )    ������ ��ȣ = 9
	times = 7,    //     *    ���� = 7
	divide = 6,   //     /    ������ = 6 
	plus = 5,     //     +    ���� = 5
	minus = 4,    //     -    ���� = 4
	operand = 1   //          �ǿ����� = 1
} precedence; //����ü ��Ī

void postfixPush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix(); //�Լ��ϼ��ϱ�
void evaluation(); //�Լ��ϼ��ϱ�
void reset();
void debug();


char infixExp[MAX_EXPRESSION_SIZE]; // infix expression�� �����ϴ� �迭[20]
char postfixExp[MAX_EXPRESSION_SIZE]; // postfix�� ����� ���ڿ��� �����ϴ� �迭[20]
char postfixStack[MAX_STACK_SIZE]; // postfix�� ��ȯ�� ���� �ʿ��� ����[10]
int evalStack[MAX_STACK_SIZE]; // ����� ���� �ʿ��� ����[10]

int postfixStackTop = -1; // postfixStack�� top -1�� �ʱ�ȭ
int evalStackTop = -1; // evalStack�� top -1�� �ʱ�ȭ

int evalResult = 0; // ��� ����� ������ ����

void postfixPush(char x)
{
	postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
	char x;
	if (postfixStackTop == -1)
		return '\0';
	else {
		x = postfixStack[postfixStackTop--];
	}
	return x;
}


void evalPush(int x)
{
	evalStack[++evalStackTop] = x;
}

int evalPop()
{
	if (evalStackTop == -1)
		return -1;
	else
		return evalStack[evalStackTop--];
}


/**
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix() //�� �Է¹ޱ�
{
	printf("Type the expression >>> ");
	scanf("%s", infixExp);
}

precedence getToken(char symbol) //symbol�� �޾Ƽ� ���� Ȯ���ϰ� �װſ� �´� �� ����
{
	switch (symbol) {
	case '(':
		return lparen;
	case ')':
		return rparen;
	case '+':
		return plus;
	case '-':
		return minus;
	case '/':
		return divide;
	case '*':
		return times;
	default:
		return operand;
	}

}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * �����ϳ��� ���޹޾�, postfixExp�� �߰�
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�.*/
void toPostfix()
{
	char *exp = infixExp;// infixExp�� ���� �ϳ����� �б����� ������
	char x; // �����ϳ��� �ӽ÷� �����ϱ� ���� ����

	//exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ����
	while (*exp != '\0')
	{

	}

	/*for (x == getToken(symbol); x != eos; x == getToken(&symbol))
	{
		if (x == operand)
			printf("%c", symbol);
		else if (x == rparen) {
			// ���� ��ȣ�� ���� ������ ��ū���� �����ؼ� ��½�Ŵ
			while (evalStack[top] != lparen)
				printToken(pop(&top));
			pop(&top); // ���� ��ȣ�� ������
		}
		else {
			// symbol�� isp�� token�� icp���� ũ�ų� ������ symbol�� ����, ���
			while (isp[evalStack[top]] >= icp[x])
				printToken(pop(&top));
		}*/
}

void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp); //����
	printf("postExp =  %s\n", postfixExp); //����
	printf("eval result = %d\n", evalResult); //���

	printf("postfixStack : ");
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset() //���� �Լ�
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	//�ݺ����� ���ؼ� ���δ� 0���� ����
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	//�ٽ� �ʱ�ȭ
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	/* postfixExp, evalStack�� �̿��� ��� */
	//���� ������ �Ǿ��ִ� ���� ǥ��� expr�� �����Ѵ�.
	//��\0���� ������ ���� ��Ÿ����.
	//stack�� top�� ���� �����̴�.
	//�Լ� getToken�� ��ū�� Ÿ�԰� ���� �ɹ��� ��ȯ�Ѵ�.
	//�ǿ����ڴ� �� ���ڷ� �� �������� �����Ѵ�.

	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; // ���� ��Ʈ���� ���� ī����
	int top = -1;

	if (n = 0, n < MAX_STACK_SIZE, n++)
	{
		token = postfixExp[n];

		while (token != '\0') {
			if (token == operand) { //��ū�� �����̸�
				evalStack[n] = push(symbol - '0');
			}//48�� ���� ���ÿ� ����
			else { //��ū�� ���ڰ� �ƴϸ�
				
				// �� �ǿ����ڸ� �����Ͽ� ������ ������ ��, �� ����� ���ÿ� ������
				op2 = pop();
				op1 = pop();

				switch (token) {
				case plus:
					evalStack[n] = push(op1 + op2);
					break;
				case minus:
					evalStack[n] = push(op1 - op2);
					break;
				case times:
					evalStack[n] = push(op1*op2);
					break;
				case divide:
					evalStack[n] = push(op1 / op2);
					break;
				}
			}
		}
	}

}

int main()
{
	char command; //����� �Է¹ޱ� ���� ����

	printf("\n====== [���μ�] [2019038083] ======\n");

	do {
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command�� �Է�

		switch (command) {
		case 'i': case 'I': //command�� i�� I�� ���� �Է¹���
			getInfix();
			break;
		case 'p': case 'P': //command�� p�� P�� ����ǥ��� ��ȯ�ϴ� �Լ� ȣ��
			toPostfix();
			break;
		case 'e': case 'E': //command�� e�� E�� ��� �Լ� ȣ��
			evaluation();
			break;
		case 'd': case 'D': //command�� d�� D�� ������Լ� ȣ��
			debug();
			break;
		case 'r': case 'R': //command�� r�� R�� �����Լ� ȣ��
			reset();
			break;
		case 'q': case 'Q': //command�� q�� Q�� ����
			break;
		default: // //command�� �����͵��� �ƴϸ� �Ʒ� �������
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q'); //command�� q�� Q�� �ƴҶ����� �ݺ�

	return 0;
}