//#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>

// int mvwaddch(WINDOW *win, int y, int x, const chtype ch);
void print_bo(char a[3][3], WINDOW* win);
char result(char a[3][3]);
bool ch_pos(int index, char ch, char board[3][3]);
bool valid_place(int row, int col, char board[3][3]);
int prompt(char text[], WINDOW* win);

