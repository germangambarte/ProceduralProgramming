#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define NOMBREARCHIVO "asistentes.dat"

typedef char Cadena[40];
typedef struct{
	Cadena nombre;
	int edad;
}Asistente;

void carga(FILE *a){
	Asistente aux;
	a = fopen("asistentes.dat","wb");
	printf("nombre (FIN: finaliza): ");
	fflush(stdin);
	gets(aux.nombre);
	while(stricmp(aux.nombre,"FIN")){
		printf("edad: ");
		fflush(stdin);
		scanf("%d", &aux.edad);
		fwrite(&aux,sizeof(aux),1,a);
		printf("nombre (FIN: finaliza): ");
		fflush(stdin);
		gets(aux.nombre);
	}
	fclose(a);

}


void mayoresDe40(FILE *a){
	Asistente aux;
	a = fopen(NOMBREARCHIVO,"rb");
	if(a==NULL) {
		printf("muestra() | no se pudo abrir el archivo\n");
		return;
	}
	rewind(a);
	fread(&aux,sizeof(aux),1,a);
	while(feof(a)==0){
		if(aux.edad > 40){
			printf("nombre: %s\n",aux.nombre);
		}
		fread(&aux,sizeof(aux),1,a);
	}
	fclose(a);
}


int main(){
	FILE *archivo;
	printf("-----CARGA-----\n");
	carga(archivo);
	printf("-----MAYORES DE 40-----\n");
	mayoresDe40(archivo);
	getchar();
	return 0;
}

