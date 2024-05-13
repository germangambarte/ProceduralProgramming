class Lista:

    __lista = list()
    __longitud: int

    def __init__(self, longitud):
        self.__longitud = int(longitud)

    def cargar_lista(self):
        print("-----CARGAR LISTA-----")
        for i in range(self.__longitud):
            self.__lista.append(int(input("Ingrese un número: ")))

    def verificar_ceros(self):
        print("-----VERIFICANDO CEROS-----")
        for valor in self.__lista:
            if valor == 0:
                print("Hay ceros en la lista")
                break
            else:
                print("No hay ceros en la lista")

    def mostrar_en_par(self):
        print("-----MOSTRANDO INDICES PARES-----")
        for index,valor in enumerate(self.__lista):
            if index % 2 == 0:
                print(valor)

    def contar_pares(self):
        print("-----CONTANDO PARES-----")
        sum = 0

        for valor in self.__lista:
            if valor % 2 == 0:
                sum += 1

        print(f"En la lista hay {sum} números pares")

if __name__ == '__main__':
    lista = Lista(5)
    lista.cargar_lista()
    lista.verificar_ceros()
    lista.mostrar_en_par()
    lista.contar_pares()
