#include <iostream>

#include <cstdio>

#include <conio.h>

#include <iomanip>

#include<stdlib.h>

using namespace std;

class TTT {
    char ctrl;
    int ip = 0;
    string name;
    char xo1, xo2;
    char grid[3][3];
    public:
        
        void single_player() {
            char k = 49;
            int score_1 = 0,score_2 = 0;

            while(k=='9') {
                for(int i;i<3;i++) {
                    for(int j;j<3;j++) {
                        grid[i][j]=k;
                    }
                    k++;
                }
            }
            cout << endl << endl << setw(48) << right << "* * * Tic Tac Toe * * *";
            cout<<endl<<endl<<endl<<"   Enter your name => ";
            getline(cin,name);

            if (name.size()<2 || name.size()>10) {
                cout<<"\n\nEnter the size of the name between 2 to 10 or else you can give but you may face dirty ui design";
                cout<<endl<<endl<<"   Enter your name => ";
                getline(cin,name);
            }
            cout<<setw(25)<<right<<"Choose X or O : ";
            cin>>xo1;
            
            
            

            cout<<"\n\n\n";
            cout<<setw(45)<<"Positions for playing the game\n";
            cout<<setw(45)<<right<<grid[0][0]<<" | "<<grid[0][1]<<" | "<<grid[0][2]<<endl;
            cout<<setw(54)<<right<<"----------"<<endl;
            cout<<setw(45)<<right<<grid[1][0]<<" | "<<grid[1][1]<<" | "<<grid[1][2]<<endl;
            cout<<setw(54)<<right<<"----------"<<endl;
            cout<<setw(45)<<right<<grid[2][0]<<" | "<<grid[2][1]<<" | "<<grid[2][2]<<endl;
            cout<<endl<<endl<<setw(50)<<"To play the game enter position and 'o' or 'x'\n"<<setw(20)<<"eg. 2 x, 3 o";
            cout<<"\n\nTap any key to continue...";
            getchar();
            
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    grid[i][j] = ' ';

            
        }
        void multi_player() {

        }
        void menu(int ip) {
            if (ip == 1) {
                system("cls");
                cout << endl << endl << setw(48) << right << "* * * Tic Tac Toe * * *";
                cout << "\n\n\n" << setw(55) << "| Important Instruction:- Use arrow |\n"<< setw(55)<< right <<"|   keys to navigate through menu   |\n";
                cout << "\n\n" << setw(45) << right << "[*] 1. Single Player";
                cout << "\n\n" << setw(45) << right << "[ ] 2. Multi-Player";
            } else if (ip == 2) {
                system("cls");
                cout << endl << endl << setw(48) << right << "* * * Tic Tac Toe * * *";
                cout << "\n\n\n" << setw(55) << "| Important Instruction:- Use arrow |\n"<< setw(55)<< right <<"|   keys to navigate through menu   |\n";
                cout << "\n\n" << setw(45) << right << "[ ] 1. Single Player";
                cout << "\n\n" << setw(45) << right << "[*] 2. Multi-Player";
            } else {
                system("cls");
                cout << endl << endl << setw(48) << right << "* * * Tic Tac Toe * * *";
                cout << "\n\n\n" << setw(55) << "| Important Instruction:- Use arrow |\n"<< setw(55)<< right <<"|   keys to navigate through menu   |\n";
                cout << "\n\n" << setw(45) << right << "[ ] 1. Single Player";
                cout << "\n\n" << setw(45) << right << "[ ] 2. Multi-Player";
            }
        }
    TTT() {
        cout << endl << endl << endl << endl << endl << setw(70) << right << "* * * * Welcome to Tic Tac Toe * * * *" << endl << endl <<endl<<endl<<endl<<endl<<endl;
        cout << setw(65) << right << "Tap any key to continue ...";

        ctrl = _getch();
        system("cls");
        menu(ip);
        while (true) {
            if (kbhit) {
                ctrl = _getch();
                if ((int) ctrl == 72) {
                    ip--;
                    if (ip <= 0) {
                        ip = 2;
                    }
                    menu(ip);
                } else if ((int)ctrl==80) {
                    ip++;
                    if (ip>2) {
                        ip=1;
                    }
                    menu(ip);
                } else if ((int)ctrl==13) {
                    break;
                } else if ((int)ctrl==-32) {
                    
                
                } else {
                    printf("\n\nUse arrow keys to control the pointer\n");
                }
            }
        }

        cout<<"\n\n\n";
        if (ip==1) {
            system("cls");
            single_player();
        } else if (ip==2) {
            system("cls");
            multi_player();
        }
    }
};

int main() {
    TTT a;
    getchar();
    return 0;
}