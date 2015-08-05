#include "common.h"
#include "manager.h"
#include "employee.h"

/*
 * The function receives:
 *  - va_list _argp - holds three arguments char*, int int.
 * The function outputs:
 *  - char** _name, int* _age, int* _salary
 * The function returns 1 always
 */
static int employee_base_object(va_list _argp, char** _name, int* _age, int* _salary);



/*
 * The function receives:
 *  - va_list _argp - holds three arguments char*, int int. int
 * The function outputs:
 *  - char** _name, int* _age, int* _salary, int* _num_of_employees
 * The function returns 1 always
 */
static int manager_base_object(va_list argp, char** _name, int* _age, int* _salary, int* _num_of_employees);




int new(void** _object, const char* _type, ...)
{
    va_list argp;

    va_start(argp,_type);

    if (!strcmp(_type,"employee"))
    {
        char* name;
        int age;
        int salary;

        if (!employee_base_object(argp, &name, &age, &salary))
        {
            printf("error in getting employee base object\n");
            return 0;

        }
        new_employee((employee**)_object, name, age, salary);

    }
    else if(!strcmp(_type, "manager"))
    {
        char* name;
        int age;
        int salary;
        int num_of_employees;
        if (!manager_base_object(argp, &name, &age, &salary, &num_of_employees))
        {
            printf(" error in getting employee base object");
            return 0;

        }
        new_manager((manager**)_object, name, age, salary, num_of_employees);

    }
    else
    {
        printf(" error in 'new' type\n");
        return 0;
    }
    
    va_end(argp);

}


int delete(void* _object, const char* _type)
{
    if (!strcmp(_type,"employee"))
    {
        delete_employee((employee*)_object);

    }
    else if(!strcmp(_type, "manager"))
    {
        delete_manager((manager*)_object);

    }
    else
    {
        printf(" error in 'delete' type\n");
        return 0;
    }


}

static int employee_base_object(va_list _argp, char** _name, int* _age, int* _salary)
{
    *_name = va_arg(_argp, char*);
    *_age = va_arg(_argp, int);
    *_salary = va_arg(_argp, int);

    return 1;
}

static int manager_base_object(va_list _argp, char** _name, int* _age, int* _salary, int* _num_of_employees)
{
    *_name = va_arg(_argp, char*);
    *_age = va_arg(_argp, int);
    *_salary = va_arg(_argp, int);
    *_num_of_employees =  va_arg(_argp, int);

    return 1;
}

