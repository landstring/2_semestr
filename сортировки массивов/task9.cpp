#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int num_lines(string file_name) { //подсчёт строк в массиве
	ifstream file(file_name);
	string line;
	int result = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			result++;
		}
	}
	file.close();
	return result;
}

int** import_from_file(string file_name) { //импорт массива из файла
	int n = num_lines(file_name);
	ifstream file(file_name);
	int** result = new int* [n];
	for (int i = 0; i < n; i++) {
		result[i] = new int[n];
	}

	string line;
	if (file.is_open()) {
		int col = 0;
		int j = 0;
		while (getline(file, line)) {
			string data = line;
			int num;
			string now_num = "";
			for (int i = 0; i < data.size(); i++) {
				if (data[i] == ' ') {
					num = stoi(now_num);
					now_num = "";
					result[col][j] = num;
					j++;
				}
				else {
					now_num += data[i];
				}
			}
			num = stoi(now_num);
			now_num = "";
			result[col][j] = num;
			col++;
			j = 0;
		}
	}
	file.close();
	return result;
}

void output_to_file(string file_name, int** arr, int n) {
	ofstream file;
	file.open(file_name);
	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				file << arr[i][j] << ' ';
			}
			file << endl;
		}
	}
	file.close();
}

int* gapSort(int* l, int n) {
	int gap = (1.0 * n) / 1.247;
	if (gap < 1) {
		gap = 1;
	}
	while (gap >= 1) {
		
		for (int j = 0; j < n - gap; j++) {
			if (l[j] < l[j + gap]) {
				int tmp = l[j];
				l[j] = l[j + gap];
				l[j + gap] = tmp;
			}
		}
		gap /= 1.247;
	}
	for (int i = 0; i < n; i++) {
		cout << l[i] << ' ';
	}
	cout << endl;
	return l;

}

int** gapSort_start(int** mas, int n) {
	for (int col = 0; col < n; col++) {
		if (col % 3 == 2) {
			int* a = new int[n];
			for (int i = 0; i < n; i++) { //взяли столбец
				a[i] = mas[i][col];
			}

			a = gapSort(a, n); //отсортировали столбец 

			for (int i = 0; i < n; i++) { //записали отсортированный столбец вместо исходного в массив 
				mas[i][col] = a[i];
			}
			delete[] a; //удалили промежуточный столбец из памяти
		}
	}
	return mas;
	
}


int main()
{
	int size = num_lines("input.txt"); //n-мерность 
	int** array = new int* [size]; //инициализация массива 
	array = import_from_file("input.txt"); //массив, импортированный из файла

	array = gapSort_start(array, size); //применение сортировки

	output_to_file("output.txt", array, size);

	for (int i = 0; i < size; i++) { // удаление динамического массива из памяти
		delete[] array[i];
	}
	delete[] array;
}