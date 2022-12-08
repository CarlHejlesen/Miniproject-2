//
// Created by Bare mig Altså Carl on 07-12-2022.
//

#include "scan_setting.h"
#include <stdio.h>
#include <stdbool.h>

void scan_setting(int *computer_on, int *size, int *lines) {
    int siz, lin;
    //1)
    char a;
    //int computer_on;
    while (true) {
        printf("do you want to play against a computer? [y] or [n]");
        scanf("%c", &a);
        if (a == 'y' || a == 'n') break;
    }

    if (a == 'y') { *computer_on = 1; }
    if (a == 'n') { *computer_on = 0; }

    //2)
    printf("how big should the table be?");
    scanf("%d", &siz);

    //3)
    printf("how many lines for win?");
    scanf("%d", &lin);
    *size = siz;
    *lines = lin;
}