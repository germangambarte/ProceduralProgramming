#include <stdio.h>
#include <malloc.h>

typedef struct _inscripcion {
	char *nombre;
	float promedio
	int anio;
	struct _inscripcion *sig;
} Inscripcion;

typedef struct {
	char *nombre;
	Inscripcion *inscripciones;
} Facultad;

void crearNodo(Inscripcion *&c){
	c = NULL;
}

void crear(Facultad f[]){
	for (int i = 0; i < N; ++i)
	{
		printf("nombre de la especialidad: ");
		gets(f[i].nombre);
		crearNodo(f[i].inscripciones);
	}
}

void carga(Facultad f[]){}
void ordenar(Inscripcion *&c){}

int main(){
	Facultad *facultades;
	int N;
	printf("cantidad de facultades: ")
	scanf("%d", &N);
	facultades = (Facultad *) malloc(sizeof(Facultad) * N);
	crear(facultades)
	crear(tutoriales);
}

