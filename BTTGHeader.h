#pragma region File_Inclusion_List

#include <iostream>;  
#include <string>;
#include <ctype.h>;

using namespace std;

#pragma endregion   

class TruthTable 
{  
public:
    int iTUInL;//stores the number of characters (total user input length)  
    char cProp1;//stores the first proposition  
    char cCon;//stores the connective proposition  
    char cProp2;//stores the second proposition    
    char cTval1, cTval2, cTval3, cTval4;//Holds truth values of statement, changed depending on connective  

    /*  Name: TruthTable

        Purpose: Default_Constructor
        Parameter(s): N/A
        Precondition(s): Object of type TruthTable must be declared
        Returns: N/A
        Side Effect: All values initialized to zero
    */
    TruthTable(); 

    /*  Name: vPrintTable

        Purpose: Prints the truth table of the statement the user entered
        Parameter(s): sUInPT
        Precondition(s): User must give valid input.
        Returns: N/A
        Side Effect: Truth table is printed to the screen
    */

    void vPrintTable(string sUInPT);

    /*  Name: bCheckValidInput

        Purpose: Ensures all characters entered by the user are valid, and syntax is correct.
        Parameter(s): sUIn
        Precondition(s): User must give input.
        Returns: 1. True means the input is valid.
                 2. False means the input is invalid.
        Side Effect: Depends on validity:
                     - If valid generate truth table
                     - if invalid ask user to re-enter input
    */
    bool bCheckValidInput(string sCUIn);

    /*  Name: bIsConnective

        Purpose: Checks a character to be one of six connectives
        Parameter(s): cCon
        Precondition(s): User must give input.
        Returns: 1. True means the input is a connective.
                 2. False means the input is not a connective.
        Side Effect: Depends on validity:
                     - If valid generate truth table
                     - if invalid ask user to re-enter input
    */
    bool bIsConnective(char cCon);
};

/* Name: sGetUIn

    Purpose: Get the user input
    Parameter(s): N/a
    Precondition(s): N/a
    Returns: User input.
    Side Effect: User has entered a propositional statement
*/
string sGetUIn(); 

