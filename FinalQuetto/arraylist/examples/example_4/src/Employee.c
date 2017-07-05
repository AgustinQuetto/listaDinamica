#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"
void menu(void)
{
    printf("1- Cargar lista de tareas\n2- Particionar por prioridad\n3- Ordenar\n4- Resolver tareas\n5- Generar\n");
    printf("6- SALIR\n");
}




//VALIDACIONES
void validarString(char stringAValid[], int maximo)
{
    int largo=strlen(stringAValid);
    while(largo>maximo)
    {
        printf("Se excedio del tamano reingrese: ");
        stringAValid=gets(stringAValid);
        largo=strlen(stringAValid);
    }
}

int validarDigitoRango(char* numero,int minimo,int maximo)
{
    int i;
    int largo=strlen(numero);
    int flag;
    int numCheck;
    do
    {
        do
        {
            flag=0;
            for(i=0; i<largo; i++)
            {
                if(!isdigit(numero[i]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=0)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
            numCheck=atoi(numero);
            if(numCheck<minimo || numCheck>maximo)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
        }
        while(flag!=0);
    }
    while(numCheck<minimo || numCheck>maximo);
    return numCheck;
}
//FIN DE VALIDACIONES




int cargarLista(ArrayList* listaParaCargar)
{
    FILE *fp;
    int returnAux=-1;
    char tarea[20]=""; //variables dentro del csv
    char tipo[2];
    char prioridad[2]; //variables dentro del csv
    fp = fopen("tareas.csv","r");
    pGeneral* unaGeneral; //puntero a estructira
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unaGeneral=(pGeneral*)malloc(sizeof(pGeneral)); //casteo al tipo de dato
            if(unaGeneral!=NULL) //chequeo si el archivo pudo ser abierto
            {
                fscanf(fp,"%[^,],%[^,],%[^\n]\n",tarea, tipo, prioridad);

                strcpy(unaGeneral->tarea,tarea);
                unaGeneral->tipo = atoi(tipo);
                unaGeneral->prioridad = atoi(prioridad);

                listaParaCargar->add(listaParaCargar,unaGeneral);
            }
        }
        returnAux=0;
    }
    fclose(fp);
    return returnAux;
}

void depurarLista(ArrayList* listaGeneral, ArrayList* listaAlta, ArrayList* listaBaja)
{
    int i;
    pGeneral* unaGeneral;
    for(i=0; i<(listaGeneral->len(listaGeneral)); i++)
    {
        unaGeneral=listaGeneral->get(listaGeneral,i);
        if(unaGeneral->tipo == 0)
        {
            listaBaja->add(listaBaja, unaGeneral);
            printf("ok");
        }
        if(unaGeneral->tipo == 1)
        {
            listaAlta->add(listaAlta,listaGeneral);
            printf("ok2");
        }
    }
}

/*void ordenarTiempo(ArrayList* listaGeneral, ArrayList* listaBaja, ArrayList* listaAlta)
{
    listaGeneral->sort(listaGeneral, )
}*/

void guardarListas(ArrayList* listaAlta, ArrayList* listaBaja)
{
    FILE* f;
    FILE* p;
    int i;
    pGeneral* unaLista;
    f=fopen("pAlta.csv", "w");
    if(f==NULL)
    {
        printf("No se pudo crear alta");
        exit(1);
    }
    for(i=0; i=listaAlta->len(listaAlta); i++)
    {
        unaLista=listaAlta->get(listaAlta, i);
        fprintf(f, "%s,%d,%d\n", unaLista->tarea, unaLista->tipo, unaLista->prioridad);
    }
    fclose(f);

    p=fopen("pBaja.csv", "w");
    if(f==NULL)
    {
        printf("No se pudo crear baja");
        exit(1);
    }
    for(i=0; i=listaBaja->len(listaBaja); i++)
    {
        unaLista=listaBaja->get(listaBaja, i);
        fprintf(f, "%s,%d,%d\n", unaLista->tarea, unaLista->tipo, unaLista->prioridad);
    }
    fclose(f);
}
