//컴퓨터학전공 20230779 김서윤

/*
	
	수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.
	예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

	아이디어: https://juintination.tistory.com/entry/%EB%B0%B1%EC%A4%80-11722%EB%B2%88-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EA%B0%90%EC%86%8C%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4
	LDS 알고리즘 참고: https://withhamit.tistory.com/197

	착각한 부분: 등차수열이 아니어도 된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int math_max(int a, int b);

int main(void)
{
	int N;
	int* num;
	int* count;
	int i, j;
	int max;

	scanf("%d", &N);
	num = (int*)malloc(sizeof(int) * N);
	count = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

  //세팅: 수열의 최소길이는 1이기 때문에
	for (i = 0; i < N; i++)
		count[i] = 1;

  //인덱스 i: 앞에 있는 숫자, 인덱스 j: 뒤에 있는 숫자
  //i에 있는 숫자가 j에 있는 숫자보다 클 때, count[j]에 저장된 뒤부터 j까지의 수열의 길이(+1)가 지금까지 저장된 count[i]에 저장된 숫자보다 클 경우, 변경(이 부분이 LDS알고리즘?)
	for (i = N - 1; i >= 0; i--)
		for (j = N - 1; j > i; j--) 
			if (num[i] > num[j])
				if (count[i] < count[j] + 1)
					count[i] = count[j] + 1;

	max = 0;
	for (i = 0; i < N ; i++)
		max = math_max(max, count[i]);

	printf("%d", max);

  free(count);
  free(num);
	
	return 0;
}
int math_max(int a, int b)
{
	return (a > b) ? a : b;
}
