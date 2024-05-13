class PP:
    __frase: str

    def __init__(self, frase):
        self.__frase = frase

    def reemplazar_dos(self):
        print("-----REMPLAZAR 2-----")
        nueva_frase = self.__frase.replace("2","0")
        self.__frase = nueva_frase
        print(self.__frase)

    def cortar_frase(self):
        print("-----CORTAR FRASE-----")
        corte = self.__frase.rsplit(" ")[0]
        print(corte)

    def contar_vocales(self):
        print("-----CONTAR VOCALES-----")
        vocales = "aeiou"
        sum = 0
        for vocal in vocales:
            sum += self.__frase.count(vocal)
        print(f"La frase tiene {sum} vocales")

if __name__ == '__main__':
    frase = PP('Programacion Procedural 2023')
    frase.reemplazar_dos()
    frase.cortar_frase()
    frase.contar_vocales()
