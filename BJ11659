//컴퓨터학전공 20230779 김서윤

/*
 첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다.
둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 
셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int prefixSum(int n, int* num, unsigned int* sum);

int main(void)
{
	int N, M;
	int i, j;
	int* num;
	unsigned int* sum;
	int k;

	//입력
	scanf("%d %d", &N, &M);
	num = (int*)malloc(sizeof(int) * N);
	sum = (unsigned int*)malloc(sizeof(unsigned int) * N);


	for (k = 0; k < N; k++) 
		scanf("%d",&num[k]);

	//sum 세팅
	for (k = 1; k < N; k++)
		sum[k] = 0;
	sum[0] = num[0]; //오답노트: 세팅할 때 기초값이 없으면 런타임 에러가 뜬다.


	//i와 j 입력 받고 누적합을 이용해 중복 연산 없도록 연산
	for (k = 0; k < M; k++) {
		scanf("%d %d", &i, &j);

		if(i==1)
			printf("%d\n", prefixSum(j - 1, num, sum));
		else
			printf("%d\n", prefixSum(j - 1, num, sum) - prefixSum(i - 2, num, sum));
	}
	
	free(num);
	free(sum);

	return 0;
}

//누적합 구하기
int prefixSum(int n, int* num, unsigned int* sum)
{
	if (sum[n] != 0)
		return sum[n]; 
	
	sum[n] = num[n] + prefixSum(n - 1, num, sum);

	return sum[n];
	
}
