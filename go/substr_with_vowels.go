package main

import "fmt"

const vowels = "aeoiu"

func check_vowels(char byte) bool {
	result := false
	for i := 0; i < len(vowels); i++ {
		if vowels[i] == char {
			result = true
			break
		}
	}
	return result
}

func solution(text string) int {
	var number = 0
	var count = 0

	var num_groups int = len(text) / 3
	var start = 0
	var end = 0

	for ngroup := 0; ngroup <= num_groups; ngroup++ {
		end = start + 3
		if end > len(text) {
			end = len(text)
		}
		sub_str := text[start:end]
		for _, ch := range sub_str {
			if check_vowels(byte(ch)) {
				number += 1
			}
		}

		if number == 2 {
			count += 1
		}

		number = 0
		start = end
	}

	return count
}

func main() {
	result := solution("aibebo")
	result_1 := solution("aobidetyuityorevghtyet")

	fmt.Printf("Result: %d\n", result)
	fmt.Printf("Result 1: %d\n", result_1)
}
