#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    int cant;
    char buffer[4][30];


        while(!feof(pFile)){

        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);
        Employee* aux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(aux != NULL){
                ll_add(pArrayListEmployee,aux);
                todoOk=1;
            }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }
            }
          }
            if(todoOk==1){
                printf("\tSe cargaron todos los archivos\n\n");
                system("pause");
            }
            else{
                printf("No se pudo leer el archivo");

            }




    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int cant;

    while( !feof(pFile))
    {
        Employee* unEmpleado = employee_new();

        cant = fread(unEmpleado,sizeof(Employee), 1, pFile);

        if( unEmpleado != NULL)
        {
          ll_add(pArrayListEmployee,unEmpleado);
        }else{

            printf("Problemas para leer el archivo");
        }

        if(cant < 1){
            if(feof(pFile)){
                break;
            }else{
                free(unEmpleado);
            }

        }

    }


    return 1;
}
