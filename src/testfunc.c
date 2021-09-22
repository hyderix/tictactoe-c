//Used to test the program functions
#include <stdio.h>
#include "tictacfunc.h"
// A simple test if the library
int main() {
    char a[3][3]={{'x', 'x', 'o'},{'o','o','x'},{'x','o','x'}};
    print_bo(a);
    printf("%c", result(a));
    return 0;
}
