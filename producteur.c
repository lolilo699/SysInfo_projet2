//
//  producteur.c doit gérer l'ouverture, la lecture et la fermeture d'un fichier, et l'écriture des nombres lus dans le fichier dans une liste. Il doit aussi gérer les cas où l'entrée n'est pas un fichier mais une URL ou un descripteur de fichier.
//  


#include <stdio.h>
#include <inttypes.h>

struct Node()
{
    uint32_t nombre;
    Node *next;
}


Node* producteur_descripteur(int fd)
{
    
}


Node* producteur_fichier(char fichier[])
{
    int fd = open(fichier, O_RDONLY);
    if(fd<0)
    {
        printf("Le fichier %c n'a pas pu s'ouvrir", fichier);
        return {n, 0, NULL};
    }
    else
    {
        return producteur_descripteur(fd);
    }
}

//Node* producteur_URL(char url[])
//{
    
//}