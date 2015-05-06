//
//  chaine_liee.c : représente la liste chainée que nous utilisons pour les nombres premiers
//


#include <stdio.h>
#include <inttypes.h>

/*Structure de la liste chainee. 
 * nombre est le nombre premier à stocker
 * nom_du_fichier représente le fichier dans lequel il a été trouvé
 * count représente le nombre de fois où il a été trouvé
 */

struct Node()
{
    uint32_t nombre;
    int count;
    Node *next;
    char nom_du_fichier[];
}

/* Fonction pour ajouter un noeud dans la liste. prend en argument un pointeur vers la liste
 * et un pointeur vers le noeud à ajouter
 */

void add_node(Node *liste, Node *n)
{
    if(liste == NULL)
    {
        return;
    }
    while (liste->next != NULL)
    {
        liste = liste->next;
    }
    liste->next = n;
}

/* Fonction pour ajouter un nombre dans la liste. On teste d'abord s'il est déjà
 * présent et s'il ne l'est pas on utilise add_node.
 */

void add_number(Node *liste, uint32_t n)
{
    if(liste == NULL)
    {
        return;
    }
    while (liste->next != NULL)
    {
        if (liste->nombre == n)
        {
            liste->count++;
            a=1;
            return;
        }
        else
        {
            liste=liste->next;
        }
    }
    Node new = {n, 1, NULL, 'file'};
    add_node(liste, &new);
}
