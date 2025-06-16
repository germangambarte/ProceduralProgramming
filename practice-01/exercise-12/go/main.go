package main

import (
	"fmt"
	"math"
	"math/rand"
)

const N = 20
const D = 5

type Respondent struct {
	departamentId    int
	lastPayAmount    float32
	satisfactionRate int
}

type DepartmentInfo struct {
	nOfRespondents int
	highestBilling float32
}

func loadRespondents(r *[N]Respondent) {
	for i := range N {
		r[i] = Respondent{
			departamentId:    rand.Intn(D) + 1,                // 1 a 19
			lastPayAmount:    float32(rand.Intn(10000)) / 100, // Ej: entre 0.00 y 99.99
			satisfactionRate: rand.Intn(3) + 1,                // 1 a 3
		}
	}
}

func showRespondents(r [N]Respondent) {
	for i := range N {
		fmt.Println(r[i])
	}
}

func processInfo(r [N]Respondent, d *[D]DepartmentInfo, t *[D][3]int) {
	for i := range N {
		index := r[i].departamentId - 1
		(*d)[index].nOfRespondents++
		if (*d)[index].highestBilling < r[i].lastPayAmount {
			(*d)[index].highestBilling = r[i].lastPayAmount
		}
		t[index][r[i].satisfactionRate-1]++
	}
}
func showSatisfactionTable(t [D][3]int, dNames []string) {
	fmt.Println("Satisfaction Rate: ")
	for index, r := range t {
		fmt.Print(dNames[index], " :\n")
		fmt.Println("  - Óptima: ",r[0])
		fmt.Println("  - Buena: ",r[1])
		fmt.Println("  - Mala: ",r[2])
	}
}

func showDepartmentsInfo(d [D]DepartmentInfo, dNames []string) {
	fmt.Println("Department Info: ")
	for index, r := range d {
		fmt.Print("  ", dNames[index], " : ", r, "\n")
	}
}

func showMaxBillingDepartments(d [D]DepartmentInfo, dNames []string) {
	var max = float32(math.MinInt32)
	for _, data := range d {
		if max < data.highestBilling {
			max = data.highestBilling
		}
	}
	fmt.Println("Mayor facturación: $", max)
	fmt.Println("Lista de departamentos que la obtuvieron: ")
	for i := range D {
		if d[i].highestBilling == max {
			fmt.Println("  - ", dNames[i])
		}
	}
}

func main() {
	departments := []string{
		"Albardón",
		"Angaco",
		"Calingasta",
		"Capital",
		"Caucete",
		// "Chimbas",
		// "Iglesia",
		// "Jachal",
		// "9 de Julio",
		// "Pocito",
		// "Rawson",
		// "Rivadavia",
		// "San Martín",
		// "Santa Lucía",
		// "Sarmiento",
		// "Ullum",
		// "Valle Fértil",
		// "25 de Mayo",
		// "Zonda",
	}
	var departmentsInfo [D]DepartmentInfo
	var satisfactionTable [D][3]int
	var respondents [N]Respondent
	loadRespondents(&respondents)
	showRespondents(respondents)
	fmt.Println()
	processInfo(respondents, &departmentsInfo, &satisfactionTable)
	fmt.Println()
	showDepartmentsInfo(departmentsInfo, departments)
	fmt.Println()
	showSatisfactionTable(satisfactionTable, departments)
	fmt.Println()
	showMaxBillingDepartments(departmentsInfo,departments)
}
