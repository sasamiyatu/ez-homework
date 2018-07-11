#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Employee Employee;

struct Employee{
    int staffID;
    char familyName[32];
    int age;
    int salary;
    struct Employee *next;
};

void PrintEmployeeColumns() {
    printf("%-6s %-15s %-3s %-6s\n", "ID", "Family Name", "Age", "Salary");
}

void PrintEmployee(Employee *ptr) {
    printf("%-6d %-15s %-3d %-6d\n", ptr->staffID, ptr->familyName, ptr->age, ptr->salary);
}

void EmployeeAdd(Employee **first, int *id, int *current_employee_count){

    if (*current_employee_count == MAX_SIZE) {
        printf("Can't add any more employees.\n");
        return;
    }
    Employee *new_guy = malloc(sizeof(Employee));
    printf("Insert name: ");
    scanf("%s", new_guy->familyName);
    printf("Insert age: ");
    scanf("%d", &(new_guy->age));
    printf("Insert starting salary: ");
    scanf("%d", &(new_guy->salary));
    if (*first == NULL) {
        *first = new_guy;
    } else {
        Employee *current = *first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_guy;
    }
    new_guy->next = NULL;
    new_guy->staffID = *id;
    ++(*id);
    ++(*current_employee_count);
    printf("New employee added:\n");
    PrintEmployeeColumns();
    PrintEmployee(new_guy);
}

void EmployeeFire(Employee **first, int *current_employee_count) {
    if (*first == NULL) {
        printf("You have no employees.\n");
        return;
    }
    int id = 0;

    while (id <= 0) {
        printf("Enter ID of employee to remove: ");

        if (scanf("%d", &id) != 1) { // 誤った入力を見つけたら
            id = 0;                    // とりあえず0番にしておき
            while (getchar() != '\n')    // 改行文字までバッファに残っている文字列をgetchar()で読み込んでくる(バッファをクリアする)
                ;  //セミコロンがあることに注意(while文の中身がない)
        }
    }
    Employee *current = *first;
    Employee *previous = NULL;
    while (current != NULL) {
        if (current->staffID == id) {
            if (previous == NULL) {
                *first = current->next;
            } else if (current->next == NULL) {
                previous->next = NULL;
            } else {
                previous->next = current->next;
            }
            printf("The following employee was fired: \n");
            PrintEmployeeColumns();
            PrintEmployee(current);
            free(current);
            --(*current_employee_count);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No employees found with ID %d\n", id);
}

void ClearArray(Employee *array[], int n) {
    int i = 0;
    for (i = 0; i < n; ++i) {
        array[i] = NULL;
    }
}


void PrintAll(Employee **first) {
    if (*first == NULL) {
        return;
    }
    Employee *current = *first;
    PrintEmployeeColumns();
    while (current != NULL) {
        PrintEmployee(current);
        current = current->next;
    }
}

void EmployeeRaise() {
    printf("You should think again, bro\n");
}


void EmployeeSearchName(Employee **first) {
    if (*first == NULL) {
        printf("You have no employees.\n");
        return;
    }
    char name[32];
    printf("Enter search key: ");
    scanf("%s", name);
    Employee *current = *first;
    Employee *search_result[MAX_SIZE];
    int matches = 0;
    while (current != NULL) {
        if (strcmp(current->familyName, name) == 0) {
            search_result[matches] = current;
            ++matches;
        }
        current = current->next;
    }
    int i = 0;
    if (matches == 0) {
        printf("No matches found.\n");
    } else {
        printf("Showing results for search key \"%s\"\n", name);
        PrintEmployeeColumns();
        for (i = 0; i < matches; ++i) {
            PrintEmployee(search_result[i]);
        }
    }

}

void EmployeeSearchSalary(Employee **first) {
    if (*first == NULL) {
        printf("You have no employees.\n");
        return;
    }
    int salary;
    printf("Enter search key: ");
    scanf("%d", &salary);
    Employee *current = *first;
    Employee *search_result[MAX_SIZE];
    int matches = 0;
    while (current != NULL) {
        if (current->salary == salary) {
            search_result[matches] = current;
            ++matches;
        }
        current = current->next;
    }
    int i = 0;
    if (matches == 0) {
        printf("No matches found.\n");
    } else {
        printf("Showing results for search key %d\n", salary);
        PrintEmployeeColumns();
        for (i = 0; i < matches; ++i) {
            PrintEmployee(search_result[i]);
        }
    }

}

Employee* Med3Name(Employee* x, Employee* y, Employee* z) {
    if (strcmp(x->familyName, y->familyName) < 0) {
        if (strcmp(y->familyName,z->familyName) < 0) return y;
        else if (strcmp(z->familyName, x->familyName) < 0) return x;
        else return z;
    } else {
        if (strcmp(z->familyName, y->familyName) < 0) return y;
        else if (strcmp(x->familyName, z->familyName) < 0) return x;
        else return z;
    }
}

Employee* Med3Salary(Employee* x, Employee* y, Employee* z) {
    if (x->salary < y->salary) {
        if (y->salary < z->salary) return y;
        else if (z->salary < x->salary) return x;
        else return z;
    } else {
        if (z->salary < y->salary) return y;
        else if (x->salary < z->salary) return x;
        else return z;
    }
}

int med3(int x, int y, int z) {
    if (x < y) {
        if (y < z) return y; else if (z < x) return x; else return z;
    } else {
        if (z < y) return y; else if (x < z) return x; else return z;
    }
}

void QuickSortName(Employee *a[], int left, int right ) {
    if (left < right) {
        int i = left, j = right;
        Employee * tmp, * pivot = Med3Name(a[i], a[i + (j - i) / 2], a[j]);
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (strcmp(a[i]->familyName,pivot->familyName) < 0) i++; /* a[i] >= pivot となる位置を検索 */
            while (strcmp(pivot->familyName, a[j]->familyName) < 0) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i], a[j] を交換 */
            i++; j--;
        }
        QuickSortName(a, left, i - 1);  /* 分割した左を再帰的にソート */
        QuickSortName(a, j + 1, right); /* 分割した右を再帰的にソート */
    }
}

void QuickSortSalary(Employee *a[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        Employee * tmp, * pivot = Med3Salary(a[i], a[i + (j-1) / 2], a[j]);
        while (1) {
            while (a[i]->salary < pivot->salary) i++;
            while (pivot->salary < a[j]->salary) j--;
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++; j--;
        }
        QuickSortSalary(a, left, i - 1);
        QuickSortSalary(a, j + 1, right);
    }
}

void ListAllEmployeesName(Employee **first, int *current_employee_count) {
    if (*first == NULL) {
        printf("You have no employees.\n");
        return;
    }
    Employee **by_name = calloc(*current_employee_count,sizeof(Employee*));
    Employee *current = *first;
    int i = 0;
    while (current != NULL) {
        by_name[i] = current;
        current = current->next;
        ++i;
    }
    QuickSortName(by_name, 0, *(current_employee_count)-1);
    printf("List of stoners by name\n");
    PrintEmployeeColumns();
    for (i = 0; i < *current_employee_count; ++i) {
        PrintEmployee(by_name[i]);
    }
    free(by_name);
}

void ListAllEmployeesSalary(Employee **first, int *current_employee_count) {
    if (*first == NULL) {
        printf("You have no employees.\n");
        return;
    }
    Employee **by_salary = calloc(*current_employee_count,sizeof(Employee*));
    Employee *current = *first;
    int i = 0;
    while (current != NULL) {
        by_salary[i] = current;
        current = current->next;
        ++i;
    }
    QuickSortSalary(by_salary, 0, *(current_employee_count)-1);
    printf("List of stoners by salary\n");
    PrintEmployeeColumns();
    for (i = 0; i < *current_employee_count; ++i) {
        PrintEmployee(by_salary[i]);
    }
    free(by_salary);
}

int main(void) {
    Employee *first = NULL;
    int next_id = 1;
    Employee *by_name[MAX_SIZE];
    Employee *by_salary[MAX_SIZE];
    int current_employee_count = 0;
    int menu = 0;
    do{
        printf("**** Employee Management Software 2000 ***\n");
        printf("     1: Add an Employee\n");
        printf("     2: Delete an Employee (FIRE!!!!) \n");
        printf("     3: Change Salary\n");
        printf("     4: Search by Name\n");
        printf("     5: Search by Salary\n");
        printf("     6: List Employees by Name\n");
        printf("     7: List Employees by Salary\n");
        printf("\n");
        printf("     9: End\n");
        printf("\n");
        printf("Select a number: ");
        if (scanf("%d", &menu) != 1) { // 誤った入力を見つけたら
            menu = 0;                    // とりあえず0番にしておき
            while (getchar() != '\n')    // 改行文字までバッファに残っている文字列をgetchar()で読み込んでくる(バッファをクリアする)
                ;  //セミコロンがあることに注意(while文の中身がない)
        }
        printf("\n");

        switch (menu) {
        case 1:
            EmployeeAdd(&first, &next_id, &current_employee_count);
            break;
        case 2:
            EmployeeFire(&first, &current_employee_count);
            break;
        case 3:
            EmployeeRaise();
            break;
        case 4:
            EmployeeSearchName(&first);
            break;
        case 5:
            EmployeeSearchSalary(&first);
            break;
        case 6:
            ListAllEmployeesName(&first, &current_employee_count);
            break;
        case 7:
            ListAllEmployeesSalary(&first, &current_employee_count);
            break;
        case 8:
            PrintAll(&first);
        case 9:
            break;
        default:
            printf("\n Enter a number between 1 and 7\n");
        }
        printf("\n");
    } while (menu != 9);

    return 0;
}
