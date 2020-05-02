#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "projectlib.h"


int main(){

    printf("\n dovrei inizializzare i libri \n");
    
    libro *radLibro = (libro *)malloc(sizeof(libro));
    // inizializzo l'albero con la funzione initialize passando come argomento &rad poiché
    // l'inserimento ricorsivo utilizza il doppio puntatore
    initializeABRLibro(&radLibro);
    
    // qui uso il puntatore singolo e quindi passo rad
    visitaInPreordineLibro(radLibro);

    queue *coda=(queue *)malloc(sizeof(queue));
    initializeQueue(coda);

    studente *radStudente = (studente *)malloc(sizeof(studente));

    
    int canIclose=1; // flag presenza richieste
    int choice=-1;
    do{
        printf("\n1. Aggiungere una richiesta ");
        printf("\n2. Gestire le richieste ");
        printf("\n0. Terminare ");
        printf("\n input: ");
            do{
                scanf("%d",&choice);
                if(choice<0 || choice>2)
                    printf(" Non valido!\n input: ");
            }while(choice<0 || choice>2);

        printf("\n ho selezionato %d \n",choice);

        switch(choice){
            case 1:
                printf("\n Aggiungere una richiesta (chiamo catch request\n");
                catchRequest(&radStudente,&radLibro,coda);
                               
                break;
            case 2:
                printf("\n Gestire le richieste (per ora stampa solo)\n");
                printQueue(coda);

                break;
            case 0:
                canIclose=emptyQueue(coda);
                if(canIclose)
                    printf("\n Arrivederci \n");
                else
                    printf("\n ci sono richieste in sospeso da gestire! \n");
                
            break;
        }

    }while( choice!=0 || canIclose!=1 );

        
    return 0; 
}
