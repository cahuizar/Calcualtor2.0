// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Right_Parenthesis_Node.h"

#include "Eval_Exp_Tree.h"

// default constructor for the  Right Parenthesis Command_Node



// The class never gets implemented, I kept it in file since there were
// comments that needed to get addressed


Right_Parenthesis_Node::Right_Parenthesis_Node(void)
{

}

Right_Parenthesis_Node::~Right_Parenthesis_Node(void)
{

}

//  do nothing, it will never evaluate or execute
void Right_Parenthesis_Node:: accept(Exp_Node_Visitor & v)
{
    v.Visit_Right_Parenthesis_Node(*this);
}

// set the priority
int Right_Parenthesis_Node:: priority(void)
{
    return 90;
}

void * Right_Parenthesis_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Right_Parenthesis_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}
