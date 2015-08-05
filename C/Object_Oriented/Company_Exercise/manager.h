#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "employee.h"

typedef struct s_manager
{
    employee* emp;
    struct p_manager* private;
    int (*f_get_num_of_employees)(const struct s_manager* _obj, int* _num_of_employees);
    int (*f_constructor)(struct s_manager* _obj, employee* emp_obj, int _num_of_employees);
    void (*f_destructor)(struct s_manager* _obj);
}manager;

/*
 * The function receives the managers's name, age, salary and num_of_employees, allocates a dynamic memory
 * for the object and outputs the pointer in _obj. 
 * The function then construct the object (sets the attributes with the corresponding values
 * and sets the methods)
 * The function return 1 if succeeds, 0 if fails, and exit(0) if there's a memory error
 */
int new_manager(manager** _obj, char* _name, int _age, int _salary, int _num_of_employees);

/*
 * The function receives a manager object '_obj', destruct it and frees the dynamic 
 * memory of the object
 */
void delete_manager(manager* _obj);

#endif /* __MANAGER_H_ */
