//��ǻ�������� 20230779 �輭��

/*
RGB�Ÿ����� ���� N�� �ִ�.�Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.

���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�.������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
N�� ���� ���� N - 1�� ���� ���� ���� �ʾƾ� �Ѵ�.
i(2 �� i �� N - 1)�� ���� ���� i - 1��, i + 1�� ���� ���� ���� �ʾƾ� �Ѵ�.
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

	//�� �Է�
	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &house[i][j]);

	//paint(memo����) ����
	for (i = 0; i < N - 1; i++)
		for ( j= 0; j < 3; j++)
			paint[i][j] = 0;
	for (i = 0; i < 3; i++)
		paint[N - 1][i] = house[N - 1][i];

	//ù��° ���� ������ �� � ������ ĥ���� ��, �ּڰ��� ���Ѵ�.
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

//�Ʒ����� �ϳ� �� �� �������� �װ� �����ϰ� ���� �ϳ� �÷�, ���� �� �� ��� ���� �� paint�� ����
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

