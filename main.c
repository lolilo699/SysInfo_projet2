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


int N=0;
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

}





int main(int argc, const char *argv[]){
    int i;
    int count=0;
    const char **File;


    for(i=1;i<argc;i++){
        if(strcmp("-maxthreads",argv[i])==0){
            i++;
            N=atoi(argv[i]);
            }
        else if (strcmp(argv[i],"-stdin")==0){
            value_input=true;
        }
        else {
        sizeFile++;
        }
    }

    File = malloc(sizeFile*sizeof(char *));

    for(i=1;i<argc;i++){
        if(strcmp("-maxthreads",argv[i])==0){
            i++;
        }
        else{
            File[count]=argv[i];
            count++;
        }
    }
    printf("taille :%d\n",sizeFile);
    printf("thread :%d\n",N);
    initialize();

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
