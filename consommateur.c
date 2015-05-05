//
//  consommateur.c
//  

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdint.h>

void prime(unsigned int n, unsigned int d)
{
    if (n != 1)
    {
        if (n % d)
        {
            d++;
            f(n, d);
        }
        else
        {
            liste_facteurs[i] = d;
            i++;
            f(n / d, d);
        }
    }
}
int conso(void)
{
    unsigned int n;
    int k;
    scanf("%u", &n);
    prime(n, 2);
    for (k =0; k < i; k++)
        printf("%d ", liste_facteurs[k]);
    printf("\n");
    return 0;
}