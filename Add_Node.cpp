// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Add_Node.h"
#include "Eval_Exp_Tree.h"

// default constructor for the Add Command
Add_Node::Add_Node(void)
{

}

Add_Node::~Add_Node(void)
{

}


// add  the two integers
void Add_Node:: accept( Exp_Node_Visitor & v)
{
    v.Visit_Addition_Node(*this);
}

// set the priority
int Add_Node:: priority(void)
{
    return 1;
}

void * Add_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Add_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}
