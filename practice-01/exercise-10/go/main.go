package main

import (
	"fmt"
	"math"
	"math/rand"
)

const R = 5
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

func count(t [R][C]int) {
	var count int
	for j := range C {
		for i := range R {
			count += t[i][j]
		}
		fmt.Printf("Del medicamento %d se vendieron %d unidades.\n", j+1, count)
		count = 0
	}
}

func max(t [R][C]int, code int) {
	var max = math.MinInt
	var index int
	for i := range C {
		if t[code][i] > max {
			max = t[code][i]
			index = i
		}
	}
	fmt.Printf("El medicamentos con mayor ventas es %d (%d).\n", index+1,max)
}

func main() {
	var table [R][C]int
	load(&table)
	show(table)
	fmt.Println()
	count(table)
	fmt.Println()
	fmt.Print("Ingrese una farmacia: ")
	var code int
	fmt.Scan(&code)
	max(table, code-1)
}
