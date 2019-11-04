#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct {
   int nota;
   int legajo;
   char nombreApe[30];
} notaAlumno;

void mostrarAlumno(notaAlumno alum);

#endif // ALUMNO_H_INCLUDED
