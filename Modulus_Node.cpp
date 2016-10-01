// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Modulus_Node.h"

#include "Eval_Exp_Tree.h"

// default constructor for the Modulus Command_Node
Modulus_Node::Modulus_Node(void)
{

}

Modulus_Node::~Modulus_Node(void)
{

}

//  modulus of the two integers
void Modulus_Node:: accept(Exp_Node_Visitor & v)
{
    v.Visit_Modulus_Node(*this);
}

// set the priority
int Modulus_Node:: priority(void)
{
    return 2;
}

void * Modulus_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Modulus_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}
