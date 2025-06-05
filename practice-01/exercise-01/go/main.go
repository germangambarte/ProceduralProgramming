package main

import (
	"fmt"
	"math/rand"
)

const N = 20

func load(a *[N]int) {
	for i := range N {
		a[i] = rand.Intn(100)
	}
}

func show(a *[N]int) {
	fmt.Println(*a)
}

func checkZeros(a *[N]int) {
	var i = 0
	for i < N && a[i] != 0 {
		i++
	}
	if i < N {
		fmt.Println("Hay al menos un cero en el arreglo.")
	} else {
		fmt.Println("No hay ceros en el arreglo.")
	}
}

func printOddPositions(a *[N]int) {
	fmt.Print("Odd Position values: ")
	for i := range N {
		if i%2 == 0 {
			fmt.Printf("%d ", a[i])
		}
	}
}

func countOddValues(a *[N]int) {
	var count = 0

	for i := range N {
		if a[i]%2 == 0 {
			count++
		}
	}
	fmt.Printf("\nCount of odd nums: %d\n", count)
}

func main() {
	var arr [N]int
	load(&arr)
	show(&arr)
	checkZeros(&arr)
	printOddPositions(&arr)
	countOddValues(&arr)
}
