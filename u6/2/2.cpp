#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define ALUMNOSPP "alumnosPP.dat"
#define ALUMNOSAL "alumnosAL.dat"

typedef char Cadena[40];
typedef struct{
	Cadena nombre;
	int registro;
	char resultado;
}Alumno;


void carga(FILE *a, const char *fn){
	Alumno aux;
	a = fopen(fn,"wb");
	if(a==NULL) {
		printf("carga() | archivo == NULL\n");
		return;
	}
	printf("nro registro: (0: finaliza): ");
	fflush(stdin);
	scanf("%d", &aux.registro);
	while(aux.registro){
		printf("nombre: ");
		fflush(stdin);
		gets(aux.nombre);
		printf("resultado: ");
		fflush(stdin);
		scanf("%c", &aux.resultado);
		fwrite(&aux,sizeof(aux),1,a);
		printf("nro registro: (0: finaliza): ");
		fflush(stdin);
		scanf("%d", &aux.registro);
	}
	fclose(a);

}


void muestra(FILE *a, const char *fn){
	Alumno aux;
	a = fopen(fn,"rb");
	if(a==NULL) {
		printf("muestra() | no se pudo abrir el archivo\n");
		return;
	}
	rewind(a);
	fread(&aux,sizeof(aux),1,a);
	while(feof(a)==0){
		printf("nombre: %s, registro %d, resultado: %c\n",
			aux.nombre, aux.registro, aux.resultado);
		fread(&aux,sizeof(aux),1,a);
	}
	fclose(a);
}


void muestraAprobados(FILE *pp, FILE *al){
	Alumno auxpp, auxal;
	al = fopen(ALUMNOSAL, "rb");
	pp = fopen(ALUMNOSPP, "rb");
	if(pp == NULL || al == NULL) {
		printf("muestraAprobados() | archivo == NULL\n");
		return;
	}
	rewind(pp);
	rewind(al);
	fread(&auxpp,sizeof(auxpp),1,pp);
	fread(&auxal,sizeof(auxal),1,al);
	while(feof(pp)==0){
		if(auxpp.resultado=='A'){
			if(auxpp.registro != auxal.registro){
				while(feof(al)==0&&auxpp.registro != auxal.registro){
					fread(&auxal,sizeof(auxal), 1, al);
				}
			}
			if(auxpp.resultado=='A' && auxal.resultado=='A'){
				printf("nombre: %s, registro %d\n",auxal.nombre, auxal.registro);
			}
		}
		fread(&auxpp,sizeof(auxpp),1,pp);
	}
	fclose(pp);
	fclose(al);
}


int main(){
	FILE *alumPP, *alumAL;
	printf("-----CARGA PP-----\n");
	carga(alumPP, ALUMNOSPP);
	printf("-----MUESTRA PP-----\n");
	muestra(alumPP,ALUMNOSPP);
	printf("-----CARGA AL-----\n");
	carga(alumAL,ALUMNOSAL);
	printf("-----MUESTRA AL-----\n");
	muestra(alumAL,ALUMNOSAL);
	printf("-----MUESTRA APROBADOS-----\n");
	muestraAprobados(alumPP,alumAL);
	return 0;
}

