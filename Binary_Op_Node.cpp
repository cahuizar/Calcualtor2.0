//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#include "Binary_Op_Node.h"


// default constructor for the Binary Op Command_Node
Binary_Op_Node:: Binary_Op_Node(void)
    :left_(NULL), right_(NULL)
{

}

// destructor
Binary_Op_Node:: ~Binary_Op_Node(void)
{
    delete left_, right_;
}

// defined to provide common behavior for all binary nodes
void Binary_Op_Node:: accept( Exp_Node_Visitor & v)
{

}

// defined to provide common behavior for all binary nodes
 Exp_Node * Binary_Op_Node:: get_left(void)
{
    return left_;
}

// defined to provide common behavior for all binary nodes
 Exp_Node * Binary_Op_Node:: get_right(void)
{
    return right_;
}

void * Binary_Op_Node:: set_left(Exp_Node * left)
{
    this->left_ = left;
}

void * Binary_Op_Node:: set_right(Exp_Node * right)
{
    this->right_ = right;
}




