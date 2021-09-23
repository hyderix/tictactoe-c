//Main game, plays a tic tac toe game with 2 players
// Standard libraries
#include <stdio.h>
#include <stdbool.h>

// Custom libraries
#include "tictacfunc.h"
// The main game code
int main() {
    const char p1='X';
    const char p2='O';
    int p1pos, p2pos;
    char res='0';
    char board[3][3];
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;j++) {
            board[i][j] = '0';
        }
    }
    bool validposp1=false;
    bool validposp2=false;
    while (1) {
        
        print_bo(board);
        while (!validposp1) {
        printf("Player 1, enter an empty square to play: ");
	scanf("%d", &p1pos);
        validposp1 = ch_pos(p1pos, p1, board); }
        res = result(board);
        if (res!='0') {
            break;
        }
        
        print_bo(board);
        while (!validposp2) {
        printf("Player 2, enter an empty square to play: ");
        scanf("%d", &p2pos);
        validposp2 = ch_pos(p2pos, p2, board); }
        if (res!='0') {
            break;
        }
        res = result(board);
        validposp1=false;
        validposp2=false;
    } 
    print_bo(board);
    // Legacy result
    //printf("%c", res);

    if (res == p1) {
	    printf("Player 1 won!\n");
    }
    else if(res == p2) {
	    printf("Player 2 won!\n");

    }
    else if(res == 't') {
	    printf("Tie!\n");

    } 
    else {
	    fprintf(stderr, "Something went wrong, this should not happen...");
	    return 1;

    }



    return 0;
};
