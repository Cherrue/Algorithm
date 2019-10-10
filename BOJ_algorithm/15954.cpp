/************************************************
 * @TITLE : 인형들
 * @DATE : 2019-10-10
 * @NUMBER : 15954
 * @URL : https://www.acmicpc.net/problem/15954
 * @CATEGORY : 
 * @TIME : 1sec
 * @MEMORY : 512MB
 * @source : 카카오 코드 페스티벌 2018 예선
 * @caution : 문제의 K개 이상!! 을 확인하라
 ************************************************
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits>
using namespace std;
double average(int* arr, int start, int end) {
	double sum = 0.0f;
	for (int i = start; i < end; i++) {
		sum += arr[i];
	}
	return sum / (end - start);
}
double standardDeviation(int* arr, int start, int end) {
	double dev = 0.0f;
	double mean = average(arr, start, end);

	for (int i = start; i < end; i++) {
		dev += pow(arr[i] - mean, 2);
	}
	return sqrt(dev / (end - start));
}
int main() {
	cout.precision(12);

	int N, K;
	int* arr_preferences;
	cin >> N >> K;
	arr_preferences = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr_preferences[i];
	}


	double smallest_stddev = numeric_limits<double>::max();
	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j<=N-K-i ; j++) {
			float now_stddev = standardDeviation(arr_preferences, i, i + K + j);
			if (smallest_stddev > now_stddev)
				smallest_stddev = now_stddev;

		}
	}

	cout << smallest_stddev;

	delete []arr_preferences;
	return 0;
}
/*
************************************************
* TEST INPUT 1
************************************************
5 3
1 2 3 4 5
************************************************
* TEST OUTPUT 1
************************************************
0.81649658092
************************************************
************************************************
* TEST INPUT 2
************************************************
10 3
1 4 1 5 9 2 6 5 3 5
************************************************
* TEST OUTPUT 2
************************************************
0.94280904158
************************************************
*/
