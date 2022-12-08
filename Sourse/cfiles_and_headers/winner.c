//
// Created by Bare mig Altså Carl on 07-12-2022.
//


#include "scan_setting.h"
#include <stdio.h>
#include <assert.h>

void horizontal_check();

void vertical_check();

void high_left_check();

void low_left_check();

void winner(int **arena, int size_of_arena, int lines, int turn, int *winner1) {

    assert(winner1 >= 0);
    assert(turn >= 0);
    assert(size_of_arena >= 0);
    assert(lines >= 0);
    int winner = 0;
    while (true) {

        if (winner > 0) { break; }
        horizontal_check(arena, size_of_arena, lines, turn, &winner); // [works]
        if (winner > 0) { break; }
        vertical_check(arena, size_of_arena, lines, turn, &winner); // [works]
        if (winner > 0) { break; }
        high_left_check(arena, size_of_arena, lines, turn, &winner);
        if (winner > 0) { break; }
        low_left_check(arena, size_of_arena, lines, turn, &winner);
        if (winner > 0) { break; }
        break;
    }
    if (winner > 0) { *winner1 = turn; }
}

void horizontal_check(int **arena, int size_of_arena, int lines, int turn, int *winner1) {
    assert(winner1 >= 0);
    assert(turn >= 0);
    assert(size_of_arena >= 0);
    assert(lines >= 0);

    //this have to run 25 times so we can tjek 25 times
    //here we will check horizontal
    int points;
    int winner = 0;
    //here we run it as many times as we need
    for (int i = 0; i <= size_of_arena - 1; i++) {
        for (int o = 0; o <= size_of_arena - 1; o++) {

            //here we check if there is a number that corelates to the players turn.
            if (arena[o][i] == turn) {//printf("test %d %d ", o, i);
                //here we secure that we wont check out of bounds by limiting the checker to inside the arena
                if (i + lines - 1 <= size_of_arena - 1) { //printf("\ndo i get here? ");
                    //this is our counter this will count up when the check equals turn
                    points = 0;
                    //here we run the checker as many times that there is lines for win
                    for (int p = 0; p <= lines - 1; p++) {
                        if (arena[o][i + p] == turn) {
                            points++; //printf("points= %d, check_tal_col=%d check_row=%d \n", points, o+p, i);
                            //if points=lines we have found our winner
                            if (points == lines) { *winner1 = turn; }
                        }
                    }
                }
            }
        }
    }


}

void vertical_check(int **arena, int size_of_arena, int lines, int turn, int *winner1) {
    assert(winner1 >= 0);
    assert(turn >= 0);
    assert(size_of_arena >= 0);
    assert(lines >= 0);

    int points;
    int winner = 0;
    //here we run it as many times as we need
    for (int i = 0; i <= size_of_arena - 1; i++) {
        for (int o = 0; o <= size_of_arena - 1; o++) {

            //here we check if there is a number that corelates to the players turn.
            if (arena[o][i] == turn) {//printf("test %d %d ", o, i);
                //here we secure that we wont check out of bounds by limiting the checker to inside the arena
                if (o + lines - 1 <= size_of_arena - 1) { //printf("\ndo i get here? ");
                    //this is our counter this will count up when the check equals turn
                    points = 0;
                    //here we run the checker as many times that there is lines for win
                    for (int p = 0; p <= lines - 1; p++) {
                        if (arena[o + p][i] == turn) {
                            points++; //printf("points= %d, check_tal_col=%d check_row=%d \n", points, o+p, i);
                            //if points=lines we have found our winner
                            if (points == lines) { *winner1 = turn; }
                        }
                    }
                }
            }
        }
    }

}

void high_left_check(int **arena, int size_of_arena, int lines, int turn, int *winner1) {
    assert(winner1 >= 0);
    assert(turn >= 0);
    assert(size_of_arena >= 0);
    assert(lines >= 0);


    int points;
    int winner = 0;
    //here we run it as many times as we need
    for (int i = 0; i <= size_of_arena - 1; i++) {
        for (int o = 0; o <= size_of_arena - 1; o++) {

            //here we check if there is a number that corelates to the players turn.
            if (arena[o][i] == turn) {//printf("test %d %d ", o, i);
                //here we secure that we wont check out of bounds by limiting the checker to inside the arena
                if (o + lines - 1 <= size_of_arena - 1 &&
                    i + lines - 1 <= size_of_arena - 1) { //printf("\ndo i get here? ");
                    //this is our counter this will count up when the check equals turn
                    points = 0;
                    //here we run the checker as many times that there is lines for win
                    for (int p = 0; p <= lines - 1; p++) {
                        if (arena[o + p][i + p] == turn) {
                            points++; //printf("points= %d, check_tal_col=%d check_row=%d \n", points, o+p, i);
                            //if points=lines    we have found our winner
                            if (points == lines) { *winner1 = turn; }
                        }
                    }
                }
            }
        }
    }


}

void low_left_check(int **arena, int size_of_arena, int lines, int turn, int *winner1) {
    assert(winner1 >= 0);
    assert(turn >= 0);
    assert(size_of_arena >= 0);
    assert(lines >= 0);

    int points;
    int winner = 0;
    //here we run it as many times as we need
    for (int i = 0; i <= size_of_arena - 1; i++) {
        for (int o = 0; o <= size_of_arena - 1; o++) {

            //here we check if there is a number that corelates to the players turn.
            if (arena[o][i] == turn) {//printf("test %d %d ", o, i);
                //here we secure that we wont check out of bounds by limiting the checker to inside the arena
                if (o - lines - 1 >= 0 && i + lines - 1 <= size_of_arena - 1) { //printf("\ndo i get here? ");
                    //this is our counter this will count up when the check equals turn
                    points = 0;
                    //here we run the checker as many times that there is lines for win
                    for (int p = 0; p <= lines - 1; p++) {
                        if (arena[o - p][i + p] == turn) {
                            points++; //printf("points= %d, check_tal_col=%d check_row=%d \n", points, o+p, i);
                            //if points=lines    we have found our winner
                            if (points == lines) { *winner1 = turn; }
                        }
                    }
                }
            }
        }
    }

}



//here my last win check started
/*
    assert(lines > 0);
    assert(size_of_arena > 0);
    int player1 = 1;
    int player2 = 2;
    int count = 0;
    int won = 0;
    int how_p_won;
    printf("%d 203", lines);
    //first we check the even win.
    //  printf("test comes in win funktion test\n");
    int counter_player1 = 0, counter_player2 = 0;
    for (int i = 0; i <= size_of_arena - 1; i++) {
        for (int b = 0; b <= size_of_arena - 1; b++) {
            // printf(" %d-%d ", i, b);

//This works
            if (arena[i][b] == 1) {
                counter_player1 = counter_player1 + 1;
                counter_player2 = 0; //printf("counter1=[%d] counter2=[%d]",counter_player1, counter_player2);
            }
            if (arena[i][b] == 2) {
                counter_player2 = counter_player2 + 1;
                counter_player1 = 0;
            }
            if (arena[i][b] == 0) {
                counter_player2 = 0;
                counter_player1 = 0;
            }
            if (counter_player1 == lines) {
                won = 1;
                how_p_won = 1;
                break;
            }
            if (counter_player2 == lines) {
                won = 2;
                how_p_won = 1;
                break;
            }
            count++;
            if (count == size_of_arena * size_of_arena) { break; }
        }
        assert(count < size_of_arena * size_of_arena + 1);

        if (count == size_of_arena * size_of_arena) { break; }
    }
    //printf("here we go out from even tjec to laterel");

    //next test will test the laterel collom.


    //this works
    count = 0;
    for (int i = 0; i <= size_of_arena - 1; i++) {
        for (int b = 0; b <= size_of_arena - 1; b++) {
            //here we start scaning.
            if (arena[i][b] == 1) {
                for (int k = i; k <= size_of_arena - 1; k++) {
                    if (arena[k][b] == 1) counter_player1 = counter_player1 + 1;
                }
                if (counter_player1 == lines) {
                    won = 1; //printf("gggggggggggggggggggggggggggggggggggggggggggggggggggggg");
                    how_p_won = 2;
                }
            }
            counter_player1 = 0;
            if (arena[i][b] == 2) {
                for (int k = i; k <= size_of_arena - 1; k++) {
                    if (arena[k][b] == 2) counter_player2 = counter_player2 + 1;
                }
                if (counter_player2 == lines) {
                    won = 2;
                    how_p_won = 2;
                }
            }
            counter_player2 = 0;
        }
        assert(count < size_of_arena * size_of_arena + 1);
        if (count == size_of_arena * size_of_arena) { break; }
    }
    //here we check the inclined wins. here we check left bottom right hight, incline win.

    // here the problem starts, i think it starts because, it tries to check outside of the main array. we must prevent this from happening.

    //here we start scanning
    //this do not work
    int count1 = 0, count2 = 0;

    //here we start the scanning
    for (int i = 0; i <= size_of_arena-1 ; i++) {
        for (int b = 0; b <= size_of_arena-1 ; b++) {
            //here we find the first number

            if (arena[i][b] == 1) {
                for (int l = i; l <= size_of_arena ; l++) {
                    printf("waaaaaaaaaaaa");
                    if (i + l <= size_of_arena  && b + l <= size_of_arena ) {
                        printf("bwaaaaaaferasee");
                        if (arena[i + l][b + l] == 1) {
                            count1 = count1 + 1;
                            printf("count1= [%d]", count1);
                            if (count1 == lines) {
                                won = 1;
                                printf("gggggggggggggggggggggggggggggggggggggggggggggggggggggg");
                                how_p_won = 3;
                            }
                        }
                    }
                }
            }


            if (arena[i][b] == 1 || arena[i][b] == 2) {
                //here we add the number given to counter, so we later can compare it to the numbers needed to win
                if (arena[i][b] == 1) { count1 = 1; }
                if (arena[i][b] == 2) { count2 = 1; }

                for (int k = 0; k <= lines - 1; k++) {
                    for (int j = 0; j <= lines - 1; j++) {
                        //this must not rice above a serten point.

                        if (i + j < size_of_arena - 1 && b + j < size_of_arena - 1) {
                            printf(" first one works %d %d\n", j, k);
                            // this will ad 1 to the counter if the statement is true
                            if (arena[i + j][b + j] == 1) {
                                count1 = count1 + 1;
                                // printf("%d count ++ at i[%d] j[%d]   b[%d] j[%d] \n", count1, i, j, b, j);
                                // here we test if player 1 has won.
                                if (count1 == lines) {
                                    //   printf("lines =%d count1%d", lines, count1);
                                    won = 1;
                                    how_p_won = 3;
                                }
                            }
                            //this will reset the counter if the next test is not the true.
                            if (arena[i + j][b + j] != 1) {
                                count1 = 0;
                                //    printf("%d count =0\n", count1);
                            }
                            if (arena[i + j][b + j] == 2) {
                                count2++;
                                // here test if player 2 has won.
                                if (count2 == lines) {
                                    won = 2;
                                    how_p_won = 3;
                                    printf("lines =%d count2%d", lines, count2);
                                }
                            }
                            //this will reset counter2 if the statment is true
                            if (arena[i + j][b + j] != 2) { count2 = 0; }
                        }
                        //this must not gove below a serten point
                        if (i - j >= 0 && b - j >= 0) {
                            //printf(" secound one works\n");
                            if (arena[i - j][b - j] == 1) {
                                count1++;
                                if (count1 == lines) {
                                    won = 1;
                                    how_p_won = 4;
                                }


                            }
                            if (arena[i - j][b - j] != 1) { count1 = 0; }
                            if (arena[i - j][b - j] == 2) {
                                count2++;
                                if (count2 == lines) {
                                    won = 2;
                                    how_p_won = 4;
                                }

                            }
                            if (arena[i - j][b - j] != 2) { count2 = 0; }
                        }

                        //here we will tjeck the incline wins from left hight to right low.
                        if (i + j < size_of_arena - 1 && b - j >= 0) {
                            //printf(" the third works\n");
                            if (arena[i + j][b - j] == 1) {
                                count1++;
                                if (count1 == lines) {
                                    won = 1;
                                    how_p_won = 5;
                                }

                            }
                            if (arena[i + j][b - j] != 1) { count1 = 0; }
                            if (arena[i + j][b - j] == 2) {
                                count2++;
                                if (count2 == lines) {
                                    won = 2;
                                    how_p_won = 5;
                                }

                            }
                            if (arena[i + j][b - j] != 2) { count2 = 0; }
                        }
                        if (i - j >= 0 && b + j < size_of_arena - 1) {
                            //printf(" the forth works\n");
                            if (arena[i - j][b + j] == 1) {
                                count1++;
                                if (count1 == lines) {
                                    won = 1;
                                    how_p_won = 6;
                                }

                            }
                            if (arena[i - j][b + j] != 1) { count1 = 0; }
                            if (arena[i - j][b + j] == 2) {
                                count2++;
                                if (count2 == lines) {
                                    won = 2;
                                    how_p_won = 6;
                                }


                            }
                            if (arena[i - j][b + j] != 2) { count2 = 0; }
                        }
                    }
                }
            }
        }
    }
    if (won == 1) { printf("player1 won the game with a %d strike, won by term %d", lines, how_p_won); }
    if (won == 2) { printf("player2 won the game with a %d strike, won by term %d", lines, how_p_won); }
    */
//}