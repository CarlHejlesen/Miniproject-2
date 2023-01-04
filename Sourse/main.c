#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "cfiles_and_headers/scan_setting.h"
//we still need to add: ai, winner so the game stops.

void scan_setting();

void game_of_lines();

int main() {
    // here we run a settings funktion
    int computer_on, size_of_arena, lines;
    while (true) {
        scan_setting(&computer_on, &size_of_arena, &lines);
        if (lines >= 0 && size_of_arena >= 0) break;
    }
    printf("com:%d  size_of_arena:%d  lines to win:%d \n", computer_on, size_of_arena, lines);

    game_of_lines(size_of_arena, computer_on, lines);
}

void arena_reset();

void print_arena();

void scan_move();

void ai_move();

void update_arena();

void winner();

//this will be our main, driver.
//in here our game,plate will be.
//the following funktions will be in there(scan_move, ai_move, print_arena, winner, update_arena)
void game_of_lines(int size_of_arena, int computer_on_off, int lines) {


//here we declare an pointer to an array, and allocate space for an array filled with x pointers

    int **arena = malloc(sizeof(int *) * size_of_arena);
    //next we declare that the pointers in the array, we alredy have declared will point to these arrays, that we allocate x space for.
    for (int i = 0; i < size_of_arena; i++) {
        arena[i] = malloc(sizeof(int) * size_of_arena);
    }

//this is a funktion that fills the arena with 0.
    arena_reset(arena, size_of_arena);

    int turn;
    int winner1 = 0;
    int row_move_ai = 0;

    while (true) {

        turn = 1;
        scan_move(arena, size_of_arena, lines, turn, computer_on_off);
        print_arena(arena, size_of_arena);
        winner(arena, size_of_arena, lines, turn, &winner1);

        if (winner1 > 0) { break; }
        turn = 2;
        //if (row_move_ai = 1) { ai_move(row_move_ai); }
        scan_move(arena, size_of_arena, lines, turn, computer_on_off);
        print_arena(arena, size_of_arena);
        winner(arena, size_of_arena, lines, turn, &winner1);
        if (winner1 > 0) { break; }
    }

    printf("Player%d won the game\n", winner1);


    for (int i = 0; i < size_of_arena; i++) {
        free(arena[i]);
    }
    free(arena);
}


void ai_move() {}


void update_arena() {}




//we wish to test on the even level first, this will require 2 for statmets we can run through the entire array.
//