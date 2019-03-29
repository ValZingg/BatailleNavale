//
// Created by Valentin.ZINGG on 21.03.2019.
//

#ifndef UNEBATAILLEDANSLEAU_FONCTIONSJEU_H
#define UNEBATAILLEDANSLEAU_FONCTIONSJEU_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "aidejeu.h"

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

void afficherCarte(char tableau[10][10],int tirs,int bateaux,char nomjoueur[255]) {
    SetConsoleOutputCP(437); //permet l'affichage des graphismes NVIDIA ASCII 2020
    int affichercolonne = 0; //variables utilisées dans le for plus bas
    int i = 0;//utlisé pour la boucle for
    int JointHaut = 0;
    int afficherligne = 0;  // Pareil que la ligne du dessus
    int sautageligne = 0; //Variable qui au bout de 5 saute une ligne , permet de bien aligner les cases
    int graduationchiffre = 1;//variable pour la graduation verticale
    printf("------------------------------------------\n");
    printf("|++++++++++++++ CAPITAINE %s +++++++++++++|\n",nomjoueur);
    printf("|++++++++++++++++ TIRS : %d ++++++++++++++|\n",tirs); //affiche le nombre de tirs
    printf("|++++++++++ BATEAUX RESTANTS : %d ++++++++|\n",bateaux); //affiche le nombre de bateaux restants
    printf("------------------------------------------\n");
    printf("  A   B   C   D   E   F   G   H   I   J\n"); //Graduation horizontale

    //! La boucle qui va suivre n'est pas élégante , mais elle fonctionne. Je m'excuse d'avance pour tout les mals de tête causés!
    for(afficherligne = 0; afficherligne < 10; afficherligne++)  //BOUCLE POUR AFFICHER LA CARTE
    {
        if(afficherligne == 0)
        {
            printf("%c",STLC); // affiche le coin en haut a gauche
        }
        for(affichercolonne = 0; affichercolonne < 10; affichercolonne++)
        {
            if(affichercolonne == 0) // au début de la ligne
            {
                if(afficherligne == 0) // si le programme est a la première ligne
                {
                    //Ne rien afficher pour laisser la place au coin
                }
                else
                {
                    printf("%c",SVLB); // afficher "├"
                }

                for(i = 0;i < 40;i++) //boucle pour afficher l'ASCII des lignes horizontales
                {
                    if(i == 39) // si c'est le dernier charactère de la ligne
                    {
                        if(afficherligne == 0)
                        {
                            printf("%c",STRC); // si la boucle est à la première ligne , affiche un coin
                        }
                        else
                        {
                            printf("%c",SVRB); //sinon affiche le charactere "┤"
                        }
                    }
                    else // sinon , continuer la ligne normalement
                    {
                        if(JointHaut == 3) //Toute les 3 charactères , afficher le charactère SC
                        {
                            printf("%c",SC);
                            JointHaut = 0; //Remettre à 0 pour reconter les charactères
                        }
                        else//Sinon afficher Le charactère SHSB
                        {
                            printf("%c",SHSB);
                            JointHaut++;
                        }
                    }
                }

                printf("\n%c",SVSB);
            }
            printf(" %c ",tableau[afficherligne][affichercolonne]);
            sautageligne++; //traque le nombre de cases affichées sur la ligne
            if(sautageligne != 10)printf("%c",SC);//affiche le charactere SC si il n'y a pas besoin de sauter la ligne
            if(sautageligne == 10) //saute une ligne si la variable = 10
            {
                printf("%c",SVSB);
                JointHaut = 0; // permet d'éviter les bugs graphiques
                printf("  %d",graduationchiffre);//affiche la graduation de côté
                graduationchiffre++;//augemente le chiffre de la graduation pour la prochaine utilisation de cette condition
                printf("\n");
                sautageligne = 0;
            }
        }
    }

    printf("%c",SBLC);//Affiche le coin inférieur gauche
    for(i = 0;i < 39;i++) //Cette boucle entière sert à afficher la ligne tout en bas de la grille
    {
        if(JointHaut == 3) //Toute les 3 charactères , afficher le charactère SC
        {
            printf("%c",SC);
            JointHaut = 0; //Remettre à 0 pour reconter les charactères
        }
        else//Sinon afficher Le charactère SHSB
        {
            printf("%c",SHSB);
            JointHaut++;
        }
    }
    printf("%c\n",SBRC);//Affiche le coin inférieur droit

    SetConsoleOutputCP(65001); //rétablit les accents
} //Affiche la carte

int TraducteurGrille(char Lettrechoix){
    int Rendu = 0; //valeur rendue
    //CETTE FONCTION "TRADUIT" LA LETTRE ENTREE PAR LE JOUEUR EN CHIFFRE QUI PERMET AU PROGRAMME DE L'UTILISER POUR LE TABLEAU
    if(Lettrechoix == 'A' || Lettrechoix == 'a')
    {
        Rendu = 0;
    }
    if(Lettrechoix == 'B' || Lettrechoix == 'b')
    {
        Rendu = 1;
    }
    if(Lettrechoix == 'C' || Lettrechoix == 'c')
    {
        Rendu = 2;
    }
    if(Lettrechoix == 'D' || Lettrechoix == 'd')
    {
        Rendu = 3;
    }
    if(Lettrechoix == 'E' || Lettrechoix == 'e')
    {
        Rendu = 4;
    }
    if(Lettrechoix == 'F' || Lettrechoix == 'f')
    {
        Rendu = 5;
    }
    if(Lettrechoix == 'G' || Lettrechoix == 'g')
    {
        Rendu = 6;
    }
    if(Lettrechoix == 'H' || Lettrechoix == 'h')
    {
        Rendu = 7;
    }
    if(Lettrechoix == 'I' || Lettrechoix == 'i')
    {
        Rendu = 8;
    }
    if(Lettrechoix == 'J' || Lettrechoix == 'j') {
        Rendu = 9;
    }
    return Rendu; //renvoie le choix de lettre sous forme de integer
}

const char* choixficher(int chiffre){
    const char * randomfichier ="null";

    if(chiffre == 0)
    {
        randomfichier = "CartesCustom/CarteCustom1.BATAILLENAVALE";
    }

    if(chiffre == 1)
    {
        randomfichier = "CartesCustom/CarteCustom2.BATAILLENAVALE";
    }

    if(chiffre == 2)
    {
        randomfichier = "CartesCustom/CarteCustom3.BATAILLENAVALE";
    }

    return randomfichier;
}

void EnregistrerScore(int ScoreFinal){
    int TableauScores[11]; // Tableau des scores , va être copié dans le fichier score
    int nbmax = 11; //taille maximum du tableau
    int temp = 0;
    int i;
    int j;
    int chiffre;
    FILE * Fichier;

    Fichier = fopen("Scores.BATAILLENAVALE", "r");
    if(Fichier == NULL)printf("Erreur ! Fichier introuvable.\n");
    for(i = 0; i < 10; i++) //Récupère toutes les valeurs dans le fichier score et le met dans le tabeau "TableauScores[10]"
    {
        fscanf(Fichier,"%d",&chiffre);
        TableauScores[i] = chiffre;
    }
    fclose(Fichier);

    if(TableauScores[10] >= ScoreFinal) //Si le score entré est meilleur que le PIRE score , il est entré dans le tableau
    {
        TableauScores[10] = ScoreFinal;
    }

    for(j = 0;j != nbmax;j++) //Cette boucle met les valeurs du tableau dans l'ordre croissant (plus le score est petit mieux c'est)
    {
        for(i = 0;i != nbmax;i++)
        {
            if(TableauScores[i] > TableauScores[i+1])
            {
                temp = TableauScores[i];
                TableauScores[i] = TableauScores[i+1];
                TableauScores[i+1] = temp;
            }
        }
    }

    Fichier = fopen("Scores.BATAILLENAVALE", "w+"); //réouvre le fichier pour mettre les nouveaux scores
    for(i = 9;i > -1;i--) //Cette boucle insère les nouveaux score dans le fichier score et retire le pire score (le 11ème)
    {
        fprintf(Fichier,"%d\n",TableauScores[i]);
    }
    fclose(Fichier);

}

void ScoresAffiche(){ //Fonction presque identique à EnregistrerScore() , Celle-ci sert uniquement a afficher les scores
    system("cls");
    int TableauScores[11]; // Tableau des scores , va être copié dans le fichier score
    int i;
    int chiffre;
    FILE * Fichier;

    printf("Voici les meilleurs scores !\n");
    printf("(En nombre de coups)\n\n");

    Fichier = fopen("Scores.BATAILLENAVALE", "r");
    if(Fichier == NULL)printf("Erreur ! Fichier introuvable.\n");
    for(i = 0; i < 10; i++) //Récupère toutes les valeurs dans le fichier score et le met dans le tabeau "TableauScores[10]"
    {
        fscanf(Fichier,"%d",&chiffre);
        TableauScores[i] = chiffre;
    }
    fclose(Fichier);

    int compteurplace = 1; //compteur de place dans le classement
    for(i = 9;i != -1;i--)
    {
        printf("%d #%d\n",TableauScores[i],compteurplace); //print le tableau entier
        compteurplace++;
    }
    printf("\n\n");

    system("pause");
    system("cls");
}

void AfficherMenu(int TableauInt[10][10]){
    system("cls"); //nettoie l'écran
    int i = 0;//utilisé pour les boucles for
    int j = 0;//utilisé pour les boucles for
    //Affichage du menu principal
    printf("\t     |    |    |\n");
    printf("\t    )_)  )_)  )_)\n");
    printf("\t   )___))___))___)\\\n");
    printf("\t  )____)____)_____)\\\\\n");
    printf("\t  ____|____|____|____\\\\\\___\n");
    printf("~~~~~~~~~~\\    BATAILLE NAVALE    /~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("---------------------------------------------\n");
    printf("1.Jouer\n");
    printf("2.Jouer avec une carte personalisee\n");
    printf("3.Aide\n");
    printf("4.Scores\n");
    printf("5.Quitter\n");
    printf("---------------------------------------------\n");
    printf("\nBateau ASCII par Christopher Johnson\n");
    printf("https://asciiart.website/index.php?art=transportation/nautical\n");

    int ChoixMenu = 0;
    scanf("%d",&ChoixMenu);
    if(ChoixMenu > 5 || ChoixMenu < 1)
    {
        printf("Aie aie aie ! Valeur non correcte !\n");
        system("pause");
        AfficherMenu(TableauInt);
    }

    switch(ChoixMenu)
    {
        default:
            //rien ici
            break;

        case 1: //JOUER AVEC LA CARTE DE BASE
            system("cls");
            //Sort du switch et commence le dans le main.c
            break;

        case 2: //JOUER AVEC UNE CARTE STOCKEE DANS UN FICHIER
            system("cls");
            int chiffre = 0; // variable utilisée pour assigner les cases de la grille
            int aleatoire = rand() % 3; //envoyé à une fonction qui choisira un fichier aléatoirement TODO : FAIRE UN VRAI RANDOM
            const char * fichierandom;//variable qui contient le nom du fichier à lire
            fichierandom = choixficher(aleatoire);
            FILE * fichier; //variable du fichier
            fichier = fopen(fichierandom, "r"); //ouvre le fichier de la grille
            if(fichier == NULL)printf("Erreur ! Fichier introuvable.\n"); // Erreur si le fichier n'est pas trouvé

            for(j = 0;j < 10;j++) //boucle pour lire les valeurs du fichier grille et les assigner au tableau du jeu
            {
                for(i = 0; i < 10; i++)
                {
                    fscanf(fichier,"%d",&chiffre); //Scanne et stock la valeur de la ligne actuelle en int
                    TableauInt[j][i] = chiffre; //Assigne la valeur stockée à la case de la grille actuelle
                }
            }
            fclose(fichier);
            break;

        case 3:
            // AIDE
            menuaide(); // Affiche l'aide avec une fonction
            AfficherMenu(TableauInt); //retourne au menu
            break;

        case 4://SCORE
            ScoresAffiche();
            AfficherMenu(TableauInt); //retourne au menu
            break;

        case 5://QUITTER
            exit(0); //Termine le programme

    }
}



#endif //UNEBATAILLEDANSLEAU_FONCTIONSJEU_H
