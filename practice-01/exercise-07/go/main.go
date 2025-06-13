package main

import (
	"fmt"
	"math/rand"
)

const R = 5
const C = 4

func load(table *[R][C]int) {
	for i := range R {
		for j := range C {
			table[i][j] = rand.Intn(150)
		}
	}
}

func show(table [R][C]int) {
	for _, a := range table {
		fmt.Println(a)
	}
}

func average(table [R][C]int) {
	var sum int
	for i := range C {
		sum += table[2][i]
	}
	fmt.Printf("Promedio: %d\n", sum/C)
}

func count(table [R][C]int) {
	var sum int
	for i := range R {
		for j := range C {
			if table[i][j] > 100 {
				sum++
			}
		}
	}
	fmt.Printf("Contador (+100): %d\n", sum)
}

func main() {
	var table [R][C]int
	load(&table)
	show(table)
	fmt.Println()
	average(table)
	fmt.Println()
	count(table)
}
