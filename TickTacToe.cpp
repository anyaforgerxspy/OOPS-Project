#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
bool tie=false;
string n1="";
string n2="";

void functionOne(){
    cout << "   |      |  " << endl;
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " " << endl;
    cout << "||" << endl;
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " " << endl;
    cout << "||" << endl;
    cout << "   |      |   " << endl;
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " " << endl;
    cout << "   |      |   " << endl;
}

void functionTwo(){
    int digit;
    if(token=='x'){
        cout << n1 << " please enter: ";
    } else {
        cout << n2 << " please enter: ";
    }
    cin >> digit;

    row = (digit - 1) / 3;
    column = (digit - 1) % 3;

    if(digit < 1 || digit > 9 || space[row][column] == 'x' || space[row][column] == '0'){
        cout << "Invalid move! Try again." << endl;
        functionTwo();
    } else {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    }
    functionOne();
}

bool functionThree(){
    for(int i=0;i<3;i++){
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || 
           space[0][i] == space[1][i] && space[0][i] == space[2][i]){
            return true;
        }
    }
    if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || 
       space[0][2] == space[1][1] && space[1][1] == space[2][0]){
        return true;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j] != 'x' && space[i][j] != '0'){
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main(){
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    cout << n1 << " is player 1, so he/she will play first." << endl;
    cout << n2 << " is player 2, so he/she will play second." << endl;

    while(!functionThree()){
        functionTwo();
    }

    if(token == 'x' && !tie){
        cout << n2 << " Wins!" << endl;
    } else if(token == '0' && !tie){
        cout << n1 << " Wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}