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

int* bubbleSort(int* d, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (d[j - 1] > d[j]) {
				int tmp = d[j - 1];
				d[j - 1] = d[j];
				d[j] = tmp;
			}
		}
	}
	return d;
}
int** bubbleSort_start(int** mas, int n) {

	for (int i = 1; i < n; i++) {
		int* a = new int[i + 1];
		for (int j = 0; j <= i; j++) {
			a[j] = mas[i - j][j];
		}

		a = bubbleSort(a, i + 1);

		for (int j = 0; j <= i; j++) {
			mas[i - j][j] = a[j];
		}
		delete[] a;
	}

	for (int j = 1; j < n - 1; j++) {
		int* a = new int[n - j];
		int k = 0;
		for (int i = n - 1; i >= j; i--) {
			a[k] = mas[i][k + j];
			k++;
		}

		a = bubbleSort(a, n - j);

		
		k = 0;
		for (int i = n - 1; i >= j; i--) {
			mas[i][k + j] = a[k];
			k++;
		}
		delete[] a;
	}
	return mas;
}

int main()
{
	int size = num_lines("input.txt"); //n-мерность 
	int** array = new int* [size]; //инициализация массива 
	array = import_from_file("input.txt"); //массив, импортированный из файла

	array = bubbleSort_start(array, size); //применение сортировки

	output_to_file("output.txt", array, size);

	for (int i = 0; i < size; i++) // удаление динамического массива из памяти
		delete[] array[i];
	delete[] array;
}