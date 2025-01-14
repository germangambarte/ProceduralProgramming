package main

import (
	"testing"
	"unsafe"
)

func TestReplaceTwosForZeros(t *testing.T) {
	test := struct {
		name     string
		input    string
		expected string
	}{"Example", "Programación Procedural 2025", "Programación Procedural 0005"}

	t.Run(test.name, func(t *testing.T) {
		result := replaceTwosForZeros(test.input)
		if result != test.expected {
			t.Errorf("Expected: %v Got: %v", test.expected, result)
		}
	})
}

func TestCopyingString(t *testing.T) {
	test := struct {
		name   string
		input  string
		expect struct {
			safe   bool
			unsafe bool
		}
	}{
		"Example",
		"Programación Procedural 2025",
		struct {
			safe   bool
			unsafe bool
		}{true, false},
	}
	t.Run(test.name, func(t *testing.T) {
		result := copyingString(test.input)
		if result != test.input {
			t.Errorf("result: %v test.input: %v", result, test.input)
		}
		if unsafe.StringData(result) == unsafe.StringData(test.input) {
			t.Errorf("result: %v test.input: %v", result, test.input)
		}
	})
}

func TestVowelsCounter(t *testing.T) {
	test := struct {
		name     string
		input    string
		expected int
	}{"Example", "Programación Procedural 2025", 9}

	t.Run(test.name, func(t *testing.T) {
		result := vowelsCounter(test.input)
		if result != test.expected {
			t.Errorf("Expected: %v\nGot: %v", test.expected, result)
			// t.Errorf("Got: %v", result)
		}
	})

}
