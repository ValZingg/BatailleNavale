#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>


void menuaide() {
    system("cls");
    printf("-----COMMENT JOUER?-----\n");
    printf("Tout d'abord il faut choisir ou tirer.\n");
    printf("Vous allez choisir la case en tapant un chiffre de 0-9\n");
    printf("Vous choisirez d'abord l'axe horizontal puis vertical.\n");
    printf("\n");
    printf("---Types de cases---\n");
    printf("~ = Eau (case ou vous n'avez pas encore tire)\n");
    printf("X = Bateau touche (case ou vous avez tire et touche)\n");
    printf("@ = Ratage (case ou vous avez tire mais rien n'a ete touche.)\n\n");
    system("pause");
    system("cls");
} // Affiche l'aide

void afficherCarte(char tableau[10][10]) {
    int affichercolonne = 0; //variables utilisées dans le for plus bas
    int afficherligne = 0;  // "            "       "    "  "   "    "
    int sautageligne = 0; //Variable qui au bout de 5 saute une ligne , permet de bien aligner les cases
    int graduationchiffre = 0;//variable pour la graduation verticale
    printf("------------------------------------------\n");
    printf("|++++++++ LA MER , MON CAPITAINE ++++++++|\n");
    printf("------------------------------------------\n");
    printf("0  1  2  3  4  5  6  7  8  9\n"); //Graduation horizontale
    for(afficherligne = 0; afficherligne < 10; afficherligne++)  //BOUCLE POUR AFFICHER LA CARTE
    {
        for(affichercolonne = 0; affichercolonne < 10; affichercolonne++)
        {

            printf("%c",tableau[afficherligne][affichercolonne]);
            printf("  ");//espacement des cases
            sautageligne++;
            if(sautageligne == 10) //saute une ligne si la variable = 5
            {
                printf("  %d",graduationchiffre);
                graduationchiffre++;
                printf("\n");
                sautageligne = 0;
            }
        }
    }
} //Affiche la carte



int main() {
    //---VARIABLES---
    char NomJoueur[255] ="NULL"; //Nom du joueur
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
            //Sors du switch et commence le jeu plus bas
            break;

        case 2: //JOUER AVEC UNE CARTE STOCKEE DANS UN FICHIER
            system("cls");
            int chiffre = 0; // variable utilisée pour assigner les cases de la grille
            FILE * fichier; //variable du fichier
            fichier = fopen("CarteCustom.BATAILLENAVALE", "r"); //ouvre le fichier de la grille
            if(fichier == NULL)printf("Erreur ! Fichier introuvable.\n"); // Erreur si le fichier n'est pas trouvé

            for(j = 0;j < 10;j++)
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

    while(jeu_en_cours == true) // Loop du jeu
    {
        afficherCarte(TableauAffiche); // Affiche la carte a chaque début de boucle
        printf("\n");
        printf("Veuillez choisir ou tirer...\n");
        printf("Entrez la case HORIZONTALE\n");
        scanf("%d",&ChoixTirHORIZONTAL); //demande l'axe horizontal
        system("cls");

        afficherCarte(TableauAffiche);
        printf("Veuillez choisir ou tirer...\n");
        printf("Entrez la case VERTICALE\n"); //demande l'axe vertical
        scanf("%d",&ChoixTirVERTICAL);

        //TODO : REMPLACER LES "IF ELSE" PAR UN TRUC PLUS PRATIQUE !

        if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 1) // Si le joueur touche une case du bateau 1
        {
            printf("\n\nTouche !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X"; //change la case touchée par le joueur. @ pour rien touché , X pour bateau touché
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            HpBateau1--;
            if(HpBateau1 == 0)
            {
                printf("Le bateau numero 1 a coule !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 0) //Si le joueur tire sur une case vide
        {
            printf("\n\nRate !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"@";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 2) //Si le joueur tire sur une case du bateau 2
        {
            printf("\n\nTouche !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            HpBateau2--;
            if(HpBateau2 == 0)
            {
                printf("Le bateau numero 2 a coule !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 3) //Si le joueur tire sur une case du bateau 2
        {
            printf("\n\nTouche !\n");
            TableauAffiche[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = *"X";
            TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] = 4;
            HpBateau3--;
            if(HpBateau3 == 0)
            {
                printf("Le bateau numero 3 a coule !\n");
                NbBateaux--;
            }
            NbTirs++;
            system("pause");
            system("cls");
        }
        else if(TableauNaval[ChoixTirVERTICAL][ChoixTirHORIZONTAL] == 4) //Si le joueur a deja tiré sur cette case
        {
            printf("Vous avez deja tire ici !\n");
            system("pause");
            system("cls");
        }



        if(NbBateaux == 0)//Si il n'y a plus aucun bateau , le jeu se termine.
        {
            jeu_en_cours = false;
            system("cls");
        }
    }

    printf("Felicitations ! Vous avez gagne en %d tours !\n\n",NbTirs); //Message de fin du jeu
    system("pause");
    return 0;
}