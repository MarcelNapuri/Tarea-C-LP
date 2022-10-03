#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Certamen.h"

struct tCertamen* crearCertamen (int n_preguntas){
    struct tCertamen* nuevoCertamen = malloc(sizeof(struct tCertamen));
    nuevoCertamen->n_preguntas = n_preguntas;
    nuevoCertamen->preguntas = malloc(n_preguntas*sizeof(struct tPregunta));
    return nuevoCertamen;
}

struct tPregunta* crearPregunta(char* tipo, void* enunciado, bool (*fun)(void*)){
    struct tPregunta* nuevaPregunta;
    *nuevaPregunta->tipo = tipo;
    nuevaPregunta->enunciado = &enunciado;
    nuevaPregunta->revisar = fun;
    return nuevaPregunta;
    /*
    if (tipo == "AlternativaSimple"){
        
        //struct tPregunta* simple = &enunciado ;
        //*simple->tipo = "AlternativaSimple";
        //struct tEnunciadoAlternativa* nuevo;       
        //simple->enunciado = &nuevo;
        
        struct tPregunta* nuevaPregunta;
        *nuevaPregunta->tipo = "AlternativaSimple";
        //struct tEnunciadoAlternativa* nuevoEnunciado = &enunciado;       
        nuevaPregunta->enunciado = &enunciado;
        
        //*nuevoEnunciado->enunciado = "texto";
        //nuevoEnunciado->n_alternativas ="num";
        //nuevoEnunciado->alternativas = "ya vere que hago aca xd";
        //nuevoEnunciado->alternativa_correcta = "xd";

        //nuevaPregunta->respuesta = "";
        
       
    }
    */
};

// Asigna l a pregunta a l a p o s i c i o n n pregunta de l certamen
void asignarPregunta(struct tCertamen* certamen, int n_pregunta, struct tPregunta* pregunta){
    certamen->preguntas[n_pregunta] = *pregunta;
}

// Retorna l a pregunta en l a p o s i c i o n n pregunta de l certamen
struct tPregunta leerPregunta(struct tCertamen* certamen, int n_pregunta){
    return certamen->preguntas[n_pregunta];
}

// Retorna e l numero de r e s p u e s t a s c o r r e c t a s que t i e n e e l certamen
int nCorrectasCertamen(struct tCertamen certamen){
    int contador = 0;
    for(int i=0; i<certamen.n_preguntas; i++){
        if(certamen.preguntas[i].revisar == true){
            contador++;
        }
    }
    return contador;
};

int largoCertamen(struct tCertamen certamen){
    return certamen.n_preguntas;
};

bool revisarAlternativaSimple(struct tPregunta pregunta){
    if(pregunta.enunciado.alternativa_correcta == pregunta.respuesta[0]){
        return true;
    }else{
        return false;
    }
}

bool revisarAlternativaMultiple(struct tPregunta pregunta){
    int contador = 0;
    for(int i=0; i<pregunta.enunciado.n_correctas; i++){
        if(pregunta.enunciado.alternativa_correcta[i] == pregunta.respuesta[i]){
            contador++;
        }
    }
    if(contador == pregunta.enunciado.n_correctas){
        return true;
    }else{
        return false;
    }
}

bool revisarVerdaderoFalso(struct tPregunta pregunta){
    if(pregunta.enunciado.alternativa_correcta == pregunta.respuesta[0]){
        return true;
    }else{
        return false;
    }
}

bool revisarCompletar(struct tPregunta pregunta){
    int contador = 0;
    for(int i=0; i<pregunta.enunciado.n_correctas; i++){
        if(pregunta.enunciado.alternativa_correcta[i] == pregunta.respuesta[i]){
            contador++;
        }
    }
    if(contador == pregunta.enunciado.n_correctas){
        return true;
    }else{
        return false;
    }
}
