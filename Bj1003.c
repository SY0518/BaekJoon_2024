//컴퓨터학전공 20230779 김서윤
/*
다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

오답: 변수명 잘 보기
  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fiboCount(int n, int* count1, int* count0);

int main(void)
{
	int T;
	int N;
	int* count1;
	int* count0;
	int i;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
  //예외처리
		if (N == 0) {
			printf("1 0\n");
			continue;
		}
		count1 = (int*)malloc(sizeof(int) * (N + 1));
		count0 = (int*)malloc(sizeof(int) * (N + 1));

		for (int j = 2; j <= N; j++) {
			count1[j] = 0;
			count0[j] = 0;
		}

		count1[0] = 0;
		count1[1] = 1;
		count0[0] = 1;
		count0[1] = 0;

		fiboCount(N, count1, count0);

		printf("%d %d\n", count0[N], count1[N]);
		
		free(count1);
		free(count0);
	}

	return 0;
}

void fiboCount(int n, int* count1, int* count0)
{
	if (n == 1 | n == 0)
		return;

	if (count1[n - 1] == 0) {
		fiboCount(n - 1, count1, count0);
	}
	if (count1[n - 2] == 0) {
		fiboCount(n - 2, count1, count0);
	}

	count1[n] = count1[n - 1] + count1[n - 2];
	count0[n] = count0[n - 1] + count0[n - 2];

	return;
}
