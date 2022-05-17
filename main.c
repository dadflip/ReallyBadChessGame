///////////////////////////////////////////////bibliothèques/////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "display/display.h"
#include "acquisition/acquisition.h"
#include "manage/manage.h"

///////////////////////////////////////////////programme principal//////////////////////////////////////////////

int main() {
    int play;   // Variable permettant d'afficher le menu à chaque fois qu'elle vaut 1 en lien avec la boucle do...while principale
    int **chessboard;
    int choice;
    int dim;
    int turn;

    do{
        play=0;
        /////////////////menu principal/////////////////////////////////////////////////////////////////////////////////////////////

        choice = manage_main_menu();    // permet le choix du sous menu voulu!

        /////////////////////////////////////////////SOUS MENU NOUVELLE PARTIE//////////////////////////////////////////////////////
switch(choice)
{

    case 1:
            ////Variables locales////////////////////////////////////////////////////////////////////////////////////////////
            //int i;
            dim = acquisition_dimensions();

            ////Corps du programme/////////////////////////////////////////////////////////////////////////////////////////

            // Création de la matrice dynamique chessboard (= plateau de l'échiquier), allocation dynamique:

            {
                // lignes:
                chessboard = (int **) malloc(dim * sizeof(int *));

                // colonnes
                for (int i = 0; i < dim; ++i) {
                    chessboard[i] = (int *) malloc(dim * sizeof(int));
                }

            }
            display_little_newline();

            // initialisation de la matrice vide:

            display_chessboard_void(dim, chessboard);
            display_little_newline();

            // initialisation du plateau avec placement des pièces sur les 2 premières rangées:

            display_chessboard_init(dim, chessboard);
            manage_save_in_file(dim, chessboard);
            manage_save_dimensions(dim);
            display_little_newline();

            display_chessboard_update(dim, chessboard);

            turn=1;         // Les blancs commencent la partie
            for(int k=0;k<4;++k){
                display_little_newline();
                while (play==0) {
                    if (turn == 1) {
                        int b = acquisition_pion_white_to_move(dim, chessboard);
                        if(b<0) {
                            if(b <= -1000){
                                play=1;
                                printf("Sauvegarde en cours...");
                                manage_wait_seconds(2);
                                manage_save_in_file(dim,chessboard);
                                manage_save_turn(turn);
                            }else {
                                play = manage_drop_game(b);
                            }
                        } else {
                            int line = b / 100;
                            int column = b % 100;
                            printf("déplacement line (%d) column (%d) \n", line, column);
                            turn = 0;
                        }
                    } else {
                        int n = acquisition_pion_black_to_move(dim, chessboard);
                        if(n<0) {
                            if(n <= -1000){
                                play=1;
                                printf("Sauvegarde en cours...");
                                manage_wait_seconds(2);
                                manage_save_in_file(dim,chessboard);
                                manage_save_turn(turn);
                            }else {
                                play = manage_drop_game(n);
                            }
                        } else {
                            int line = n / 100;
                            int column = n % 100;
                            printf("déplacement line (%d) column (%d) \n", line, column);
                            turn = 1;
                        }
                    }
                }
            }

            for (int i = 0; i < dim; ++i) {
                free(chessboard[i]);
            }
            free(chessboard);

            printf("mémoire libérée ! \n");
break;

            ////////////////////////////////////////////////////////SOUS MENU QUITTER /////////////////////////////////////////////////////////





    case 0:
            printf("partie quittée ! \n");
            play=0;
break;



            /////////////////////////////////////////////////////////SOUS MENU PARTIE ENREGISTREE/////////////////////////////////////////////






    case 2:

            manage_wait_seconds(2);     // variable introduisant une pause de 2 secondes...
            printf("chargement de la sauvegarde - terminé!\n");
            manage_wait_seconds(2);
            dim = manage_read_dimensions();


            // lignes:
            chessboard = (int **) malloc(dim * sizeof(int *));

            // colonnes
            for (int i = 0; i < dim; ++i) {
                chessboard[i] = (int *) malloc(dim * sizeof(int));
            }
            manage_reload_last_file(dim, chessboard);

            display_little_newline();


            //////////////////// JEU TOUR A TOUR//////////////////////////////////////

            turn = manage_read_turn();

            for (int k = 0; k < 4; ++k) {
                display_little_newline();
                while (play == 0) {
                    if (turn == 1) {
                        int b = acquisition_pion_white_to_move(dim, chessboard);
                        if (b < 0) {
                            if (b <= -1000) {
                                play = 1;
                                printf("Sauvegarde en cours...");
                                manage_wait_seconds(2);
                                manage_save_in_file(dim, chessboard);
                                manage_save_turn(turn);
                            } else {
                                play = manage_drop_game(b);
                            }
                        } else {
                            int line = b / 100;
                            int column = b % 100;
                            printf("déplacement line (%d) column (%d) \n", line, column);
                            turn = 0;
                        }
                    } else {
                        int n = acquisition_pion_black_to_move(dim, chessboard);
                        if (n < 0) {
                            if (n <= -1000) {
                                play = 1;
                                printf("Sauvegarde en cours...");
                                manage_wait_seconds(2);
                                manage_save_in_file(dim, chessboard);
                                manage_save_turn(turn);
                            } else {
                                play = manage_drop_game(n);
                            }
                        } else {
                            int line = n / 100;
                            int column = n % 100;
                            printf("déplacement line (%d) column (%d) \n", line, column);
                            turn = 1;
                        }
                    }
                }
            }


            /////////////////////FIN JEU TOUR A TOUR////////////////////////////////////




            for (int i = 0; i < dim; ++i) {
                free(chessboard[i]);
            }
            free(chessboard);

            printf("mémoire libérée ! \n");
            display_clear();
            break;

    default:
        printf("Error");
        }

    }while(play==1);

}