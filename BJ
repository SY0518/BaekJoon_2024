//컴퓨터학과 20230779 김서윤
/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int calculate(unsigned int* num, int i);

int main(void)
{
	unsigned int* num;
	int N;

  //입력
	scanf("%d", &N);
	num = (unsigned int*)malloc(sizeof(unsigned int) * (N + 1));

  //세팅
	for (int i = 0; i <= N; i++)
		num[i] = 0;

	calculate(num, N);

	/*
	테스트용
	for (int i = 0; i <= N; i++)
		printf("%d: %d\n", i, num[i]);
	*/
	printf("%d", num[N]);

  free(num);
	return 0;
}

//3으로 나누거나 2로 나누는 건 일어나지 않을 수도 있어서 가장 큰 수로 세팅해놓고 비교.
//연산자 실수 주의
unsigned int calculate(unsigned int* num, int i)
{
	int a, b, c; //더 적은 횟수의 연산을 찾기 위해 임시 변수 설정

	if (i < 1)
		return INT_MAX;

	if (i == 1)
		return 0; //처음엔 배열 인덱스 1에 1을 저장했었는데 숫자 하나씩 크게 나와서 안에서 처리하기로 했다. 

	if (num[i] != 0)
		return num[i];

	a = INT_MAX;
	b = INT_MAX;

	if (i % 3 == 0)
		a = calculate(num, i / 3) + 1;
	if (i % 2 == 0)
		b = calculate(num, i / 2) + 1;
	c = calculate(num,i - 1) + 1;

//비교
	num[i] = (a < b) ? a : b;
	num[i] = (num[i] < c) ? num[i] : c;

	return num[i];
}
