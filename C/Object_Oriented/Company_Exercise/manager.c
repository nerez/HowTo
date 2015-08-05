#include "manager.h"

struct p_manager
{
    int num_of_employees;
    employee* emp;
};


/*
 * The function receives a 'manager' object, and its 'employee' object and its attributes 'num_of_employees'
 * The function allocates the needed memory for the object's attributes but not the object itself, 
 * and sets the corresponding attributes and methods in it.
 * The function returns 1 always. unless there is an allocation error, when it exit(0)
 */
int manager_constructor(manager* _obj, employee* emp_obj, const int _num_of_employees);



/*
 * The function receives an 'manager' object, and frees all the dynamicaly allocated
 * memory of its attributes (but not the object itself). 
 */
void manager_destructor(struct s_manager* _obj);


/*
 * The function receievs a 'manager' object.
 * The function outputs the num_of_employees attribute of the object in '_num_of_employees'.
 * The function return 1 if succeeds, otherwise returns 0
 */
static int get_num_of_employees(const manager* _obj, int* _num_of_employees);


/*
 * The function receives an 'manager' object. 
 * The functino outputs a copy of the 'name' attribute of the object in '_name'.
 * '_name' has to be freed with 'free' function
 * The function returns 1 if succeeds, otherwise returns 0
 */
static int get_name(const manager* _obj, char** _name);



/*
 * The function receievs an 'manager' object.
 * The function outputs the age attribute of the object in '_age'.
 * The function return 1 if succeeds, otherwise returns 0
 */
static int get_age(const manager* _obj, int* _age);


/*
 * The function receievs an 'manager' object.
 * The function outputs the salary attribute of the object in '_salary'.
 * The function return 1 if succeeds, otherwise returns 0
 */
static int get_salary(const manager* _obj, int* _salary);






static int get_num_of_employees(const manager* _obj, int* _num_of_employees)
{
    *_num_of_employees = _obj->private->num_of_employees;
    return 1;

}


int new_manager(manager** _obj, char* _name, int _age, int _salary, int _num_of_employees)
{
    employee* emp_obj;

    if (!new_employee(&emp_obj, _name, _age, _salary))
    {
        printf(" error in new");
        return 0;
    }

    *_obj = (manager*)malloc(sizeof(manager));
    if (!*_obj)
    {
        printf(" Allocation error in new, _obj");
        exit(0);

    }

    if (!manager_constructor(*_obj, emp_obj, _num_of_employees))
    {
        return 0;
    }
    return 1;

}

int manager_constructor(manager* _obj, employee* emp_obj, const int _num_of_employees)
{
    if (!_obj)
    {
        printf(" manager_constructor _obj is NULL\n");
        exit(0);
    }
    
    _obj->private = (struct p_manager*)malloc(sizeof(struct p_manager));
    if (!_obj->private)
    {
        printf(" Allocation error in manager_constructor, _obj->private");
        exit(0);
    }

    _obj->private->num_of_employees     = _num_of_employees;
    _obj->private->emp                  = emp_obj;
    _obj->f_get_name                    = get_name;
    _obj->f_get_age                     = get_age;
    _obj->f_get_salary                  = get_salary;
    _obj->f_get_num_of_employees        = get_num_of_employees;
    _obj->f_constructor                 = manager_constructor;
    _obj->f_destructor                  = manager_destructor;

    return 1;
}

void delete_manager(manager* _obj)
{
    if (_obj) 
    {
        _obj->f_destructor(_obj);
        free(_obj);
    }

}

void manager_destructor(manager* _obj)
{
    if (_obj)
    {
        if (_obj->private)
        {
            if (_obj->private->emp)
            {
                delete_employee(_obj->private->emp);
            }
            free(_obj->private);
        }
    }
}


static int get_name(const manager* _obj, char** _name)
{
    employee* obj = _obj->private->emp;
    
    if (!obj->f_get_name(obj, _name))
        return 0;
        
    if (!_name)
    {
        printf("copy of name failed\n");
        return 0;
    }
    return 1;
}

static int get_age(const manager* _obj, int* _age)
{
    employee* obj = _obj->private->emp;
    
    if (!obj->f_get_age(obj, _age))
        return 0;
    
    return 1;
}

static int get_salary(const manager* _obj, int* _salary)
{
    employee* obj = _obj->private->emp;
    
    if (!obj->f_get_salary(obj, _salary))
        return 0;
        
    return 1;
}


