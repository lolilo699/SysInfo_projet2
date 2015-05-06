#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#include "producteur.c"
#include "consommateur.c"
#include "chaine_liee.c"

sem_t *semaphore;

int main(int argc, char** argv[])
{
    
    pthread_t cons[max_threads];
    for (int i=0; i < max_threads; i++)
    {
        if (pthread_create(&cons[i], NULL, conso, NULL))
        {
            perror("phtread_create cons");
            exit(EXIT_FAILURE);
        }
    }
    for (int j=0; j < argc; j++)
    {
        if(actif[i])
        {
            pthread_join(cons[j], NULL)
        }
    }
}