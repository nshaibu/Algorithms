package main

import (
	"errors"
	"fmt"
	"math"
)

func two_sums(nums []int, target int) ([2]int, error) {
	visited := map[int]int{}

	for index, element := range nums {
		sub_target := int(math.Abs(float64(target - element)))
		_, ok := visited[sub_target]
		if ok {
			return [2]int{index, visited[sub_target]}, nil
		} else {
			visited[element] = index
		}
	}
	return [2]int{0, 0}, errors.New("Failed")
}

func main() {
	arr := [...]int{3, 4, 7, 9, 0, 3}
	fmt.Println(two_sums(arr[:], 10))
}
