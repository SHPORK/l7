#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include <queue>
#include <iostream>
using namespace std;

void DFS(int v, int* vis, int m, int** a) {
	vis[v] = 1;
	printf("%d ", v + 1);
	for (int i = 0; i < m; i++) {
		if (a[v][i] == 1 && vis[i] == 0) {
			DFS(i, vis, m, a);
		}
	}
}

int main(void)
{
	int m;
	printf("Enter amount of peaks: \n");
	scanf("%d", &m);

	int** a;
	a = (int**)malloc((m) * sizeof(int*));
	srand(time(NULL));
	// (1)
	printf("   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(m * sizeof(int));

		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
			if (j <= i) {
				a[i][j] = a[j][i];
				printf("%4d ", a[i][j]);
			}
			else {
				a[i][j] = rand() % 2;
				printf("%4d ", a[i][j]);
			}
		}
	}

	int v = 0;
	int* vis;
	vis = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		vis[i] = 0;
	}
	printf("\n\n");

	DFS(v, vis, m, a);

	free(a);
	free(vis);
	getchar();
	getchar();
	return(0);
}

