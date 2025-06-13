package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

const N = 3

type Product struct {
	id    int
	price float32
	stock int
}

type Provider struct {
	name      string
	id        int
	purchases int
}

func processPurchase(prods *[N]Product, provs *[N]Provider, prodId int, provId int, units int) error {
	prodIndex := searchProductById(*prods, prodId)
	if prodIndex >= N {
		return fmt.Errorf("No se encontró producto.")
	}
	provIndex := searchProviderById(*provs, provId)
	if provIndex >= N {
		return fmt.Errorf("No se encontró proveedor.")
	}
	prods[prodIndex].stock -= units
	provs[provIndex].purchases++
	return nil
}

func processPurchases(prods *[N]Product, provs *[N]Provider) {
	var provId, prodId, unitPurchase int
	fmt.Print("Id de proveedor: ")
	fmt.Scan(&provId)
	for provId != 0 {
		fmt.Print("Código de producto: ")
		fmt.Scan(&prodId)
		fmt.Print("Unidades compradas: ")
		fmt.Scan(&unitPurchase)

		err := processPurchase(prods, provs, prodId, provId, unitPurchase)

		if err != nil {
			fmt.Println(err)
		}

		fmt.Print("Id de proveedor: ")
		fmt.Scan(&provId)
	}
}

func searchProductById(x [N]Product, id int) int {
	var i = 0
	for i < N && x[i].id != id {
		i++
	}
	return i
}

func searchProviderById(x [N]Provider, id int) int {
	var i = 0
	for i < N && x[i].id != id {
		i++
	}
	return i
}

func showInvestment(x [N]Product) {
	for _, p := range x {
		fmt.Printf("Producto: %d, inversión: $%.2f\n", p.id, p.price*float32(p.stock))
	}
}

func filter(x [N]Provider) (int, []Provider) {
	var newArr []Provider
	var length = 0

	for _, prov := range x {
		if prov.purchases >= 3 {
			newArr = append(newArr, prov)
			length++
		}
	}
	return length, newArr
}

func showNewArray(provs []Provider, M int) {
	sort.Slice(provs, func(i, j int) bool {
		return provs[i].name < provs[j].name
	})
	for i := 0; i < M; i++ {
		fmt.Println(provs[i])
	}
}

func searchAltProviderByName(x []Provider, M int, name string) int {
	var i = 0
	for i < M && x[i].name != name {

		i++
	}
	return i
}

func showAltInfo(provs []Provider, M int) error {
	var reader = bufio.NewReader(os.Stdin)
	fmt.Print("Ingrese nombre del Proveedor: ")
	name, _ := reader.ReadString('\n')
	name = strings.TrimSpace(name)
	index := searchAltProviderByName(provs, M, name)
	if index == M {
		return fmt.Errorf("Proveedor no encontrado.")
	}
	fmt.Printf("%s tuvo %d ventas.", provs[index].name, provs[index].purchases)
	return nil
}

func main() {
	var products = [N]Product{
		{id: 1, price: 120.00, stock: 20},
		{id: 2, price: 100.00, stock: 10},
		{id: 3, price: 110.00, stock: 15},
	}
	var providers = [N]Provider{
		{name: "Bernal", id: 1001, purchases: 0},
		{name: "Vives", id: 1002, purchases: 0},
		{name: "SM", id: 1003, purchases: 0},
	}

	processPurchases(&products, &providers)
	fmt.Println()
	showInvestment(products)
	fmt.Println()
	length, altProviders := filter(providers)
	showNewArray(altProviders, length)
	fmt.Println()
	showAltInfo(altProviders, length)

}
