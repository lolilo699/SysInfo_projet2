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
int temps_initial = malloc(sizeof(struct timeval));
int temps_final = malloc(sizeof(struct timeval));



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

void nombre_premier()
{
    while (liste_nombres_premier->next != NULL)
    {
        if (liste_nombres_premier->count ==1)
        {
            count1++;
            printf("Le nombre premier unique est %d.\n", liste_nombres_premier->nombre);
            printf("Il a été trouvé dans le fichier %c.\n", liste_nombres_premier->nom_du_fichier);
            printf("Le programme a mis %d secondes pour s'exécuter.\n", (temps_final - temps_initial));
            return;
        }
        else
        {
            liste_nombres_premier = liste_nombres_premier->next;
        }
    }
    printf("Il n'y a pas de nombre unique.\n");
    printf("Le programme a mis %d secondes pour s'exécuter.\n", (temps_final - temps_initial));

}



int main(int argc, const char *argv[])
{
    gettimeofday(temps_initial, NULL);
    initialize();
    pthread_mutex_t *prod = malloc (argc * sizeof(pthread_mutex_t));
    bool *actif = calloc (argc, sizeof(bool));
    int count = 0;
    
    for(int i = 1; i < argc; i++)
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
            actif[i] = true;
            nb_producteurs++;
        }
    }
    pthread_mutex_t *consos = malloc (max_threads * sizeof(pthread_mutex_t));
    
    while (count != nb_producteurs)
    {
        for (int i = 0; i < max_threads; i++)
        {
            if (pthread_join(&consos[i]) == true)
                {
                    pthread_create(&consos[i], NULL, conso, NULL);
                    count++;
                }
        }
    }
    pthread_join(&consos);
    gettimeofday(temps_final, NULL);
    nombre_premier();
}
