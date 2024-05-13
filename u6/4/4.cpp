#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define ASPIRANTESDAT "pagos.dat"

typedef char Cadena[100];

typedef struct  {
	int numero;
	Cadena nya;
	int cantFamiliares;
	int cuotas;
	float valorCuota;
} Aspirante;

typedef struct {
	Cadena nya;
	int cantFamiliares;
} Casa;

void carga(FILE *a){
	Aspirante aux;
	a = fopen(ASPIRANTESDAT,"wb");

	if(a == NULL){
		printf("mostrar() | a == NULL");
	}

	printf("numero (0:FIN): ");
	fflush(stdin);
	scanf("%d", &aux.numero);

	while(aux.numero !=0){
		printf("nombre y apellido: ");
		fflush(stdin);
		gets(aux.nya);

		printf("cantidad de integrantes: ");
		fflush(stdin);
		scanf("%d", &aux.cantFamiliares);

		printf("cantidad de cuotas: ");
		fflush(stdin);
		scanf("%d", &aux.cuotas);

		printf("valor de cuota: ");
		fflush(stdin);
		scanf("%f", &aux.valorCuota);

		fwrite(&aux,sizeof(aux),1,a);

		printf("numero (0:FIN): ");
		fflush(stdin);
		scanf("%d", &aux.numero);

	}
	fclose(a);
}

void mostrar(FILE *a){
	Aspirante aux;
	a = fopen(ASPIRANTESDAT,"rb");

	if(a == NULL){
		printf("mostrar() | a == NULL");
		return;
	}

	rewind(a);
	fread(&aux,sizeof(aux),1,a);
	while (feof(a)==0) {
		printf(
			"nombre y apellido: %s, cuotas: %d, importe: %.2f\n",
			aux.nya, aux.cuotas, aux.valorCuota
		);
	fread(&aux,sizeof(aux),1,a);
	}
	fclose(a);
}

void cuotasPorNYA(FILE *a){
	Cadena nya;
	Aspirante aux;
	printf("nya: ");
	gets(nya);

	a = fopen(ASPIRANTESDAT, "rb");

	if(a == NULL){
		printf("mostrar() | a == NULL");
		return;
	}

	rewind(a);
	fread(&aux,sizeof(aux),1,a);
	while (feof(a)==0) {
		if(stricmp(aux.nya,nya)==0){
			printf(
				"cuotas: %d, importe: %.2f\n",
				aux.cuotas, aux.valorCuota
			);
			return;
		}
		fread(&aux,sizeof(aux),1,a);
	}
	fclose(a);
}

int aspirantesACasa(FILE *a, Casa *&c){
	Aspirante aux;
	int cont = 0, i = 0;
	a = fopen(ASPIRANTESDAT,"rb");

	if(a == NULL){
		printf("mostrar() | a == NULL");
		return;
	}

	rewind(a);
	fread(&aux,sizeof(aux),1,a);

	while (feof(a)==0) {
		if(aux.cantFamiliares > 5) cont+=1;
		fread(&aux,sizeof(aux),1,a);
	}
	c = (Casa *)malloc(sizeof(Casa) * cont);
	rewind(a);
	fread(&aux,sizeof(aux),1,a);

	while (feof(a)==0) {
		if(aux.cantFamiliares > 5) {
			strcpy(c[i].nya, aux.nya);
			c[i].cantFamiliares = aux.cantFamiliares;
			i+=1;
		}
		fread(&aux,sizeof(aux),1,a);
	}
	fclose(a);
	return cont;
}

void ordenar(Casa *&c, int N);

void mostrarArreglo(Casa *&c, int N);

int showMenu(){
	int opc;
	printf("\n-----MENU-----\n");
	printf("1. Listar Aspirantes.\n");
	printf("2. Cuotas por nombre y apellido.\n");
	printf("3. Integrantes que pueden acceder a una casa.\n");
	printf("4. Integrantes que pueden acceder a una casa (ordenados).\n");
	printf("0. Salir.\n");
	scanf("%d", &opc);
	system("cls");
	return opc;
}

int main(){
	FILE *aspirantes;
	Casa *aspACasa;
	int opcion, cantidadRegistros;
	printf("\n-----CARGA-----\n");
	carga(aspirantes);
	opcion = showMenu();
	while(opcion != 0){
		switch (opcion) {
		case 1:
			mostrar(aspirantes);
			break;
		case 2:
			cuotasPorNYA(aspirantes);
			break;
		case 3:
			cantidadRegistros = aspirantesACasa(aspirantes,aspACasa);
			break;
		case 4:
			ordenar(aspACasa, cantidadRegistros);
			mostrarArreglo(aspACasa, cantidadRegistros);
			break;
		default:
			printf("La opcion no esta disponible");
			break;
		}
		opcion = showMenu();
	}
	free(aspACasa);
	return 0;
}

