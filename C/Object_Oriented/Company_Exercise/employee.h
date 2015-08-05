#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NAME_SIZE 50


typedef struct s_employee
{
    struct p_employee* private;
    int (*f_get_name)(const struct s_employee* _obj, char** _name);
    int (*f_get_age)(const struct s_employee* _obj, int* _age);
    int (*f_get_salary)(const struct s_employee* _obj, int* _salary);
    int (*f_constructor)(struct s_employee* _obj, const char* _name, const int _age, const int _salary);
    void (*f_destructor)(struct s_employee* _obj);
}employee;


/*
 * The function receives an employee object '_obj', destruct it and frees the dynamic 
 * memory of the object
 */
void delete_employee(employee* _obj);


/*
 * The function receives the employee's name, age and salary, allocates a dynamic memory
 * for the object and outputs the pointer in _obj. 
 * The function then construct the object (sets the attributes with the corresponding values
 * and sets the methods)
 * The function return 1 if succeeds, 0 if fails, and exit(0) if there's a memory error
 */
int new_employee(employee** _obj, const char* _name, const int _age, const int _salary);

#endif /* __EMPLOYEE_H_ */

