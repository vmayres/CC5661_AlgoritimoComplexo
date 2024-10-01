#include <stdio.h>
#include <stdlib.h>

void fibInt(int n) {
	int num = 0;
	int ant1 = 0;
	int ant2 = 0;
	
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			printf("%d, ", num);
			num++;
		}
		else {
			printf("%d, ", num);
			ant2 = ant1;
			ant1 = num;
			num = ant1 + ant2;
		}
		
	}
}

int main(void) {
	int n;
	printf("Digite N da sequencia de fibonacci: ");
	scanf_s("%d", &n);
	fibInt(n);
	return 0;
}