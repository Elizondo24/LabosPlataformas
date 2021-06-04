#include <stdio.h>
#include <stdlib.h>

void leerArchivo(char path []){

    FILE *archivo;
    char cadena [10];
    archivo = fopen(path,"r");

    if (archivo != NULL)
    {
       while (!feof(archivo))
       {
           fgets(cadena, 10, archivo);

           printf("Usuario: %s\n",cadena);
       }
       
    } 
    fclose(archivo);
    
}   

int main(){

    int a;
    
    

    while (1)
    {
        printf("0- Para salir\n");
        printf("1-Imprimir lista de usuarios\n");
        printf("2-Imprimir lista de usuarios y su condicion\n");
        printf("3-Ordenar los usuarios por ultima ora de accseso\n");
        printf("4-Actualizar los datos de un usuario\n") ;
        printf("Digite el numero de la accion que desea realizar:");
        scanf( "%d", &a);

        if (a==0)
        {
            return 0;
        }
        
        
        if (a==1)
        {
            leerArchivo("user_list.txt");
        }


    }
    
    
    return 0;
}