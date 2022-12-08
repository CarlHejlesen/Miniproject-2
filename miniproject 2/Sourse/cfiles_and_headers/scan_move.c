//
// Created by Bare mig Altså Carl on 07-12-2022.
//
#include "scan_setting.h"
#include <stdlib.h>
#include <stdio.h>



void scan_move(int **arena, int size_of_arena, int lines, int turn) {
    assert(size_of_arena > 0);
    assert(lines > 0);
    assert(turn>=0);

    int row;
    int low = -20;
    int row_1, row_2;

    //player 1 turn


    while (true) {
        while (true) {
            printf("what move do you want to do p%d?\n", turn);
            scanf("%d", &row);
            if (row >= 0 && row <= size_of_arena) { break; }
            printf("not valid input try again.  Chose a number between 0 and %d\n", size_of_arena - 1);
        }
        for (int i = 0; i < size_of_arena; i++) {
            if (arena[i][row] == 0) {
                low = i;
            }
            if (arena[i][row] == 1 || arena[i][row] == 2) {
                //printf("here it did not work row=[%d] collom=[%d]\n", i, row_1);
            }
        }
        if (low != -20 && row <= size_of_arena - 1 && row >= 0) {
            arena[low][row] = turn;
            //printf("it is valid)");
            break;
        }
    }

/*
    print_arena(arena, size_of_arena);
    winner(arena, size_of_arena, lines);
//player 2 turn
    low = -20;

    while (true) {
        while (true) {
            printf("what move do you want to do p2?\n");
            scanf("%d", &row_2);
            if (row_2 >= 0 && row_2 <= size_of_arena) { break; }
            printf("not valid input try again.  Chose a number between 0 and %d\n", size_of_arena - 1);
        }
        for (int i = 0; i < size_of_arena; i++) {
            if (arena[i][row_2] == 0) { low = i; }
            if (arena[i][row_2] == 1 || arena[i][row_2] == 2) {
                //printf("here it did not work row=[%d] collom=[%d]\n", i, row_2);
            }
        }
        if (low != -20 && row_2 <= size_of_arena - 1 && row_2 >= 0) {
            arena[low][row_2] = 2;
            //printf("it is valid)");

            break;
        }
    }
*/
}