#include <iostream>
#include "logic.h"
#include "input.h"
using namespace std;
const int w = 8;


void move(Piece board[w][w]){
    bool isValid = false;
    while(!isValid){
        int* moveParams = input();
        int xI = moveParams[0]; int yI = moveParams[1]; 
        int xF = moveParams[2]; int yF = moveParams[3];
        isValid = board[w][w].canMove(xF, yF, board);
        if(isValid){
            board[w][w].place(board, xI, yI, xF, yF, board[xI][yI].color(), board[xI][yI].pieceType());
            break;
        }
    }

}

//Runs the Game
int main() {
    int turn = 0;
    bool checkmate = false;
    bool stalemate = false;
    Piece board[w][w];

    startGame(board);
    while (!checkmate && !stalemate) {
    move(board);
    printBoard(board);
    turn++;
    }

    return 0;
}