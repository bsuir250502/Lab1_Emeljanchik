#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE( x )  (sizeof( x )/sizeof( *x ))
typedef struct {
    char surname[40];
    char name[40];
    char father_name[50];
    int salary[12];
} employee_t;

int compare_employees_by_surname(const void *a, const void *b)
{
    const employee_t *ap = a;
    const employee_t *bp = b;
    return strcmp(ap->surname, bp->surname);
}

void display_employees(employee_t *employees, size_t size)
{
    employee_t *e;
    size_t i,j;
    puts(" Surname       | Name          | Father name   | Salary");
    puts("---------------+---------------+---------------+-------");
    for(i = 0 ; i < size ; i++ ) {
        e = &employees[i];
        printf("%15s|%15s|%15s|", e->surname, e->name, e->father_name);
        for(j = 0; j < 12; j++) {
            printf(" %d", e->salary[j]);
        }
        puts("");
    }
}

char *my_gets(char *buf, size_t size)
{
    fgets(buf, size, stdin);
    buf[strlen(buf)-1] = '\0';
    return buf;
}

void sort_employees(employee_t *employees, size_t size)
{
    qsort(employees, size, sizeof(*employees), compare_employees_by_surname);
}

const char * month_name(int month)
{
    switch(month){
    case  0: return "January";
    case  1: return "February";
    case  2: return "March";
    case  3: return "April";
    case  4: return "May";
    case  5: return "June";
    case  6: return "July";
    case  7: return "August";
    case  8: return "September";
    case  9: return "October";
    case 10: return "November";
    case 11: return "December";
    };
    return "INCORRECT_MONTH";
}

int try_read_number(int * target)
{
    char *end;
    char input_buffer[1024];
    my_gets(input_buffer, SIZE(input_buffer));
    *target = strtol(input_buffer, &end, 10);
    if(*end) {
        return 1;
    }
    return 0;
}

int read_number_in_range(int min, int max)
{
    int result;
    int error;
    do{
        printf("Enter number between %d and %d: ", min, max);
        error = try_read_number(&result);
    } while( error || result < min || result > max );
    return result;
}

int main()
{
    unsigned int i;
    int month;
    employee_t employees[25];
    size_t number_of_employees;
    for (i = 0; i < SIZE(employees); i++) {
        printf("Enter surname for employee #%u (or press enter to stop): ", i+1);
        my_gets(employees[i].surname, SIZE(employees[i].surname));
        if(!strcmp(employees[i].surname,"")){
            break;
        }
        printf("Enter name for employee #%u: ", i+1);
        my_gets(employees[i].name, SIZE(employees[i].name));
        printf("Enter father name for employee #%u: ", i+1);
        my_gets(employees[i].father_name, SIZE(employees[i].father_name));
        for (month = 0; month < 12; month++) {
            printf("Enter salary in %s: ", month_name(month));
            employees[i].salary[month] = read_number_in_range(0,20000);
        }
    }
    number_of_employees = i;
    sort_employees(employees, number_of_employees);
    printf("User surname, name, father name and salarys:\n");
    display_employees(employees, number_of_employees);
    return 0;
}
