#include <iostream>
using namespace std;
const int w = 8;

//Create objects of derived class based on piece type
class Piece {
private:
    char pieceType;
    int posX;
    int posY;
    bool isWhite;

    char getPiece(){
        return pieceType;
    }

    void replace(Piece board[w][w], int xI, int yI, xF, yF, bool white, char type){
        boardI[xI][yI] = new emptySquare(xI, yI);
        board[]

        if(type == 'R'){
            board[xF][yF] = new Rook(xF, yF, white);
        } else if(type == 'K'){
            board[xF][yF] = new King(x, y, white);
        } else if(type == 'N'){
            board[xF][yF] = new Knight(xF, yF, white);
        } else if(type == 'B'){
        board[xF][yF] = new Bishop(xF, yF, white);
        } else if(type == 'P'){
            board[xF][yF] = new Pawn(xF, yF, white);
        } else if(type == 'Q'){
            board[xF][yF] = new Queen(xF, yF, white);
        }
    }

    void diagonal(){

    }

    void horizontal(){

    }

    void vertical(){

    }

    //Checks if the piece can move on a certain square
    virtual void move(){

    }



};

class Piece : public King {

    King(int x, int y, bool isWhite){
        pieceType = 'K';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(xF, yF){
        
    }
}

class Piece : public Pawn {

    Pawn(int x, int y, bool isWhite){
        pieceType = "P";
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(xF, yF){
        Piece.replace(board, xI, yI, xF, yF, isWhite, pieceType);
    }
}

class Piece : public Bishop {

    Bishop(int x, int y, bool isWhite){
        pieceType = 'B';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(Piece board[w][w],xF, yF){
        Piece.replace(board, xI, yI, xF, yF, isWhite, pieceType);
    }
}

class Piece : public Rook {

    Rook(int x, int y, bool isWhite){
        pieceType = 'R';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(xF, yF){
        Piece.replace(board, xI, yI, xF, yF, isWhite, pieceType);
    }
}

class Piece : public Knight {

    Knight(int x, int y, bool isWhite){
        pieceType = 'N';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(xF, yF){

    }
}

class Piece : public Queen {

    Queen(int x, int y, bool isWhite){
    pieceType = 'Q';
    posX = x;
    posY = y; 
    this->isWhite = isWhite;
    }

    bool move(xF, yF){

    }
}
class Piece : emptySquare(){

    emptySquare(int x, int y){
        pieceType = '0';
        posX = x; 
        posY = y;
    }

}



//Creates an empty array representing the chessboard and returns it
void Chessboard(Piece board[w][w]) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < 8; y++) {
            board[x][y] = emptySquare(x, y);
        }
    }

}


//Sets the board to its default state and returns the updated state
void initialState(Piece board[w][w]) {
    // Black Pieces
    board[0][0] = new Rook(0, 0, false);
    board[0][7] = new Rook(0, 7, false);
    board[0][1] = new Knight(0, 1, false);
    board[0][6] = new Knight(0, 6, false);
    board[0][2] = new Bishop(0, 2, false);
    board[0][5] = new Bishop(0, 5, false);
    board[0][3] = new King(0, 3, false);
    board[0][4] = new Queen(0, 4, false);

    // Black Pawns
    for (int i = 0; i < w; i++) {
        board[1][i] = new Pawn(1);
    }


    // White Pieces
    board[7][0] = new Rook(7, 0, true);
    board[7][7] = new Rook(7, 7, true);
    board[7][1] = new Knight(7, 1, true);
    board[7][6] = new Knight(7, 6, true);
    board[7][2] = new Bishop(7, 2, true);
    board[7][5] = new Bishop(7, 5, true);
    board[7][3] = new Queen(7, 3, true);
    board[7][4] = new King(7, 4, true);

    // White Pawns
    for (int i = 0; i < w; i++) {
        board[6][i] = new Pawn(6, i, true);
    }

}


//Prints the board to the console
void printBoard(Piece board[w][w]) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < w; y++) {
            cout << board[x][y].getPiece() << " ";
        }
        cout << endl;
    }
}

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
