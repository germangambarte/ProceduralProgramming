#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define EMPLEADOSDAT "EMPLEADOS.dat"
#define EMPRESASDAT "EMPRESAS.dat"

typedef char Cadena[124];
typedef struct {
  Cadena nombreEmpleado;
  Cadena nombreEmpresa;
  int dni;
  int cuit;
  float sueldo;
} Empleado;
typedef struct {
  Cadena nombre;
  int totalEmpleados;
  float totalLiquidacion;
} Empresa;

void carga(FILE *e, int cont){
  Empleado aux;
  int dni;
  e = fopen(EMPLEADOSDAT,"wb");

  if (e==NULL){
    printf("carga() | e == NULL");
    return ;
  }

  printf("dni (0:FIN): ");
  scanf("%d", &dni);

  while(dni != 0){
    aux.dni = dni;

    printf("nombre empleado: ");
    gets(aux.nombreEmpleado);

    printf("nombre empresa: ");
    gets(aux.nombreEmpresa);

    printf("cuit: ");
    scanf("%d", &aux.cuit);

    printf("sueldo: ");
    scanf("%f", &aux.sueldo);

    fwrite(&aux,sizeof(aux), 1, e);

    printf("dni (0:FIN): ");
    scanf("%d", &dni);
  }
  fclose(e);
}

void ordenaEmpleados(Empleado e[], int N){
  Empleado aux;
  int cota,k;
  cota = N-1;
  k=1;
  while(k!=1){
    k=-1;
    for (int i = 0; i < cota; i++){
      if(strcmp(e[i].nombreEmpleado, e[i+1].nombreEmpleado) > 0){
        aux = e[i];
        e[i] = e[i+1];
        e[i+1] = aux;
        k=i;
      }
    }
    cota = k;
  }
}

void mostrarEmpleados(Empleado e[], int N){
  Cadena empr;
  float sum = 0;
  strcpy(empr,e[0].nombreEmpresa);
  printf("lista de empleados de %s:\n", empr);
  for (int i = 0; i < N; i++) {
    if(stricmp(empr,e[i].nombreEmpresa)!=0){
      printf("Total pagado por %s: $%.2f \n",empr, sum);
      strcpy(empr,e[0].nombreEmpresa);
      printf("\nlista de empleados de %s: \n", empr);
      sum = 0;
    }
    printf(
      "\tdni: %d, nombre: %s, sueldo: $%.2f\n",
      e[i].dni, e[i].nombreEmpleado, e[i].sueldo
      );
    sum += e[i].sueldo;
  }
}

void listarEmpleados(FILE *e, int N){
  Empleado empleados[N];
  e = fopen(EMPLEADOSDAT,"r+");

  if (e==NULL){
    printf("carga() | e == NULL");
    return ;
  }
  fread(empleados,sizeof(Empleado),N,e);
  fclose(e); 
  ordenaEmpleados(empleados,N);
  mostrarEmpleados(empleados,N);

}

void cargaEmpresas(FILE *empl, FILE *empr) {
  Empresa empresa;
  Empleado empleado;
  Cadena empresa;

  empl = fopen(EMPLEADOSDAT, "rb");
  empr = fopen(EMPRESASDAT, "wb");

  if(empr == NULL){
    printf("cargaEmpresa() | empr == NULL");
    return ;
  }
  if(empl == NULL){
    printf("cargaEmpresa() | empl == NULL");
    return ;
  }

  rewind(empl);
  fread(&empleado,sizeof(empleado),1,empl);
  strcpy(empresa.nombre,empleado.nombreEmpresa);
  empresa.totalEmpleados = 0;
  empresa.totalLiquidacion = 0;
  while (feof(empl) == 0){

    if(strcmp(empresa.nombre,empleado.nombreEmpresa)!=0){
      fwrite(&empresa,sizeof(empresa),1,empr);
      strcpy(empresa.nombre,empleado.nombreEmpresa);
      empresa.totalEmpleados = 0;
      empresa.totalLiquidacion = 0;
    }

    empresa.totalEmpleados += 1;
    empresa.totalLiquidacion += empleado.sueldo;
    
    fread(&empleado,sizeof(empleado),1,empl);
  }
  fclose(empr);
  fclose(empl);
}

int main(){
  int N = 0;
  Empleado arregloEmpleado[N];
  FILE *empleados, *empresas;
  printf("-----CARGA-----\n");
  carga(empleados,N);
  printf("-----LISTADO DE LIQUIDACION-----\n");
  listarEmpleados(empleados,N);
  printf("-----CARGA EMPRESAS.dat-----\n");
  cargaEmpresas(empleados,empresas);
  return 0;
}
