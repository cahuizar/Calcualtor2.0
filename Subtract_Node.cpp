// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Subtract_Node.h"

#include "Eval_Exp_Tree.h"

// default constructor for the Subtract Command_Node
Subtract_Node::Subtract_Node(void)
{

}

Subtract_Node::~Subtract_Node(void)
{

}

// subtract the two integers
void Subtract_Node::accept(Exp_Node_Visitor & v)
{
    v.Visit_Subtraction_Node(*this);
}

// set the priority
int Subtract_Node:: priority(void)
{
    return 1;
}

void * Subtract_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Subtract_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}
