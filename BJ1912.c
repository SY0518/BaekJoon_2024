//컴퓨터학과 20230779 김서윤
/*
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

오답노트: 사이즈 때문에 시간 복잡도가 n^2가 나오면 안되므로 중첩반복문을 사용하면 안됨. 신경 쓸 것.
    연속한 숫자를 이용하는 게 조건이기 때문에 이 전에 푼 가장 긴 감소 수열이랑 비슷하게 풀 수 있는 문제.
    max를 INT_MIN으로 시작해서 N이 0일 때를 따로 처리해줘야함.
    반복문에서 dp[0]일 때를 안 굴리므로 마지막에 이 부분을 추가해줘야한다.
  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int N;
	int* num;
	int* dp;
	int temp, max;
	int i;

	scanf("%d", &N);
	num = (int*)malloc(sizeof(int) * N);
	dp = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) 
		scanf("%d", &num[i]);

	dp[0] = num[0];
	max = INT_MIN;
	for (i = 1; i < N; i++) {
		dp[i] = num[i];    //여기서 시작할 경우
		temp = dp[i-1] + num[i];    //전부터 이어질 경우

		if (dp[i] < temp)    //위의 두 경우를 비교해 최종 dp[i]는 i까지의 수를 연속으로 더했을 때 가장 큰 수
			dp[i] = temp;

		if (max < dp[i])    //max는 그 dp[i]들 중 가장 큰 값을 기록
			max = dp[i];
	}

	if (dp[0] > max)
		max = dp[0];

	if (N == 0)
		max = 0;

	printf("%d", max);


	free(num);
	free(dp);

	return 0;
}
