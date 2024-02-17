#include <iostream>
#include <cmath>
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

    bool getColor(){
        return isWhite;
    }

    void place(Piece board[w][w], int xI, int yI, xF, yF, bool white, char type){
        boardI[xI][yI] = new emptySquare(xI, yI);

        switch(type){
            case 'R':
            board[xF][yF] = new Rook(xF, yF, white);
            break;
            case 'N':
            board[xF][yF] = new Knight(xF, yF, white);
            break;
            case 'B':
            board[xF][yF] = new Bishop(xF, yF, white);
            break;
            case 'P':
            board[xF][yF] = new Pawn(xF, yF, white);
            break;
            case 'Q':
            board[xF][yF] = new Queen(xF, yF, white);
            break;
            case 'K':
            board[xF][yF] = new King(xF, yF, white);
            break;
        }
    }

    bool isValid(xF, yF){
        if(xF < 8 && xF >= 0 && yF < 8 && yF >= 0){
            return true;
        }
        return false;
    }

    bool isDiagonal(int xI, int yI, int xF, int yF){
            if((int)abs(xF - xI) == (int)abs(yF-yI)){
                for(int i = 0; i < ; i++){
                    if(isOccupied()){
                        return false;
                    }
                }
            }
        return true;
    }

    bool isHorizontal(int xI, int yI, int xF, int yF){
        if(yI == yF){
            for(int i = 0; i < xF-xI; i++){
                if(isOccupied()){
                    return false;
                }
            }
        }
        return true;
    }

    bool isVertical(int xI, int yI, int xF, int yF){
        if(xI == xF){
            for(int i = 0; i < yF-yI; i++){
                if(isOccupied()){
                    return false;
                }
            }
        }
        return true;
    }

    bool isL(int xI, int yI, int xF, int yF){
        if(((int)abs(xF - xI) == 2 && (int)(abs)(yF-yI) == 1) ||
         ((int)abs(xF - xI) == 1 && (int)(abs)(yF-yI) == 2))){
            return true;
        }

        return false;
    }

    //Checks if the square is occupied by a piece of the same color
    bool isOccupied(int x, int y, Piece board[w][w], bool isWhite){
        if(board[x][y].getType() != '0' && 
        (board[x][y].getColor() != isWhite)){
            return true;
        }
        return false;
    }

    //Checks if the piece can move on a certain square
    virtual void move(){

    }



};

class Piece : public King {

    King(int x, int y, bool isWhite){
        int numMoves = 0;
        pieceType = 'K';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canCastle(){
        if(numMoves == 0 ){
            return true;
        }
        return false;
    }


    bool canMove(int xF, int yF){
        if(Piece.isValid() && !isOccupied() && xFi - x <= 1 
        && yF - y <= 1){
            return true;
        }
        return false;
    }
}

class Piece : public Pawn {
    int numMoves;

    Pawn(int x, int y, bool isWhite){
        numMoves = 0;
        pieceType = "P";
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(int xF, int yF){
        if(xF-x <= 2 && numMoves == 0 && Piece.isHorizontal(xF, yF)){
            numMoves++;
        }
        Piece.place(board, xI, yI, xF, yF, isWhite, pieceType);
    }
}

class Piece : public Bishop {

    Bishop(int x, int y, bool isWhite){
        pieceType = 'B';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canMove(Piece board[w][w], int xF, int yF){
        if(isDiagonal(xF, yF) && isValid(xF, yF, isWhite)){
            Piece.place(board, xI, yI, xF, yF, isWhite, pieceType);
        }
    }
}

class Piece : public Rook {
    int numMoves;

    Rook(int x, int y, bool isWhite){
        numMoves = 0;
        pieceType = 'R';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canMove(xF, yF){
        if((Piece.isVertical(xF, yF) || Piece.isHorizontal(xF, yF) && isValid(xF, yF, isWhite))){
            Piece.place(board, xI, yI, xF, yF, isWhite, pieceType);
        }
    }
}

class Piece : public Knight {

    Knight(int x, int y, bool isWhite){
        pieceType = 'N';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool move(int xF, int yF){
        if(Piece.isL(xF, yF) && Piece.isValid(xF, yF, isWhite)){
            Piece.place(board, xI, yI, xF, yF, isWhite, pieceType);
        }
    }
}

class Piece : public Queen {

    Queen(int x, int y, bool isWhite){
    pieceType = 'Q';
    posX = x;
    posY = y; 
    this->isWhite = isWhite;
    }

    bool move(int xF, int yF){
        if((Piece.isDiagonal(xF, yF) || Piece.isHorizontal(xF, yF) || Piece.isVertical(xF, yF)) 
        && isValid(xF, yF, isWhite)){
            Piece.place(board, xI, yI, xF, yF, isWhite, pieceType);
        }
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