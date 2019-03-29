//
// Created by Valentin.ZINGG on 21.03.2019.
//

#ifndef UNEBATAILLEDANSLEAU_AIDEJEU_H
#define UNEBATAILLEDANSLEAU_AIDEJEU_H
#include <stdio.h>
#include <stdlib.h>

void menuaide() {
    system("cls");
    printf("-----COMMENT JOUER?-----\n");
    printf("Tout d'abord il faut choisir où tirer.\n");
    printf("Vous allez choisir la case en tapant un chiffre de 1-10 et une lettre de A-J\n");
    printf("Vous choisirez d'abord l'axe horizontal puis vertical.\n\n");
    printf("Il y a toujours 4 Bateaux:\n");
    printf("La Corvette qui fait 1 CASE\n");
    printf("La Frégate qui fait 2 CASES\n");
    printf("Le Destroyer qui fait 3 CASES\n");
    printf("Le Cuirassé qui fait 4 CASES\n");
    printf("<!!!>IL NE PEUT PAS Y AVOIR DE BATEAUX EN DIAGONALE<!!!>\n");
    printf("\n");
    printf("---Types de cases---\n");
    printf("~ = Eau (case ou vous n'avez pas encore tiré)\n");
    printf("X = Bateau touche (case ou vous avez tiré et touché)\n");
    printf("@ = Ratage (case ou vous avez tiré mais rien n'a ete touché.)\n\n");
    system("pause");
    system("cls");
} // Affiche l'aide

#endif //UNEBATAILLEDANSLEAU_AIDEJEU_H
