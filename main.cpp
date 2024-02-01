#include <iostream>
#include <logic.h>
#include <move.h>
using namespace std;
const int w = 8;


//Runs the Game
int main() {
    int turn = 0;
    bool checkmate = false;
    char board[w][w];

    startGame(board);
    //while (!checkmate) {

    printBoard(board);
    turn++;
    //}

}