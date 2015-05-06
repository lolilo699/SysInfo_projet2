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

unsigned int liste_facteurs[];

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

int conso(sem_t *s, Node *n, Node1 *n1)
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
            Node *n2 = {liste_facteurs[i], 0, liste_nombres->file, c};
            if (liste_nombres_premiers == NULL)
            {
                liste_nombres_premiers = n2;
            }
            else
            {
                while (liste_nombres_premiers->next != NULL)
                {
                    liste_nombres_premiers = liste_nombres_premiers->next;
                }
                liste_nombres_premiers->next = n2;
            }
            sem_post(&empty1);
            pthread_mutex_unlock(&mutex1);
            for (k=0; k < i; k++)
            {
                liste_facteurs[i]=0;
            }
        }
    }
    return 0;
}