package main
import (
	"fmt"
	// "math"
)

// func add(x, y int) int {
// 	return x+y
// }

func swap(x, y string) (string, string) {
	return y, x
}

func main() {
	x, y := swap("A", "B")
	fmt.Println(x, y)
	// fmt.Println(math.Pi)
	// fmt.Println(add(1, 2))
}
