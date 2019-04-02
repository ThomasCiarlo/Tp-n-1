#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "libreria.h"

int main()
{
    int flagA=0;
    int flagB=0;
    int flagOper=0;
    int flagResultado=0;
    int opcion;
    int a;
    int b;
    int suma;
    int resta;
    int multiplicacion;
    int factorialA;
    int factorialB;
    char seguir='s';
    float division;


  do{


    system("cls");//Actualiza la pantalla en cada pasada

    printf("\n");
    printf("~~~~~~~~~~~~~~La Calculadora~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");

//--------------------------Cambia el valor de x e y---------------//

    cambiarValorAyB(flagA,flagB,a,b);

//------------------Se encarga de poner valores a las operaciones----------//

    printf(" 3. Calcular todas las operaciones \n\n");

    flagOper = mostarOperaciones(flagA,flagB,flagOper,a,b);//Esta funcion cambia el valor de la variable y muestra valores por pantalla

    printf("\n");
//---------------------------------------------------------------------//

    printf("4. Informar resultados\n\n");//en la siguiente funcion muestra los resultados y lo pone por pantalla
    mostrarResultados(a,b,suma,resta,multiplicacion,factorialA,factorialB,flagOper,flagResultado,division);

//-----------------------------------------------------------------------------------------------------------//
    printf("\n5. Desea Continuar en la calculadora? S/N: \n");
//---------------------------------------------Menus de opciones----------------------------------------//

    printf("===Seleccione su opcion===: ");
    scanf("%d",&opcion);
    fflush(stdin);

        switch(opcion){
        case 1:
            printf("Ingrese el primer operador: ");
            fflush(stdin);
            scanf("%d" , &a);
            flagA=1;
            break;
        case 2:
            printf("Ingrese el segundo operador: ");
            fflush(stdin);
            scanf("%d", &b);
            flagB=1;
            break;
        case 3:
            if(flagOper==1){
                printf("Calculando las operaciones...\n");
                suma = suma2(a,b);
                resta = resta2(a , b);
                multiplicacion = multiplicacion2(a,b);
                division = division2(a,b);
                factorialA=factorial(a);
                factorialB=factorial(b);
                Sleep(2000);
                printf("Se realizaron todas las operaciones con exito\n");
                flagResultado=1;
                system("pause");
            }
            else{
                printf("Error falta ingresar un operador\n");
                system("pause");
            }
            break;
        case 4:
            if(flagResultado==1 && flagOper==1){
                flagResultado=2;
            }
          else{
                if(flagA==0 || flagB==0){
                   printf("Falta algun operador y que calcule las operaciones...\n");
                    system("pause");
                }
                else{
                    printf("Falta calcular las operaciones\n");
                    system("pause");
                }
            }
            break;
        case 5:
            printf("S para seguir/ N para salir... ");
            fflush(stdin);
            scanf("%c", &seguir);
            break;
        default:
            printf("Opcion incorrecta vuelva a intentar");
            Sleep(2000);
            break;
        }

          }while(seguir=='s');



}


