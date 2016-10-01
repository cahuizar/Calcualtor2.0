// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Left_Parenthesis_Node.h"

#include "Eval_Exp_Tree.h"

// The class never gets implemented, I kept it in file since there were
// comments that needed to get addressed


// default constructor for the Left Parenthesis Command_Node
Left_Parenthesis_Node::Left_Parenthesis_Node(void)
{

}

Left_Parenthesis_Node::~Left_Parenthesis_Node(void)
{

}

//  do nothing, it will never evaluate or execute
void Left_Parenthesis_Node:: accept(Exp_Node_Visitor & v)
{
    v.Visit_Left_Parenthesis_Node(*this);
}


// set the priority
int Left_Parenthesis_Node:: priority(void)
{
    return 100;
}


void * Left_Parenthesis_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Left_Parenthesis_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}

