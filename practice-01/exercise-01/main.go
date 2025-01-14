package main

import (
	"math/rand/v2"
)

const (
	N = 5
)

func generateArray() []int {
	var array = make([]int, N)
	for i := range array {
		array[i] = rand.IntN(100)
	}
	return array
}

func cointainZeros(array []int) bool {
	for _, num := range array {
		if num == 0 {
			return true
		}
	}
	return false
}

func getPairIndexComponents(array []int) []int {
	var pairComponents = []int{}
	for i := range array {
		if i%2 == 0 {
			pairComponents = append(pairComponents, array[i])
		}
	}
	return pairComponents
}

func getPairItemsCount(array []int) int {
	var count = 0
	for _, num := range array {
		if num%2 == 0 {
			count += 1
		}
	}
	return count
}
