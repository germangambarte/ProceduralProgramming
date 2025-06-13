package main

import (
	"fmt"
	"strings"
)

const N = 3

type Article struct {
	code  int
	name  string
	price float32
	stock int
}

func load(x *[N]Article) {
	for i := 0; i < N; i++ {
		fmt.Println("Código: ")
		fmt.Scan(&x[i].code)
		fmt.Println("Nombre: ")
		fmt.Scan(&x[i].name)
		fmt.Println("Precio unitario: ")
		fmt.Scan(&x[i].price)
		fmt.Println("Stock: ")
		fmt.Scan(&x[i].stock)
	}
}

func searchByName(x *[N]Article, name string) int {
	var i = 0
	for i < N && x[i].name != name {
		i++
	}
	return i
}

func searchByCode(x *[N]Article, code int) int {
	var i = 0
	for i < N && x[i].code != code {
		i++
	}
	return i
}

func process(x *[N]Article) {
	var articleName string
	var amount int

	fmt.Print("Nombre del producto: ")
	fmt.Scan(&articleName)

	for strings.ToLower(articleName) != "fin" {
		fmt.Print("Unidades vendidas: ")
		fmt.Scan(&amount)

		idx := searchByName(x, articleName)

		if idx < N {
			x[idx].stock -= amount
		} else {
			fmt.Println("No encontrado.")
		}

		fmt.Print("Nombre del producto: ")
		fmt.Scan(&articleName)
	}
}

func checkEmptyStock(x *[N]Article) {
	fmt.Println("Articulos sin stock: ")
	for _, a := range x {
		if a.stock == 0 {
			fmt.Printf("	- %s\n", a.name)
		}
	}
}

func showStock(x *[N]Article) {
	var code int

	fmt.Print("Ingrese el código: ")
	fmt.Scan(&code)

	idx := searchByCode(x, code)
	if idx < N {
		fmt.Printf("Stock: %d\n", x[idx].stock)
	} else {
		fmt.Println("No encontrado.")
	}
}

func main() {
	var articles = [N]Article{
		{code: 101, name: "Lapicera", price: 150.50, stock: 20},
		{code: 102, name: "Cuaderno", price: 300.00, stock: 10},
		{code: 103, name: "Regla", price: 120.75, stock: 5},
	}
	process(&articles)
	fmt.Println()
	checkEmptyStock(&articles)
	fmt.Println()
	showStock(&articles)
}
