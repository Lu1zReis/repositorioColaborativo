#include <stdio.h>

void contagem (int ini, int fim) {
	int i, c1, aux, vet[10]={};
	for (i = ini; i < fim+1; i++) {
		c1 = i;
		while (c1 != 0) {
			aux  = c1 % 10;
			vet[aux]++;
			c1   = c1 / 10;
		}
	}
	for (i = 0; i < 10; i++) printf("%d ", vet[i]);
	printf("\n");
}

int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	while (a != 0 && b != 0) {
		contagem(a, b);
		scanf("%d %d", &a, &b);
	}
	
	return 0;
}

