#include "manage.h"
#include <stdio.h>
#include "../display/display.h"
#include <time.h>
#include <ctype.h>



// menu:
int manage_main_menu() {
    int choice;
    printf("##################################### Chess Game ############################################### \n");
    printf("----------------------------------- Menu Principal --------------------------------------------- \n");


    printf("(1) Démarrer une partie \n");
    printf("(2) Reprendre une partie \n");
    printf("(autre caractère) Quitter \n");
    printf(">> ");
    scanf("%d",&choice);
    display_little_newline();

    if(choice<0 || choice>2){
        choice=0;
    }

    return choice;

}

// move:









// controle :

void manage_wait_seconds(int tps){
    int x;
    int wait = tps;

    // printf("Pause pendant %d secondes\n", wait);
    printf("> \t");

    for(x=1; x<=wait; x++)
    {
        printf(".");
        fflush(stdout);

        sleep((int)1);
    }

    printf(" \t OK !\n\n");
}

void sleep(int nbr_seconds)
{
    clock_t goal;

    goal = (nbr_seconds * CLOCKS_PER_SEC) + clock();

    while(goal > clock())
    {
        ;
    }
}


// save and load:

void manage_save_in_file(int dim, int **chessboard){
    FILE *savefile = fopen("savegame.txt","w");
    if(savefile != NULL){
        for(int i=0; i<dim; ++i){
            for (int j=0; j<dim; j++){
                if(chessboard[i][j]<10) {
                    fprintf(savefile, "0");
                    fprintf(savefile, "%d", chessboard[i][j]);
                } else {
                    fprintf(savefile,"%d",chessboard[i][j]);
                }
            }
            fprintf(savefile,"\n");
        }
    }
    fclose(savefile);
}

void manage_save_dimensions(int dim){
    FILE *savefiledim = fopen("savedim.txt","w");
    if(savefiledim != NULL){
        fprintf(savefiledim,"%d",dim);
    }
    fclose(savefiledim);
}

int manage_read_dimensions(){
    FILE *savefiledim = fopen("savedim.txt","r");
    int dim = 0;
    if(savefiledim != NULL){
        fscanf(savefiledim,"%d",&dim);
    }
    fclose(savefiledim);
    return dim;
}

void manage_save_turn(int turn){
    FILE *savefileturn = fopen("saveturn.txt","w");
    if(savefileturn != NULL){
        fprintf(savefileturn,"%d",turn);
    }
    fclose(savefileturn);
}   // Permet de sauvegarder le joueur ayant joué en dernier lors de la partie précédente

int manage_read_turn(){

    FILE *savefileturn = fopen("saveturn.txt","r");
    int dim = 0;
    if(savefileturn != NULL){
        fscanf(savefileturn,"%d",&dim);
    }
    fclose(savefileturn);
    return dim;

}       // Permet d'obtenir le joueur ayant joué en dernier lors de la partie précédente

void manage_reload_last_file(int dim, int **chessboard) {
    char numbers[3];
    int move_cursor_l = 0,move_cursor_c;

    FILE *savefile = fopen("savegame.txt", "r");
    if (savefile != NULL) {
        move_cursor_c= fseek(savefile,0,SEEK_CUR);

        do {
            fgets(numbers, 3, savefile);    // On stocke 2 caractères dans la chaine numbers

            if (numbers[0] == '\n') {
                // printf("hello");
                //reperage_cursor_c = 0;
                move_cursor_l++;
                move_cursor_c=0;
            } else {
                chessboard[move_cursor_l][move_cursor_c/2] = (int) (numbers[0] - 48)*10 + (int) (numbers[1] -
                                                                                                 48);       // conversion ASCII (48 -> 0, 49 -> 1 ...)
                //printf("%d/", chessboard[move_cursor_l][move_cursor_c/2]);
                move_cursor_c=move_cursor_c+2;  // Gère le déplacement horizontal (avec pas de 2 (car 2 chiffres représentent 1 pion)) du curseur jusqu'à la taille de l'échiquier!
            }

        }while (move_cursor_l<dim);     // Gère le déplacement vertical (de ligne en ligne) du curseur jusqu'à la taille de l'échiquier!
    }
    fclose(savefile);
    printf("\n \n");


}       // permet de recharger la sauvegarde précédente...

int manage_drop_game(int k){

    printf("Partie abandonnée \n");
    if (k/100 ==-1){
        printf("Les blancs ont gagné");
    }else{
        printf("Les noirs ont gagné");
    }
    return 1;
}       // Gère l'abandon des joueurs...