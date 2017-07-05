/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS 5

#include "../inc/ArrayList.h"
#include "../inc/Employee.h"
int opc;

int main(void)
{
    ArrayList* listaGeneral = al_newArrayList();
    ArrayList* listaAlta = al_newArrayList();
    ArrayList* listaBaja = al_newArrayList();


    do{
        menu();
        printf("Opcion: ");
        scanf("%d", &opc);

        switch(opc){
    case 1:
        if(cargarLista(listaGeneral) == 0){
            printf("Cargado correctamente\n");
        }else{
            printf("Hubo un error\n");
        }
        break;
    case 2:
        depurarLista(listaGeneral, listaAlta, listaBaja);
        break;
    case 3:
        /*ordenarListas(listaAlta);
        ordenarListas(listaBaja);*/
        break;
    case 4:
        break;
    case 5:
        guardarListas(listaAlta, listaBaja);
        break;
    case 6:
        break;
        }

    }while(opc!=6);

    system("PAUSE");
    return 0;
}
















