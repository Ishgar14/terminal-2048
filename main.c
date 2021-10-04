#include <math.h>
#include <time.h>
#include "./screen.h"


char getch();



void up(int **screen, int size){
    for(int i = size - 1; i > 0; i--){
        for (int j = 0; j < size; j++) {
            if (screen[i][j] == screen[i - 1][j]){
                screen[i][j] = 0;
                screen[i - 1][j] *= 2;
            }
            else if(screen[i - 1][j] == 0){
                screen[i - 1][j] = screen[i][j];
                screen[i][j] = 0;
            }
        }
    }
}

void down(int **screen, int size){
    for(int i = 0; i < size - 1; i++){
        for (int j = 0; j < size; j++) {
            if (screen[i][j] == screen[i + 1][j]){
                screen[i][j] = 0;
                screen[i + 1][j] *= 2;
            }
            else if(screen[i + 1][j] == 0){
                screen[i + 1][j] = screen[i][j];
                screen[i][j] = 0;
            }
        }
    }
}

void left(int **screen, int size){
    for(int i = 0; i < size; i++){
        for (int j = size - 1; j > 0; j--) {
            if (screen[i][j] == screen[i][j - 1]){
                screen[i][j] = 0;
                screen[i][j - 1] *= 2;
            }
            else if(screen[i][j - 1] == 0){
                screen[i][j - 1] = screen[i][j];
                screen[i][j] = 0;
            }
        }
    }
}

void right(int **screen, int size){
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++) {
            if (screen[i][j] == screen[i][j + 1]){
                screen[i][j] = 0;
                screen[i][j + 1] *= 2;
            }
            else if(screen[i][j + 1] == 0){
                screen[i][j + 1] = screen[i][j];
                screen[i][j] = 0;
            }
        }
    }
}


void movement(int **screen, int size, int *score) {
    switch (getch()) {
        case 'w':
            up(screen, size);
            break;
        case 'a':
            left(screen, size);
            break;
        case 's':
            down(screen, size);
            break;
        case 'd':
            right(screen, size);
            break;
        case 'q':
            printf("Your score was %d\n", *score);
            printf("Thank you for playing!\n");
            exit(EXIT_SUCCESS);
            break;
    }
}


void main() {
    srand(time(0));
    int size = 7, score = 0;

    int **screen = make_screen(size);

    while (1) {
        render(screen, size);
        movement(screen, size, &score);
        if (has_empty_space(screen, size)) {
            put_random_number(screen, size);
            clear();
            score = (int) log2(greatest_number(screen, size));
        }
        else {
            printf("Game Over\nYour score was %d", score);
            break;
        }
    }
}