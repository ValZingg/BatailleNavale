#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <windows.h>
#include "fonctionsjeu.h" //Contient la fonction pour afficher la carte et la fonction pour Convertir les inputs CHAR de l'utilisateur en INT
#include "aidejeu.h" //Contient la fonction pour afficher l'aide du jeu

#pragma execution_character_set ("utf-8")

/*
 * Auteur : Valentin Zingg
 * Titre : Bataille Navale
 * Description : Un jeu ou il faut trouver et couler des bateaux sur une grille.
 * Date de création : 21 février 2019
 * Dernière mise à jour : 28 mars 2019
 */

#define MAX_HEALTH_SHIP_NUMBER_1 1; //vie maximum du bateau 1
#define MAX_HEALTH_SHIP_NUMBER_2 2; //vie maximum du bateau 2
#define MAX_HEALTH_SHIP_NUMBER_3 3; //vie maximum du bateau 3
#define MAX_HEALTH_SHIP_NUMBER_4 4; //vie maximum du bateau 4

#define STLC 218 // ┌
#define STRC 191 // ┐
#define SBLC 192 // └
#define SBRC 217 // ┘
#define SVSB 179 // │
#define SVRB 180 // ┤
#define SVLB 195 // ├
#define SHSB 196 // ─
#define SHBB 193 // ┴
#define SHTB 194 // ┬
#define SC   197 // ┼

int main() {
    SetConsoleOutputCP(65001);
    //---VARIABLES---
    char NomJoueur[255] ="NULL"; //Nom du joueur
    char ChoixLettreHORIZONTAL;
    int ChoixScore; //variable du switch pour savoir si le joueur veux enregistrer son score
    int ChoixTirVERTICAL;
    int ChoixTirHORIZONTAL;
    int NbTirs = 0; // nombre de tirs effectués par le joueur
    int NbBateaux = 4; // Nombre de bateau à la surface
    int HpBateau1 = MAX_HEALTH_SHIP_NUMBER_1; // Points de vie du bateau 1
    int HpBateau2 = MAX_HEALTH_SHIP_NUMBER_2; // Points de vie du bateau 2
    int HpBateau3 = MAX_HEALTH_SHIP_NUMBER_3; // Points de vie du bateau 3
    int HpBateau4 = MAX_HEALTH_SHIP_NUMBER_4; // Points de vie du bateau 4
    bool jeu_en_cours = true;

    int TableauNaval[10][10]={ //cette carte est invisible au joueur
           0,0,0,0,1,0,0,0,0,0,   // 0 = Rien
           0,2,2,0,0,0,0,0,0,0,   // 1 = Bateau 1
           0,0,0,0,0,0,0,0,0,0,   // 2 = Bateau 2
           0,3,3,3,0,0,4,0,0,0,   // 3 = Bateau 3
           0,0,0,0,0,0,4,0,0,0,   // 4 = Bateau 4
           0,0,0,0,0,0,4,0,0,0,   // 5 = Deja tiré ici
           0,0,0,0,0,0,4,0,0,0,
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


    //!-----------------------------DEBUT DU PROGRAMME-----------------------------------

    //Input du nom du joueur
    printf("Entrez votre nom :");
    gets(NomJoueur); //! gets > scanf
    printf("Bonjour , %s !\n",NomJoueur);
    system("pause");
    system("cls");

    AfficherMenu(TableauNaval); // Affiche le menu


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
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 5;
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
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 5;
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 2) //Si le joueur tire sur une case du bateau 2
        {
            printf("\n\nTouché !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 5;
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
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 3) //Si le joueur tire sur une case du bateau 3
        {
            printf("\n\nTouché !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 5;
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
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 4) //Si le joueur tire sur une case du bateau 4
        {
            printf("\n\nTouché !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 5;
            HpBateau4--;
            if(HpBateau4 == 0)
            {
                printf("Le bateau numero 4 a coulé !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 5) //Si le joueur a deja tiré sur cette case
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
    printf("Voulez-vous enregistrer votre score ?\n");
    printf("1.Oui\n");
    printf("2.Non\n\n");
    printf("-> ");
    scanf("%d",&ChoixScore);
    switch(ChoixScore)
    {
        default:
            printf("erreur !");
            exit(1);

        case 1:
            EnregistrerScore(NbTirs); //appelle la fonction pour enregistrer le score
            printf("Score enregistré !\n");
            AfficherMenu(TableauNaval); // retourne au menu
            break;

        case 2:
            AfficherMenu(TableauNaval); //retourne au menu
            break;
    }
    system("pause");
    return 0;
}