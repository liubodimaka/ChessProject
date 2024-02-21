#include <iostream>
#include <cmath>
using namespace std;
const int w = 8;

class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;
class emptySquare;

//Create objects of derived class based on piece type
class Piece {
public:
    char pieceType;
    int posX;
    int posY;
    bool isWhite;

    char pieceType(){
        return pieceType;
    }

    bool color(){
        return isWhite;
    }

    void place(Piece board[w][w], int xI, int yI, int xF, int yF, bool white, char type){
        //delete board[xI][yI];
        board[xI][yI] = emptySquare(xI, yI);

        switch(type){
            case 'R':
            board[xF][yF] = Rook(xF, yF, white);
            break;
            case 'N':
            board[xF][yF] = Knight(xF, yF, white);
            break;
            case 'B':
            board[xF][yF] = Bishop(xF, yF, white);
            break;
            case 'P':
            board[xF][yF] = Pawn(xF, yF, white);
            break;
            case 'Q':
            board[xF][yF] = Queen(xF, yF, white);
            break;
            case 'K':
            board[xF][yF] = King(xF, yF, white);
            break;
        }
    }


    bool isValid(int xF, int yF){
        if(xF < 8 && xF >= 0 && yF < 8 && yF >= 0){
            return true;
        }
        return false;
    }

    bool isDiagonal(int xF, int yF, Piece board[w][w]){
            if((int)abs(xF - posX) == (int)abs(yF-posY)){
                for(int i = 0; i < xF; i++){
                    if(isOccupied(xF, yF, board)){
                        return false;
                    }
                }
            }
        return true;
    }

    bool isHorizontal(int xF, int yF, Piece board[w][w]){
        if(posY == yF){
            for(int i = 0; i < xF-posX; i++){
                if(isOccupied(xF, yF, board)){
                    return false;
                }
            }
        }
        return true;
    }

    bool isVertical(int xF, int yF, Piece board[w][w]){
        if(posX == xF){
            for(int i = 0; i < yF-posY; i++){
                if(isOccupied(xF, yF, board)){
                    return false;
                }
            }
        }
        return true;
    }

    bool isL(int xF, int yF, Piece board[w][w]){
        if(((int)abs(xF - posX) == 2 && (int)(abs)(yF - posY) == 1) ||
         ((int)abs(xF - posX) == 1 && (int)abs(yF - posY) == 2)){
            return true;
        }

        return false;
    }

    //Checks if the square is occupied by a piece of the same color
    bool isOccupied(int xF, int yF, Piece board[w][w]){
        if(board[xF][yF].pieceType() != '0' && 
        (board[xF][yF].color() != isWhite)){
            return true;
        }
        return false;
    }

    //Checks if the piece can move on a certain square
    virtual bool canMove(int xF, int yF, Piece board[w][w]){

    }



};

class King : public Piece {
public:
    bool hasMoved = false;

    King(int x, int y, bool isWhite){
        bool hasMoved = false;
        pieceType = 'K';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canCastle(){
        if(!hasMoved){
            return true;
        }
        return false;
    }


    bool canMove(int xF, int yF, Piece board[w][w]) override {
        if(isValid(xF, yF) && !isOccupied(xF, yF, board) && xF
        - posX <= 1 && yF - posY <= 1){
            return true;
        }
        return false;
    }
};

class Pawn : public Piece {
public:
    bool hasMoved;

    Pawn(int x, int y, bool isWhite){
        bool hasMoved = false;
        pieceType = 'P';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canMove(int xF, int yF, Piece board[w][w]) override {
        if(xF-posX <= 2 && !hasMoved && isHorizontal(xF, yF, board)){
            hasMoved = true;
            return true;
        }
        return false;
    }
};

class Bishop : public Piece {
public:
    Bishop(int x, int y, bool isWhite){
        pieceType = 'B';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canMove(int xF, int yF, Piece board[w][w]) override {
        if(isDiagonal(xF, yF, board) && isValid(xF, yF)){
            return true;
        }
        return false;
    }
};

class Rook : public Piece {
public:
    bool hasMoved;

    Rook(int x, int y, bool isWhite){
        bool hasMoved = false;
        pieceType = 'R';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canMove(int xF, int yF, Piece board[w][w]) override {
        if((isVertical(xF, yF, board) || isHorizontal(xF, yF, board) && isValid(xF, yF))){
            hasMoved = true;
            return true;
        }
        return false;
    }
};

class Knight : public Piece {
public:
    Knight(int x, int y, bool isWhite){
        pieceType = 'N';
        posX = x;
        posY = y; 
        this->isWhite = isWhite;
    }

    bool canMove(int xF, int yF, Piece board[w][w]) override {
        if(isL(xF, yF, board) && isValid(xF, yF)){
            return true;
            //Piece.place(board, xI, yI, xF, yF, isWhite, pieceType);
        }
        return false;
    }
};

class Queen : public Piece {
public:
    Queen(int x, int y, bool isWhite){
    pieceType = 'Q';
    posX = x;
    posY = y; 
    this->isWhite = isWhite;
    }

    bool canMove(int xF, int yF, Piece board[w][w]) override {
        if((isDiagonal(xF, yF, board) || isHorizontal(xF, yF, board) || isVertical(xF, yF))
         && isValid(xF, yF)){
            return true;
        }
        return false;
    }
};

class emptySquare : public Piece{
public:
    emptySquare(int x, int y){
        pieceType = '0';
        posX = x; 
        posY = y;
    }

};



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
    board[0][0] = Rook(0, 0, false);
    board[0][7] = Rook(0, 7, false);
    board[0][1] = Knight(0, 1, false);
    board[0][6] = Knight(0, 6, false);
    board[0][2] = Bishop(0, 2, false);
    board[0][5] = Bishop(0, 5, false);
    board[0][3] = King(0, 3, false);
    board[0][4] = Queen(0, 4, false);

    // Black Pawns
    for (int i = 0; i < w; i++) {
        board[1][i] = Pawn(1, i, false);
    }


    // White Pieces
    board[7][0] = Rook(7, 0, true);
    board[7][7] = Rook(7, 7, true);
    board[7][1] = Knight(7, 1, true);
    board[7][6] = Knight(7, 6, true);
    board[7][2] = Bishop(7, 2, true);
    board[7][5] = Bishop(7, 5, true);
    board[7][3] = Queen(7, 3, true);
    board[7][4] = King(7, 4, true);

    // White Pawns
    for (int i = 0; i < w; i++) {
        board[6][i] = Pawn(6, i, true);
    }

}

void startGame(Piece board[w][w]) {
    Chessboard(board);
    initialState(board);
}

//Prints the board to the console
void printBoard(Piece board[w][w]) {
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < w; y++) {
            cout << board[x][y].pieceType() << " ";
        }
        cout << endl;
    }
}