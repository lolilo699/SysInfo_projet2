#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
/*
#include "producteur.c"
#include "consommateur.c"
#include "chaine_liee.c"
*/

int max_threads=0;
int err;
int sizeFile=0;
bool value_input=false;
pthread_mutex_t mutex1;
sem_t empty1;
sem_t full1;
pthread_mutex_t mutex2;
sem_t empty2;
sem_t full2;
Node1 *liste_nombres;
Node *liste_nombres_premier;
bool fini;
int producteur_finis;
int nb_producteurs;



void initialize(){
    if (pthread_mutex_init(&mutex1, NULL)) {
        perror("pthread_mutex_init(&mutex1, NULL)");
        exit(EXIT_FAILURE);
    }
    if (pthread_mutex_init(&mutex2, NULL)) {
        perror("pthread_mutex_init(&mutex2, NULL)");
        exit(EXIT_FAILURE);
    }
    if (sem_init(&full1, 0, 0)) {
        perror("sem_init(&full1, 0, 0)");
        exit(EXIT_FAILURE);
    }
    if (sem_init(&empty1, 0, N)) {
        perror("sem_init(&empty1, 0, N)");
        exit(EXIT_FAILURE);
    }
    if (sem_init(&full2, 0, 0)) {
        perror("sem_init(&full2, 0, 0)");
        exit(EXIT_FAILURE);
    }
    if (sem_init(&empty2, 0, N)) {
        perror("sem_init(&empty2, 0, N)");
        exit(EXIT_FAILURE);
    }
    nb_producteurs = 0;
    fini = false;
}





int main(int argc, const char *argv[]){
    int i;
    int count=0;
    const char **File;
    initialize();
    pthread_mutex_t *prod = malloc (argc * sizeof(pthread_mutex_t));
    bool *actif = calloc (argc, sizeof(bool));

    for(i=1;i<argc;i++)
    {
        if(strcmp("-maxthreads",argv[i])==0)
        {
            i++;
            max_threads = atoi(argv[i]);
        }
        else if (strcmp(argv[i],"-stdin")==0)
        {
            pthread_create(&prod[i], NULL, producteur_stdin, NULL);
            actif[i] = true;
            nb_producteurs++;
        }
        else if (strncmp(argv[i], "http://", strlen("http://")) == 0)
        {
            pthread_create(&prod[i], NULL, producteur_URL, NULL);
            actif[i] = true;
            nb_producteurs++;
        }
        else
        {
            pthread_create(&prod[i], NULL, producteur_fichier, NULL);
            nb_producteurs++;
        }
    }
//    printf("taille :%d\n",sizeFile);
//    printf("thread :%d\n",N);

//    pthread_t cons[max_threads];
//    for (int i=0; i < max_threads; i++)
//    {
//        if (pthread_create(&cons[i], NULL, conso, NULL))
//        {
//            perror("phtread_create cons");
//            exit(EXIT_FAILURE);
//        }
//    }
    
//    for (int j=0; j < argc; j++)
//    {
//        if(actif[j])
//        {
//            pthread_join(prod[j], NULL)
//        }
//    }
//    for (int k=0; k < max_threads; k++)
//    {
//        pthread_join(cons[k], NULL)
//    }
}
