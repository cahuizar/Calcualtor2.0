//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_Multiply_Node_H_
#define _CS507_Multiply_Node_H_

#include "Binary_Op_Node.h"
#include "Stack.h"

// COMMENT: The name of your class is misleading. It is not an
// implementation of the Command Pattern. The class name should
// not give that impression.

// I addressed this comment by taking out the "Command" out of the name

class Multiply_Node : public Binary_Op_Node
{

public:
    Multiply_Node(void);
    ~Multiply_Node(void);
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

#endif // _CS507_Multiply_Node_H_
