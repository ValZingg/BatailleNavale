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
#include <time.h>

#define CORVETTESIZE 1;
#define FREGATESIZE 2;
#define DESTROYERSIZE 3;
#define CUIRASSESIZE 4;

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
    //!Cette fonction utilise le int random passé dans la fonction pour choisir une carte aléatoirement
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
    int temp = 0; //Stocke temporairement une valeur du tableau dans une boucle
    int i;
    int j;
    int chiffre; //Variable de stockage temporaire pour le tableau
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

void GrilleRandom(int Tableau[10][10]){
    int casesrestantes = 100; //Nombre de case de grille a placer restantes
    int casesEau = 90; // Nombre de cases d'eau restante à placer dans la grille
    srand(time(NULL)); //initialisation pour le random
    int random = 0; // Chiffre aléatoire
    int ligne = 0;
    int colonne = 0;
    int i = 0;
    int j = 0;

    bool Bateau1_Place = false; //Pour savoir si la corvette a étée placée
    bool Bateau2_Place = false; //Pour savoir si la fregate a étée placée
    bool Bateau3_Place = false; //Pour savoir si le destroyer a étée placée
    bool Bateau4_Place = false; //Pour savoir si le cuirassé a étée placée

    bool PlacementTermine = false;

    while(PlacementTermine == false) // Boucle de création
    {
        random = rand()%11; //genère un chiffre random a chaque debut de boucle

        switch(random)
        {
            default:
                printf("Erreur !\n");
                exit(0);

            case 0:
            case 5: //SI LE CHIFFRE EST 0 , 5 , 6 , 7 , 8 , 9 , 10: Place une case d'eau
            case 6: //Le switch pour l'eau possède plus de "cases" pour éviter que les bateaux ne soient trop collés ensembles.
            case 7:
            case 8:
            case 9:
            case 10:
                if(casesEau > 0)
                {
                    Tableau[ligne][colonne] = 0; //assigne la case comme de l'eau
                    casesEau--;
                    casesrestantes--;
                    colonne++; //avance à la prochaine case
                }
                break;

            case 1: //SI LE RANDOM TOMBE SUR 1 , PLACE LA CORVETTE
                if(Bateau1_Place == false)
                {
                    Tableau[ligne][colonne] = CORVETTESIZE; //Assigne la corvette a cette case du tableau
                    casesrestantes--;
                    colonne++;
                    Bateau1_Place = true;
                }
                break;

            case 2: // FREGATE
                if(Bateau2_Place == false)
                {
                    for(i = 0;i < 2;i++)
                    {
                        Tableau[ligne][colonne] = FREGATESIZE;
                        colonne++;
                        casesrestantes--;
                    }
                    Bateau2_Place = true;
                }
                break;

            case 3: //destroyer
                if(Bateau3_Place == false)
                {
                    for(i = 0;i < 3;i++)
                    {
                        Tableau[ligne][colonne] = DESTROYERSIZE;
                        colonne++;
                        casesrestantes--;
                    }
                    Bateau3_Place = true;
                }
                break;

            case 4: //Cuirassé
                if(Bateau4_Place == false)
                {
                    for(i = 0;i < 4;i++)
                    {
                        Tableau[ligne][colonne] = CUIRASSESIZE;
                        colonne++;
                        casesrestantes--;
                    }
                    Bateau4_Place = true;
                }
                break;
        }
        if(colonne == 9) //sautage de ligne
        {
            colonne = 0;
            ligne++;
        }
        if(casesrestantes == 0) //Si il n'y a plus de cases a placer , quitte la boucle
        {
            PlacementTermine = true;
            break;
        }
    }

    //ECRITURE DE LA GRILLE DANS UN FICHIER
    system("cls");
    char nomfichier[255] ="NULL";
    printf("Entrez un nom de fichier...\n");
    scanf("%s",nomfichier); //demande au joueur d'entrer le nom du fichier
    strcat(nomfichier, ".BATAILLENAVALE"); // ajoute le suffixe .BATAILLENAVALE


    FILE *fichiergrille;
    fichiergrille = fopen(nomfichier, "w+"); //Crée le fichier ou le remplace si il a le même nom
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10;j++)
        {
            fprintf(fichiergrille,"%d\n",Tableau[i][j]); //Place le tableau dans le fichier
        }
    }
    system("cls");
    printf("Creation terminée.\n");
    printf("grille %s créé !\n",nomfichier);
    printf("Démarrage du jeu...\n\n");
    system("pause");
    fclose(fichiergrille);//ferme le fichier.
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
    printf("1.Jouer avec une grille générée aléatoirement\n");
    printf("2.Jouer avec une grille choisie aléatoirement\n");
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

        case 1: //JOUER AVEC UNE GRILLE GENEREE ALEATOIREMENT
            GrilleRandom(TableauInt);
            //Sors ensuite de la boucle directement avec le nouveau tableau
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
