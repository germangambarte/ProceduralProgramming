#include <stdio.h>
#include <malloc.h>
#define N 12

typedef struct _turno {
	int dni;
	int nroEspecialidad;
	struct _turno *sig;
} turno;

typedef struct {
	int numero;
	char *nombre;
	turno *turnos;
} especialidad;

void crearNodo(especialidad *&c){
	c = NULL;
}

void crear(especialidad e[]){
	for (int i = 0; i < N; ++i)
	{
		printf("numero de la especialidad: ");
		scanf("%d", &e[i].numero);
		printf("titulo de la especialidad: ");
		gets(e[i].nombre);
		crearNodo(e[i].especialidades);
	}
}



int main(){
	especialidad especialidades[N];
	crear(tutoriales);
}

