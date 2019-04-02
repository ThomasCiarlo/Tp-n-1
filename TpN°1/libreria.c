#include <stdio.h>
#include <stdlib.h>


/** \suma
 *
 * \A
 * \B
 * \a+b
 *
 */
int suma2(int x, int y){

	 return x+y;
}

/** \resta
 *
 * \A
 * \B
 * \a-b
 *
 */
int resta2(int x, int y){

	return x-y;
}

/** \multiplicacion
 *
 * \A
 * \B
 * \a*b
 *
 */
int multiplicacion2(int x, int y){

	return x*y;
}

/** \division
 *
 * \A
 * \B
 * \a/b (float)
 *
 */
float division2(int x, int y){

    return (float) x / y;

}

/** \factorial
 *
 * \A
 * \B
 * \a! y b!
 *
 */
int factorial(int x){
	    int rta;

        if(x<=1){
            rta=1;
        }
        else{
            rta=x*factorial(x-1);
        }
		return rta;
}

/** \cambiarValorAyB
 *
 * \A
 * \B
 * \a=x y b=y o a=a y b=b
 *
 */
void cambiarValorAyB(int flagA ,int flagB ,int a ,int b){

    if(flagA==1){
        printf(" 1. Primer operador A= %d \n", a);
    }
    else{
        printf(" 1. Primer operador (A=x) \n");
    }

      if(flagB==1){
        printf(" 2. Segundo operador B= %d \n", b);
    }
    else{
        printf(" 2. Segundo operador (B=y)\n");
    }

}

/** \MostarOperaciones
 *
 * \flagA
 * \flagB
 * \flagOper
 * \a
 * \b
 *
 * \Muestra el valor de a y b y las operacion que se van a realizar, retorna el valor de flagOper
 */
int mostarOperaciones(int flagA, int flagB, int flagOper, int a, int b){

        if(flagB==1 && flagA==1){
            printf("\ta) Calcular la suma de: %d + %d \n",a,b);
            printf("\tb) Calcular la resta de: %d - %d \n",a,b);
            printf("\tc) Calcular la multiplicacion %d x %d \n",a,b);
            printf("\td) Calcular la division de %d / %d \n",a,b);
            printf("\te) Calcular el factorial de %d! y %d! \n",a,b);
            flagOper=1;
        }
        else if(flagA==1){
            printf("\ta) Calcular la suma de: %d +B \n",a);
            printf("\tb) Calcular la resta de: %d - B \n",a);
            printf("\tc) Calcular la multiplicacion %d x B \n",a);
            printf("\td) Calcular la division de %d / B \n",a);
            printf("\te) Calcular el factorial de %d! y B! \n",a);
        }
        else if(flagB==1){
            printf("\ta) Calcular la suma de: A+%d \n",b);
            printf("\tb) Calcular la resta de: A - %d\n",b);
            printf("\tc) Calcular la multiplicacion A x %d \n",b);
            printf("\td) Calcular la division de A / %d \n",b);
            printf("\te) Calcular el factorial de A! y %d! \n",b);
        }
        else{
            printf("\ta) Calcular la suma de: A+B \n");
            printf("\tb) Calcular la resta de: A - B \n");
            printf("\tc) Calcular la multiplicacion A x B \n");
            printf("\td) Calcular la division de A / B \n");
            printf("\te) Calcular el factorial de A! y B! \n");
        }

        return flagOper;


}

/** \MostarResultado
 *
 * \flagA
 * \flagB
 * \flagOper
 * \suma
 * \resta
 * \a
 * \b
 * \division
 * \multiplicacion
 * \factorialA
 * \factorialB
 *
 * \Muestra lo resultados por pantallas de las operaciones, y revisa en caso de dividir por menores de 0 lo mismo a la hora de factorear
 */
void mostrarResultados(int a, int b, int suma, int resta,int multiplicacion,int factorialA,int factorialB,int flagOper,int flagResultado, float division){

         if(flagResultado==2){
            printf("\ta) El resultado de la suma es: %d \n",suma);
            printf("\tb) El resultado de la resta es: %d \n", resta);
            printf("\tc) El resultado de la multiplicacion es: %d \n",multiplicacion);

            if(b>0){
            printf("\td) El resultado de la division es: %.2f \n", division);
            }
            else{
                printf("\td) No se puede dividir por 0 ni por un numero menor al mismo\n");
            }

            if(a>=0 && b>=0){
            printf("\te) El factorial de A: %d ! y B: %d ! \n",factorialA,factorialB);
            }
            else if(a>=0 && b<0){
                printf("\te) El factorial de A: %d y B no se puede factorial porque es menor de 0\n",factorialA);
            }
             else if(a<0 && b>=0){
                printf("\te) El factorial de B: %d y A no se puede factoreos porque es menor de 0\n",factorialB);
            }
            else{
                printf("\te) No se puede mostar los facotros porque son numeros negativos!\n");
            }

         }
         else{
            printf("\ta) El resultado de la suma es: A+B \n");
            printf("\tb) El resultado de la resta es: A-B \n");
            printf("\tc) El resultado de la multiplicacion es: A*B \n");
            printf("\td) El resultado de la division es: A/B \n");
            printf("\te) El factorial de : A! y B! \n");
         }




}











