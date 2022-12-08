#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "cfiles_and_headers/scan_setting.h"



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
//size_of_arena=4;
    game_of_lines(size_of_arena, computer_on, lines);
}

//settings



void arena_reset();

void print_arena();

void scan_move();

void ai_move();

void update_arena();

void winner();

//dette er vores main, driver.
void game_of_lines(int size_of_arena, int computer_on_off, int lines) {
//herinde skal malloc pladen ligge, den skal hedde arena.
//herinde skal ligge følgene funktioner (scan_move, ai_move, update_arena, print_arena, winner)


// here we build the 2 array. with mem. first we make an array with pointers that points to arrays. then we make the arrays
    int **arena = malloc(sizeof(int *) * size_of_arena);
    for (int i = 0; i < size_of_arena; i++) {
        arena[i] = malloc(sizeof(int) * size_of_arena);
    }


//extra funktion der reseter pladen. skal kun køre en gang
    int run = 0;
    while (run == 0) {
        arena_reset(arena, size_of_arena);
        run++;
    }


    int turn;

    int row_move_ai = 0;
    while (true) {

turn=1;
        scan_move(arena, size_of_arena, lines, turn);
        print_arena(arena, size_of_arena);
        winner(arena, size_of_arena, lines, turn);

turn=2;
        if(row_move_ai=1){ai_move(row_move_ai);}
        scan_move(arena, size_of_arena, lines, turn);
        print_arena(arena, size_of_arena);
        winner(arena, size_of_arena, lines, turn);


        update_arena();

        //printf("test line 93");
    }
    printf("test line 94");
}




void ai_move() {}


void update_arena() {}

//her opstår problemet


//we wish to test on the even level first, this will require 2 for statmets we can run through the entire array.
//