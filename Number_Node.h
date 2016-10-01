//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_Number_Node_H_
#define _CS507_Number_Node_H_

#include "Exp_Node.h"
#include "Stack.h"


// COMMENT: The name of your class is misleading. It is not an
// implementation of the Command Pattern. The class name should
// not give that impression.

// I addressed this comment by taking out the "Command" out of the name

class Number_Node : public Exp_Node
{

public:
    Number_Node(int n);
    virtual ~Number_Node(void);

  // COMMENT: Do not return a value from the accept () of visit () methods
  // in the Visitor pattern. This approach implies that all visit and accept
  // methods must return a value, which may not always be the case. Instead,
  // accumulate state in the visitor object, and access the state as needed.

  // I addressed this comment by properly implementing the visitor pattern
  // and getting rid of the return value on the visitor and accept() method.

    virtual void accept(Exp_Node_Visitor & v);
    virtual int get_number(void);
    int priority (void);
    void * set_left(Exp_Node * left);
    void * set_right(Exp_Node* right);

protected:
    int n_;
};

#endif // _CS507_Number_Node_H_

