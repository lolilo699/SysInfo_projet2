//
//  consommateur.c
//  

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>
#include <semaphore.h>

//variable globale utilisée pour stocker la liste des facteurs premiers d'un nombre
unsigned int liste_facteurs[];


//fonction trouvée sur openclassrooms pour factoriser
int prime(unsigned int n, unsigned int d)
{
    if (n != 1)
    {
        if (n % d != 0)
        {
            d++;
            prime(n, d);
        }
        else
        {
            liste_facteurs[i] = d;
            i++;
            prime(n / d, d);
        }
    }
    return i;
}

/* Fonction qui représente le consommateur : prend un nombre, le factorise et ajoute les facteurs
 * dans une liste
 *
 */
void conso()
{
    while(liste_nombres->next != NULL)
    {
        uint64_t n3 = liste_nombres->nombre;
        int i = prime(n, 2);
        int k;
        for (k =0; k < i; k++)
        {
            pthread_mutex_lock(&mutex1);
            sem_wait(&full1);
            add_number( n3);
            sem_post(&empty1);
            pthread_mutex_unlock(&mutex1);
            for (k=0; k < i; k++)
            {
                liste_facteurs[i]=0;
            }
        }
    }
}