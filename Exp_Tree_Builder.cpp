// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Exp_Tree_Builder.h"
#include "Calculator.h"

// default constructor for the exp command factory
Exp_Tree_Builder:: Exp_Tree_Builder(void)
    :tree_(NULL)
{

}

// destructor
Exp_Tree_Builder:: ~Exp_Tree_Builder(void)
{
    delete tree_;
}

// build a number command
void Exp_Tree_Builder:: build_number(int num)
{
    Exp_Node * node = new Number_Node(num);

    // in case only a number is entered on calculator
    if(operator_holder_.is_empty())
    {
        tree_ = node;
    }
    number_holder_.push(node);

}

// build an add command
void Exp_Tree_Builder:: build_add (void)
{
    Exp_Node * node = new Add_Node();
    postfix_tree(node);

}

// build a subtract command
void Exp_Tree_Builder:: build_subtract (void)
{
    Exp_Node * node = new Subtract_Node();
    postfix_tree(node);
}

// build a multiply command
void Exp_Tree_Builder:: build_multiply(void)
{
    Exp_Node * node = new Multiply_Node();
    postfix_tree(node);
}

// build a number command
void Exp_Tree_Builder:: build_divide(void)
{
    Exp_Node * node = new Divide_Node();
    postfix_tree(node);
}

// build modulus command
void Exp_Tree_Builder:: build_modulus(void)
{
    Exp_Node * node = new Modulus_Node();
    postfix_tree(node);
}

// create a sub expression and get get the result from it when the closing parenthesis happens.
// It will return the result back to the original expression
int Exp_Tree_Builder:: create_sub_tree(std::stringstream &input)
{
    Calculator calc;
    calc.create_command_node(input);
    int result =  calc.get_result();
    return result;

}

Exp_Node * Exp_Tree_Builder::get_expression(void)
{
    return this->tree_;
}

// COMMENT: Please give this method a better name, one that reflects
// its intent.

// I addressed this comment by changing the name to postfix_tree
void Exp_Tree_Builder:: postfix_tree(Exp_Node *node)
{
    if(operator_holder_.is_empty())
    {
        operator_holder_.push(node);
        tree_ = node;
    }
    else
    {
        Exp_Node * top = operator_holder_.top();
        int top_priority = top->priority();
        int cur_priority = node->priority();

        if(top_priority > cur_priority)
        {
            tree_ = node;
            empty_operator_stack();
            operator_holder_.push(node);

        }
        // push into the stack if the top priority is less than or equal to the current one
        else if(top_priority <= cur_priority)
        {
            operator_holder_.push(node);
        }
    }
}

// ensure that there is nothing left on the operator stack
void Exp_Tree_Builder:: empty_operator_stack(void)
{
    while(!operator_holder_.is_empty())
    {

        Exp_Node * top = operator_holder_.top();
        operator_holder_.pop();

        Exp_Node * right_child = number_holder_.top();
        number_holder_.pop();
        Exp_Node * left_child = number_holder_.top();
        number_holder_.pop();

        top->set_right(right_child);
        top->set_left(left_child);
        number_holder_.push(top);
    }
}
