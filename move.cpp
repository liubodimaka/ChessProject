#include <iostream>
using namespace std;
const w = 8;

void startGame(Piece board[w][w]) {
    Chessboard(board);
    initialState(board);
}


//Converts lowercase letter to X position 
//on the board
bool convertLetterToX(string move, int posX) {
    char  letterA = 'a';
    if (move.length() == 4 && (move[2] - letterA <= 8)) {
        posX = move[2] - letterA;
    }
    else if (move.length() == 3 && (move[1] - letterA <= 8)) {
        posX = move[1] - letterA;
    }
    else if (move.length() == 2 && (move[0] - letterA <= 8)) {
        posX = move[0] - letterA;
    }
}


//Account for multiple pieces that can move on the same square,
//check, checkmate, taking, and any combination of these
//Converts piece 
//add castle(move == "O-O-O || O-O") and take cases(move.length() == 4)
bool convertToPiece(string move, char piece,
    bool isKingCastle, bool isQueenCastle) {
    if (move == "O-O-O") {
        isQueenCastle = true;
    }
    else if (move == "O-O") {
        isKingCastle = true;
    }
    else if (move.length() == 3) {
        switch (move[0]) {
        case 'N':
            piece = 'N';
            return true;
            break;
        case 'B':
            piece = 'B';
            return true;
            break;
        case 'R':
            piece = 'R';
            return true;
            break;
        case 'Q':
            piece = 'Q';
            return true;
            break;
        case 'K':
            piece = 'K';
            return true;
            break;
        }
    }
    else if (move.length() == 2) {
        piece = 'p';
    }
    return true;
    return false;
}

//Converts input to 
bool convertToPosition(string move, int posX, int posY) {
    //switch(move[])
    return true;
}

//Asks for input in chess notation and 
//converts to move on board
void convertToMove(char board[w][w], string move) {
    //Unicode characters are ordered alphanumberically
    //move.length() ==2;
    //move[0] <= h
    //int y = stoi(move, 1)
    //y <= 8
    //switch case for every piece
    //determine if it's black or white's move - turn % 2 = 0
    int posX;
    int posY;
    while (true) {
        string move;
        cin >> move;
        if (move.length() == 2) {
            convertToPosition(move, posX, posY);
        }
        else if (move.length() == 3) {
            convertToPosition(move, posX, posY);
        }

    }

}