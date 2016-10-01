//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================


// The class never gets implemented, I kept it in file since there were
// comments that needed to get addressed


#ifndef _CS507_Left_Parenthesis_Node_COMMAND_H_
#define _CS507_Left_Parenthesis_Node_COMMAND_H_

#include "Binary_Op_Node.h"
#include "Stack.h"

// COMMENT: The name of your class is misleading. It is not an
// implementation of the Command Pattern. The class name should
// not give that impression.

// I addressed this comment by renaming the class and removing
// Command from it

// COMMENT: Per our discussion in class from Assignment 3, having
// the parenthesis as a node is not a good design. Please fix this
// problem in your design.

// I addressed this comment by figuring out a way to implement
// the parenthesis without creating the nodes.

class Left_Parenthesis_Node : public Binary_Op_Node
{

public:
    Left_Parenthesis_Node(void);
    ~Left_Parenthesis_Node(void);

  // COMMENT: Do not return a value from the accept () of visit () methods
  // in the Visitor pattern. This approach implies that all visit and accept
  // methods must return a value, which may not always be the case. Instead,
  // accumulate state in the visitor object, and access the state as needed.

  // I addressed this comment by properly implementing the visitor pattern
  // and getting rid of the return value on the visitor and accept() method.

    void accept(Exp_Node_Visitor & v);
    int priority(void);
    void *set_left(Exp_Node * left);
    void *set_right(Exp_Node* right);
};

#endif // _CS507_LEFT_PARENTHESIS_NODE_COMMAND_H_
