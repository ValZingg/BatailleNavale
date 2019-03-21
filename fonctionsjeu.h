//
// Created by Valentin.ZINGG on 21.03.2019.
//

#ifndef UNEBATAILLEDANSLEAU_FONCTIONSJEU_H
#define UNEBATAILLEDANSLEAU_FONCTIONSJEU_H
#include <stdio.h>
#include <stdlib.h>

void afficherCarte(char tableau[10][10],int tirs,int bateaux,char nomjoueur[255]) {
    int affichercolonne = 0; //variables utilisées dans le for plus bas
    int afficherligne = 0;  // Pareil que la ligne du dessus
    int sautageligne = 0; //Variable qui au bout de 5 saute une ligne , permet de bien aligner les cases
    int graduationchiffre = 1;//variable pour la graduation verticale
    printf("------------------------------------------\n");
    printf("|++++++++++++++ CAPITAINE %s +++++++++++++|\n",nomjoueur);
    printf("|++++++++++++++++ TIRS : %d ++++++++++++++|\n",tirs); //affiche le nombre de tirs
    printf("|++++++++++ BATEAUX RESTANTS : %d ++++++++|\n",bateaux); //affiche le nombre de bateaux restants
    printf("------------------------------------------\n");
    printf("A  B  C  D  E  F  G  H  I  J\n"); //Graduation horizontale

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

#endif //UNEBATAILLEDANSLEAU_FONCTIONSJEU_H
