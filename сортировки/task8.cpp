#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct date { //���� 
	int dd, mm, yy;
};

struct people {
	string Surname; //�������
	string Position; //��������� 
	date DateOfBirth; //���� �������� 
	int exp; //���� ������
	int Salary; //��������
};

vector<people> mergeSort(vector<people> l) {
	if (l.size() > 1) {
		int mid = l.size() / 2;

		vector <people> lefthalf(l.begin(), l.begin() + mid);
		vector <people> righthalf(l.begin() + mid, l.end());

		lefthalf = mergeSort(lefthalf);
		righthalf = mergeSort(righthalf);

		int i = 0;
		int j = 0;
		int k = 0;
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

	vector <people> v; //������ ����������� 
	people temp; //������� ��������� 
	string line; //������� ������ ���������� 
	string data; //������� ������ ���������� ��� ������ ������
	string text; //���������� ��� �������� ����� 
	ifstream fin("input.txt"); //����� ����� ��������� �������� 

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			int j = 0;
			data = line;
			while (j != data.size()) {
				temp.Surname = "";
				while (data[j] != ';') { //���������� ������� � temp
					temp.Surname += data[j];
					j++;
				}
				j++;

				temp.Position = "";
				while (data[j] != ';') { //���������� ��������� � temp 
					temp.Position += data[j];
					j++;
				}
				j++;

				text = "";
				while (data[j] != '.') { //����� ������ 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.dd = stoi(text);

				text = "";
				while (data[j] != '.') { //����� 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.mm = stoi(text);

				text = "";
				while (data[j] != ';') { //��� 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.yy = stoi(text);

				text = "";
				while (data[j] != ';') { //���� ������ 
					text += data[j];
					j++;
				}
				j++;
				temp.exp = stoi(text);

				text = "";
				while (data[j] != ';') { //��
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

	ofstream fout; //������ ������ ������
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
