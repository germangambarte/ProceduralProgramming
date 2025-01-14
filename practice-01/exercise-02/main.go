package main

import (
	"slices"
	"strings"
)

func replaceTwosForZeros(phrase string) string {
	result := strings.Map(func(r rune) rune {
		if r == '2' {
			return '0'
		}
		return r
	}, phrase)
	return result
}

func copyingString(source string) string {
	return strings.Clone(source)
}

func vowelsCounter(phrase string) int {
	posibleVowels := []rune{'a', 'e', 'i', 'o', 'u', 'á', 'é', 'í', 'ó', 'ú'}
	counter := 0
	for _, letter := range phrase {
		if slices.Contains(posibleVowels, letter) {
			counter++
		}
	}
	return counter
}
