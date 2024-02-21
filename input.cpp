#include <iostream>
using namespace std;


int convertToX(string input){
    int x = input[0] - 'a';
    if(x <= 8){
        return x;
    }
    return -1;
}

int convertToY(string input){
    char y = input[1] - '0';
    if(y <= 8){
        return y;
    }
    return -1;
}

bool isWithinLimits(int x, int y){
    if(x != -1 && y != -1){
            return true;
    } else {
        return false;
    }
}


int* input(){
    bool withinLimits = false;
    int xI, yI, xF, yF;

    while(!withinLimits){
        cout << "Enter starting position(ex. a4): ";
        string input;
        cin >> input;
        if(input.length() == 2){
            xI = convertToX(input);
            yI = convertToY(input);
            withinLimits = isWithinLimits(xI, yI);
        } 
    }

    withinLimits = false;
    while(!withinLimits){
        cout << "Enter final position(ex. a4): ";
        string input;
        cin >> input;
        if(input.length() == 2){
            xF = convertToX(input);
            yF = convertToY(input);
            withinLimits = isWithinLimits(xF, yF);
        } 
    }
    int moveParams[4] = {xI, yI, xF, yF};
    return moveParams;
}

// cout << "Invalid move. Input must be 2 characters long including a letter a-h and number 1-8. " << endl;