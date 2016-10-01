// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Multiply_Node.h"
#include "Eval_Exp_Tree.h"

// default constructor for the  Multiply Command_Node
Multiply_Node::Multiply_Node(void)
{
}

Multiply_Node::~Multiply_Node(void)
{

}

// multiply the two integers
void Multiply_Node:: accept(Exp_Node_Visitor & v)
{

    return v.Visit_Multiplication_Node(*this);
}

// set the priority
int Multiply_Node:: priority(void)
{
    return 2;
}

void * Multiply_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Multiply_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}
