#include "employee.h"

/* Private attributes of 'employee' object */
struct p_employee
{
    char* name;
    int age;
    int salary;
};

/*
 * The function receives an 'employee' object, and its 'name' 'age' and 'salary'
 * The function allocates the needed memory for the object's attributes but not the object itself, 
 * and sets the corresponding attributes and methods in it.
 * The function returns 1 always. unless there is an allocation error, when it exit(0)
 */
int employee_constructor(employee* _obj, const char* _name, const int _age, const int _salary);



/*
 * The function receives an 'employee' object, and frees all the dynamicaly allocated
 * memory of its attributes (but not the object itself). 
 */
void employee_destructor(employee* _obj);



/*
 * The function receives an 'employee' object. 
 * The functino outputs a copy of the 'name' attribute of the object in '_name'.
 * '_name' has to be freed with 'free' function
 * The function returns 1 if succeeds, otherwise returns 0
 */
static int get_name(const employee* _obj, char** _name);



/*
 * The function receievs an 'employee' object.
 * The function outputs the age attribute of the object in '_age'.
 * The function return 1 if succeeds, otherwise returns 0
 */
static int get_age(const employee* _obj, int* _age);


/*
 * The function receievs an 'employee' object.
 * The function outputs the salary attribute of the object in '_salary'.
 * The function return 1 if succeeds, otherwise returns 0
 */
static int get_salary(const employee* _obj, int* _salary);





static int get_name(const employee* _obj, char** _name)
{
    if ((_obj) && (_obj->private) && (_obj->private->name))
    {
        *_name = strdup(_obj->private->name);
        if (!_name)
        {
            printf("copy of name failed\n");
            return 0;
        }
        return 1;
    }
    return 0;
}

static int get_age(const employee* _obj, int* _age)
{
    if ((_obj) && (_obj->private))
    {
        *_age = _obj->private->age;
        return 1;
    }
    return 0;
}

static int get_salary(const employee* _obj, int* _salary)
{
    
    if ((_obj) && (_obj->private))
    {
        *_salary= _obj->private->salary;
        return 1;
    }
    return 0;
}

int new_employee(employee** _obj, const char* _name, const int _age, const int _salary)
{
    *_obj = (employee*)malloc(sizeof(employee));
    if (!*_obj)
    {
        printf(" Allocation error in new, _obj");
        exit(0);
    }
    
    if (!employee_constructor(*_obj, _name, _age, _salary))
    {
        printf("employee_constructor faild\n");
        return 0;
    }
    return 1;

}


int employee_constructor(employee* _obj, const char* _name, const int _age, const int _salary)
{
    if (!_obj)
    {
        printf(" employee_constructor _obj is NULL\n");
        exit(0);
    }
    
    /* Allocates all the dynamic memory needed for the object */
    _obj->private = (struct p_employee*)malloc(sizeof(struct p_employee));
    if (!_obj->private)
    {
        printf(" Allocation error in employee_constructor, _obj->private\n");
        exit(0);
    }
    _obj->private->name = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
    if (!_obj->private->name)
    {
        printf(" Allocation error in contructor, _obj->private->name\n");
        exit(0);

    }
    
    /* Set all the data needed - methods and attributes */
    _obj->private->name              = strdup(_name);
    _obj->private->age               = _age;
    _obj->private->salary            = _salary;
    _obj->f_get_name                 = get_name;
    _obj->f_get_age                  = get_age;
    _obj->f_get_salary               = get_salary;
    _obj->f_constructor              = employee_constructor;
    _obj->f_destructor               = employee_destructor;

    return 1;
}


void delete_employee(employee* _obj)
{
    if (_obj)
    {
        _obj->f_destructor(_obj);
        free(_obj);
        return;
    }
    
    printf("_obj->f_destructor failed\n");

}

void employee_destructor(employee* _obj)
{
    if ((_obj) && (_obj->private)) 
    {
        if (_obj->private->name)
        {
            free(_obj->private->name);
        }
        free(_obj->private);
    }
}


