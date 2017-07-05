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
#ifndef __EMPLOYEE
#define __EMPLOYEE

struct
{
    char tarea[20];
    int tipo;
    int prioridad;

}typedef pGeneral;

void menu(void);
void validarString(char stringAValid[], int maximo);
int validarDigitoRango(char* numero,int minimo,int maximo);
int cargarLista(ArrayList* listaParaCargar);
void depurarLista(ArrayList* listaGeneral, ArrayList* listaAlta, ArrayList* listaBaja);
void ordenarTiempo(ArrayList* lista);
#endif // __EMPLOYEE


