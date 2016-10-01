//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_EXP_BUILDER_H_
#define _CS507_EXP_BUILDER_H_

// include all of the header files of the commands
#include "Exp_Node.h"
#include "Number_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Stack.h"

class Exp_Builder
{
public:
    Exp_Builder (void);
    virtual ~Exp_Builder (void);
    virtual void build_number (int num) = 0;
    virtual void build_add (void ) = 0;
    virtual void build_subtract (void) = 0;
    virtual void build_multiply(void ) = 0;
    virtual void build_divide(void ) = 0;
    virtual void build_modulus (void ) = 0;
    virtual int create_sub_tree(std::stringstream &input) = 0;
    virtual Exp_Node * get_expression(void) = 0;
};

#endif // _CS507_EXP_BUILDER_CONVERSION_H_
