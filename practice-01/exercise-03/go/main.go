package main

import "fmt"

const N = 3

type Student struct {
	name     string
	lastname string
	dni      int
}

func load(x *[N]Student) {
	for i := 0; i < N; i++ {
		fmt.Print("Nombre: ")
		fmt.Scan(&x[i].name)
		fmt.Print("Apellido: ")
		fmt.Scan(&x[i].lastname)
		fmt.Print("DNI: ")
		fmt.Scan(&x[i].dni)
	}
}

func show(x *[N]Student) {
	for _, s := range x {
		fmt.Printf("nombre: %s, apellido: %s, dni: %d\n", s.name, s.lastname, s.dni)
	}
}

func count(x *[N]Student) {
	var count = 0
	for _, s := range x {
		if s.dni > 40_000_000 {
			count++
		}
	}
	fmt.Printf("Cantidad de DNIs mayores a 40M: %d\n", count)
}

func main() {
	var students [N]Student
	load(&students)
	fmt.Println()
	show(&students)
	fmt.Println()
	count(&students)
}
