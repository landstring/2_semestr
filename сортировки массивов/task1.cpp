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
	int** result = new int*[n];
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
				else{
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

int* quickSort(int* column, int L, int R) {
	int i = L;
	int j = R - 1;
	int middle = column[R / 2];
	while (i <= j) {
		while (column[i] < middle) {
			i++;
		}
		while (column[j] > middle) {
			j--;
		}
		if (i <= j) {
			int tmp = column[i];
			column[i] = column[j];
			column[j] = tmp;
			i++;
			j--;
		}
	}
	if (j > L) {
		column = quickSort(column, L, j);
	}
	if (i < R - 1) {
		column = quickSort(column, i, R);
	}
	return column;

}
int** quickSort_start(int** mas, int n) {
	for (int col = 0; col < n; col++) {
		int* a = new int[n];
		for (int i = 0; i < n; i++) { //взяли столбец
			a[i] = mas[i][col];
		}

		a = quickSort(a, 0, n); //отсортировали столбец 

		for (int i = 0; i < n; i++) { //записали отсортированный столбец вместо исходного в массив 
			mas[i][col] = a[i];
		}
		delete[] a; //удалили промежуточный столбец из памяти 
	}
	return mas;
	
}

int main()
{
	int size = num_lines("input.txt"); //n-мерность 
	int** array = new int* [size]; //инициализация массива 
	array = import_from_file("input.txt"); //массив, импортированный из файла
	
	array = quickSort_start(array, size); //применение сортировки
	
	output_to_file("output.txt", array, size);

	for (int i = 0; i < size; i++) // удаление динамического массива из памяти
		delete[] array[i];
	delete[] array;
}

