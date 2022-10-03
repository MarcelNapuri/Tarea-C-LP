#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "certamen.h"
#include "certamen.c"

int main (){
    FILE *fp;
    fp = fopen("certamen.txt" , "r");
    if (fp == NULL){
        printf("Error en la apertura del archivo\n");
        return 1;
    }
    
    int i;         
    char c[64];  //ENUNCIADO

    fscanf(fp, "%d" , &i);
    printf( "número de preguntas = %d\n" , i);
    //crearCertamen(i);

    void* preguntas[i];
    char tipos [i][128];

    while (!feof(fp))
    {
      fscanf(fp, "%s\n" , c);
      printf("%s\n" , c);  
      if(c == "AlternativaSimple"){

      }
    }
    


    /*
    for (int j = 0; j < i; j++ ){
        char c[64];
        printf("---------------\n");
        fscanf(fp , "%s\n" ,c);    //tipo de pregunta
        printf("%s\n" , c);
        strcpy(tipos[i],c);
        printf("---------------\n");
        if (strcmp(c,"AlternativaSimple") == 0){
            printf("pregunta 1\n");            
            char enun[128];
            int n;
            fscanf(fp,"%s",enun);
            printf("%s\n" , enun);
            fscanf(fp, "%d\n" , &n);
            printf("%d\n" , n);
            for(int j = 0; j < n; j++){
                fgets(c,64,fp);    //tipo de pregunta
                printf(  "%s\n" , c);
            }
            fscanf(fp, "%d" , &n);
            printf( "%d\n" , n);
            break;
        }

        if (c == "AlternativaMultiple"){

        }

        if (c == "VerdaderoFalso"){

        }

        if (c == "Completar"){

        }
    }

    */
    fclose(fp);
    printf("\n");
    return 0;

}