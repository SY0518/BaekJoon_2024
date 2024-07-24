//컴퓨터학전공 20230779 김서윤

/*
0과 1로만 이루어진 수를 이진수라 한다. 이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 이들을 이친수(pinary number)라 한다. 이친수는 다음의 성질을 만족한다.

이친수는 0으로 시작하지 않는다.
이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.

N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.

오답: 범위 주의. 답을 저장하기 위한 변수도 범위를 맞춰줘야한다.
    피보나치가 맞는데 지피티한테 예시 물어봤다가 답을 속아서 삽질 너무 길게 함.......................... 줏대를 갖자.
  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long counting(int n, long long* count);

int main(void)
{
	int n;
	long long result;
	long long* count;
	int i;

	scanf("%d", &n);
	count = (long long*)malloc(sizeof(long long) * n);

	for (i = 3; i < n; i++)
		count[i] = 0;
	count[0] = 1;
	count[1] = 1;
	count[2] = 2;

	result = counting(n-1, count);

	printf("%lld", result);

	free(count);

	return 0;
}

long long counting(int n, long long* count)
{
	if (n < 0)
		return 0;

	if (count[n] == 0)
		count[n] = counting(n - 1, count) + counting(n - 2, count);

	return count[n];
}
