// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Calculator.h"
#include "Exp_Tree_Builder.h"

//Default Constructor
Calculator::Calculator(void)
    :result(0), expression_is_finished(true)
{

}

//destructor
Calculator::~Calculator(void)
{

}

// main menu for the calculator

void Calculator::main_menu(void)
{
    bool keepGoing = true;

    std::string selection;

    std::cout<<"Welcome to the Infix to Postfix Calculator\n"<<std::endl;

    while(keepGoing)
    {
        getline(std::cin, selection);

        // exit
        if ( selection == "QUIT" )
        {
            keepGoing = false;
        }

        //take the input and send it to the create command function
        else
        {
            std::stringstream input(selection);
            create_command_node(input);
        }

    }
}

// take the input and use the factory to create the commands for each character

void Calculator::create_command_node(std::stringstream &input)
{

    Exp_Tree_Builder  b;

    std::string token;

    double temp_number;

    bool parsing_error_found = false;

    // check the tokens

    while(!input.eof())
    {
        input >> token;

        // check to see if its a number
        if ( std::istringstream(token) >> temp_number )
        {
            b.build_number(temp_number);

        }
        else if( token == "+" )
        {
            b.build_add();
        }
        else if( token == "-" )
        {
            b.build_subtract();
        }
        else if( token == "*" )
        {
            b.build_multiply();
        }
        else if( token == "/" )
        {
            b.build_divide();
        }
        else if( token == "%" )
        {
            b.build_modulus();
        }

        else if( token == "(" )
        {
            int sub_exp_result = b.create_sub_tree(input);
            b.build_number(sub_exp_result);

        }
        // break out of the sub expression and ensure result does not display
        else if( token == ")" )
        {
            // since original expression is not finished, do not display the result
            expression_is_finished = false;
            break;
        }

        // display error if no condition is met
        else
        {
            std::cout<<"\nError: please make sure operator and or numbers are entered\n"<<std::endl;
            parsing_error_found = true;
        }

    }

    // run  conditional statement only if numbers and operators were entered
    if(parsing_error_found == false)
    {
        b.empty_operator_stack();
        Eval_Exp_Tree eval;
        Exp_Node * exp = b.get_expression();
        try
        {
            exp->accept(eval);
            this->result = eval.result();
            // display results only if its on original expression
            if(expression_is_finished == true)
            {
                std::cout<<"\nResult: "<<result<<std::endl<<std::endl;
            }
        }
        // catch if user divides by 0
        catch(const Eval_Exp_Tree::divide_by_zero& e)
        {
            std::cout<<"Error you have tried to divide by 0...\n"<<std::endl;
        }
        // catch if user mods by 0
        catch(const Eval_Exp_Tree::mod_by_zero& e)
        {
            std::cout<<"Error you have tried to mod by 0...\n"<<std::endl;
        }
    }
}
// return the result to the sub expression
int Calculator::get_result()
{
    return this->result;
}
