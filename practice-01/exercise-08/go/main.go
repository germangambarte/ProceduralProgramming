package main

import (
	"fmt"
	"math/rand"
)

const R = 3
const C = 4

func load(t *[R][C]int) {
	for i := range R {
		for j := range C {
			t[i][j] = rand.Intn(100)
		}
	}
}

func show(t [R][C]int) {
	for _, r := range t {
		fmt.Println(r)
	}
}

func sumOddValues(t [R][C]int) {
	var sum int

	for i := range R {
		for j := range C {
			if t[i][j]%2 != 0 {

				sum += t[i][j]
			}
		}
	}
	fmt.Printf("Suma de impares: %d\n", sum)
}

func count(t [R][C]int, row int) int {
	var count int
	row = row - 1
	for j := range C {
		if t[row][j] > 10 {
			count++
		}
	}
	return count
}

func main() {
	var table [R][C]int
	load(&table)
	show(table)
	fmt.Println()
	sumOddValues(table)
	fmt.Println()
	var row int
	fmt.Print("Ingrese una fila: ")
	fmt.Scan(&row)
	result := count(table, row)
	fmt.Printf("Cantidad de elementos +10: %d\n", result)
}
