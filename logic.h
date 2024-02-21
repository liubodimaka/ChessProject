const int w = 8;


#ifndef LOGIC_H
#define LOGIC_H

void startGame(Piece board[w][w]);


void printBoard(Piece board[w][w]);

//void Chessboard(Piece board[w][w]);

//void initialState(Piece board[w][w]);


class Piece {
public:
    char pieceType;
    int posX;
    int posY;
    bool isWhite;

    char pieceType() const { return pieceType; }
    bool color() const { return isWhite; }
    bool isValid(int x, int y) const {}
    void place(Piece board[w][w], int xI, int yI, int xF, int yF, bool white, char type){}
    virtual bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class King : public Piece {
public:
    bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class Pawn : public Piece {
public:
    bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class Bishop : public Piece {
public:
    bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class Rook : public Piece {
public:
    bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class Knight : public Piece {
public:
    bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class Queen : public Piece {
public:
    bool canMove(int xF, int yF, Piece board[w][w]) const {}
};

class emptySquare : public Piece {

};


#endif
