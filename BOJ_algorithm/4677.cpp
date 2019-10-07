/************************************************
 * @TITLE : Oil Deposits
 * @DATE : 2019-10-07
 * @NUMBER : 4677
 * @URL : https://www.acmicpc.net/problem/4677
 * @CATEGORY : BFS(queue)
 * @TIME : 1sec
 * @MEMORY : 128MB
 ************************************************
*/
#include<iostream>
#include<queue> // STL(Standard Template Library)
using namespace std; // STL�� std namespace���� �������

int g_oil_deposit_count = 0;
void BFS(char** data, int **check, int size_x, int size_y, int x, int y) {
	queue<int> Q;

	if (check[y][x] == 1)
		return;

	check[y][x] = 1;

	if (data[y][x] == '@') {
		Q.push(y * size_x + x);
		g_oil_deposit_count++;
	}

	while (!Q.empty()) {
		int now_y = Q.front() / size_x;
		int now_x = Q.front() % size_x;
		Q.pop();
		for (int i = -1; i <= 1; i++) {
			int next_y = now_y + i;
			if (next_y < 0 || next_y >= size_y)
				continue;
			for (int j = -1; j <= 1; j++) {
				int next_x = now_x + j;
				if (next_x < 0 || next_x >= size_x)
					continue;
				if (check[next_y][next_x] == 1)
					continue;
				check[next_y][next_x] = 1;
				if (data[next_y][next_x] == '@') {
					Q.push(next_y * size_x + next_x);
				}
			}
		}
	}
}
int main4677() {
	int size_x, size_y;

	while(true){
		cin >> size_y >> size_x;
		if (size_y == 0) break;
		g_oil_deposit_count = 0;

		// initialize pockets
		string str;
		char** arr_pockets = new char* [size_y];
		for (int i = 0; i < size_y; i++) {
			arr_pockets[i] = new char[size_x];
			cin >> str;
			for (int j = 0; j < size_x; j++) {
				arr_pockets[i][j] = str[j];
			}
		}
		
		// initialize check array
		int** arr_check = new int* [size_y];
		for (int i = 0; i < size_y; i++) {
			arr_check[i] = new int[size_x];
			for (int j = 0; j < size_x; j++) {
				arr_check[i][j] = 0;
			}
		}

		// count oil deposit by BFS -> global var g_oil_deposit_count
		for (int i = 0; i < size_y; i++) {
			for (int j = 0; j < size_x; j++) {
				if (arr_check[i][j] == 0) {
					BFS(arr_pockets, arr_check, size_x, size_y, j, i);
				}
			}
		}
		cout << g_oil_deposit_count << endl;

		// delete pockets
		for (int i = 0; i < size_y; i++)
			delete []arr_pockets[i];
		delete []arr_pockets;
		// delete check array
		for (int i = 0; i < size_y; i++)
			delete []arr_check[i];
		delete []arr_check;
	}

	return 0;
}

/*
************************************************
* TEST INPUT
************************************************
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
************************************************
* TEST OUTPUT
0
1
2
2
************************************************
*/