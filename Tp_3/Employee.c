#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "validation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/** \ VALIDA EL CAMPO ID
 *
 * \ Employee* this
 * \ int* ID
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_setId(Employee* this,int id)
{

    int todoOk=0;

    if(this != NULL && id > 0)
    {

        this->id = id;
        todoOk=1;

    }

    return todoOk;
}









/** \ LLENA EL CAMPO ID
 *
 * \ Employee* this
 * \ int* ID
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_getId(Employee* this,int* id)
{

    int todoOk=0;

    if(this != NULL && id != NULL)
    {

        *id = this->id;
        todoOk=1;

    }

    return todoOk;





}

/** \ VALIDA EL NOMBRE PASADO POR PARAMETRO
 *
 * \ Employee* this
 * \ int* NOMBRE
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk=0;


    if(this != NULL && nombre !=NULL && strlen(nombre) > 1 )
    {

        strcpy(this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;

}

/** \ LLENA EL CAMPO NOMBRE
 *
 * \ Employee* this
 * \ int* NOMRBE
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk=0;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk=1;
    }



    return todoOk;

}


/** \ LLENA LAS HORAS SI SON CORRECTAS
 *
 * \ Employee* this
 * \ int* HORASTRABAJADAS
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk=0;

    if(this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk=1;

    }

    return todoOk;


}



/** \ LLENA EL CAMPO HORAS
 *
 * \ Employee* this
 * \ int* HORAS
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{


    int todoOk=0;

    if(this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;

    }

    return todoOk;


}


/** \ VALIDA QUE EL SUELDO INGRESADO SEA CORRECTO
 *
 * \ Employee* this
 * \ int* sueldo
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_setSueldo(Employee* this,int sueldo){


    int todoOk=0;

    if(this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        todoOk=1;

    }

    return todoOk;


}

/** \ LLENA EL CAMPO SUELDO
 *
 * \ Employee* this
 * \ int* sueldo
 * \ RETORNA 1 SI TODO SALIO BIEN
 *
 */
int employee_getSueldo(Employee* this,int* sueldo){



    int todoOk=0;

    if(this != NULL && sueldo != NULL)
    {

        *sueldo = this->sueldo;
        todoOk=1;

    }

    return todoOk;






}

/** \ INICIALIZA UN EMPLEADO EN CON TODOS LOS CAMPOS EN 0 Y NULL
 *
 * \ RETORNA THIS
 *
 */
Employee* employee_new()
{


    Employee* this = (Employee*) malloc(sizeof(Employee));


    if(this!=NULL)
    {
        this->id = 0;
        this->horasTrabajadas = 0;
        this->sueldo= 0;
        strcpy(this->nombre,"");
    }

    return this;

}


/** \ CREA UN EMPLEADO SI LOS DATOS PASADOS POR PARAMETRO SON CORRECTOS
 *
 * \ char* idStr
 * \ char* nombreStr
 * \ char* horasTrabajadasStr
 * \ char* sueldoStr
 * \ RETORNA THIS
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    int validation = 0;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new();

        if(employee_setId(this, atoi(idStr)) && employee_setNombre(this,nombreStr) && employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) && employee_setSueldo(this,atoi(sueldoStr)))
        {
          validation = 1;
        }

        if(validation == 0)
        {
            free(this);
            this = NULL;
        }


    }


    return this;


}


/** \ MUESTRA UN EMPLEADO DE LA LISTA
 *
 * \ Employee* emp
 * \ RETORNA VOID
 *
 */
void mostrarEmployee(Employee* emp){

    printf("\n\t%9d %8s %8d %8d \n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);

}

/** \ ORDENA EL SUELDO DE MENOR A MAYOR O DE MAYOR A MENOR
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA 1 EN CASO
 *
 */
int ordenarXsueldo(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if(p1->sueldo > p2->sueldo){
                retorno = 1;
            }

            else if(p1->sueldo < p2->sueldo){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;




}

/** \ ORDENA LOS ID DE MENOR A MAYOR O DE MAYOR A MENOR
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA 1 EN CASO
 *
 */
int OrdenarXId(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if(p1->id > p2->id){
                retorno = 1;
            }

            else if(p1->id < p2->id){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;

}


/** \ ORDENA LAS HORAS DE MENOR A MAYOR O DE MAYOR A MENOR
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA 1 EN CASO
 *
 */
int OrdenarXHoras(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if(p1->horasTrabajadas > p2->horasTrabajadas){
                retorno = 1;
            }

            else if(p1->horasTrabajadas < p2->horasTrabajadas){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;

}


int menuOpcionesOrdenar(){

    int opc;

    printf("\t################### MENU DE ORDENAMIENTO ##################\n\n");

    printf("\t1.Ordenar por sueldo\n");
    printf("\t2.Ordenar por id\n");
    printf("\t3.Odenar por nombre\n");
    printf("\t4.Ordenar por Horas\n");
    printf("Selecciones la opcion: ");
    scanf("%d",&opc);

    return opc;

}


/** \ MENU DE ORDENAR DE MENOR A MAYOR
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA VOID
 *
 */
void ordenarMenor(LinkedList* pArrayListEmployee){

    system("cls");


    switch(menuOpcionesOrdenar()){
    case 1:
        ll_sort(pArrayListEmployee,ordenarXsueldo,1);
        break;
    case 2:
        ll_sort(pArrayListEmployee,OrdenarXId,1);
        break;
    case 3:
        ll_sort(pArrayListEmployee,ordenarNombre,1);
        break;
    case 4:
        ll_sort(pArrayListEmployee,OrdenarXHoras,1);
        break;
    default:
        printf("opcion incorrecta");
        break;
    }

}


/** \ ORDENA LOS NOMBRE, ALFABETICAMENTE
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA 1 EN CASO DE QUE TODO ALLA SALIDO BIEN
 *
 */
int ordenarNombre(void* emp1,void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if((strcmp(p1->nombre,p2->nombre)==1)){
                retorno = 1;
            }

            else if((strcmp(p1->nombre,p2->nombre)!=1)){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;




}


/** \ ORDENA DE MAYOR A MENOR
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA VOID
 *
 */
void ordenarMayor(LinkedList* pArrayListEmployee){

    system("cls");


    switch(menuOpcionesOrdenar()){
    case 1:
        ll_sort(pArrayListEmployee,ordenarXsueldo,0);
        break;
    case 2:
        ll_sort(pArrayListEmployee,OrdenarXId,0);
        break;
    case 3:
        ll_sort(pArrayListEmployee,ordenarNombre,0);
        break;
    case 4:
        ll_sort(pArrayListEmployee,OrdenarXHoras,0);
        break;
    default:
        printf("opcion incorrecta");
        break;
    }

}



int menuOpciones(){

    int opc;

    printf("\t################### MENU DE OPCIONES ##################\n\n");

    printf("1. Cargar los datos de los empleados desde el archivo data.csv\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin.\n");
    printf("10. Salir\n");
    printf("Selecciones la opcion: ");
    scanf("%d",&opc);

    return opc;

}



/** \ DA DE ALTA UN EMPLEADO
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA 1 EN CASO DE QUE TODO ALLA SALIDO BIEN
 *
 */
int AltaEmpleado(LinkedList* pArrayListEmployee){

    char idAux[30];
    char auxNombre[30];
    char auxHoras[30];
    char auxSuledo[30];
    int id;
    int todoOk;
    Employee* emp;


    system("cls");

    printf("\t######### ALTA DE EMPLEADO ##########\n\n");

    id = incremetarID(pArrayListEmployee,1);
    sprintf(idAux, "%d", id);
    printf("\n\tEl id: %s ",idAux);


    printf("\n\tIngrese el nombre: ");
    fflush(stdin);
    gets(auxNombre);
    validarCararteres(auxNombre);

    printf("\n\tIngrese las horas trabajadas: ");
    fflush(stdin);
    gets(auxHoras);
    validarNumero(auxHoras);

    printf("\n\tIngrese el sueldo: ");
    fflush(stdin);
    gets(auxSuledo);
    validarNumero(auxSuledo);

    emp = employee_newParametros(idAux,auxNombre,auxHoras,auxSuledo);

    if(emp != NULL){
        ll_add(pArrayListEmployee,emp);
        todoOk=1;
    }

    return todoOk;

}

/** \ ELIMINA EL EMPLEADO
 *
 * \ LinkedList* pArrayListEmployee
 * \ RETORNA 1 EN CASO DE QUE TODO ALLA SALIDO BIEN
 *
 */
int eliminarEmpleado(LinkedList* pArrayListEmployee){

    int idAux;
    int indice;
    int todoOk=0;

    system("cls");
    printf("\t######### ELIMINACION DE USUARIO ###########\n");

    printf("\tIngrese el id del empleado que desea eliminar: ");
    fflush(stdin);
    scanf("%d",&idAux);

    indice = searchId(pArrayListEmployee,idAux);

    if(indice != -1){
        char opc;
        printf("\tEmpleado encontrado esta seguro de desea eliminarlo S/N \n\n");
        mostrarEmployee((Employee*)ll_get(pArrayListEmployee,indice));
        printf("\n\tElejir: ");
        fflush(stdin);
        scanf("%s",&opc);
            if(opc == 's'){
                ll_remove(pArrayListEmployee,indice);
            }
            todoOk=1;
    }
    else{
        printf("\tEl usuario no se encontro\n");
        system("pause");
    }

    return todoOk;


}

void mostrarEmplees(LinkedList* pArrayListEmployee){

    int opc;
    int num;
    system("cls");

    printf("\t##### LISTADO DE EMPLEADOS #########\n\n");

    printf("\t1. Mostrar Todos los empleados\n");
    printf("\t2. Mostrar un numero seleccionado por el User\n");
    printf("\tSeleccione la opcion que desea: ");
    fflush(stdin);
    scanf("%d",&opc);

    if(opc == 2)
    {
        printf("\tIndique el numero de user a mostrar: ");
        fflush(stdin);
        scanf("%d",&num);

        num=num-1;
        printf("\n\t\tID  NOMBRE   HORAS   SUELDO\n\n");
        for(int i = 0; i <= num; i++)
        {
            mostrarEmployee((Employee*)ll_get(pArrayListEmployee,i));
        }
    }
    else
    {
        printf("\n\t\tID  NOMBRE HORAS SUELDO");
        for(int i= 0; i<=ll_len(pArrayListEmployee); i++)
        {
            mostrarEmployee((Employee*)ll_get(pArrayListEmployee,i));
        }
    }


}


/** \ MENU DE MODIFICACIONES
 *
 * \ LinkedList* pArrayListEmployee
 * \ int INDICE
 * \ VOID
 *
 */
void menuDeModificaciones(LinkedList* pArrayListEmployee,int indice)
{
    // ESTE ES EL MENU DE MODIFICACIONES

    int opc;
    int todoOk=0;

    printf("\t1.Modificar Horas trabajadas\n");
    printf("\t2.Modificar sueldo \n");
    printf("\tSeleccione la opcion que desea: ");
    fflush(stdin);
    scanf("%d",&opc);

    switch(opc)
    {
    case 1:
        todoOk = modificarHorasTrabajadas(pArrayListEmployee,indice);
        if(todoOk==1)
        {
            printf("\tModificacion exitosa\n");
        }
        else
        {
            printf("No se pudo actualizar correctamente");
        }
        break;
    case 2:
        todoOk = modificarSueldo(pArrayListEmployee,indice);
        if(todoOk==1)
        {
            printf("\tModificacion exitosa\n");
        }
        else
        {
            printf("No se pudo actualizar correctamente");
        }
        break;
    default:
        printf("\tOpcion incorrecta\n");
        break;
    }

}

/** \ MODIFICA LAS HORAS TRABAJAS
 *
 * \ LinkedList* pArrayListEmployee
 * \ int indice
 * \ RETORNA 1 SI TODO SALIO BIEN SI NO RETORNA 0
 *
 */
int modificarHorasTrabajadas(LinkedList* pArrayListEmployee, int indice)
{
    // MODIFICA LA HORAS TRABAJADAS
    int horasAux;
    int todoOk=0;
    Employee* emp;

    emp = ll_get(pArrayListEmployee,indice);

    printf("\n\t## MODIFICAR HORAS TRABAJADAS ##\n");
    printf("\tseleccione el nuevo monto de horas trabajdas: ");
    fflush(stdin);
    scanf("%d",&horasAux);

    if(horasAux > 0)
    {
        emp->horasTrabajadas=horasAux;
        todoOk=1;
    }
    else
    {
        printf("No se pudo actualizar le monto de horas");
    }



    return todoOk;

}


/** \ MODIFICA EL SUELDO
 *
 * \ LinkedList* pArrayListEmployee
 * \ int indice
 * \ RETORNA 1 SI TODO SALIO BIEN SI NO RETORNA 0
 *
 */
int modificarSueldo(LinkedList* pArrayListEmployee, int indice)
{

    int sueldoAux;
    int todoOk=0;
    Employee* emp;

    emp = ll_get(pArrayListEmployee,indice);

    printf("\n\t## MODIFICAR SUELDO EMPLEADO ##\n");
    printf("\tseleccione el nuevo sueldo del empleado: ");
    fflush(stdin);
    scanf("%d",&sueldoAux);

    if(sueldoAux > 0)
    {
        emp->sueldo=sueldoAux;
        todoOk=1;
    }
    else
    {
        printf("No se pudo actualizar le monto de horas");
    }



    return todoOk;

}

/** \ BUSCA EL ID
 *
 * \ LinkedList* pArrayListEmployee
 * \ int IDAUX
 * \ RETORNA EL INDICE SI TODO SALIO BIEN SI NO RETORNA -1
 *
 */
int searchId(LinkedList* pArrayListEmployee,int idAux){

    Employee* empAux;
    int indice = -1;

    for(int i=0;i<ll_len(pArrayListEmployee);i++){
        empAux = ll_get(pArrayListEmployee,i);
        if(empAux->id == idAux){
            indice=i;
        }
    }

    return indice;

}

/** \ INCREMETA EL ID Y BUSCA QUE NO ESTE REPETIDO
 *
 * \ LinkedList* pArrayListEmployee
 * \ int DESDE
 * \ RETORNA EL ID CREADO
 *
 */
int incremetarID(LinkedList* pArrayListEmployee,int desde){

    int idAnterior=desde;
    int x;

    x=searchId(pArrayListEmployee,idAnterior);

    while(x!=-1){
        idAnterior+=1;
        x=searchId(pArrayListEmployee,idAnterior);
    }

    return idAnterior;


}



