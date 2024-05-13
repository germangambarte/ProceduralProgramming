#include <stdio.h>
#include <malloc.h>
#define PAGOS "pagos.dat"
#define AUXPAGOS "auxpagos.dat"

typedef struct  {
	int numero;
	float importe;
} Pagos;

// typedef tdatos Pagos;

typedef struct snodo {
	int numero;
	float importe;
	int tipo;
	struct snodo *sig;
} Operacion;

// PUNTO A:
void incializar(Operacion *&o){
	o = NULL;
}

void carga(Operacion *&o){
	Operacion *nuevo;
	int aux;
	printf("numero (0:FIN): ");
	scanf("%d", &aux);
	while(aux !=0){
		nuevo = (Operacion *)malloc(sizeof(Operacion));
		nuevo->numero = aux;
		printf("importe: ");
		scanf("%f", &nuevo->importe);
		printf("tipo: ");
		scanf("%d", &nuevo->tipo);

		nuevo->sig = o;
		o=nuevo;

		printf("numero (0:FIN): ");
		scanf("%d", &aux);

	}
}

void mostrar(Operacion *o){
	if(o!=NULL){
		printf(
			"numero: %d, importe: %.2f, tipo: %d\n",
			o->numero, o->importe ,o->tipo
			);
		mostrar(o->sig);
	} else {
		return;
	}
}

// PUNTO B
void buscarMayor(Operacion *o, int &max){
	if(o != NULL){
		if(o->importe > max && o->tipo == 1) {
			max = o->importe;
		}
		buscarMayor(o->sig, max);
	} else {
		return;
	}
}

void imprimirMayor(Operacion *o, int &max){
	if(o != NULL){
		if(o->importe == max && o->tipo == 1) {
			printf(
				"numero: %d, importe: %.2f",
				o->numero, o->importe
				);
		}
		imprimirMayor(o->sig, max);
	} else {
		return;
	}
}

// PUNTO C
void cargaArchivo(Operacion *o, FILE *p){
	p = fopen(PAGOS,"wb");
	Pagos *np;

	if(p == NULL){
		printf("cargaArchivo() | p=NULL");
		return;
	}

	while(o != NULL){
		if(o->tipo == 2){
			np->numero=o->numero;
			np->importe=o->importe;
			fwrite(&np,sizeof(np),1,p);
		}
		o = o->sig;
	}
	fclose(p);
}

// PUNTO D
void eliminarLista(Operacion *o){
	Operacion *actual;
	while(o!=NULL){
		actual = o;
		o=o->sig;
		free(actual);
	}
	return;
}

// PUNTO E
float calcularPromedio(FILE *p, float sum){
	Pagos aux;
	int cont = 0;
	p = fopen(PAGOS,"rb");

	if(p==NULL){
		printf("calcularPromedio() | p==NULL");
		return 0;
	}

	rewind(p);
	fread(&aux, sizeof(aux), 1, p);

	while(feof(p)==0){
		sum += aux.importe;
		cont += 1;
		fread(&aux, sizeof(aux), 1, p);
	}
	fclose(p);
	return sum / cont;
}

// PUNTO F
void marcar(FILE *p){
	Pagos aux;
	p = fopen(PAGOS,"w+");

	if(p==NULL){
		printf("marcar() | p==NULL");
		return ;
	}

	rewind(p);
	fread(&aux, sizeof(aux), 1, p);
	while(feof(p)==0){
		if(aux.importe<500){
			fseek(p, -sizeof(aux), SEEK_CUR);
			aux.importe = -1;
			fwrite(&aux, sizeof(aux), 1, p);
		}
		fread(&aux, sizeof(aux), 1, p);
	}
}

void eliminar(FILE *p, FILE *ap){
	Pagos aux;
	ap = fopen(AUXPAGOS,"wb");

	if(ap==NULL){
		printf("eliminar() | ap==NULL");
		return;
	}

	rewind(ap);
	fread(&aux,sizeof(aux),1,ap);
	while(feof(p)==0){
		if(aux.importe != -1){
			fwrite(&aux,sizeof(aux),1,ap);
		}
		fread(&aux,sizeof(aux),1,p);
	}
}

int main(){
	Operacion *operaciones;
	FILE *pagos, *auxP;
	int maximo = 0;
	float promedio;
	incializar(operaciones);
	printf("\n-----CARGA-----\n");
	carga(operaciones);
	printf("\n-----MOSTRAR-----\n");
	mostrar(operaciones);
	printf("\n-----MAYOR-----\n");
	buscarMayor(operaciones,maximo);
	imprimirMayor(operaciones,maximo);
	printf("\n-----CARGA ARCHIVO-----\n");
	cargaArchivo(operaciones,pagos);
	printf("\n-----ELIMINAR LISTA-----\n");
	eliminarLista(operaciones);
	printf("\n-----PROMEDIO-----\n");
	promedio = calcularPromedio(pagos,0);
	printf("promedio: %.2f\n",promedio);
	printf("\n-----ELIMINAR REGISTROS-----\n");
	marcar(pagos);
	eliminar(pagos, auxP);
	fclose(pagos);
	fclose(auxP);
	remove(PAGOS);
	rename(AUXPAGOS,PAGOS);
	return 0;
}

