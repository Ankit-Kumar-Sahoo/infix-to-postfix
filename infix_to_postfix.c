//CONVERTING AN INFIX EXPRESSION TO AN POSTFIX EXPRESSION :

//Using 2 STACKS .


#include <stdio.h>
#include <math.h>
#include <string.h>

struct stack
{
    float arr[20];
    int tos;
};


void push(struct stack * ,float);
float pop(struct stack *);
float solve(char *);
int isoprnd(char);        //if operand (1), if operator (0) .
int precedence(char);
int empty(int);

int main()
{
    char infix[20];
    char postfix[20];
    printf("Enter the INFIX expression :");
    scanf("%s", infix);
    postfix[20] = solve(infix);
    printf("The POSTFIX expression is : %S", postfix);
    return 0;
     
}

float solve(char * infix[20])
{
    struct stack S1 ,S2;
    S1.tos=-1;
    S2.tos=-1;
    int i;
    char ch;
    int c;
    float x;
    for ( i = 0; i < strlen(infix)-1 ; i++)
    {
        ch=infix[i];

        if (isoprnd(ch)==1)
        {
            push(&S2 , ch - '\0');
        }
        else
        {
            if (empty(S1.tos==1))
            {
                push(&S1 , ch);
            }
            else
            {
                switch (ch)
                {
                    case '$' :
                        c = precedence(S1.tos--);
                        if (c==3)
                        {
                            x = pop(&S1);
                            push(&S2 ,x);
                            push(&S1 , ch);
                        }
                        if (c==1 || c==2)
                        {
                            push(&S1 , ch);
                        }
                    break;

                    case ('/' || '*' || '%') :
                        c = precedence(S1.tos--);
                        if (c==3 || c==2)
                        {
                            x = pop(&S1);
                            push(&S2 ,x);
                            push(&S1 , ch);
                        }
                        if (c==1)
                        {
                            push(&S1 , ch);
                        }
                    break;

                    case ('-') :
                            x = pop(&S1);
                            push(&S2 ,x);
                            push(&S1 , ch);
                    break;

                     case ('+') :
                            x = pop(&S1);
                            push(&S2 ,x);
                            push(&S1 , ch);
                    break;
                            
                        
                }

            }
            
            
        }
        

    }
    

}


int preceence(ch)
{
    switch (ch)
        {
        case '+' :
        case '-' :
                return 1;
        case '*' :
        case '/' : 
        case '%' :
                return 2;
        case '$' :
                return 3;
        }

    
}

int empty(int x)
{
    if (x == -1)
    {
        return 1; 
    }
    else 
        return 0;
    
}

void push(struct stack * p,float x)
{
    
    if(p->tos==4)
        {
            printf("\nSTACK OVERFLOW\n");
            return;
        }
    p->tos=p->tos+1;
    p->arr[p->tos]=x;
    
}

float pop(struct stack * p)
{   
    int x;
    if(p->tos==-1)
        {
            printf("\nSTACK UNDERFLOW\n");
            return 0;
            
        }
    x=p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
    
}





