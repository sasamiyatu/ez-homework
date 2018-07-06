#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int staffID;
  char familyName[32];
  int age;
  int salary;
} Employee;

void EmployeeAdd(Employee employees[]){
  printf("You added someone, maybe\n");
  printf("社員を追加します。\n");
  printf("追加する社員の名前を入力してください: \n");
  printf("年齢を入力してください：\n");
}

void EmployeeFire() {
  printf("Someone got fired...again\n");
}

void EmployeeRaise() {
  printf("You should think again, bro\n");
}

void EmployeeSearchName() {
  printf("FIND THAT STONER AND SHOOT HIM\n");
}

void EmployeeSearchSalary() {
  printf("I don't think searching based on SALARY will help you bro\n");
}

void ListAllEmployeesName() {
  printf("List of stoners by name\n");
}

void ListAllEmployeesSalary() {
  printf("This one was easy to sort LOL\n");
}

int main(void) {
  Employee employees[100];
  int menu = 0;
  do{
    printf("**** 社員データベース管理プログラム ***\n");
    printf("     1: 社員追加\n");
    printf("     2: 社員削除\n");
    printf("     3: 昇給\n");
    printf("     4: 社員検索（名前）\n");
    printf("     5: 社員検索（年俸）\n");
    printf("     6: 全社員の表示（名前順）\n");
    printf("     7: 全社員の表示（年俸順）\n");
    printf("\n");
    printf("     9: End\n");
    printf("\n");
    printf("Select a number ? ");
    if (scanf("%d", &menu) != 1) { // 誤った入力を見つけたら
      menu = 0;                    // とりあえず0番にしておき
      while (getchar() != '\n')    // 改行文字までバッファに残っている文字列をgetchar()で読み込んでくる(バッファをクリアする)
        ;  //セミコロンがあることに注意(while文の中身がない)
    }
    printf("\n");
   
    switch (menu) {
    case 1:
      EmployeeAdd(employees);
      break;
    case 2:
      EmployeeFire();
      break;
    case 3:
      EmployeeRaise();
      break;
    case 4:
      EmployeeSearchName();
      break;
    case 5:
      EmployeeSearchSalary();
      break;
    case 6:
      ListAllEmployeesName();
      break;
    case 7:
      ListAllEmployeesSalary();
      break;
    case 9:
      break;
    default:
      printf("\n 1〜7までの数字，または9を入力してください\n");
    }
    printf("\n");
  } while (menu != 9);

}
