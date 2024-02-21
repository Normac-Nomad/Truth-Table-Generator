#pragma region File_Inclusion_List

#include "BTTGHeader.h"

#pragma endregion   

int main(){ 

    TruthTable TruthTable1;

	int iReEnter = 1;//checks to see if the user wants to re-enter another expression
	string sMainUIn;//string-main-user-input  

	while (iReEnter == 1) { 

		sMainUIn = sGetUIn();  

        if (TruthTable1.bCheckValidInput(sMainUIn)){//if the input is valid, print the truth table
            TruthTable1.vPrintTable(sMainUIn);
            cout << endl << "Would you like to try again? (1 = yes): ";
            cin >> iReEnter;
            if (iReEnter == 1) {
                sMainUIn = sGetUIn();
            }
        }
        else {//if the input is invalid, ask the user to try again (or exit)
            system("cls");
            cout << endl << endl << "ERROR: Your formula was not syntactically correct." << endl;
            cout << "Would you like to try again? (1 = yes): ";
            cin >> iReEnter;
            if (iReEnter == 1) {
                sMainUIn = sGetUIn();
            }
        }
	} 

	return 0;
}
