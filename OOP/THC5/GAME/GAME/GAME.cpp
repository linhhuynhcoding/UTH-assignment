// GAME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BieuthucPT.h"
#include "BieuthucPS.h"
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include "Dethi.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

int main()
{
    int level = 1;
    int index = 1;
    while (level != 0) {
        int cnt = 0;
        int n1, n2, n3;
        n3 = level / 3;
        n2 = level / 3;
        n1 = level - n2 - n3;
        Dethi* dt = new Dethi(n1, n2, n3, level);
        for (Bieuthuc ch : dt->danhsach()) {
            string outputLevel(1, char(level + '0'));
            string outputQuestion(1, char(index + '0'));
            outputLevel = "LEVEL " + outputLevel;
            outputQuestion = "QUESTION " + outputQuestion;

            cout << setw(15) << left << outputLevel;
            cout << setw(1) << left << "$";
            cout << setw(15) << right << outputQuestion;
            cout << "\n=============== ";
            cout << "===============\n";
            cout << ch << " = ? ";            
            float ans;
            cin >> ans;
            system("cls");
            if (!ch.kiemtra(ans)) {
                cout << setw(15) << left << outputLevel;
                cout << setw(1) << left << "$";
                cout << setw(15) << right << outputQuestion;
                cout << "\n=============== ";
                cout << "===============\n";
                cout << "DAP AN SAI\n";
                level--;
                index = 1;
            }
            else {
                cout << setw(15) << left << outputLevel;
                cout << setw(1) << left << "$";
                cout << setw(15) << right << outputQuestion;
                cout << "\n=============== ";
                cout << "===============\n";
                cout << "DAP AN DUNG\n";
                index++;
            }
            system("pause");
            system("cls");
        }
        if (index > level) {
            level++;
            index = 1;
        }
    }
}
