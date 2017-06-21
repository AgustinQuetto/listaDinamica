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

#include "../inc/ArrayList.h"
#include "../inc/Employee.h"

int main(void)
{
    int opc;

    ArrayList* listaDestinatarios = al_newArrayList(); //creo array dinamicos de cada lista
    ArrayList* listaNegra = al_newArrayList(); //creo array dinamicos de cada lista
    ArrayList* listaDepurada = al_newArrayList(); //creo array dinamicos de cada lista

    do{
        printf("1. CARGAR DESTINATARIOS\n2. CARGAR LISTA NEGRA\n3. DEPURAR\n4. LISTAR\n5. SALIR\nOpcion: ");
        scanf("%d",&opc);

        switch(opc){
            case 1:
                if(cargarDestinatarios("destinatarios.csv", listaDestinatarios) == 0){
                    printf("\nLa lista ha sido cargada.\n");
                }else{
                    printf("\nNo se ha podido cargar.\n");
                }
                break;
            case 2:
                if(cargarListaNegra("black_list.csv", listaNegra) == 0){
                    printf("\nLa lista ha sido cargada.\n");
                }else{
                    printf("\nNo se ha podido cargar.\n");
                }
                break;
            case 3:
                //filtran los destinatarios que no figuren en la lista negra
                depurar(listaDestinatarios, listaNegra, listaDepurada);
                break;
            case 4:
                //muestra la lista depurada
                listarDestinatarios(listaDepurada);
                break;
            case 5:
                exit(1);
            break;
            }
    }while(opc!=5);


    return 0;
}
