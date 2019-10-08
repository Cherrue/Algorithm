/************************************************
 * @TITLE : Robots on a grid
 * @DATE : 2019-10-08
 * @NUMBER : 5011
 * @URL : https://www.acmicpc.net/problem/5011
 * @CATEGORY : DFS / BFS
 * @TIME : 1sec
 * @MEMORY : 128MB
 * @ DFS : timeout / BFS : 메모리부족으로 실패!
 ************************************************
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int g_count = 0;
int g_count_normal = 0; 

void BFS(char** data, int size_x, int size_y, int x, int y) {
	queue<int> Q;

	Q.push(y * size_x + x);

	while (!Q.empty()) {
		int now_y = Q.front() / size_x;
		int now_x = Q.front() % size_x;
		Q.pop();

		int next_y = now_y;
		int next_x = now_x + 1;
		if (next_x < size_x) {
			if (next_y == size_y - 1 && next_x == size_x - 1) {
				g_count++;
			}
			
			if (data[next_y][next_x] == '.') {
				Q.push(next_y * size_x + next_x);
			}
			
		}

		next_y = now_y + 1;
		next_x = now_x;
		if (next_y < size_y) {
			if (next_y == size_y - 1 && next_x == size_x - 1) {
				g_count++;
			}
			
			if (data[next_y][next_x] == '.') {
				Q.push(next_y * size_x + next_x);
			}
		}
		

	}
}
void repeat_DFS(char** arr, int x, int y, int size) {
	stack<pair<int, int>> s;
	s.push(make_pair(x, y));

	while (!s.empty()) {/*
		if (g_count > 100) {
			cout << "too much way";
			break;
		}*/

		x = s.top().first;
		y = s.top().second;
		s.pop();

		int nx = x + 1;
		int ny = y;

		if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
			if (ny == size - 1 && nx == size - 1)
				g_count++;

			if (arr[ny][nx] == '.') {
				s.push(make_pair(nx, ny));
			}
		}

		nx = x;
		ny = y+1;

		if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
			if (ny == size - 1 && nx == size - 1)
				g_count++;

			if (arr[ny][nx] == '.') {
				s.push(make_pair(nx, ny));
			}
		}
	}
}
void broken_DFS(char** arr, int x, int y, int size) {
	if (g_count > 100) {
		//cout << "too much way";
		return;
	}
	if (x < 0 || x >= size)
		return;
	if (y < 0 || y >= size)
		return;
	if (arr[y][x] == '#')
		return;
	if (x == size - 1 && y == size - 1) {
		g_count++;
		return;
	}

	broken_DFS(arr, x + 1, y, size);
	broken_DFS(arr, x, y + 1, size);
}
void normal_DFS(char** arr, bool** visited, int x, int y, int size) {
	if (x == size - 1 && y == size - 1) {
		g_count_normal++;
		return;
	}
	if (x < 0 || x >= size)
		return;
	if (y < 0 || y >= size)
		return;
	if (arr[y][x] == '#')
		return;
	if (visited[y][x] == true)
		return;
	visited[y][x] = true;
	normal_DFS(arr, visited, x - 1, y, size);
	normal_DFS(arr, visited, x, y - 1, size);
	normal_DFS(arr, visited, x + 1, y, size);
	normal_DFS(arr, visited, x, y + 1, size);
}
int main() {
	int size;
	cin >> size;
	char** grid = new char* [size];
	for (int i = 0; i < size; i++) {
		grid[i] = new char[size];
		for (int j = 0; j < size; j++)
			cin >> grid[i][j];
	}
	bool** visited = new bool* [size];
	for (int i = 0; i < size; i++) {
		visited[i] = new bool[size];
		for (int j = 0; j < size; j++)
			visited[i][j] =  false;
	}
	//while (1) {}
	//broken_DFS(grid, 0, 0, size);
	//repeat_DFS(grid, 0, 0, size);
	BFS(grid, size, size, 0, 0);
	if (g_count != 0) {
		cout << g_count;
	}
	else {
		//normal_DFS(grid, visited, 0, 0, size);
		if(g_count_normal != 0)
			cout << "THE GAME IS A LIE";
		else
			cout << "INCONCEIVABLE";
	}

	for (int i = 0; i < size; i++) {
		delete[]grid[i];
	}
	delete[]grid;
	for (int i = 0; i < size; i++) {
		delete[]visited[i];
	}
	delete[]visited;
	return 0;
}
/*
************************************************
* TEST INPUT 1
************************************************
5
.....
#..#.
#..#.
...#.
.....
************************************************
* TEST OUTPUT 1
************************************************
6
************************************************
************************************************
* TEST INPUT 2
************************************************
7
......#
####...
.#.....
.#...#.
.#.....
.#..###
.#.....
************************************************
* TEST OUTPUT 2
************************************************
THE GAME IS A LIE
************************************************
*/
