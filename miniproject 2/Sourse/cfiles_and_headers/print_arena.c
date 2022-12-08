//
// Created by Bare mig Altså Carl on 07-12-2022.
//
#include "scan_setting.h"
#include <stdio.h>

void print_arena(int **arena, int size_of_arena) {
    for (int i = 0; i < size_of_arena; i++) {
        for (int b = 0; b < size_of_arena; b++) {
            //printf("[%d,%d]=%d ", i, b, arena[i][b]);
            printf("%d", arena[i][b]);
            if (b == size_of_arena - 1) { printf("\n"); }
        }
    }
}