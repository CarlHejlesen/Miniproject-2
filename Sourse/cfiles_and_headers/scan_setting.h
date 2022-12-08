//
// Created by Bare mig Altså Carl on 07-12-2022.
//

#ifndef MINIPROJECT_2_SCAN_SETTING_H
#define MINIPROJECT_2_SCAN_SETTING_H
#include "scan_setting.c"
void scan_setting(int *computer_on, int *size, int *lines);

#include "reset_arena.c"
void arena_reset(int **arena, int size_of_arena);

#include "scan_move.c"
void scan_move(int **arena, int size_of_arena, int lines, int turn);

#include "print_arena.c"
void print_arena(int **arena, int size_of_arena);

#include "winner.c"
void winner(int **arena, int size_of_arena, int lines, int turn, int *winner1);

#endif //MINIPROJECT_2_SCAN_SETTING_H
