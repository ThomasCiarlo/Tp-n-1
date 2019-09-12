#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int todoOk=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        option = menuOpciones();

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                todoOk=ll_isEmpty(listaEmpleados);
                if(todoOk == 0){
                controller_editEmployee(listaEmpleados);
                }else{
                    printf("\n\tSin empleados cargados no se puede acceder a esta opcion\n");
                    system("pause");
                }
                break;
            case 5:
                if(ll_isEmpty(listaEmpleados)==0){ // VERIFICAR QUE ALLA EMPLEADOS EN LA LISTA PARA ACCEDER A ESTAS OPERACIONES
                controller_removeEmployee(listaEmpleados);
                }else{
                    printf("\n\tSin empleados cargados no se puede acceder a esta opcion\n");
                    system("pause");
                }
            break;
            case 6:
                if(ll_isEmpty(listaEmpleados)==0){
                controller_ListEmployee(listaEmpleados);
                system("pause");
                }else{
                    printf("\n\tSin empleados cargados no se puede acceder a esta opcion\n");
                    system("pause");
                }
                break;
            case 7:
                if(ll_isEmpty(listaEmpleados)==0){
                controller_sortEmployee(listaEmpleados);
                system("pause");
                }else{
                    printf("\n\tSin empleados cargados no se puede acceder a esta opcion\n");
                    system("pause");
                }
                break;
            case 8:
                  controller_saveAsText("data.csv",listaEmpleados);
                  system("pause");
            break;
            case 9:
                  controller_saveAsBinary("data.bin",listaEmpleados);
                  system("pause");
            break;
            case 10:
            break;
            default:
                printf("\n\tOpcion Incorrecta");
                break;
        }
    }while(option != 10);
    return 0;
}
