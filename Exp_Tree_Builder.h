//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_EXP_TREE_BUILDER_H_
#define _CS507_EXP_TREE_BUILDER_H_

#include "Exp_Builder.h"
#include "Exp_Node.h"
#include "Stack.h"

class Calculator;


class Exp_Tree_Builder : public Exp_Builder
{
public:
    Exp_Tree_Builder (void);
    virtual ~Exp_Tree_Builder (void) ;
    virtual void build_number (int num);
    virtual void build_add (void);
    virtual void build_subtract (void);
    virtual void build_multiply(void );
    virtual void build_divide(void );
    virtual void build_modulus (void );
    virtual int create_sub_tree(std::stringstream &input);
    virtual Exp_Node * get_expression(void);
    virtual void postfix_tree(Exp_Node *node);
    virtual void empty_operator_stack(void);


private:
     Exp_Node * tree_;
     Stack <Exp_Node*> operator_holder_;
     Stack <Exp_Node*> number_holder_;
};

#endif // _CS507_EXP_TREE_BUILDER_CONVERSION_H_
