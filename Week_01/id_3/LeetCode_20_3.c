#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum bool_t
{
    false = 0,
    true,
}bool;

struct stack
{
    char *array;
    int top;
    int size;
};

struct stack *init(int size){
    struct stack *p = NULL;
    
    if(0 == size)
    {
        return NULL;
    }
    
    p = malloc(sizeof(struct stack));
    if(NULL == p)
    {
        return NULL;
    }

    p->array = malloc(sizeof(char) * size);
    p->top = -1;
    p->size = size;

    return p;
}

bool isEmpty(struct stack * p)
{
    return p->top == -1 ? true : false;
}

bool isFull(struct stack *p)
{
    return p->top + 1 == p->size ? true : false;
}

bool push(struct stack* p, char c)
{
    if(isFull(p)){
        return false;
    }

    p->array[++(p->top)] = c;
    return true;
}

bool pop(struct stack* p, char* c)
{
    if(isEmpty(p)){
        return false;
    }
    
    *c = p->array[(p->top)--];
    return true;
}



bool isValid(char * s){
    struct stack* pStack = NULL;
    char *pString = NULL;
    char c;
    char tmp;

    if(!(*s))
    {
        return true;
    }

    pStack = init(strlen(s));
    pString = s;

    while(*pString)
    {
        c = *pString;
        if('(' == c || '{' == c || '[' == c)
        {
            push(pStack, c);
            
            pString++;
            continue;
        }
        
        if(!pop(pStack, &tmp))
        {
            return false;
        }

        if(')' == c)
        {
            if('(' != tmp)
            {
                return false;
            }
        }
        else if(']' == c)
        {
            if('[' != tmp)
            {
                return false;
            }
        }
        else
        {
            if('{' != tmp)
            {
                return false;
            }
        }
        
        pString ++;
    }

    if(isEmpty(pStack))
    {
        return true;
    }

    return false;
}

void main()
{
    char array[] = ")";

    printf("result: %d\n", isValid(array));

}