#include "BTTGHeader.h" 

TruthTable::TruthTable() {
    iTUInL = 0; 
    char cProp1 = 0;
    char cCon = 0;
    char cProp2 = 0;   
    char cTval1 = 0, cTval2 = 0, cTval3 = 0, cTval4 = 0;
} 

void TruthTable::vPrintTable(string sUInPT)
{
    char cProp1 = sUInPT[0]; 
    char cCon = sUInPT[1]; 
    char cProp2 = sUInPT[2];  
    char cTval1 = 0, cTval2 = 0, cTval3 = 0, cTval4 = 0;

    if (cCon == '&') {//and connective
        cTval1 = 'T';
        cTval2 = 'F';
        cTval3 = 'F';
        cTval4 = 'F';
    }
    else if (cCon == '$') {//or connective
        cTval1 = 'T';
        cTval2 = 'T';
        cTval3 = 'T';
        cTval4 = 'F';
    }
    else if (cCon == '<') {//left implication connective
        cTval1 = 'T';
        cTval2 = 'F';
        cTval3 = 'T';
        cTval4 = 'T';
    }
    else if (cCon == '>') {//right implication connective
        cTval1 = 'T';
        cTval2 = 'T';
        cTval3 = 'F';
        cTval4 = 'T';
    }
    else if (cCon == '=') {//bi-implication connective
        cTval1 = 'T';
        cTval2 = 'F';
        cTval3 = 'F';
        cTval4 = 'T';
    }

    char cTable[8][10] = { {'-','-','-','-','-','-','-','-','-','-',},
                         {'|',cProp1,'|',cProp2,'|','|',cProp1,cCon,cProp2,'|'},
                         {'|','-','|','-','|','|','-','-','-','|',},
                         {'|','T','|','T','|','|',' ',cTval1,' ','|',},
                         {'|','T','|','F','|','|',' ',cTval2,' ','|',},
                         {'|','F','|','T','|','|',' ',cTval3,' ','|',},
                         {'|','F','|','F','|','|',' ',cTval4,' ','|',},
                         {'-','-','-','-','-','-','-','-','-','-',},
    };

    //print the table 
    system("cls");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++)
            cout << cTable[i][j] << "\t";
        cout << endl;
    }

}

bool TruthTable::bCheckValidInput(string sCUIn) {
    iTUInL = sCUIn.length();

    if (iTUInL > 3)
        return false;
    else {
        for (int i = 0; i < iTUInL; i++) {
            if (!(isalpha(sCUIn[i]) || (sCUIn[i] == '&') || (sCUIn[i] == '$') || (sCUIn[i] == '<') || (sCUIn[i] == '>') || (sCUIn[i] == '=')))
                return false;
        }
        if (!((isalpha(sCUIn[0])) && (isalpha(sCUIn[2])) && ((sCUIn[1] == '&') || (sCUIn[1] == '$') || (sCUIn[1] == '<') || (sCUIn[1] == '>') || (sCUIn[1] == '=')))) {
            return false;
        }
    }
    return true;
}

bool TruthTable::bIsConnective(char cCon) {
    if ((cCon == '&') || (cCon == '$') || (cCon == '<') || (cCon == '>') || (cCon == '='))
        return true;
    else return false;
}

string sGetUIn() {
    string sGUIn;
    system("cls");
    cout << endl << endl << "List of logical connectives:" << endl;
    cout << "    1. & is And" << endl;
    cout << "    2. $ is Or" << endl;
    cout << "    3. < is Implication Left" << endl;
    cout << "    4. > is Implication Right" << endl;
    cout << "    5. = is Bi-implication" << endl << endl;
    cout << "Please enter your propositional formula (limited to 3 characters): ";
    getline(cin, sGUIn); cout << endl << endl;
    return sGUIn;
} 
