#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct date { //дата 
	int dd, mm, yy;
};

struct people {
	string Surname; //фамили€
	string Position; //должность 
	date DateOfBirth; //дата рождени€ 
	int exp; //стаж работы
	int Salary; //зарплата
};

vector<people> mergeSort(vector<people> l) {
	if (l.size() > 1) {
		int mid = l.size() / 2;

		vector <people> lefthalf(l.begin(), l.begin() + mid);
		vector <people> righthalf(l.begin() + mid, l.end());

		lefthalf = mergeSort(lefthalf);
		righthalf = mergeSort(righthalf);

		unsigned i = 0;
		unsigned j = 0;
		unsigned k = 0;
		while (i < lefthalf.size() && j < righthalf.size()) {
			if (lefthalf[i].Salary < righthalf[j].Salary || (lefthalf[i].Salary == righthalf[j].Salary && lefthalf[i].DateOfBirth.yy < righthalf[j].DateOfBirth.yy)) {
				l[k] = lefthalf[i];
				i++;
			}
			else {
				l[k] = righthalf[j];
				j++;
			}
			k++;
		}

		while (i < lefthalf.size()) {
			l[k] = lefthalf[i];
			i++;
			k++;
		}

		while (j < righthalf.size()) {
			l[k] = righthalf[j];
			j++;
			k++;
		}

	}
	return l;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	vector <people> v; //список сотрудников 
	people temp; //текущий сотрудник 
	string line; //текуща€ строка докуммента 
	string data; //текуща€ строка докуммента дл€ вывода данных
	string text; //переменна€ дл€ хранени€ строк 
	ifstream fin("input.txt"); //поток ввода текстовый документ 

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			int j = 0;
			data = line;
			while (j != data.size()) {
				temp.Surname = "";
				while (data[j] != ';') { //сохранение фамилии в temp
					temp.Surname += data[j];
					j++;
				}
				j++;

				temp.Position = "";
				while (data[j] != ';') { //сохранение должности в temp 
					temp.Position += data[j];
					j++;
				}
				j++;

				text = "";
				while (data[j] != '.') { //число мес€ца 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.dd = stoi(text);

				text = "";
				while (data[j] != '.') { //мес€ц 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.mm = stoi(text);

				text = "";
				while (data[j] != ';') { //год 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.yy = stoi(text);

				text = "";
				while (data[j] != ';') { //стаж работы 
					text += data[j];
					j++;
				}
				j++;
				temp.exp = stoi(text);

				text = "";
				while (data[j] != ';') { //«ѕ
					text += data[j];
					j++;
				}
				j++;
				temp.Salary = stoi(text);
				v.push_back(temp);
			}
		}
	}
	fin.close();

	v = mergeSort(v);

	ofstream fout; //объект вывода данных
	fout.open("output.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < v.size(); i++) {
			fout << v[i].Surname << ';';
			fout << v[i].Position << ';';
			if (v[i].DateOfBirth.dd < 10) {
				fout << '0';
			}
			fout << v[i].DateOfBirth.dd << '.';
			if (v[i].DateOfBirth.mm < 10) {
				fout << '0';
			}
			fout << v[i].DateOfBirth.mm << '.';
			fout << v[i].DateOfBirth.yy << ';' << v[i].exp << ';' << v[i].Salary << ';' << endl;
		}
	}
	fout.close();

}
