#include <iostream>
using namespace std;
const int w = 8;


class Piece {
private:
    char pieceType;
    int posX;
    int posY;
    bool isOccupied;
    bool isWhite;


    Piece(){

    }


    void diagonal(){

    }

    void horizontal(){

    }

    void vertical(){

    }

    //Checks if the piece can move on a certain square
    void move(){

    }



};

Piece : public King {

    bool move(xF, yF){

    }
}

Piece : public Pawn {
    bool move(xF, yF){

    }
}

Piece : public Bishop {
    bool move(xF, yF){

    }
}

Piece : public Rook {
    bool move(xF, yF){

    }
}

Piece : public Knight {
    bool move(xF, yF){

    }
}

Piece : public Queen {
    bool move(xF, yF){

    }
}
Piece : emptySquare(){
    emptySquare():{
        posX = ;
        posY = ;
        isOccupied = false;

    }
}



//Creates an empty array representing the chessboard and returns it
void Chessboard(char board[w][w]) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < 8; y++) {
            board[x][y] = '0';
        }
    }

}


//Sets the board to its default state and returns the updated state
void initialState(char board[w][w]) {
    // Black Pieces
    board[w - 8][w - 8] = 'r';
    board[w - 8][w - 1] = 'r';
    board[w - 8][w - 7] = 'n';
    board[w - 8][w - 2] = 'n';
    board[w - 8][w - 6] = 'b';
    board[w - 8][w - 3] = 'b';
    board[w - 8][w - 5] = 'k';
    board[w - 8][w - 4] = 'q';

    // Black Pawns
    for (int i = 0; i < w; i++) {
        board[w - 7][i] = 'p';
    }


    // White Pieces
    board[w - 1][w - 8] = 'R';
    board[w - 1][w - 1] = 'R';
    board[w - 1][w - 7] = 'N';
    board[w - 1][w - 2] = 'N';
    board[w - 1][w - 6] = 'B';
    board[w - 1][w - 3] = 'B';
    board[w - 1][w - 5] = 'Q';
    board[w - 1][w - 4] = 'K';

    // White Pawns
    for (int i = 0; i < w; i++) {
        board[w - 2][i] = 'P';
    }

}


//Prints the board to the console
void printBoard(char board[w][w]) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < w; y++) {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
}

void startGame(char board[w][w]) {
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
