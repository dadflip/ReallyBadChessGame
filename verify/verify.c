//
// Created by dave on 5/13/22.
//

#include "verify.h"

int verify_colorofpion_tomove(int y,int x,int **chessboard ){

    int a;

    if (chessboard[y][x] != 0 && chessboard[y][x] / 10 == 0) {   // la case d'origine contient pion noir

        a = 0;                // on retourne 0 pour indiquer que la case contient pion couleur noir

    } else if (chessboard[y][x] != 0 && chessboard[y][x] / 10 == 1){ // la case d'origine contient un pion blanc

        a = 1;               // on retourne 1 pour indiquer que la case  contient pion couleur blanc

    } else {

        a = 2;                                 // on retourne 2 pour indiquer que la case d'origine est vide

    }

    return a;
}   //On vérifie si le pion à déplacer nous appartient...

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int verify_dest_case_isvoid(int y,int x,int **chessboard){
    int adv_n_b;

    /*si le déplacement est autorisé... (ici on mettra les fonctions gérant le déplacement des pions)*/

    if (chessboard[y][x] != 0 && chessboard[y][x] / 10 == 0) {   // la case de destination contient pion noir

        adv_n_b = 0;                // on retourne 0 pour indiquer que la case destination contient pion couleur noir

    } else if (chessboard[y][x] != 0 && chessboard[y][x] / 10 == 1){ // la case contient un pion blanc

        adv_n_b = 1;               // on retourne 1 pour indiquer que la case destination contient pion couleur blanc

    } else {

        adv_n_b = 2;                                 // on retourne 2 pour indiquer que la case destination est vide

    }

    /*sinon on retournera adv_n_b=3*/

    return adv_n_b;
}       // On vérifie le contenu de la case de destination et si oui ou non on peut y déplacer notre pion

