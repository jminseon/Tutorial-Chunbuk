#include <stdio.h>

struct student1 { //student ����ü ����
   char lastName;
   int studentId;
   char grade;
};

typedef struct{ //student2 ����ü ����
   char lastName;
   int studentId;
   char grade;
} student2;

int main() {
   struct student1 st1 = { 'A', 100, 'A' }; //student1�� A, 100, A�� �ʱ�ȭ
   //struct ����ü Ű���带 ���� ������ �����߻�

   printf("st1.lastName = %c\n", st1.lastName); //A
   printf("st1.studentId = %d\n", st1.studentId); //100
   printf("st1.grade = %c\n", st1.grade); //A�� ��µ�

   student2 st2 = { 'B', 200, 'B' }; //student2�� B, 200, B�� �ʱ�ȭ
   //struct ����ü Ű���带 ���� �ʾƵ� ������ typedef�� ��� ����

   printf("\nst2.lastName = %c\n", st2.lastName); //B
   printf("st2.studentId = %d\n", st2.studentId); //200
   printf("st2.grade = %c\n", st2.grade); //B

   student2 st3; //student2 ����ü�� st3 ����

   st3 = st2; //st2�� ���� st3�� ����

   printf("\nst3.lastName = %c\n", st3.lastName); //B
   printf("st3.studentId = %d\n", st3.studentId); //200
   printf("st3.grade = %c\n", st3.grade); //B�� ��µ�

   //equality test //st3=st2;������ �� ������ ���� ������ ���� ���
   if ((st3.lastName == st2.lastName)&&(st3.studentId == st2.studentId)&&(st3.grade == st2.grade))
      printf("equal\n");
   else
      printf("not equal\n");
    //����ü ������ ������ ��� ���ƾ� equal�� ��µǰ� ����
    //equal�� ��µǹǷ� st3�� st2�� ���� ��� �����ϴٴ� ���� �� �� ����
   
    printf("\n[----- [���μ�] [2019038083] -----]\n");
     
   return 0;
}