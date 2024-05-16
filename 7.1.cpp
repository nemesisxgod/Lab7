#include <iostream>
using namespace std;

// Функция для добавления цифры к числу, увеличивая его разрядность
int digit_add(long long number, int dch) {
	while (number >= dch) {
		dch *= 10;
	}

	return dch + number;
}

// Рекурсивная функция для формирования суммы N с помощью операций сложения и вычитания
bool func(long long N, long long sum, long long head, long long tail) {
	if (head == 0) {
		if (sum + tail == N)
			cout << tail;

		return sum + tail == N;
	}

	if (func(N, sum + tail, head / 10, head % 10)) {
		cout << "+" << tail; // Если удалось сформировать сумму, добавляем "+" и tail к выводу
	}
	else if (func(N, sum - tail, head / 10, head % 10)) {
		cout << "-" << tail; // Если удалось сформировать разность, добавляем "-" и tail к выводу
	}
	else if (func(N, sum, head / 10, digit_add(tail, head % 10))) // Если не удалось сформировать сумму или разность, попробуем добавить новую цифру к tail
	{
	}
	else {
		return false; // Если ни одна операция не привела к нужной сумме, возвращаем false
	}

	return true;
}

int main() {
	long long N, digits;
	cin >> N >> digits;
	func(N, 0, digits / 10, digits % 10);
}
