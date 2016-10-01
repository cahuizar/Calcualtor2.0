//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_Calculator_H_
#define _CS507_Calculator_H_

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>

#include"Array.h"
#include"Stack.h"
#include "Exp_Node.h"
#include "Exp_Builder.h"

#include "Eval_Exp_Tree.h"

#include "Binary_Op_Node.h"
#include "Add_Node.h"
#include "Multiply_Node.h"
#include "Subtract_Node.h"
#include "Number_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"

#include "Exp_Node_Visitor.h"
//#include "Exp_Tree_Builder.h"

class Exp_Tree_Builder;


// COMMENT: Please come up with a better name for this class that
// reflects its purpose.

// I addressed this comment by changing the name to Calculator

class Calculator
{

public:
    Calculator(void);
    ~Calculator(void);
    void main_menu(void);
    void infix_to_postfix(Exp_Node * cmd, Array<Exp_Node*> &postfix, Stack<Exp_Node*> &operator_holder, int &array_counter );
    void create_command_node(std::stringstream &input);
    int get_result(void);

private:
    int result;
    bool expression_is_finished;

};

#endif // _CS507_Calculator_H_
