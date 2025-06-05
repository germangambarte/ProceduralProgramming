package main

import "fmt"

const N = 4

type Candidate struct {
	name  string
	genre string
	dni   int
	age   int
	code  int
}

func load(x *[N]Candidate) {
	for i := 0; i < N; i++ {
		fmt.Print("Nombre: ")
		fmt.Scan(&x[i].name)
		fmt.Print("Genero: ")
		fmt.Scan(&x[i].genre)
		fmt.Print("DNI: ")
		fmt.Scan(&x[i].dni)
		fmt.Print("Age: ")
		fmt.Scan(&x[i].age)
		fmt.Print("Code: ")
		fmt.Scan(&x[i].code)
	}
}

func countWomen(x *[N]Candidate) {
	var count = 0
	for _, c := range x {
		if c.genre == "F" && c.age < 30 {
			count++
		}
	}
	fmt.Printf("Cantidad de mujeres -30 años: %d\n", count)
}

func averageMenAge(x *[N]Candidate) {
	var count = 0
	var sum = 0
	for _, c := range x {
		if c.genre == "M" {
			sum += c.age
			count++
		}
	}
	fmt.Printf("Edad promedio de los varones: %.2f\n", float32(sum/count))
}

func printCandidates(x *[N]Candidate) {
	for _, c := range x {
		if c.code == 14 {
			fmt.Printf("nombre: %s, dni: %d\n", c.name, c.dni)
		}
	}
}

func main(){
	var candidate [N]Candidate
	load(&candidate)
	fmt.Println()
	countWomen(&candidate)
	fmt.Println()
	averageMenAge(&candidate)
	fmt.Println()
	printCandidates(&candidate)
}
