// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Eval_Exp_Tree.h"

#include "Add_Node.h"
#include "Number_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Subtract_Node.h"


using namespace std;

Eval_Exp_Tree:: Eval_Exp_Tree ( void )
    : result_(0), right_(0), left_(0)
{

}
// visit addition node
void Eval_Exp_Tree:: Visit_Addition_Node (  Add_Node & node)
{
    node.get_left()->accept(*this);
    node.get_right()->accept(*this);
    right_ = number_holder.top();
    number_holder.pop();
    left_ = number_holder.top();
    number_holder.pop();
    result_ = left_ + right_;
    number_holder.push(result_);

}

// visit subtraction node
void Eval_Exp_Tree:: Visit_Subtraction_Node ( Subtract_Node & node)
{
    node.get_left()->accept(*this);
    node.get_right()->accept(*this);
    right_ = number_holder.top();
    number_holder.pop();
    left_ = number_holder.top();
    number_holder.pop();
    result_ = left_ - right_;
    number_holder.push(result_);
}

// visit division node
void Eval_Exp_Tree:: Visit_Division_Node (Divide_Node & node)
{
    node.get_left()->accept(*this);
    node.get_right()->accept(*this);
    right_ = number_holder.top();
    number_holder.pop();
    left_ = number_holder.top();
    number_holder.pop();
    if(right_ == 0)
    {
        throw divide_by_zero();
    }
    result_ = left_ / right_;
    number_holder.push(result_);
}

// visit number node
void Eval_Exp_Tree:: Visit_Number_Node (Number_Node & node)
{
    number_holder.push(node.get_number());
}

// visit multiplication node
void Eval_Exp_Tree:: Visit_Multiplication_Node ( Multiply_Node & node)
{
    node.get_left()->accept(*this);
    node.get_right()->accept(*this);
    right_ = number_holder.top();
    number_holder.pop();
    left_ = number_holder.top();
    number_holder.pop();
    result_ = left_ * right_;
    number_holder.push(result_);
}

// visit modulus node
void Eval_Exp_Tree:: Visit_Modulus_Node ( Modulus_Node & node)
{
    node.get_left()->accept(*this);
    node.get_right()->accept(*this);
    right_ = number_holder.top();
    number_holder.pop();
    left_ = number_holder.top();
    number_holder.pop();
    if(right_ == 0)
    {
        throw mod_by_zero();
    }
    result_ = left_ % right_;
    number_holder.push(result_);
}


int Eval_Exp_Tree::result(void)
{
    result_ = number_holder.top();
    number_holder.pop();
    return result_;
}
