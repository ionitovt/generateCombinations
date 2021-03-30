#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateCombinations(unsigned n, unsigned k);
int comb(int n, int k);
int factoriel(int n);



int main(){

	generateCombinations(5, 3);
	return 0;
}

void generateCombinations(unsigned n, unsigned k){
	int p[50], m, max;
	for (int i = 0; i < k; i++){
		p[i] = i;
		for (int j = 0; j < k; j++){
			//Принтираме първите r комбинации
			printf("%d", p[j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 2; i < comb(n, k); i++){
		m = k - 1;
		max = n;
		while (p[m] == max){
			//Намираме елемента най-вдясно
			m--;
			max--;
		}

		//Инкрементираме по-горния най-десен елемент
		p[k] = p[k] + 1;
		for (int j = m + 1; j < k; j++){
			p[j] = p[j - 1] + 1;
		}
		//Принтираме новата комбинация
		for (int j = 0; j < k; j++){
			printf("%d", p[j]);
		}
		printf("\n");
	}
}

int comb(int n, int k){
	return factoriel(n) / ((factoriel(k)) * (factoriel(n - k)));
}



int factoriel(int n) {
	int p = n, sum = 1;
	for (int i = 0; i < n; i++) {
		sum *= p;
		p--;
	}
	return sum;
}