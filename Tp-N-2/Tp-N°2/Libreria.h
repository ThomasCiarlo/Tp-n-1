#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#define VACIO 0
#define OCUPADO 1
#define TAMEMPLEADO 14
#define TAMSECTORES 5


typedef struct
{
    int id;
    char puesto[20];

}eSector;


typedef struct
{
 int legajo;
 char nombre[51];
 char apellido[51];
 float sueldo;
 int idSector;
 int estado;


}eEmpleado;


int validarCararteres(char letra[]);
int validarNumero(char num[]);
int validarNumeroFloat(char num[]);
int validarSexo(char sexo);
int buscarVacio(eEmpleado empleado[],int tamEmpleado);
int buscarOcupado(eEmpleado empleado[],int tamEmpleado);
int generarLegajo(eEmpleado empleado[],int tamEmpleado);
int findEmployeeById(eEmpleado nomina[],int tamEmpleado, int modiLeg);
int usuarioRegistrado(eEmpleado nomina[],int leg);
int removeEmployee(eEmpleado empleado[],int tamEmpleado, int leg);
int printEmployees(eEmpleado empleado[], int tamEmpleado,eSector sector[],int tamSectores);
int menuDeModificacion(eEmpleado empleado[], int tamEmpleado);
int menuDeModificacion(eEmpleado empleado[], int tamEmpleado);
int modiNombre(eEmpleado empleado[],int i);
int modiSueldo(eEmpleado empleado[],int i);
int modiApellido(eEmpleado empleado[],int i);
int modiSector(eEmpleado empleado[], int tamEmpleado);
int hardCodearSector(eSector nomina[],int tam);
int AsignarSector();
int crearEmpleado(eEmpleado empleado[], int tam,eSector sector[],int tamSectores);
int addEmployees(eEmpleado empleado[],int tamEmpleado,int leg,char nombre[],char apellido[],float sueldo,int sector);
int sortEmployees(eEmpleado empleado[],int tamEmpleado,eSector sector[],int tamSector);
int totalYPromedioSueldosPorSector(eEmpleado empleado[],int tamEmpleado,eSector sector[], int tamSector);
void initEmployees(eEmpleado empleado[],int tam);
void mostrarEmpleado(eEmpleado empleado,eSector sector);
void eliminarEmpleado(eEmpleado empleado[],int tamEmpleado);
void cargarDescripcion(eSector sector[],int tamSectores,int idSectores,char cadena[]);
void construirEmpleado(eEmpleado empleado[],int i,eSector sector[], int tamSectores);
void menuConsultas(eEmpleado empleado[],int tamEmpleado,eSector sector[], int tamSector);
void hardCodear(eEmpleado nomina[],int tamEmpleado);
void cargando();




