package main

import (
	"fmt"
	"math"
	"math/rand"
)

const R = 4
const C = 6

func load(t *[R][C]int) {
	for i := range R {
		for j := range C {
			t[i][j] = rand.Intn(100)
		}
	}
}

func show(t [R][C]int) {
	for _, v := range t {
		fmt.Println(v)
	}
}

func min(t [R][C]int, depto int) {
	var min = math.MaxInt
	var index int
	for j := range C {
		if t[depto-1][j] < min {
			min = t[depto-1][j]
			index = j
		}
	}
	fmt.Printf("Mes de menor venta: %d\n", index+1)
}

func average(t [R][C]int) int {
	var sum, avg int
	for i := range R {
		for j := range C {
			sum += t[i][j]
		}
	}
	avg = sum / (R * C)
	fmt.Printf("Promedio de venta: $%d", avg)
	return avg
}

func info(amount int, avg int) {
	if amount > avg {
		fmt.Println("El monto supera el promedio.")
	} else {
		fmt.Println("El monto no supera el promedio.")
	}
}

func main() {
	var table [R][C]int
	var depto, month int
	load(&table)
	show(table)
	fmt.Println()
	fmt.Print("Ingrese un departamento: ")
	fmt.Scan(&depto)
	min(table, depto)
	fmt.Println()
	avg := average(table)
	fmt.Println()
	fmt.Print("Ingrese un departamento: ")
	fmt.Scan(&depto)
	fmt.Print("Ingrese un mes: ")
	fmt.Scan(&month)
	info(table[depto-1][month-1], avg)

}
