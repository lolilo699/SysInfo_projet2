//
//  producteur.c doit gérer l'ouverture, la lecture et la fermeture d'un fichier, et l'écriture des nombres lus dans le fichier dans une liste. Il doit aussi gérer les cas où l'entrée n'est pas un fichier mais une URL, l'entrée standard ou un descripteur de fichier.
//  


#include <stdio.h>
#include <inttypes.h>
#include <endian.h>

struct Node()
{
    uint64_t nombre;
    Node *next;
}


Node* producteur_descripteur(int fd)
{
    uint64_t nombre;
    Node *premier;
    premier->nombre = 0;
    premier->next = NULL;
    Node *courant;
    courant=premier;
    while(true)
    {
        int bytes;
        bytes = read(fd, &nombre, sizeof(uint64_t));
        if(bytes==8)
        {
            nombre = be64toh(nombre);
            if(premier==courant)
            {
                premier->nombre = nombre;
            }
            else
            {
                Node *n;
                n->nombre = nombre;
                n->next = NULL;
                courant->next = n;
                courant = courant->next;
            }
            
        }
        else
        {
            printf("Erreur");
        }
    }
    return premier;
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

Node* producteur_stdin()
{
    return producteur_descripteur(STDIN_FILENO);
}