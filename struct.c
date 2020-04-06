#include <stdio.h>

struct student1 { //student 구조체 선언
   char lastName;
   int studentId;
   char grade;
};

typedef struct{ //student2 구조체 선언
   char lastName;
   int studentId;
   char grade;
} student2;

int main() {
   struct student1 st1 = { 'A', 100, 'A' }; //student1을 A, 100, A로 초기화
   //struct 구조체 키워드를 쓰지 않으면 에러발생

   printf("st1.lastName = %c\n", st1.lastName); //A
   printf("st1.studentId = %d\n", st1.studentId); //100
   printf("st1.grade = %c\n", st1.grade); //A가 출력됨

   student2 st2 = { 'B', 200, 'B' }; //student2를 B, 200, B로 초기화
   //struct 구조체 키워드를 쓰지 않아도 괜찮음 typedef를 썼기 때문

   printf("\nst2.lastName = %c\n", st2.lastName); //B
   printf("st2.studentId = %d\n", st2.studentId); //200
   printf("st2.grade = %c\n", st2.grade); //B

   student2 st3; //student2 구조체에 st3 선언

   st3 = st2; //st2의 값을 st3로 복사

   printf("\nst3.lastName = %c\n", st3.lastName); //B
   printf("st3.studentId = %d\n", st3.studentId); //200
   printf("st3.grade = %c\n", st3.grade); //B가 출력됨

   //equality test //st3=st2;했을떄 각 변수의 값이 같은지 보는 방법
   if ((st3.lastName == st2.lastName)&&(st3.studentId == st2.studentId)&&(st3.grade == st2.grade))
      printf("equal\n");
   else
      printf("not equal\n");
    //구조체 변수의 값들이 모두 같아야 equal이 출력되게 만듬
    //equal이 출력되므로 st3와 st2의 값이 모두 동일하다는 것을 알 수 있음
   
    printf("\n[----- [전민선] [2019038083] -----]\n");
     
   return 0;
}