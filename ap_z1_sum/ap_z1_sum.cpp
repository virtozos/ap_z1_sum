#include <iostream>

using namespace std;

int next_number(int x) {
	int sum = 0;
	for (; x; x /= 10)
		sum += ((x % 10) * (x % 10));
	return sum;
}

void sequence(int* array, int& sequence_start, int& sequence_end) {
	bool check = true;
	for (int i = 1; check; i++) {
		array[i] = next_number(array[i - 1]);

		for (int j = 0; j < i; j++) {
			if (array[i] == array[j]) {
				sequence_start = j;
				sequence_end = i;
				check = false;
				break;
			}
		}

	}
}

int min_sum(int* array_1, int* array_2, int sequence_end_1, int sequence_end_2) {
	bool check = true;
	for (int i = 0; i < sequence_end_1 && check; i++) {
		for (int j = 0; j < sequence_end_2 && check; j++) {
			if (array_1[i] == array_2[j]) {
				return i + 1 + j + 1;
				check = false;
			}
		}
		if (i == sequence_end_1 - 1 && check == true)
			return 0;
	}
}

int main()
{
	int a, b;
	cin >> a;
	cin >> b;

	while (a || b) {

		int* array_a = new int[200], *array_b = new int[200];
		int sequence_start_a, sequence_end_a, sequence_start_b, sequence_end_b, min_sum_a, min_sum_b;
		array_a[0] = a;
		array_b[0] = b;

		//zapelnia tablice kolejnymi liczbami, az znajdzie cykl
		sequence(array_a, sequence_start_a, sequence_end_a);
		sequence(array_b, sequence_start_b, sequence_end_b);

		cout << a << ' ' << b << ' ';
		//szuka wspolnej liczby
		min_sum_a = min_sum(array_a, array_b, sequence_end_a, sequence_end_b);
		min_sum_b = min_sum(array_b, array_a, sequence_end_b, sequence_end_a);

		if (!min_sum_a || min_sum_a < min_sum_b)
			cout << min_sum_a;
		else
			cout << min_sum_b;

		delete[] array_a;
		delete[] array_b;
		cin >> a;
		cin >> b;

		if (a || b)
			cout << '\n';
	}
}
