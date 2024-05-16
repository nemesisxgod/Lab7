package main

import (
	"fmt"
)

// Функция для добавления цифры к числу, увеличивая его разрядность
func digitAdd(number int64, dch int) int {
	for number >= int64(dch) {
		dch *= 10
	}
	return dch + int(number)
}

// Рекурсивная функция для формирования суммы N с помощью операций сложения и вычитания
func function(N, sum, head, tail int64) bool {
	if head == 0 {
		if sum+tail == N {
			fmt.Print(tail)
		}
		return sum+tail == N
	}

	if function(N, sum+tail, head/10, head%10) {
		fmt.Print("+", tail) // Если удалось сформировать сумму, добавляем "+" и tail к выводу
	} else if function(N, sum-tail, head/10, head%10) {
		fmt.Print("-", tail) // Если удалось сформировать разность, добавляем "-" и tail к выводу
	} else if function(N, sum, head/10, int64(digitAdd(tail, int(head%10)))) {
		// Если не удалось сформировать сумму или разность, попробуем добавить новую цифру к tail
	} else {
		return false // Если ни одна операция не привела к нужной сумме, возвращаем false
	}

	return true
}

func main() {
	var N, digits int64
	fmt.Scan(&N, &digits)
	function(N, 0, digits/10, digits%10)
}
