package main

import (
	"fmt"
	"math/rand"
)

const R = 4
const C = 6

// func load(c *[R][C]int) {
// 	var thematic, turn int
// 	fmt.Println("Ingrese la temática: ")
// 	fmt.Scan(&thematic)
// 	for thematic != 0 {
// 		if thematic < 1 && thematic > R {
// 			fmt.Println("El área temática debe ser un entero entre 1-6")
// 			fmt.Println("Ingrese la temática: ")
// 			fmt.Scan(&thematic)
// 			continue
// 		}

// 		fmt.Println("Ingrese el turno: ")
// 		fmt.Scan(&turn)
// 		if turn < 1 && turn > C {
// 			fmt.Println("El turno debe ser un entero entre 1-4")
// 			continue
// 		}

// 		c[thematic-1][turn-1]++

//			fmt.Println("Ingrese la temática: ")
//			fmt.Scan(&thematic)
//		}
//	}
func randomLoad(c *[R][C]int) {
	for i := range R {
		for j := range C {
			c[i][j] = rand.Intn(10)
		}
	}
}

func show(c [R][C]int) {
	for _, r := range c {
		fmt.Println(r)
	}
}

func count(c [R][C]int) {
	var sum int
	for i := range R {
		for j := range C {
			sum += c[i][j]
		}
		fmt.Printf("El turno %d, tiene %d alumnos.\n", i+1, sum)
		sum = 0
	}
}

func average(c [R][C]int) {
	var sum, thematic int
	fmt.Print("Ingresar temática: ")
	fmt.Scan(&thematic)
	for j := range C {
		sum += c[thematic-1][j]
	}
	fmt.Printf("Promedio de inscriptos (T%d): %d\n", thematic, sum/6)
}

func main() {
	var congress [R][C]int
	randomLoad(&congress)
	show(congress)
	fmt.Println()
	count(congress)
	fmt.Println()
	average(congress)
}
