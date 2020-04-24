#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stack.h>

#define MAX_STACK_SIZE 10 //스택의 크기 10으로 고정
#define MAX_EXPRESSION_SIZE 20

// stack 내에서 우선순위, lparen = 0 가장 낮음
typedef enum {
	lparen = 0,   //     (    왼쪽 괄호 = 0
	rparen = 9,   //     )    오른쪽 괄호 = 9
	times = 7,    //     *    곱셈 = 7
	divide = 6,   //     /    나눗셈 = 6 
	plus = 5,     //     +    덧셈 = 5
	minus = 4,    //     -    뺄셈 = 4
	operand = 1   //          피연산자 = 1
} precedence; //구조체 별칭

void postfixPush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix(); //함수완성하기
void evaluation(); //함수완성하기
void reset();
void debug();


char infixExp[MAX_EXPRESSION_SIZE]; // infix expression을 저장하는 배열[20]
char postfixExp[MAX_EXPRESSION_SIZE]; // postfix로 변경된 문자열을 저장하는 배열[20]
char postfixStack[MAX_STACK_SIZE]; // postfix로 변환을 위해 필요한 스택[10]
int evalStack[MAX_STACK_SIZE]; // 계산을 위해 필요한 스택[10]

int postfixStackTop = -1; // postfixStack용 top -1로 초기화
int evalStackTop = -1; // evalStack용 top -1로 초기화

int evalResult = 0; // 계산 결과를 저장할 변수

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
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix() //값 입력받기
{
	printf("Type the expression >>> ");
	scanf("%s", infixExp);
}

precedence getToken(char symbol) //symbol을 받아서 뭔지 확인하고 그거에 맞는 값 리턴
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
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.*/
void toPostfix()
{
	char *exp = infixExp;// infixExp의 문자 하나씩을 읽기위한 포인터
	char x; // 문자하나를 임시로 저장하기 위한 변수

	//exp를 증가시켜가면서, 문자를 읽고 postfix로 변경
	while (*exp != '\0')
	{

	}

	/*for (x == getToken(symbol); x != eos; x == getToken(&symbol))
	{
		if (x == operand)
			printf("%c", symbol);
		else if (x == rparen) {
			// 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴
			while (evalStack[top] != lparen)
				printToken(pop(&top));
			pop(&top); // 왼쪽 괄호를 버린다
		}
		else {
			// symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거, 출력
			while (isp[evalStack[top]] >= icp[x])
				printToken(pop(&top));
		}*/
}

void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp); //중위
	printf("postExp =  %s\n", postfixExp); //후위
	printf("eval result = %d\n", evalResult); //결과

	printf("postfixStack : ");
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset() //리셋 함수
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	//반복문을 통해서 전부다 0으로 리셋
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	//다시 초기화
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	/* postfixExp, evalStack을 이용한 계산 */
	//전역 변수로 되어있는 후위 표기식 expr을 연산한다.
	//‘\0’은 수식의 끝을 나타낸다.
	//stack과 top은 전역 변수이다.
	//함수 getToken은 토큰의 타입과 문자 심벌을 반환한다.
	//피연산자는 한 문자로 된 숫자임을 가정한다.

	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; // 수식 스트링을 위한 카운터
	int top = -1;

	if (n = 0, n < MAX_STACK_SIZE, n++)
	{
		token = postfixExp[n];

		while (token != '\0') {
			if (token == operand) { //토큰이 숫자이면
				evalStack[n] = push(symbol - '0');
			}//48을 빼서 스택에 삽입
			else { //토큰이 숫자가 아니면
				
				// 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함
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
	char command; //명령을 입력받기 위한 변수

	printf("\n====== [전민선] [2019038083] ======\n");

	do {
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command값 입력

		switch (command) {
		case 'i': case 'I': //command가 i나 I면 값을 입력받음
			getInfix();
			break;
		case 'p': case 'P': //command가 p나 P면 후위표기로 변환하는 함수 호출
			toPostfix();
			break;
		case 'e': case 'E': //command가 e나 E면 계산 함수 호출
			evaluation();
			break;
		case 'd': case 'D': //command가 d나 D면 디버그함수 호출
			debug();
			break;
		case 'r': case 'R': //command가 r나 R면 리셋함수 호출
			reset();
			break;
		case 'q': case 'Q': //command가 q나 Q면 종료
			break;
		default: // //command가 위에것들이 아니면 아래 문구출력
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q'); //command가 q나 Q가 아닐때까지 반복

	return 0;
}