//
// Created by Nathan Liénard ,Davide Chinedum and Matthias Dumondelle 5/5/22.
//

#ifndef CHESS_GAME_ACQUISITION_H
#define CHESS_GAME_ACQUISITION_H

int acquisition_dimensions();     // permet d'acquérir les dimensions du plateau entrées par l'utilisateur
int acquisition_pion_black_to_move(int, int**);
int acquisition_pion_white_to_move(int, int**);
#endif //CHESS_GAME_ACQUISITION_H