// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Divide_Node.h"
#include "Eval_Exp_Tree.h"

// default constructor for the  Divide Command_Node
Divide_Node::Divide_Node(void)
{

}

Divide_Node::~Divide_Node(void)
{

}

//  Divide the two integers
void Divide_Node:: accept(Exp_Node_Visitor & v)
{
    v.Visit_Division_Node(*this);
}

// set the priority
int Divide_Node:: priority(void)
{
    return 2;
}

void * Divide_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Divide_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}
