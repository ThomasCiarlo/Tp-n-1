#include <stdio.h>
#include <stdlib.h>
#include "Libreria.h"


int main()
{
    int opcion;
    int x;
    int sectoresInicializados=0;
    int empleadoCreado;

    eEmpleado empleado[TAMEMPLEADO];
    initEmployees(empleado,TAMEMPLEADO);

    eSector sector[TAMSECTORES];

    cargando();


    do{

     system("cls");

        printf("\t~~~~~~~~~~~~~~~~~ Menu Del Administrador ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

        printf("\t    1. Alta del empleado \n\n\t    2. Mostrar Empleados\n\n\t    3. Baja De Empleado\n\n\t    4. Modificar Empleado\n\n\t    5. Cargar Sectores\n\n\t    6. Menu de consultas\n\n\t    7. Salir\n\n\t    Elejir: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            if(sectoresInicializados==1){
            crearEmpleado(empleado,TAMEMPLEADO,sector,TAMSECTORES);
            }
            else{
                printf("\n\t**Primero cargue los sectores**");
            }
            Sleep(1000);
            break;
        case 2:
            empleadoCreado=buscarOcupado(empleado,TAMEMPLEADO);
            if(empleadoCreado!=-1){
                x=printEmployees(empleado,TAMEMPLEADO,sector,TAMSECTORES);
                if(x==0){
                printf("\tNo hay usuarios registrados\n");
                }
            }
            else{
                printf("\n\tNo hay usuarios registrados\n");
            }
            system("pause");
            break;
        case 3:
            empleadoCreado=buscarOcupado(empleado,TAMEMPLEADO);
            if(empleadoCreado!=-1){
            eliminarEmpleado(empleado,TAMEMPLEADO);
            }
            else{
                printf("\n\tPrimero registre algun empleado\n");
            }
            system("pause");
            break;
        case 4:
            empleadoCreado=buscarOcupado(empleado,TAMEMPLEADO);
            if(empleadoCreado!=-1){
            x=menuDeModificacion(empleado,TAMEMPLEADO);
                if(x==1){
                    printf("\tModificacion correcta\n\n");
                }
            }

            else{
                printf("Primero registre un empleado\n");
            }
            system("pause");
            break;
        case 5:
            sectoresInicializados=hardCodearSector(sector,TAMSECTORES);
            printf("\n\n\tSectores cargados correctamente\n\n");
            system("pause");
            break;
        case 6:
            empleadoCreado=buscarOcupado(empleado,TAMEMPLEADO);
            if(empleadoCreado!=-1){
            menuConsultas(empleado,TAMEMPLEADO,sector,TAMSECTORES);
            }else{
                printf("Primero registre algun empleado\n");
            }
            system("pause");
            break;
        }
    }while(opcion!=7);



    return 0;
}



