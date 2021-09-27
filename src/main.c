// Main game, plays a tic tac toe game with 2 players
// Standard libraries
#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
// #include <curses.h>

// Custom libraries
#include "tictacfunc.h"
// The main game code

int main() {
    initscr();
    WINDOW* win;
    win = newwin(0, 0, 0, 0);
    if (win == NULL) {
	fprintf(stderr, "Win is null\n");
	return 1;
    }
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
        if (res!='0') {
            break;
        }
        
        while (!validposp1) {
        print_bo(board, win);

        p1pos = prompt("Player 1, enter an empty square to play(1-9): ", win);
	// scanf("%d", &p1pos);
	// p1pos = wgetch(win)-15;
	// p1pos = 5;

	wclear(win);

        validposp1 = ch_pos(p1pos, p1, board); }
        res = result(board);
        if (res!='0') {
            break;
        }
        
        while (!validposp2) {
        print_bo(board, win);
        p2pos = prompt("Player 2, enter an empty square to play(1-9): ", win);
	wclear(win);
        // scanf("%d", &p2pos);
	// p2pos = wgetch(win)-15;
        validposp2 = ch_pos(p2pos, p2, board); }
        res = result(board);
        validposp1=false;
        validposp2=false;
    } 
    print_bo(board, win);
    // Legacy result
    //printf("%c", res);
    wclear(win);
    wrefresh(win);
    delwin(win);

    if (res == p1) {
	    printf("Player 1 won!\n");
    }
    else if(res == p2) {
	    printf("Player 2 won!\n");

    }
    else  {
	    printf("Tie!\n");

    } 
/*    else {
	    fprintf(stderr, "Something went wrong, this should not happen...");
	    return 1;

    }*/


    return 0;
};
