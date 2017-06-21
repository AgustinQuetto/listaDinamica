#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"
#include "../inc/ArrayList.h"

void listar(eDestinatario* p)
{
    printf("Nombre: %s\t\tCorreo electronico: %s\n",p->nombre,p->mail);
}

void listarDestinatarios(ArrayList* listarDestinatarios){
    int i;
    for(i=0;i<listarDestinatarios->size;i++){
        listar(listarDestinatarios->pElements[i]);
    }
}

int cargarDestinatarios(char* nombreArchivo, ArrayList* listaDestinatarios){
    FILE* fp;
    int returnAux= -1;
    char nombre[50]="";
    char mail[150]="";
    fp = fopen(nombreArchivo, "r");
    eDestinatario* unDestinatario;
    if(fp!=NULL){
        while(!feof(fp)){
            unDestinatario=(eDestinatario*)malloc(sizeof(eDestinatario));
            if(unDestinatario!=NULL){
                fscanf(fp, "%[^,],%[^\n]\n", nombre, mail);
                strcpy(unDestinatario->nombre,nombre);
                strcpy(unDestinatario->mail,mail);
                listaDestinatarios->add(listaDestinatarios, unDestinatario);
            }
        }
        returnAux = 0;
    }
    fclose(fp);
    return returnAux;
}

int cargarListaNegra(char* nombreArchivo, ArrayList* listaDestinatarios){
    FILE* fp;
    int returnAux= -1;
    char nombre[50]="";
    char mail[150]="";
    fp = fopen(nombreArchivo, "r");
    eDestinatario* unDestinatario;
    if(fp!=NULL){
        while(!feof(fp)){
            unDestinatario=(eDestinatario*)malloc(sizeof(eDestinatario));
            if(unDestinatario!=NULL){
                fscanf(fp, "%[^,],%[^\n]\n", nombre, mail);
                strcpy(unDestinatario->nombre,nombre);
                strcpy(unDestinatario->mail,mail);
                listaDestinatarios->add(listaDestinatarios, unDestinatario);
            }
        }
        returnAux = 0;
    }
    fclose(fp);
    return returnAux;
}

int depurar(ArrayList* listaDestinatarios, ArrayList* listaNegra, ArrayList* listaDepurada){
    int i, j;
    char nombre[50]="";
    char mail[150]="";
    eDestinatario* unDestinatario;

    for(i=0;i<listaDestinatarios->size;i++){
        for(j=0;j<listaNegra->size;j++){
            if(listaDestinatarios->pElements[i] == listaNegra->pElements[j]){
                unDestinatario=(eDestinatario*)malloc(sizeof(eDestinatario));
                strcpy(unDestinatario->nombre,nombre);
                strcpy(unDestinatario->mail,mail);
                listaDepurada->add(listaDepurada, unDestinatario);
            }
        }
    }
}
