#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <windows.h>
#include "fonctionsjeu.h"
#include "aidejeu.h"

#pragma execution_character_set ("utf-8")

/*
 * Auteur : Valentin Zingg
 * Titre : Bataille Navale
 * Description : Un jeu ou il faut trouver et couler des bateaux sur une grille.
 * Date de création : 21 février 2019
 * Dernière mise à jour : 20 mars 2019
 */

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//TODO : UTILISER DES CONSTANTES POUR LES BATEAUX ET AUTRES !
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main() {
    SetConsoleOutputCP(65001);
    //---VARIABLES---
    char NomJoueur[255] ="NULL"; //Nom du joueur
    char ChoixLettreHORIZONTAL;
    int ChoixMenu = 0;
    int ChoixTirVERTICAL;
    int ChoixTirHORIZONTAL;
    int NbTirs = 0; // nombre de tirs effectués par le joueur
    int NbBateaux = 3; // Nombre de bateau à la surface
    int HpBateau1 = 1; // Points de vie du bateau 1
    int HpBateau2 = 2; // Points de vie du bateau 2
    int HpBateau3 = 3; // Points de vie du bateau 3
    int i = 0;//utilisé pour les boucles for
    int j = 0;//utilisé pour les boucles for
    bool jeu_en_cours = true;

    int TableauNaval[10][10]={ //cette carte est invisible au joueur
           0,0,0,0,1,0,0,0,0,0,   // 0 = Rien
           0,2,2,0,0,0,0,0,0,0,   // 1 = Bateau 1
           0,0,0,0,0,0,0,0,0,0,   // 2 = Bateau 2
           0,3,3,3,0,0,0,0,0,0,   // 3 = Bateau 3
           0,0,0,0,0,0,0,0,0,0,   // 4 = Deja tiré ici
           0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0,
    };
    char TableauAffiche[10][10]={ //La carte qui va s'afficher au joueur
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",    // ~ = Vague d'eau
            "~~~~~~~~~~",    // X = Endroit attaqué , bateau touché
            "~~~~~~~~~~",    // @ = Endroit attaqué , rien touché
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
            "~~~~~~~~~~",
    };
    //---VARIABLES---


    //Input du nom du joueur
    printf("Entrez votre nom :");
    scanf("%s",NomJoueur);
    printf("\nBonjour , %s !\n",NomJoueur);
    system("pause");
    system("cls");

    //Affichage du menu principal
    printf("----------BATAILLE NAVALE----------\n\n");
    printf("1.Jouer\n");
    printf("2.Jouer avec une carte personalisee\n");
    printf("3.Aide\n");
    printf("4.Quitter\n");
    scanf("%d",&ChoixMenu);

    switch(ChoixMenu)
    {
        default:
            //rien ici
            break;

        case 1: //JOUER AVEC LA CARTE DE BASE
            system("cls");
            //Sort du switch et commence le jeu plus bas
            break;

        case 2: //JOUER AVEC UNE CARTE STOCKEE DANS UN FICHIER
            system("cls");
            int chiffre = 0; // variable utilisée pour assigner les cases de la grille
            FILE * fichier; //variable du fichier
            fichier = fopen("CartesCustom/CarteCustom1.BATAILLENAVALE", "r"); //ouvre le fichier de la grille
            if(fichier == NULL)printf("Erreur ! Fichier introuvable.\n"); // Erreur si le fichier n'est pas trouvé

            for(j = 0;j < 10;j++) //boucle pour lire les valeurs du fichier grille et les assigner au tableau du jeu
            {
                for(i = 0; i < 10; i++)
                {
                    fscanf(fichier,"%d",&chiffre); //Scanne et stock la valeur de la ligne actuelle en int
                    TableauNaval[j][i] = chiffre; //Assigne la valeur stockée à la case de la grille actuelle
                }
            }
            break;

        case 3:
            // AIDE
            menuaide(); // Affiche l'aide avec une fonction
            break;

        case 4://QUITTER
            return 99; //Termine le programme

    }


    //!------------------------------BOUCLE DU JEU---------------------------------------
    while(jeu_en_cours == true)
    {
        afficherCarte(TableauAffiche,NbTirs,NbBateaux,NomJoueur); // Affiche la carte a chaque début de boucle
        printf("\n");
        printf("Veuillez choisir ou tirer...\n");
        printf("Entrez la lettre HORIZONTALE\n");
        scanf(" %c", &ChoixLettreHORIZONTAL); //demande l'axe horizontal
        ChoixTirHORIZONTAL = TraducteurGrille(ChoixLettreHORIZONTAL);
        system("cls");

        afficherCarte(TableauAffiche,NbTirs,NbBateaux,NomJoueur);
        printf("Veuillez choisir ou tirer...\n");
        printf("Entrez la case VERTICALE\n"); //demande l'axe vertical
        scanf("%d",&ChoixTirVERTICAL);
        ChoixTirVERTICAL--; //Soustrait la valeur de 1 car la grille commence la graduation à 1 alors que le tableau à 0

        //TODO : REMPLACER LES "IF ELSE" PAR UN TRUC PLUS PRATIQUE !

        if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 1) // Si le joueur touche une case du bateau 1
        {
            printf("\n\nTouché !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X"; //change la case touchée par le joueur. @ pour rien touché , X pour bateau touché
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            HpBateau1--;
            if(HpBateau1 == 0)
            {
                printf("Le bateau numero 1 a coulé !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 0) //Si le joueur tire sur une case vide
        {
            printf("\n\nRaté !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"@";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 2) //Si le joueur tire sur une case du bateau 2
        {
            printf("\n\nTouché !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            HpBateau2--;
            if(HpBateau2 == 0)
            {
                printf("Le bateau numero 2 a coulé !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 3) //Si le joueur tire sur une case du bateau 2
        {
            printf("\n\nTouché !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            HpBateau3--;
            if(HpBateau3 == 0)
            {
                printf("Le bateau numero 3 a coulé !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 4) //Si le joueur a deja tiré sur cette case
        {
            printf("Vous avez deja tiré ici !\n");
            system("pause");
            system("cls");
        }



        if(NbBateaux == 0)//Si il n'y a plus aucun bateau , le jeu se termine.
        {
            jeu_en_cours = false;
            system("cls");
        }
    }

    printf("Félicitations ! Vous avez gagné en %d tirs !\n\n",NbTirs); //Message de fin du jeu
    system("pause");
    return 0;
}