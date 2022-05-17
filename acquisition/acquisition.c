
/////////////////////////////////////////////////LIBRARIES//////////////////////////////////////////////////////
#include <stdio.h>
#include "../manage/manage.h"
#include "acquisition.h"
#include "../display/display.h"
#include "../verify/verify.h"
#include <ctype.h>
#include <string.h>



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int acquisition_dimensions(){
    int dim;
    printf("Entrez les dimensions (comprises entre 6 et 12) :\t");
    scanf("%d", &dim);
    while (dim < 6 || dim >12){
        printf(" \t \t \t xxxxxxxxxxxxxxxxxx \n");
        printf("saisie invalide ! \n");
        printf("Entrez les dimensions (comprises entre 6 et 12) :\t");
        scanf("%d", &dim);
    }
    display_little_newline();
    return dim;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int acquisition_pion_black_to_move(int dim, int **chessboard){
    char case_pion[3], case_dest[3];
    int y_p, x_p;
    int y_d, x_d;
    int val_case_dest;
    int verif;



//SAISIE DE LA CASE DE DEPART//////////////////////////////////////////////////////////

    do {

        do {
            display_clear();
            display_chessboard_update(dim, chessboard);     // Permet d'afficher le plateau à chaque tour de boucle
            display_little_newline();
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>> Tour des Noirs <<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n");
            /*---------------------------------------------------------------------------------------------------------------------------------*/
            do {
                printf(">>> Quel pion voulez vous déplacer? \n format -> LettreNombre(1 ou 2 chiffres): ");
                scanf("%s", case_pion);
            } while (strlen(case_pion) > 3 || isalpha(case_pion[0]) == 0 ||
                     (strlen(case_pion) == 2 && isdigit(case_pion[1]) == 0) ||
                     (strlen(case_pion) == 3 && isdigit(case_pion[1]) == 0 &&
                      isdigit(case_pion[2] == 0)));
            // Boucle si on entre plus de 3 caractères ou que le premier caractère n'est pas une lettre ou que les deux derniers ne sont pas des chiffres
            /*---------------------------------------------------------------------------------------------------------------------------------*/
            for (int i = 0; i < strlen(case_pion); ++i) {
                case_pion[i] = toupper(case_pion[i]);
                printf("%c", case_pion[i]);
            }
            // Met en majuscules les caractères entrés par l'utilisateur
            /*---------------------------------------------------------------------------------------------------------------------------------*/
            display_little_newline();

            y_p = ((int) case_pion[0]) - 65;
            printf(">>> ligne y= %d | ", y_p);

            // stocke la valeur décimale de la lettre entrée - 65 (car 65 est le code ASCII de A majuscule) pour avoir les lignes de 0 à dim


            if (y_p != 23 && y_p != 18) {   // Si on ne saisit pas 'X' pour abandonner...

                if (strlen(case_pion) ==
                    2) {   // Si la longueur de la chaine est 2, c'est que l'utilisateur a entré un nombre à un chiffre après la lettre

                    x_p = ((int) case_pion[1] - 48) - 1;        // -1, car le tableau commence à l'indice 0

                } else {                            // Si la longueur de la chaine est 3, c'est que l'utilisateur a entré un nombre à 2 chiffres après la lettre

                    x_p = ((int) ((case_pion[1]) - 48) * 10 + (int) case_pion[2] - 48) - 1;

                }
                printf("colonne x= %d <<< \n", x_p);

                // stocke la valeur décimale du nombre entré - 48 (car 48 est le code ASCII du caractère 1) pour avoir les colonnes de 0 à dim

                /*---------------------------------------------------------------------------------------------------------------------------------*/

                if (y_p > dim || y_p < 0 || x_p > dim-1 || x_p < 0) {
                    printf("La case entrée n'existe pas!");     // message d'erreur sur la saisie de la case
                    manage_wait_seconds(3);
                }
            } else if (y_p== 23) {    // caractère 'X' saisi
                return (0+1)*(-100);    // on retourne un nombre négatif soit : -100 si les noirs abandonnent

            } else{     // caractère 'S' saisi
                return (0+1)*(-1000);   // on retourne un nombre négatif soit: -1000 si les noirs abandonnent
            }

        } while (y_p > dim || y_p < 0 || x_p > dim-1 || x_p < 0);
        //Si la case saisie est hors plateau, on boucle !

        /*---------------------------------------------------------------------------------------------------------------------------------*/

        if (verify_colorofpion_tomove(y_p, x_p, chessboard) == 0) { // si le pion à déplacer est noir
            printf(" OK ! \n");
        } else if (verify_colorofpion_tomove(y_p, x_p, chessboard) == 1) {  // s'il est blanc...
            printf("ERREUR PION ! \n");
            manage_wait_seconds(1);
        } else {                                                        // sinon la case est vide
            printf("CASE VIDE ! \n");
            manage_wait_seconds(1);
        }

        verif = verify_colorofpion_tomove(y_p, x_p, chessboard);

    } while (verif !=0);
    // on boucle tant que la couleur du pion à déplacer n'est pas noir !

    /*---------------------------------------------------------------------------------------------------------------------------------*/


    //SAISIE DE LA CASE DE DESTINATION/////////////////////////////////////////////////////

    do{
        do{

            do {
                printf(">>> Case de destination?,\n format -> LettreNombre(1 ou 2 chiffres): ");
                scanf("%s", case_dest);
            }while(strlen(case_dest)>3 || isalpha(case_dest[0])==0 || (strlen(case_dest)==2 && isdigit(case_dest[1])==0) || (strlen(case_dest)== 3 && isdigit(case_dest[1])==0 &&
                                                                                                                             isdigit(case_dest[2]==0)));
            //Boucle si on saisit plus de trois caractères ou que le premier élément n'est pas une lettre ou que les 2 dernier ne sont pas des chiffres

            /*---------------------------------------------------------------------------------------------------------------------------------*/

            for (int i = 0; i < strlen(case_dest); ++i) {
                case_dest[i] = toupper(case_dest[i]);
                printf("%c", case_dest[i]);
            }
            // on met tous les caractères entrés en majuscules

            /*---------------------------------------------------------------------------------------------------------------------------------*/
            display_little_newline();

            y_d = ((int) case_dest[0]) - 65;

            if(y_d != 23 && y_d != 18) {    // si on ne saisit pas 'X' ou 'S'

                if (strlen(case_dest) == 2) {
                    x_d = ((int) case_dest[1] - 48) - 1;        // -1, car le tableau commence à l'indice 0
                } else {
                    x_d = ((int) ((case_dest[1]) - 48) * 10 + (int) case_dest[2] - 48) - 1;

                }

            }else if (y_d == 23){   // Caractère 'X' saisi
                return (0+1)*(-100);

            }else{   // Caractère 'S' saisi
                return (0+1)*(-1000);
            }

            if(y_d>dim || y_d<0 || x_d >dim-1 || x_d<0){
                printf("La case entrée n'existe pas! \n");     // message d'erreur sur la saisie de la case
                manage_wait_seconds(3);
            }

        } while(y_d>dim || y_d<0 || x_d >dim-1 || x_d<0);
        //Si la case saisie est hors plateau, on boucle !

        verif=verify_dest_case_isvoid(y_d,x_d,chessboard);

    }while( verif == 0);
    // on boucle tant que la case de destination contient un pion noir

    val_case_dest= y_d*100+x_d;     // ligne*100+colonne

    return val_case_dest;       // on retourne ligne*100+colonne

}






int acquisition_pion_white_to_move(int dim, int **chessboard){
    char case_pion[3], case_dest[3];
    int y_p, x_p;
    int y_d, x_d;
    int val_case_dest;
    int verif;



//SAISIE DE LA CASE DE DEPART//////////////////////////////////////////////////////////

    do {

        do {
            display_clear();
            display_chessboard_update(dim, chessboard);
            display_little_newline();
            printf(":::::::::::::::::::::::::::: Tour des Blancs ::::::::::::::::::::::::::::::::::::: \n");
            /*---------------------------------------------------------------------------------------------------------------------------------*/
            do {
                printf("::: Quel pion voulez vous déplacer? \n format -> LettreNombre(1 ou 2 chiffres): ");
                scanf("%s", case_pion);
            } while (strlen(case_pion) > 3 || isalpha(case_pion[0]) == 0 ||
                     (strlen(case_pion) == 2 && isdigit(case_pion[1]) == 0) ||
                     (strlen(case_pion) == 3 && isdigit(case_pion[1]) == 0 &&
                      isdigit(case_pion[2] == 0)));
            // Boucle si on entre plus de 3 caractères ou que le premier caractère n'est pas une lettre ou que les deux derniers ne sont pas des chiffres
            /*---------------------------------------------------------------------------------------------------------------------------------*/
            for (int i = 0; i < strlen(case_pion); ++i) {
                case_pion[i] = toupper(case_pion[i]);
                printf("%c", case_pion[i]);
            }
            // Met en majuscules les caractères entrés par l'utilisateur
            /*---------------------------------------------------------------------------------------------------------------------------------*/
            display_little_newline();

            y_p = ((int) case_pion[0]) - 65;
            printf("::: ligne y= %d | ", y_p);

            // stocke la valeur décimale de la lettre entrée - 65 (car 65 est le code ASCII de A majuscule) pour avoir les lignes de 0 à dim


            if (y_p != 23 && y_p !=18) {   // Si on ne saisit pas 'X' pour abandonner... ou S pour sauvegarder et quitter

                if (strlen(case_pion) ==
                    2) {   // Si la longueur de la chaine est 2, c'est que l'utilisateur a entré un nombre à un chiffre après la lettre

                    x_p = ((int) case_pion[1] - 48) - 1;        // -1, car le tableau commence à l'indice 0

                } else {                            // Si la longueur de la chaine est 3, c'est que l'utilisateur a entré un nombre à 2 chiffres après la lettre

                    x_p = ((int) ((case_pion[1]) - 48) * 10 + (int) case_pion[2] - 48) - 1;

                }
                printf("colonne x= %d ::: \n", x_p);

                // stocke la valeur décimale du nombre entré - 48 (car 48 est le code ASCII du caractère 1) pour avoir les colonnes de 0 à dim

                /*---------------------------------------------------------------------------------------------------------------------------------*/

                if (y_p > dim || y_p < 0 || x_p > dim-1 || x_p < 0) {
                    printf("La case entrée n'existe pas!");     // message d'erreur sur la saisie de la case
                    manage_wait_seconds(3);
                }

            } else if(y_p == 23) {
                return (1+1) * (-100);

            }else{
                return (1+1)*(-1000);
            }

        } while (y_p > dim || y_p < 0 || x_p > dim-1 || x_p < 0);
        //Si la case saisie est hors plateau, on boucle !

        /*---------------------------------------------------------------------------------------------------------------------------------*/

        if (verify_colorofpion_tomove(y_p, x_p, chessboard) == 1) { // si le pion à déplacer est blanc
            printf(" OK ! \n");
        } else if (verify_colorofpion_tomove(y_p, x_p, chessboard) == 0) {  // s'il est noir...
            printf("ERREUR PION ! \n");
            manage_wait_seconds(1);
        } else {                                                                // sinon la case est vide
            printf("CASE VIDE ! \n");
            manage_wait_seconds(1);
        }

        verif = verify_colorofpion_tomove(y_p, x_p, chessboard);

    } while (verif !=1);
    // on boucle tant que la couleur du pion à déplacer n'est pas blanc !

    /*---------------------------------------------------------------------------------------------------------------------------------*/


    //SAISIE DE LA CASE DE DESTINATION/////////////////////////////////////////////////////

    do{
        do{

            do {
                printf("::: Case de destination?,\n format -> LettreNombre(1 ou 2 chiffres): ");
                scanf("%s", case_dest);
            }while(strlen(case_dest)>3 || isalpha(case_dest[0])==0 || (strlen(case_dest)==2 && isdigit(case_dest[1])==0) || (strlen(case_dest)== 3 && isdigit(case_dest[1])==0 &&
                                                                                                                             isdigit(case_dest[2]==0)));
            //Boucle si on saisit plus de trois caractères ou que le premier élément n'est pas une lettre ou que les 2 dernier ne sont pas des chiffres

            /*---------------------------------------------------------------------------------------------------------------------------------*/

            for (int i = 0; i < strlen(case_dest); ++i) {
                case_dest[i] = toupper(case_dest[i]);
                printf("%c", case_dest[i]);
            }
            // on met tous les caractères entrés en majuscules

            /*---------------------------------------------------------------------------------------------------------------------------------*/
            display_little_newline();

            y_d = ((int) case_dest[0]) - 65;

            if(y_d != 23 && y_d != 18) {

                if (strlen(case_dest) == 2) {
                    x_d = ((int) case_dest[1] - 48) - 1;        // -1, car le tableau commence à l'indice 0
                } else {
                    x_d = ((int) ((case_dest[1]) - 48) * 10 + (int) case_dest[2] - 48) - 1;

                }

            }else if(y_d == 23){
                return (1+1)*(-100);

            } else{
                return (1+1)*(-1000);
            }

            if(y_d>dim || y_d<0 || x_d >dim-1 || x_d<0){
                printf("La case entrée n'existe pas! \n");     // message d'erreur sur la saisie de la case
                manage_wait_seconds(3);
            }

        } while(y_d>dim || y_d<0 || x_d >dim-1 || x_d<0);
        //Si la case saisie est hors plateau, on boucle !


    }while(verify_dest_case_isvoid(y_d,x_d,chessboard) == 1);
    // on boucle tant que la case de destination contient un pion blanc

    val_case_dest= y_d*100+x_d;

    return val_case_dest;

}