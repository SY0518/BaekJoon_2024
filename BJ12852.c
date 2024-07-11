//컴퓨터학과 20230779 김서윤

/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

아이디어: 챗지피티
dp 배열은 각 숫자를 1로 만드는 최소 연산 횟수를 저장합니다.
path 배열은 각 숫자에서 이전 숫자를 추적하여 경로를 저장합니다.
N에서 1까지의 최소 연산 횟수는 dp[N]에 저장되고, list 배열을 이용하여 경로를 역추적합니다.
경로는 배열 sequence에 저장되고, 마지막에 역순으로 출력합니다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int calculate( int* num, int i, int* list);

int main(void)
{
	int* num;
	int* list;
	int N;
	int i;
	int* sequence;
	int temp;

	scanf("%d", &N);

	num = (int*)malloc(sizeof(int) * (N + 1));
	list = (int*)malloc(sizeof(int) * (N + 1));

	for (i = 0; i <= N; i++)
		num[i] = 0;
	for (i = 0; i <= N; i++)
		list[i] = 0;

	calculate(num, N, list);

	/*
	for (int i = 0; i <= N; i++)
		printf("%d: %d\n", i, num[i]);
	*/

  //기록한 이전 경로들을 역추적해서 경로를 찾는다.
	sequence = (int*)malloc(sizeof(int) * (num[N] + 1));
	temp = N;
	for (i = 0; temp > 0;i++) {
		sequence[i] = temp;
		temp = list[temp];
	}

	printf("%d\n", num[N]);

	for (i = 0; i < num[N]; i++)
		printf("%d ", sequence[i]);
	printf("1");

	free(num);
	free(list);

	return 0;
}

 int calculate(int* num, int i, int* list)
{
	int a, b, c;

	if (i < 1)
		return INT_MAX;

	if (i == 1)
		return 0;

	if (num[i] != 0)
		return num[i];

	a = INT_MAX;
	b = INT_MAX;

	if (i % 3 == 0)
		a = calculate(num, i / 3, list) + 1;
	if (i % 2 == 0)
		b = calculate(num, i / 2, list) + 1;
	c = calculate(num, i - 1, list) + 1;

	num[i] = (a < b) ? a : b;
	num[i] = (num[i] < c) ? num[i] : c;

  //이 부분이 1463이랑 다름
  //이전 경로의 기록 (i일 때 이전 연산값은 뭐였는지)
	if (num[i] == a)
		list[i]= i / 3;
	else if (num[i] == b)
		list[i] = i / 2;
	else
		list[i] = i - 1;

	return num[i];
}
