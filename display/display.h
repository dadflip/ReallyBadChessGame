//
// Created by Nathan Liénard ,Davide Chinedum and Matthias Dumondelle on 5/5/22.
//

#ifndef CHESS_GAME_DISPLAY_H
#define CHESS_GAME_DISPLAY_H


///chessboard///
void display_chessboard_void(int, int**); // met le plateau à zéro
void display_chessboard_init(int, int**);  // remplit les deux premières rangées du plateau
void display_chessboard_update(int, int**); // met à jour le plateau après chaque tour
void display_chessboard_reload();           // recharge la dernière partie enregistrée

///pions///
char display_pions_label(int, int, int**); // Attribue une "étiquette" de type aux pions représentés par des nombres
char display_pions_color(int, int, int**); // Attribue une "étiquette" de couleur aux pions



///screen///
void display_little_newline();  // sauts de lignes du plus petit au plus grand
void display_medium_newline();
void display_large_newline();
void display_clear();       // "effacement" de l'écran










#endif //CHESS_GAME_DISPLAY_H