// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Number_Node.h"

#include "Eval_Exp_Tree.h"

// default constructor for the Number Command_Node
Number_Node::Number_Node(int n)
    : n_(n)
{

}

Number_Node::~Number_Node(void)
{

}

// add number into the stack
void Number_Node:: accept(Exp_Node_Visitor & v)
{
    v.Visit_Number_Node(*this);
}

// set the priority
int Number_Node:: priority(void)
{
    // do nothing since number priority does not matter
    return 0;
}

int Number_Node:: get_number(void)
{
    return n_;
}

void * Number_Node:: set_left(Exp_Node * left)
{

}

void * Number_Node:: set_right(Exp_Node * right)
{

}
