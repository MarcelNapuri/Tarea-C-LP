#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tEnunciadoAlternativa{
    char enunciado[128];
    int n_alternativas;
    char** alternativas;
    int alternativa_correcta;
};

struct tEnunciadoAlternativaMultiple{ 
    char enunciado[128];
    int n_alternativas;
    char** alternativas;
    int n_correctas;
    int* alternativa_correcta;
} ; 

struct tEnunciadoVerdaderoFalso{
    char enunciado[128];
    bool respuesta;
};

struct tEnunciadCompletar{
    int n_textos;
    char** textos;
    char** respuestas;
} ;

struct tPregunta{
    char tipo[64];
    void* enunciado;      //apunta a cualquiera de las otras estructuras
    void* respuesta;
    bool (*revisar)(void*, void*);
};

struct tCertamen{
    int n_preguntas;
    struct tPregunta* preguntas;
}; 

struct tCertamen* crearCertamen (int n_preguntas);  // Crea un nuevo certamen vac i o
struct tPregunta* crearPregunta(char*tipo, void* enunciado, bool(*fun)(void*));
void asignarPregunta(struct tCertamen* certamen, int n_pregunta, struct tPregunta* pregunta);
struct tPregunta leerPregunta(struct tCertamen* certamen, int n_pregunta);
int nCorrectasCertamen(struct tCertamen certamen);
int largoCertamen(struct tCertamen certamen);
bool revisarAlternativaSimple(struct tPregunta pregunta);
bool revisarAlternativaMultiple(struct tPregunta pregunta);
bool revisarVerdaderoFalso(struct tPregunta pregunta);
bool revisarCompletar(struct tPregunta pregunta);