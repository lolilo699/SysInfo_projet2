//
//  producteur.c doit gérer l'ouverture, la lecture et la fermeture d'un fichier, et l'écriture des nombres lus dans le fichier dans une liste. Il doit aussi gérer les cas où l'entrée n'est pas un fichier mais une URL, l'entrée standard ou un descripteur de fichier.
//  


#include <stdio.h>
#include <inttypes.h>
#include <endian.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <curl/curl.h>
#include <curl/easy.h>


struct Node1()
{
    uint64_t nombre;
    char file[];
    Node *next;
}


Node1* producteur_descripteur(int fd, char file)
{
    uint64_t nombre;
    Node1 *premier;
    premier->nombre = 0;
    premier->next = NULL;
    Node1 *courant;
    courant=premier;
    while(true)
    {
        int bytes;
        bytes = read(fd, &nombre, sizeof(uint64_t));
        if(bytes==8)
        {
            nombre = be64toh(nombre);
            if(premier==courant)
            {
                premier->nombre = nombre;
            }
            else
            {
                Node1 *n;
                n->nombre = nombre;
                n->file = file;
                n->next = NULL;
                courant->next = n;
                courant = courant->next;
            }
            
        }
        else
        {
            printf("Erreur");
        }
    }
    return premier;
}


Node1* producteur_fichier(char fichier[])
{
    int fd = open(fichier, O_RDONLY);
    if(fd<0)
    {
        printf("Le fichier %c n'a pas pu s'ouvrir", fichier);
        return {n, 0, NULL};
    }
    else
    {
        return producteur_descripteur(fd, fichier);
    }
}
/*
 * Fonction nécessaire pour producteur_URL
 */

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
    int fd = *((int *) userp);
    
    return write(fd, contents, size*nmemb);
}

/*
 * infos sur curl : http://curl.haxx.se/libcurl/c/
 */
Node1* producteur_URL(char url[])
{
    int fd;
    CURL *curl_handler = curl_easy_init();
    curl_easy_setopt(curl_handler, CURLOPT_URL, &url);
    curl_easy_setopt(curl_handler, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_handler, CURLOPT_WRITEDATA, (void *)&fd);
//    curl_easy_setopt(curl_handler, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_perform(curl_handler);
    curl_easy_cleanup(curl_handler);
    return producteur_descripteur(fd, url);
    
}

Node1* producteur_stdin()
{
    return producteur_descripteur(STDIN_FILENO, "STDIN");
}