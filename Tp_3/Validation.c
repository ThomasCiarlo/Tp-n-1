#include <stdlib.h>
#include <string.h>
#include <stdio.h>



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
int validarEmail(char email[]){

	int flag=0;

	for(int i=0;i<100;i++){
		if((email[i]>=65 && email[i]<=90) || (email[i]>=97 && email[i]<=127)){
			for(int j=i;j<30;j++){
				if(email[j]=='@'){
					for(int k=j;k<20;k++){
						if(email[k]=='.' || (email[k]>=65 && email[k]<=90) || (email[k]>=97 && email[k]<=127) ){
							flag=1;
						}
					}
				}
			}
		}
	}
	return flag;
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
