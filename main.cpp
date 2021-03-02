//Main game, plays a tic tac toe game with 2 players
#include <iostream>
#include "tictacfunc.h"
// The main game code
int main() {
    const char p1='x';
    const char p2='o';
    int p1pos, p2pos;
    char res='0';
    char board[3][3];
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;j++) {
            board[i][j] = '0';
        }
    }
    bool validposp1, validposp2;
    validposp1=false;
    validposp2=false;
    while (1) {
        
        print_bo(board);
        while (!validposp1) {
        std::cout<<"Player 1, enter an empty square to play: ";
        std::cin>>p1pos;
        validposp1 = ch_pos(p1pos, p1, board); }
        res = result(board);
        if (res!='0') {
            break;
        }
        
        print_bo(board);
        while (!validposp2) {
        std::cout<<"Player 2, enter an empty square to play: ";
        std::cin>>p2pos;
        validposp2 = ch_pos(p2pos, p2, board); }
        if (res!='0') {
            break;
        }
        res = result(board);
        validposp1=false;
        validposp2=false;
    } 
    print_bo(board);
    std::cout<<res<<" won!";


    return 0;
}