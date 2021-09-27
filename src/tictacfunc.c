// Functions for dealing with the board
#include <ncurses.h>
// #include <curses.h>
#include "tictacfunc.h"
#include <stdio.h>
#include <stdbool.h>


// int mvwaddch(WINDOW *win, int y, int x, const chtype ch);

// Prints the two-dimensional array a
void print_bo(char a[3][3], WINDOW* win) {
    wmove(win, 0, 0);

    waddstr(win, "-------\n");
    // printf("-------\n");
    for (int i=0;i<3;++i) {
	    addstr("|");
        for (int j=0;j<3;j++) {
            // std::cout<<a[i][j];
	    wprintw(win, "%c", a[i][j]);
	    waddstr(win, "|");
        }
        // std::cout<<std::endl;
	waddstr(win, "\n");
        waddstr(win, "-------");
	waddstr(win, "\n");
    }
    wrefresh(win);
}

// Implements the logic to check who has won
char result(char a[3][3]) {
    // Checks rows
    for (int i=0;i<3;++i) {
       if ( a[i][0]==a[i][1]&&a[i][0]==a[i][2]&&a[i][1]==a[i][2]&&a[i][1]!='0') {
            return a[i][1];
        }
    }
    // Checks cols
    for(int i=0;i<3;++i) {
        if (a[0][i]==a[1][i]&&a[0][i]==a[2][i]&&a[1][i]==a[2][i]&&a[1][i]!='0') {
            return a[1][i];
        }
    }
    // Checks diagonal 1
    if (a[0][0]==a[1][1]&&a[2][2]==a[1][1]&&a[1][1]!='0') {
        return a[1][1];
    }
    // Checks diagonal 2
    if (a[0][2]==a[1][1]&&a[2][0]==a[1][1]&&a[1][1]!='0') {
        return a[1][1];
    }
    // Checks tie AFTER all others, if returning 0 it will continue
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (a[i][j]=='0') {
                return '0';
            }
        }
    }
    return 't';
}
// Places if index is a valid ch placement on board
bool ch_pos(int index, char ch, char board[3][3]) {
    int row, col;
    index--;
    col = index%3;
    row = (index-(index%3))/3;
    if (valid_place(row, col, board)) {
        board[row][col]=ch;
        return true;
    } else {
        return false;
    }
}

// Checks if the position is valid
bool valid_place(int row, int col, char board[3][3]) {
    if (row>2) {
	    return false;
    }
    if (col>2) {
	    return false;
    }
 
    if (board[row][col] == '0') {
        return true;
    }
    else {
        return false;
    }
}

int prompt(char* text, WINDOW* win) {
    
    move(30, 0);


    waddstr(win, text);

    wrefresh(win);
    int ascii_num = wgetch(win);
    // printf("%d", ascii_num);
    return ascii_num-48;

}
