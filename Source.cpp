#include <iostream>

#include <thread>
#include <chrono>

using namespace std;

void swap(int* sh, int i, int j){
	int s = sh[i];
	sh[i] = sh[j];
	sh[j] = s;
}

bool NextSet(int* sh, int n){
	int j = n - 2;
	while (j != -1 && sh[j] >= sh[j + 1]) { j--; }
	if (j == -1) {return false;} // больше перестановок нет
	int k = n - 1;
	while (sh[j] >= sh[k]) { k--; }
	swap(sh, j, k);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r) {swap(sh, l++, r--);}
	return true;
}

void Print(int* a, int n, int num)  // вывод перестановки
{
	cout.width(3); // ширина поля вывода номера перестановки
	cout << num << ": ";
	for (int i = 0; i < n; i++) { cout << a[i] << " "; }
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, * sh, num = 1, q = 0;
	cout << "n = ";
	cin >> n;
	sh = new int[n];
	for (int i = 0; i < n; i++) {sh[i] = i + 1;}

	char ch;
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	start = std::chrono::high_resolution_clock::now();

	Print(sh, n, num);
	while (NextSet(sh, n)) {
		for (int i = 0; i < n; i++) { if (sh[i] == i + 1) { q++; } }
		if (q > 0) { num++; Print(sh, n, num); }
		q = 0;
	}
	cout << "Всего перестановок " << num;

	stop = std::chrono::high_resolution_clock::now();
	int time = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
	std::cout << "\nВремя: " << time / 3600 << " часов " << (time % 360) / 60 << " минут " << time % 60 << " секунд\n";

	cin.get(); cin.get();
	return 0;
}
