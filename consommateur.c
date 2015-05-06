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

#include "chaine_liee.c"
#include "producteur.c"

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
    while(n1->next != NULL)
    {
        uint64_t n3 = n1->nombre;
        int i = prime(n, 2);
        int k;
        for (k =0; k < i; k++)
        {
            sem_wait(s);
            Node *n2 = {liste_facteurs[i], 0, n1->file, c};
            n->next = n2;
            sem_post(s);
            for (k=0; k < i; k++)
            {
                liste_facteurs[i]=0;
            }
        }
    }
    return 0;
}