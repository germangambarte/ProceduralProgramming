| numero | importe | tipo |
| ------ | ------- | ---- |
| 1      | 123     | 1    |
| 2      | 234     | 2    |
| 3      | 123     | 1    |

tengo un error en la siguiente función escrita en C y no se cual es:

```C
void marcar(FILE *p){
	Pagos aux;
	p = fopen(PAGOS,"r+");

	if(p==NULL){
		printf("marcar() | p==NULL");
		return ;
	}

	rewind(p);
	fread(&aux, sizeof(aux), 1, p);
	while(feof(p)==0){
		if(aux.importe<500){
			fseek(p, -sizeof(Pagos), SEEK_CUR);
			aux.importe = -1;
			fwrite(&aux, sizeof(aux), 1, p);
		}
		fread(&aux, sizeof(aux), 1, p);
	}
}
```
