//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#include "Exp_Node_Visitor.h"
#include "Stack.h"

class Add_Node;
class Subtract_Node;
class Divide_Node;
class Number_Node;
class Multiply_Node;
class Modulus_Node;
class Eval_Exp_Tree : public Exp_Node_Visitor
{
public:
    class divide_by_zero : public std::exception
    {
        public:
        /// Default constructor.
        divide_by_zero (void)
          : std::exception () { }

    };
    class mod_by_zero : public std::exception
    {
        public:
        /// Default constructor.
        mod_by_zero (void)
          : std::exception () { }

    };
    Eval_Exp_Tree  (void);

    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node ( Add_Node & node);
    virtual void Visit_Subtraction_Node ( Subtract_Node & node);
    virtual void Visit_Division_Node ( Divide_Node & node);
    virtual void Visit_Number_Node ( Number_Node & node);
    virtual void Visit_Multiplication_Node ( Multiply_Node & node);
    virtual void Visit_Modulus_Node (Modulus_Node & node);

    virtual int result (void);

private:
    int result_;
    Stack<int> number_holder;
    int right_;
    int left_;
    // other state for calculating result
};
