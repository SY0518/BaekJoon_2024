//컴퓨터학전공 20230779 김서윤
/*
 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
*/

int counting(int* count, int n);

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, result;
	int* count;

	scanf("%d", &n);
	count = (int*)malloc(sizeof(int) * (n+1));

	for (int i = 0; i <= n; i++)
		count[i] = 0;
	count[0] = 1;

	result = counting(count, n);

	printf("%d", result);

	free(count);
	return 0;
}

int counting(int* count, int n)
{
	if (n < 0)
		return 0;

	if (count[n] == 0) {
		count[n] += counting(count, n - 1);
		count[n] += counting(count, n - 2) * 2;

		count[n] %= 10007;
	}

	return count[n];
}