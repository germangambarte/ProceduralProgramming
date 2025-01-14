package main

import (
	"reflect"
	"testing"
)

func TestCointainZeros(t *testing.T) {
	tests := []struct {
		name     string
		input    []int
		expected bool
	}{
		{"No zeros", []int{2, 3, 4, 5, 6, 3, 2}, false},
		{"Contains zeros", []int{2, 3, 4, 5, 6, 0, 2}, true},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			result := cointainZeros(test.input)
			if result != test.expected {
				t.Errorf("Expected: %v\nGot: %v", test.expected, result)
			}
		})
	}
}

func TestGetPairIndexComponents(t *testing.T) {
	tests := []struct {
		name     string
		input    []int
		expected []int
	}{
		{"Example 1", []int{5, 6, 3, 9, 1, 2, 3}, []int{5, 3, 1, 3}},
		{"Example 2", []int{2, 4, 7, 3, 1, 6, 7}, []int{2, 7, 1, 7}},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			result := getPairIndexComponents(test.input)
			if !reflect.DeepEqual(test.expected, result) {
				t.Errorf("Expected: %v\nGot: %v", test.expected, result)
			}
		})
	}
}

func TestPairItemsCount(t *testing.T) {
	tests := []struct {
		name     string
		input    []int
		expected int
	}{
		{"Example 1", []int{1, 3, 5, 4, 7, 6, 2, 9, 8}, 4},
		{"Example 2", []int{2, 3, 6, 1, 8, 10, 4, 2, 5}, 6},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			result := getPairItemsCount(test.input)
			if !reflect.DeepEqual(test.expected, result) {
				t.Errorf("Expected: %v\nGot: %v", test.expected, result)
			}
		})
	}
}
