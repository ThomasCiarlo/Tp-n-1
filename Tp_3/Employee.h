#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



int menuOpciones();
int ordenarXsueldo(void* emp1, void* emp2);
int OrdenarXId(void* emp1, void* emp2);
int menuOpcionesOrdenar();
int AltaEmpleado(LinkedList* pArrayListEmployee);
int eliminarEmpleado(LinkedList* pArrayListEmployee);
int modificarHorasTrabajadas(LinkedList* pArrayListEmployee, int indice);
int modificarSueldo(LinkedList* pArrayListEmployee, int indice);
int searchId(LinkedList* pArrayListEmployee,int idAux);
int incremetarID(LinkedList* pArrayListEmployee,int desde);
int OrdenarXHoras(void* emp1, void* emp2);
int ordenarNombre(void* emp1, void* emp2);
void mostrarEmplees(LinkedList* pArrayListEmployee);
void ordenarMenor(LinkedList* pArrayListEmployee);
void mostrarEmployee(Employee* emp);
void ordenarMayor(LinkedList* pArrayListEmployee);
void menuDeModificaciones(LinkedList* pArrayListEmployee,int indice);


#endif // employee_H_INCLUDED
