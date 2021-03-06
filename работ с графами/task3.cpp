#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int N, M; //кол-во вершин и рёбер
	cout << "Enter N, M: ";
	cin >> N >> M; //ввод кол-ва рёбер и вершин
	int x, y; //две вершины 
	vector<vector<int>> Gr;
	Gr.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		if (x < N && y < N) {
			Gr[x].push_back(y);
		}
	}
	for (int i = 0; i < Gr.size(); i++) {
		sort(Gr[i].begin(), Gr[i].end());
		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
	}
	
	
	for (int i = 0; i < Gr.size(); i++) {
		cout << Gr[i].size() << ' ';
	}
}