//컴퓨터학전공 20230779 김서윤

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int counting(int** map, int** count, int i, int j, int std, int M, int N);

int main(void)
{
	int M, N;
	int** map;
	int** count;
	int i, j;

	scanf("%d %d", &M, &N);
	map = (int**)malloc(sizeof(int*) * M);
	for (i = 0; i < M; i++)
		map[i] = (int*)malloc(sizeof(int) * N);
	count = (int**)malloc(sizeof(int*) * M);
	for (i = 0; i < M; i++)
		count[i] = (int*)malloc(sizeof(int) * N);

	for(i=0;i<M;i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			count[i][j] = 0;
		}
	count[M - 1][N - 1] = 1;

	printf("%d", counting(map, count, 0, 0, INT_MAX, M, N));

	for (i = 0; i < M; i++)
		free(map[i]);
	free(map);
	for (i = 0; i < M; i++)
		free(count[i]);
	free(count);

	return 0;
}

int counting(int** map, int** count, int i, int j, int std, int M, int N)
{
	int up, down, right, left;

	//예외처리
	if (i<0 || i>=M)
		return 0;
	if (j<0 || j>=N)
		return 0;
	if (std < map[i][j])
		return 0;

	if (count[i][j] == 0) {
		up = counting(map, count, i - 1, j, map[i][j], M, N);
		down = counting(map, count, i + 1, j, map[i][j], M, N);
		left = counting(map, count, i, j - 1, map[i][j], M, N);
		right = counting(map, count, i, j + 1, map[i][j], M, N);

		count[i][j] = up + down + left + right;
	}

	return count[i][j];
}
