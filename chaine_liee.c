//
//  chaine_liee.c
//  
//
//  Created by Justine Doutreloux on 29/04/15.
//
//

#include <stdio.h>
#include <inttypes.h>

void add_node(Node *liste, Node *n)
{
    if(liste == NULL)
    {
        return;
    }
    while (liste->next != NULL)
    {
        liste = liste->next;
    }
    liste->next = n;
}

void add_number(Node *liste, uint32_t n)
{
    if(liste == NULL)
    {
        return;
    }
    while (liste->next != NULL)
    {
        if (liste->nombre == n)
        {
            liste->count++;
            a=1;
            return;
        }
        else
        {
            liste=liste->next;
        }
    }
    Node new = {n, 1, NULL, 'file'};
    add_node(liste, &new);
}
