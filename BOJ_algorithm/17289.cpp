/************************************************
 * @TITLE : 에니그마
 * @DATE : 2019-10-08
 * @NUMBER : 17289
 * @URL : https://www.acmicpc.net/problem/17289
 * @CATEGORY : character to integer
 * @TIME : 1sec
 * @MEMORY : 256MB
 * @ 채점 준비중 이라 제출 못함
 ************************************************
*/
#include<iostream>
#include<string.h>
using namespace std;
int convertAlphabet2Integer(char alphabet) {
	return alphabet - 'A';
}
int main17289() {
	string saw = "CHICKENS";
	string input;
	cin >> input;
	string result = "";
	for(int i=0; i<input.length(); i++){
		char target = input[i];
		for (int j = 0; j < saw.length(); j++) {
			char convert = saw[j];

			target = saw[j] + convertAlphabet2Integer(target);
			if (target > 'Z') 
				target -= 26;
		}
		cout << target;


		saw[0] += 1;
		if (saw[0] > 'Z')
			saw[0] -= 26;
	}
	return 0;
}
/*
************************************************
* TEST INPUT
************************************************
KVZEOAQZITQLPHJNFKOIIP
************************************************
* TEST OUTPUT
************************************************
WINTERISCOMINGJOHNSNOW
************************************************
*/
