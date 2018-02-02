#include <stdio.h>
#include <stdlib.h>
const char *BOX_TL = "\u250C";
const char *BOX_TR = "\u2510";
const char *BOX_BL = "\u2514";
const char *BOX_BR = "\u2518";
const char *BOX_T = "\u2500";
const char *BOX_L = "\u2502";
int main(int argc, char **argv) {
    if(argc == 3) {
        int w = atoi(argv[1]);
        int h = atoi(argv[2]);
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                const char *symbol;
                if(i == 0) {
                    if(j == 0) {
                        symbol = BOX_TL;
                    }
                    else if(j == w - 1) {
                        symbol = BOX_TR;
                    }
                    else {
                        symbol = BOX_T;
                    }
                }
                else if(i == h - 1) {
                    if(j == 0) {
                        symbol = BOX_BL;
                    }
                    else if(j == w - 1) {
                        symbol = BOX_BR;
                    }
                    else {
                        symbol = BOX_T;
                    }
                }
                else if(j == 0 || j == w - 1) {
                    symbol = BOX_L;
                }
                else {
                    symbol = " ";
                }
                fputs(symbol, stdout);
            }
            putc('\n', stdout);
        }
    }
    else {
        fprintf(stderr, "Usage: %s WIDTH HEIGHT\n", argv[0]);
    }
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE;
}
