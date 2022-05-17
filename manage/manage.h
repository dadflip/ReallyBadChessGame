//
// Created by Nathan Liénard ,Davide Chinedum and Matthias Dumondelle 5/5/22.
//


#ifndef CHESS_GAME_MANAGE_H
#define CHESS_GAME_MANAGE_H

void sleep(int nbr_seconds);    // fonction gérant l'horloge... et la mise en pause du système


void manage_wait_seconds(int);  // Permet de faire une pause de n secondes
int manage_main_menu();  // permet la gestion du menu principal
void manage_save_in_file(int, int**);   // gestion de la sauvegarde de la partie actuelle dans un fichier texte
void manage_reload_last_file(int, int**);   // Permet de charger la dernière sauvegarde
int manage_read_dimensions();   // permet de lire les dimension du dernier plateau enregistré
void manage_save_dimensions(int);   // permet de sauvegarder les dimensions du plateau précédent dans un fichier texte
void manage_save_turn(int);         // Enregistre la dernière personne ayant sauvegardé...
int manage_read_turn();         // ...pour la faire jouer en premier au prochain lancement du jeu !
int manage_drop_game(int);      // Gère l'abandon du jeu par chaque joueur


#endif //CHESS_GAME_MANAGE_H