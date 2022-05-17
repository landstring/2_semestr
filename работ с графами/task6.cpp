#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

vector<int> searchParents(vector<vector<int>> Gr, int x, vector<int> way) {	
	if (find(way.begin(), way.end(), x) != way.end()) {
		vector<int> res;
		return res;
	}
	else {
		way.push_back(x);
		vector<int> res;
		vector<int> resRecursion;
		for (int i = 0; i < Gr.size(); i++) {
			for (int j = 0; j < Gr[i].size(); j++) {
				if (Gr[i][j] == x) {
					res.push_back(i);
				}
			}
		}

		int N = res.size();
		for (int i = 0; i < N; i++) {
			resRecursion = searchParents(Gr, res[i], way);
			for (int j = 0; j < resRecursion.size(); j++) {
				if (x != resRecursion[j]) {
					res.push_back(resRecursion[j]);
				}
			}
		}
		return res;
	}
}

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

	int s; //вершина
	cout << "Enter node: "; cin >> s;
	vector<int> way; //путь обхода по вершине
	vector<int> result = searchParents(Gr, s, way);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}