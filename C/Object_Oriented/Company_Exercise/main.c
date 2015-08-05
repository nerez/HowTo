#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "manager.h"
#include "common.h"

int main()
{
    employee* emp;
    manager* manag;
    char* name;
    int age;
    int salary;
    int num_of_employees;
    int rc = 0;

    name = (char*)malloc(sizeof(MAX_NAME_SIZE));
    if (!name)
    {
        printf(" ERROR allocating name");
        exit(1);

    }

    do
    {
        if (!new((void**)&emp, "employee", "noam" /*name*/, 31 /*age*/, 10/*salary*/))
        {
            printf(" ERROR in new!\n");
            rc = 1;

        }

        if (!new((void**)&manag, "manager", "moshe" /*name*/, 41 /*name*/, 12 /*salary*/, 4 /*workers*/))
        {
            printf(" ERROR in new!\n");
            rc = 1;

        }

        if (!emp->f_get_name(emp, &name))
        {
            printf(" ERROR in getting name!\n");
            rc = 1;

        }
        if (!emp->f_get_age(emp, &age))
        {
            printf(" ERROR in getting age!\n");
            rc = 1;

        }
        if (!emp->f_get_salary(emp, &salary))
        {
            printf(" ERROR in getting salary!\n");
            rc = 1;

        }

        printf(" name: %s, age: %d, salary %d\n", name, age, salary);
        if (!manag->f_get_name(manag, &name))
        {
            printf(" ERROR in getting name!\n");
            rc = 1;

        }
        if (!manag->f_get_age(manag, &age))
        {
            printf(" ERROR in getting age!\n");
            rc = 1;

        }
        if (!manag->f_get_salary(manag, &salary))
        {
            printf(" ERROR in getting salary!\n");
            rc = 1;

        }
        if (!manag->f_get_num_of_employees(manag, &num_of_employees))
        {
            printf(" ERROR in getting salary!\n");
            rc = 1;

        }
        printf(" name: %s, age: %d, salary %d, num_of_employees: %d\n", name, age, salary, num_of_employees);

    }while(0);

    delete(emp,"employee");
    delete(manag, "manager");
    free(name);
    return rc;

}
