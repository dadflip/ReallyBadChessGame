//
// Created by dave on 5/14/22.
//

#include "move.h"


int deplacement_fou(int val_case_dest, int x_p, int y_p, int **chessboard) {

    int x_d = val_case_dest % 10;
    int y_d = val_case_dest / 10;

    if (x_d - x_p == y_d - y_p) {

        do {

            if (x_p < x_d) {
                if (y_p < y_d) {

                    if (chessboard[x_p + 1][y_p - 1] == 0) {
                        x_p = x_p + 1;
                        y_p = y_p - 1;
                    } else {
                        return 9;
                    }


                }


            } else {
                return 9;
            }

        }while (x_p!=x_d && y_p!=y_d);






}