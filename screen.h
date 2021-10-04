#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **make_screen(int size) {
    int **screen = (int**) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        screen[i] = (int*) calloc(size, sizeof(int));
        memset(&screen[i][0], 0, size * sizeof(int));
    }

    return screen;
}

void render(int **screen, int size) {
    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < size; j++) {
            if (screen[i][j] == 0)
                printf("      |");
            else
                printf("%5d |", screen[i][j]);
        }

        printf("\n");
        for (int j = 0; j < size - 1; j++)
            printf("========");
        printf("==\n");
    }
}

void clear() {
    system("cls");
}

int has_empty_space(int **screen, int size){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (screen[i][j] == 0)
                return 1;
        
    return 0;
}


void put_random_number(int **screen, int size) {
    int row = rand() % size, col = rand() % size;

    while(screen[row][col] != 0){
        row = rand() % size;
        col = rand() % size;
    }

    screen[row][col] = 1 << (rand() % 3);
}

int greatest_number(int **screen, int size) {
    int max = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if(screen[i][j] > max)
                max = screen[i][j];
                
    return max;
}