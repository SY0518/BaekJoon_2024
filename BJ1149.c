//컴퓨터학전공 20230779 김서윤

/*
RGB거리에는 집이 N개 있다.거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다.각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N - 1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N - 1)번 집의 색은 i - 1번, i + 1번 집의 색과 같지 않아야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int painting(int** house, int** paint, int i, int j);

int main(void)
{
	int N;
	int** house;
	int** paint;
	int i, j;
	int smallest, temp;

	scanf("%d", &N);
	house = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		house[i] = (int*)malloc(sizeof(int) * 3);
	paint = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		paint[i] = (int*)malloc(sizeof(int) * 3);

	//값 입력
	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &house[i][j]);

	//paint(memo역할) 세팅
	for (i = 0; i < N - 1; i++)
		for ( j= 0; j < 3; j++)
			paint[i][j] = 0;
	for (i = 0; i < 3; i++)
		paint[N - 1][i] = house[N - 1][i];

	//첫번째 집을 세가지 중 어떤 색으로 칠했을 때, 최솟값을 구한다.
	smallest = INT_MAX;
	for (i = 0; i < 3; i++) {
		temp = painting(house, paint, 0, i);

		if (temp < smallest)
			smallest = temp;
	}

	printf("%d", smallest);
	
	for (i = 0; i < N; i++)
		free(house[i]);
	free(house);
	for (i = 0; i < N; i++)
		free(paint[i]);
	free(paint);

	return 0;
}

//아래에서 하나 고른 걸 기준으로 그걸 제외하고 위로 하나 올려, 같은 걸 고를 경우 작은 걸 paint에 저장
int painting(int** house, int** paint, int i, int j)
{
	int a, b;
	int aj, bj;

	if (paint[i][j] != 0) {
		return paint[i][j];
	}

	if (j == 0) {
		aj = 1;
		bj = 2;
	}
	else if (j == 1) {
		aj = 0;
		bj = 2;
	}
	else {
		aj = 0;
		bj = 1;
	}

	a = painting(house, paint, i + 1, aj);
	b = painting(house, paint, i + 1, bj);

	paint[i][j] = ((a < b) ? a : b) + house[i][j];

	return paint[i][j];
}

