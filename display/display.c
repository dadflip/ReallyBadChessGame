/////////////////////////////////////////////////LIBRARIES////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"

////////////////////////////////////////////////////FONCTIONS////////////////////////////////////////////////////
void display_chessboard_void(int dim, int **chessboard){
    int i,j;

    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++) {
            chessboard[i][j]=0;     // On initialise le plateau à zéro!
        }
    }
/*
    for (i = 0; i < dim; ++i) {
        for (j = 0; j < dim; ++j) {
            printf("|%d",chessboard[i][j]);
        }
        printf("| \n");
    }

    for (i = 0; i < dim; ++i) {
        free(chessboard[i]);
    }
    free(chessboard);

    printf("mémoire libérée !");
*/

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display_chessboard_init(int dim, int **chessboard){
    srand(time(NULL));

// Blacks:

    for(int l=0; l<2; ++l) {
        for (int c = 0; c < dim; ++c) {
            chessboard[l][c] = (rand()%5)+1;      // Nb aléatoire entre 1 et 6 exclus !
        }
    }
    // seulement les 2 premières rangées sont remplies !

    chessboard[0][rand()%dim]=6;            // Génération du roi

// Whites:

    for(int l=dim-1; l>dim-3; --l) {
        for (int c=0; c < dim; ++c) {
            chessboard[l][c] = (rand()%5)+11;      // Nb aléatoire entre 11 et 17 exclus !
        }
    }
    // seulement les 2 dernières rangées sont remplies !

    chessboard[dim-1][rand()%dim]=16;               // Génération du roi

// Affichage de la matrice
/*
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++) {
                printf("|%d", chessboard[i][j]);
        }
        printf("| \n");
    }


    for (int i = 0; i < lines; ++i) {
        free(chessboard[i]);
    }
    free(chessboard);

    printf("mémoire libérée !");

*/
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display_chessboard_update(int dim, int **chessboard){

    for (int i = 0; i < dim; ++i) {
        printf("(%c) ",'a'+i);
        for (int j = 0; j < dim; ++j) {
            printf("|%c%c", display_pions_label(i, j,chessboard), display_pions_color(i, j,chessboard));
        }
        printf("| \n");
    }
    printf("    ");      // espace nécéssaire pour la mise en forme de l'échiquier

    for (int j =0; j< dim;++j){
        printf("(%d)",j+1);
    }
    display_little_newline();
/*
    for (int i = 0; i < dim; ++i) {
        free(chessboard[i]);
    }
    free(chessboard);

    printf("mémoire libérée !");
    */
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char display_pions_label(int i, int j, int **chessboard){

    char Pieces[7]={' ','P','F','T','C','D','R'};
    return Pieces[chessboard[i][j]%10]; // retourne le caractère (donc le type de pion) correspondant à l'indice dans le tableau

}

char display_pions_color(int i, int j, int **chessboard){

    char Color[2]={'N','B'};

    if (chessboard[i][j] !=0){
        return Color[chessboard[i][j]/10]; // retourne N pour noir et B pour blanc
    } else {
        return ' ';                         // sinon retourne vide
    }





}


























/*_____________________________________________________________________________________________________________*/
void display_little_newline(){
    printf("\n \n");
}
void display_medium_newline(){
    printf("\n \n \n \n");
}
void display_large_newline(){
    printf("\n \n \n \n \n \n \n \n \n \n \n");
}
void display_clear(){
    printf("\n \n \n \n \n \n \n \n \n \n \n");
    printf("\n \n \n \n \n \n \n \n \n \n \n");
    printf("\n \n \n \n \n \n \n \n \n \n \n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////