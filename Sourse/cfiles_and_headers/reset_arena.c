//
// Created by Bare mig Altså Carl on 07-12-2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "scan_setting.h"

void arena_reset(int **arena, int size_of_arena) {

    for (int i = 0; i < size_of_arena; i++) {
        for (int b = 0; b < size_of_arena; b++) {
            arena[i][b] = 0;

        }
    }
    for (int i = 0; i < size_of_arena; i++) {
        for (int b = 0; b < size_of_arena; b++) {
            printf("[%d][%d]=%d ", i, b, arena[i][b]);
            if (b == size_of_arena - 1) { printf("\n"); }
        }
    }


}