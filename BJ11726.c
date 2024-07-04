//컴퓨터학전공 20230779 김서윤

/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.



입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int puzzle(long long int* rec, int i);

int main(void)
{
	int n;
	long long int* rec;
	int i;
	int result;

	scanf("%d", &n);

	rec = (long long int*)malloc(sizeof(long long int) * (n + 1));

	//전체사각형 세팅
	for (i = 1; i <= n; i++)
		rec[i] = 0;
	rec[0] = 1;

	result = puzzle(rec, n);

	printf("%d", result);

	free(rec);
	return 0;
}

long long int puzzle(long long int* rec, int i)
{
	if (i < 0)
		return 0;

	if (rec[i] != 0)
		return rec[i];

	rec[i] = (puzzle(rec, i - 2) + puzzle(rec, i - 1)) % 10007;

	if (rec[i] < 0){
		printf("에러! : %d, %lld\n", i, rec[i]);
		return 0;
		}
	return rec[i];
}
