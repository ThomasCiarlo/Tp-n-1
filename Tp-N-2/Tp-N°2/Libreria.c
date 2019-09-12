#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.h"


int validarCararteres(char letra[]){
/** \ valida si lo que se ingresa en un char
 *
 * \ char letra[]
 * \ 1 en caso de que se alla ingresa caracteres
 *
 */
    for(int i=0; i<strlen(letra); i++)
    {
        while(!((letra[i]>=65 && letra[i]<=90) || (letra[i]>=97 && letra[i]<=127)))
        {

            printf("Solo ingrese letras: ");
            scanf("%s", letra);
            i=0;
        }

    }
    return 1;

}

int validarNumeroFloat(char num[]){

/** \ valida si lo que se ingresa en un float
 *
 * \ char numero[]
 * \ 1 en caso de que se alla ingresa numeros float
 *
 */

    for(int i=0; i<strlen(num); i++)
    {
        while(!(isdigit(num[i]) || num[i]=='.')){

            printf("\n\tIngrese Solo numeros: ");
            scanf("%s", num);
            i=0;

        }




    }

    return 1;

}

int validarNumero(char num[]){

/** \ valida si lo que se ingresa en un int
 *
 * \ char letra[]
 * \ 1 en caso de que se alla ingresa numeros
 *
 */

    for(int i=0; i<strlen(num); i++)
    {
        while(!(isdigit(num[i]))){

            printf("\n\tIngrese Solo numeros: ");
            scanf("%s", num);
            i=0;

        }


    }

    return 1;

}

int generarLegajo(eEmpleado empleado[],int tamEmpleado){

/** \ genera un legajo aleatorio
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 *
 * \ de vuelve un legajo creado a lazar
 *
 */

        int enteroIng;
        int x;

        srand(time(0));
        enteroIng= rand() % 8999 + 1000;

        x=usuarioRegistrado(empleado,enteroIng);

        while(x==1)
        {
            srand(time(0));
            enteroIng= rand() % 8999 + 1000;
        }
    return enteroIng;

}

int validarSueldo(float sueldo){

/** \ valida que el sueldo sea mayor a 0
 *
 * \ float sueldo
 * \ de vuelve 1 en caso de que el sueldo sea correcto
 *
 */

  while(sueldo<0)
        {
            printf("\t  Sueldo incorrecto intente de nuevo: ");
            scanf("%f", &sueldo);
        }

    return 1;

}

void initEmployees(eEmpleado empleado[],int tam){

/** \ pone el estado de los empleados en vacio
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 *
 * \  no retorna ningun valor
 *
 */

        for(int i=0; i<TAMEMPLEADO; i++)
    {
        empleado[i].estado=VACIO;
    }


}

void construirEmpleado(eEmpleado empleado[],int i,eSector sector[], int tamSectores){

/** \ le pide al usuario todos los datos para generar el empleado
 *
 * \ eEmpleado empleado[]
 * \ int i
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \ esta funcion no retorna nada
 *
 */


    char auxNombre[51];
    char auxApellido[51];
    char auxSueldo[40];
    float sueldo;
    int leg;
    int sec;
    int x;




    system("cls");

    printf("\t############### REGISTRAR EMPLEADO #############\n\n");

    //----------- GENERA Y MUESTRA EL LEGAJO---------//

    leg=generarLegajo(empleado,TAMEMPLEADO);

    printf("\n\t Legajo : %d \n", leg);

    //--------------- ASIGNACION DEL NOMBRE----------//

    printf("\n\t Ingrese el nombre del empleado: ");
    fflush(stdin);
    scanf("%s",auxNombre);

    x=validarCararteres(auxNombre);

    if(x==1){
        printf("\n\tNombre correcto\n");
    }

    //-------------ASIGNACION DEL APELLIDO----------//

    printf("\n\t Ingrese el Apellido del empleado: ");
    scanf("%s",auxApellido);

    x=validarCararteres(auxApellido);

    if(x==1){
        printf("\n\tApellido correcto\n");
    }

    //----------- INGRESO DEL SUELDO----------//
    printf("\n\t Ingrese el sueldo del empleado: ");
    fflush(stdin);
    scanf("%s",auxSueldo);

    x=validarNumeroFloat(auxSueldo);
    sueldo=atof(auxSueldo);

    if(x==1){
        printf("\n\tSueldo correcto\n");
    }

    //------------------- ASIGNACION DEL SECTOR----------//

    sec=AsignarSector();

    x=addEmployees(empleado,i,leg,auxNombre,auxApellido,sueldo,sec);

    if(x==1){
      printf("\n\t#Empleado cargado correctamente#\n");
      empleado[i].estado=OCUPADO;
    }


}

int addEmployees(eEmpleado empleado[],int tamEmpleado,int leg,char nombre[],char apellido[],float sueldo,int sector){

/** \ se le pasa por parametro todos los datos que van a construir al empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ int leg
 * \ char nombre[]
 * \ char apellido[]
 * \ float sueldo
 * \ int sector
 * \
 * \ la funcion retorna un 1 en caso de que todo se alla cargado correctamente
 *
 */

    empleado[tamEmpleado].legajo=leg;
    strcpy(empleado[tamEmpleado].nombre,nombre);
    strcpy(empleado[tamEmpleado].apellido,apellido);
    empleado[tamEmpleado].sueldo=sueldo;
    empleado[tamEmpleado].idSector=sector;


    return 1;

}

int crearEmpleado(eEmpleado empleado[], int tam,eSector sector[],int tamSectores){

/** \ en esta funcion se fija si hay un lugar para crear empleado y le pregunta si quiere seguir agregando
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 para poder acceder a las funciones de borrar y modificar empleado
 * La funcion dispone de una funcion que esta comentanda en el momento la cual ya le registra algunos empleados, para hacer la prueba!
 *
 */

    char seguir='s';
    int i;
    int empleadoCreado=0;

    do
    {

        i=buscarVacio(empleado,tam);

        if(i!=-1)
        {
            system("cls");

            printf("\n\t ********* Alta De Empleados ********\n\n");

            construirEmpleado(empleado,i,sector,TAMSECTORES);
            //hardCodear(empleado,TAMEMPLEADO);
            empleadoCreado=1;

        }

        else
        {

            printf("Ya no se puede agregar mas gente\n");
            break;

        }
        printf("\n\tDesea Seguir registrando S/N: ");
        fflush(stdin);
        scanf("%c", &seguir);

    }
    while(seguir=='s');

    return empleadoCreado;

}

int buscarVacio(eEmpleado empleado[],int tamEmpleado){

/** \ en esta funcion se busca algun estado en VACIO
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \
 * \
 * \ la funcion retorna el indice en donde se encontro ese lugar vacio
 *
 */
    int indice=-1;
    for(int i=0; i<tamEmpleado; i++)
    {

        if(empleado[i].estado==VACIO)
        {
            indice=i;
            break;
        }

    }

    return indice;

}

int buscarOcupado(eEmpleado empleado[],int tamEmpleado){

/** \ en esta funcion se busca algun estado en VACIO
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \
 * \
 * \ la funcion retorna el indice en donde se encontro ese lugar vacio
 *
 */
    int indice=-1;
    for(int i=0; i<tamEmpleado; i++)
    {

        if(empleado[i].estado==OCUPADO)
        {
            indice=i;
            break;
        }

    }

    return indice;

}


int usuarioRegistrado(eEmpleado nomina[],int leg){

/** \ en esta funcion se muestra el usuario ya registrado con ese legajo
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \
 * \
 * \ la funcion de vuelve 1 en caso de que se alla ejecutado correctamente
 *
 */


    int x;
    int contador=0;
    x=findEmployeeById(nomina,TAMEMPLEADO,leg);
    if(x>=0 && nomina[x].estado==OCUPADO)
    {
        contador++;
    }
    return contador;
}

int findEmployeeById(eEmpleado nomina[],int tamEmpleado, int modiLeg){

/** \ en esta funcion se busca un legajo pasado por parametro
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ int modileg
 * \
 * \
 * \
 * \
 * \ la funcion retorna el indice donde esta ese legajo
 *
 */

    int indice=-1;

    for(int i=0; i<TAMEMPLEADO; i++)
    {

        if(nomina[i].legajo==modiLeg)
        {

            indice=i;
            break;

        }

    }
    return indice;

}

//-------------------- FUNCIONES PARA MOSTRAR ------------------------------//


int printEmployees(eEmpleado empleado[], int tamEmpleado,eSector sector[],int tamSectores){

/** \ en la siguiente funcion se muestra toda la nomina de empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 en caso de que alla funcionado correctamente
 *
 */
    int contador=0;

    system("cls");

    printf("   \tLegajo \tNombre \tApellido    Sueldo    Sector \n");
    printf(" \t------- ------   -------    ------    ------\n\n");

    for(int i=0; i<tamEmpleado; i++)
    {

        if(empleado[i].estado==OCUPADO)
        {
            mostrarEmpleado(empleado[i],sector[empleado[i].idSector-1]);
            contador++;
        }
       }
     return contador;


}

void mostrarEmpleado(eEmpleado empleado,eSector sector){
    /** \ en esta funcion se muestra un solo empleado de la nomina
 *
 * \ eEmpleado empleado
 * \ int tamEmpleado
 * \ eSector sector
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion no retorna nada
 *
 */

    printf(" %10d %10s %10s %10.2f %10s \n\n",empleado.legajo,empleado.nombre,empleado.apellido,empleado.sueldo,sector.puesto);
}



//-------------------- BORRAR EMPLEADO --------------------//

int removeEmployee(eEmpleado empleado[],int tamEmpleado, int leg){

/** \ en esta funcion se elimina de forma logica al empleado que desea el usuario
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ int leg
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 en caso de que todo alla salido bien
 *
 */


    int contador=0;
    char opc;

    for(int i=0;i<tamEmpleado;i++){
        if(empleado[i].legajo==leg){
            printf("\t\n Usuario encontrado, esta seguro que desea eliminarlo S / N: ");
            fflush(stdin);
            scanf("%c",&opc);
            if(opc =='s'){
                empleado[i].estado=VACIO;
                contador++;
            }

        }
    }

    return contador;

}

void eliminarEmpleado(eEmpleado empleado[],int tamEmpleado){

/** \ este es el menu donde se va a eliminar el empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion no retorna nada
 */


    int x;
    int leg;


    system("cls");

    printf("\t############# ELIMINACION DE USUARIOS ##################\n\n");

    printf("\t Ingrese el legajo del empleado: ");
    fflush(stdin);
    scanf("%d",&leg);

    x=removeEmployee(empleado,tamEmpleado,leg);

    if(x==1){
        printf("\t\n Usuario eleminado correctamente\n\n");
    }
    else{
        printf("\t\n El usuario no se encontro\n\n");
    }

}

//------------------------- MODIFICACION DEL EMPLEADO ----------------//

int menuDeModificacion(eEmpleado empleado[], int tamEmpleado){
/** \ este es el menu de modificacion de empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 en caso de que se alla modificado correctamente
 *
 */


    int modiLeg;
    int i;
    char opc;
    int contador=0;

    system("cls");

    printf("\t############ MENU DE MODIFICACION #############\n\n");

    printf("\tIngrese el legajo del empleado: ");
    scanf("%d", &modiLeg);

    i=findEmployeeById(empleado,tamEmpleado,modiLeg);
    fflush(stdin);

    if(empleado[i].estado==OCUPADO)
    {

        printf("\n\n\tUsuario encontrado que desea modificar \n");
        printf("\t\ta) Sueldo \n");
        printf("\t\tb) Nombre\n");
        printf("\t\tc) Apellido\n");
        printf("\t\td) Sector\n");
        printf("\t\te) Atras\n");
        printf("\n\tEliga la opcion que desea: ");
        scanf("%c", &opc);

        switch(opc)
        {
        case 'a':
            contador=modiSueldo(empleado,i);
            break;
        case 'b':
            contador=modiNombre(empleado,i);
            break;
        case 'c':
            contador=modiApellido(empleado,i);
            break;
        case 'd':
            contador=modiSector(empleado,i);
            break;
        case 'e':
            contador++;
            break;

        }

    }
    return contador;

}
int modiSueldo(eEmpleado empleado[],int i){

/** \ en esta funcion se modifica el sueldo
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 en caso de que todo alla salido correctamente
 *
 */

    float sueldoNuevo;
    char sueldo[51];
    int x;

    printf("\n\tIngrese el nuevo sueldo del empleado: ");
    fflush(stdin);
    scanf("%s", sueldo);

    x=validarNumeroFloat(sueldo);
    sueldoNuevo=atof(sueldo);

    if(x==1){
        empleado[i].sueldo=sueldoNuevo;
        printf("\tSueldo modificado\n\n");
        Sleep(1000);

    }
    return x;





}
int modiNombre(eEmpleado empleado[],int i){
/** \ en esta funcion se fija se modifica el nombre del empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 si todo salio bien
 *
 */
    char nombreNuevo[20];
    int x;

    printf("\n\tIngrese el nuevo Nombre del empleado: ");
    fflush(stdin);
    scanf("%s", nombreNuevo);

    x=validarCararteres(nombreNuevo);

    if(x==1)
    {
        while(strlen(nombreNuevo)>51)
        {
            printf("\tNombre incorrecto intente de nuevo: ");
            scanf("%s", nombreNuevo);
        }
    }

    strcpy(empleado[i].nombre,nombreNuevo);

    printf("\tNombre modificado\n\n");
    Sleep(1000);
    return x;


}

int modiApellido(eEmpleado empleado[],int i){
/** \ en esta funcion modifica el apellido del empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 si todo salio bien
 *
 */

    char apellidoNuevo[20];
    int x;

    printf("\n\tIngrese el nuevo Apellido del empleado: ");
    fflush(stdin);
    scanf("%s", apellidoNuevo);

    x=validarCararteres(apellidoNuevo);

    if(x==1)
    {
        while(strlen(apellidoNuevo)>51)
        {
            printf("\tApellido incorrecto intente de nuevo: ");
            scanf("%s", apellidoNuevo);
        }
    }

    strcpy(empleado[i].apellido,apellidoNuevo);

    printf("\tApellido modificado\n\n");
    Sleep(1000);
    return x;


}

int modiSector(eEmpleado empleado[], int tamEmpleado){
/** \ en esta funcion se modifica el sector del empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 si todo salio bien
 *
 */
 int x;

  x=AsignarSector();

 empleado[tamEmpleado].idSector=x;

 return 1;


}

//----------- SECTORES ---------------------------//

int hardCodearSector(eSector nomina[],int tam){
/** \ en esta funcion se cargan los sectores
 *
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 para que se active el alta de empleados
 *
 */
    int contador=0;

    eSector sector[12]=
    {
        {1,"Sistemas"},
        {2,"RRHH"},
        {3,"Ventas"},
        {4,"Legales"},
        {5,"Sin Definir"}


    };

    for(int i=0; i<tam; i++)
    {
        nomina[i]=sector[i];
    }

    contador=1;

    return contador;


}


int AsignarSector(){
/** \ en esta funcion se va asignar el sector al empleado
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \
 * \
 * \
 * \
 * \ la funcion retorna el id del sector seleccionado
 *
 */


    int opciones;
    int validador=0;

    system("cls");

    printf("\t############# CARGUE EL PUESTO DEL EMPLEADO ###########\n\n");

    printf("1. Sistemas\n");
    printf("2. RRHH\n");
    printf("3. Ventas\n");
    printf("4. Legales\n ");

    printf("Ingrese El sector al que pertenece: ");
    scanf("%d",&opciones);

    switch(opciones){
    case 1:
       validador=1;
       break;
    case 2:
       validador=2;
       break;
    case 3:
       validador=3;
       break;
    case 4:
        validador=4;
       break;
    default:
        printf("Opcion incorrecta, sector sin definir");
        validador=5;
        break;

    }

    return validador;
}


//---------------- CONSULTAS ---------------//


int totalYPromedioSueldosPorSector(eEmpleado empleado[],int tamEmpleado,eSector sector[], int tamSector){

/** \ en esta funcion se  muestra el total de sueldos por sector, el promedio y los user que superan este sueldo
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion de vuelve uno en caso de que funcione correctamente
 *
 */


    float acumulador;
    float promedio;
    int contadorPromedio;
    int contador=0;
    int flag=0;


    for(int i=0;i<tamSector-1;i++){

            acumulador=0;
            contador=0;
            promedio=0;
            contadorPromedio=0;
            printf("\n%s :\n",sector[i].puesto);

        for(int j=0;j<tamEmpleado;j++){
            if(empleado[j].idSector == sector[i].id && empleado[j].estado == OCUPADO){

                contador++;
                acumulador += empleado[j].sueldo;
                promedio = acumulador/contador;
                flag=1;

                }
            }

            for(int k=0;k<tamEmpleado;k++){
                if(empleado[k].idSector==sector[i].id && empleado[k].sueldo>=promedio && empleado[k].estado==OCUPADO){
                    contadorPromedio++;
                }
            }
            printf("\tEl total de sueldos del sector es: %.2f y el promedio es: %.2f, los empleados que superan este sueldo son: %d\n\n",acumulador,promedio,contadorPromedio);

        }

        return flag;

}

int sortEmployees(eEmpleado empleado[],int tamEmpleado,eSector sector[],int tamSector){
/** \ en esta funcion se ordenan de manera alfabeticamente los empleados, y por sector, de menor a mayor o de mayor a menor
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion retorna un 1 en caso de que todo alla funcionado bien
 *
 */
    int flag=0;
    int opc;
    eEmpleado empleadoAux;

    printf("\n\t1. De menor a mayor\n\t2. De mayor a menor\n\t Elejir: ");
    scanf("%d",&opc);

    if(opc==1){

    for(int i=0;i<tamEmpleado-1;i++){
        for(int j=i+1;j<tamEmpleado;j++){
            if(empleado[i].idSector > empleado[j].idSector && empleado[i].estado==OCUPADO && empleado[j].estado==OCUPADO){
                empleadoAux=empleado[j];
                empleado[j]=empleado[i];
                empleado[i]=empleadoAux;
                flag=1;
            }
            else if(empleado[i].idSector==empleado[j].idSector && empleado[i].estado==OCUPADO && empleado[j].estado==OCUPADO && (stricmp(empleado[j].apellido,empleado[i].apellido)==-1)){
                empleadoAux=empleado[j];
                empleado[j]=empleado[i];
                empleado[i]=empleadoAux;
                flag=1;
            }
        }
     }
    }

      else if(opc==2){
            for(int i=0;i<tamEmpleado-1;i++){
                for(int j=i+1;j<tamEmpleado;j++){
                    if(empleado[i].idSector < empleado[j].idSector && empleado[i].estado==OCUPADO && empleado[j].estado==OCUPADO){
                    empleadoAux=empleado[j];
                    empleado[j]=empleado[i];
                    empleado[i]=empleadoAux;
                    flag=1;
                    }
                    else if(empleado[i].idSector==empleado[j].idSector && empleado[i].estado==OCUPADO && empleado[j].estado==OCUPADO && (stricmp(empleado[j].apellido,empleado[i].apellido)==1)){
                    empleadoAux=empleado[j];
                    empleado[j]=empleado[i];
                    empleado[i]=empleadoAux;
                    flag=1;
                    }
                }
            }
         }
         else{
            printf("\n\tOpcion Incorrecta...\n");
            flag=1;
         }


    return flag;

}

void menuConsultas(eEmpleado empleado[],int tamEmpleado,eSector sector[], int tamSector){

/** \ en esta funcion se genera el menu de consultas
 *
 * \ eEmpleado empleado[]
 * \ int tamEmpleado
 * \ eSector sector[]
 * \ int tamSectores
 * \
 * \
 * \
 * \
 * \ la funcion no retorna nada
 *
 */


    int opc;
    int x;

    system("cls");

    printf("########### MENU DE CONSULTAS ##############\n\n");


    printf("\t 1. sueldos, promedios y User que superan el promedio\n\t 2. Empleados ordenados alfabeticamente\n\t 3. Atras\n\n ");
    printf("Ingrese la opciones que desea: ");
    fflush(stdin);
    scanf("%d",&opc);

    switch(opc){
    case 1:
        x=totalYPromedioSueldosPorSector(empleado,tamEmpleado,sector,tamSector);
        if(x==0){
            printf("\n\tfaltaron registrar empleados o algo fallo en el sistema\n");
        }
        break;
    case 2:
        x=sortEmployees(empleado,TAMEMPLEADO,sector,tamSector);
        if(x==1){
        printEmployees(empleado,TAMEMPLEADO,sector,TAMSECTORES);
        }else{
            printf("\t\nNo hay usuarios registrados o se registro algun error\n\n");
        }
        break;
    case 3:
        break;
    default:
        printf("\n\tOpcion incorrecta\n\n");
        Sleep(500);
    }


}

//---------------------------- HARDCODEAR -------------------//

void hardCodear(eEmpleado nomina[],int tamEmpleado){

    eEmpleado empleado[]=
    {
        {1234,"thomas","Ciarlo",25000,1,1},
        {1235,"ana","lopes",25000,2,1},
        {1236,"juan","coria",25000,3,1},
        {1237,"jorge","gomez",27000,2,1},
        {1238,"Eve","ibarra",12000,4,1},
        {1239,"daniel","Lucero",23000,1,1},
        {1231,"martin","corta",17000,2,1},
        {1232,"bruno","lopes",15000,3,1},
        {1233,"sofia","seminario",15000,4,1},
        {1240,"emma","ciarlo",16000,1,1},
        {1211,"agus","copes",29000,2,1},
        {1227,"franco","fernandez",35000,3,1},
        {1222,"gaby","nieva",120000,4,1}

    };
    for(int i=0; i<tamEmpleado; i++)
    {
        nomina[i]=empleado[i];
    }


}

void cargando(){

    //simula un barra de carga al iniciar el programa como parte grafica de la app

    printf("\t###### SISTEMA DE ALTA, BAJA Y MODIFICACION DE USUARIOS#####\n\n\n");


    printf("\n\t\t Cargando: ---");
    Sleep(200);
    printf("---");
    Sleep(200);
    printf("---");
    Sleep(200);
    printf("---");
    Sleep(200);
    printf("---");
    Sleep(200);
    printf("---");
    Sleep(200);
    printf("---");
    Sleep(200);
    printf("---");
    Sleep(200);


}


