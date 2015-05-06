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
    semaphore = sem_open("liste", O_CREATn S_ISUR | S_IWUSR, 0);
    int max_threads = argv[1];
    
    sem_unlink("liste");
}