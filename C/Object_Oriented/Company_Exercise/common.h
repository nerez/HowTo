#ifndef __COMMON_H_
#define __COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "employee.h"
#include "manager.h"

/*
 * This Module defines the two main functions of 'new' and 'delete'. which are used by all objects
 */
 
 
/*
 * Creates a new object of type "manager" or "employee". 
 * employee receives 3 arugments: char* name, int age, int salary
 * manager receives 4 arguments: char* name, int age, int salary, int num_of_employees
 */
int new(void** _object, const char* _type, ...);

/*
 * Deletes object of type "manager" or "employee". 
 */
int delete(void* _object, const char* _type);

#endif /* __COMMON_H_ */
