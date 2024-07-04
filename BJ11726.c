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

int puzzle(int* rec, int i);

int main(void)
{
	int n;
	int* rec;
	int i;
	int result;

	//입력
	scanf("%d", &n);
	rec = ( int*)malloc(sizeof(int) * (n + 1));

	//전체사각형 세팅
	for (i = 1; i <= n; i++)
		rec[i] = 0;
	rec[0] = 1;

	//역행 이유: 앞에서 부터 나가면 puzzle 안에 값이 두번씩 더해져야하는데 처음 더해졌을 때부터 0이 아닌 걸로 판단해서 연산이 안됨
	//역행하며 연산
	result = puzzle(rec, n);

	printf("%d", result);

	free(rec);
	return 0;
}

//나머지 연산의 합의 나머지 연산을 하면 원래값의 합의 나머지가 나온다!
//f(n) = f(n-2) + f(n-1) : 세로형을 넣으면 바로 옆칸으로 이동함, 가로형을 넣으면 옆옆칸으로 이동함 > 즉, 그 두 칸으로 가는 경우의 수를 더해주면 둘 중 하나에서 이쪽으로 올 경우의 수가 나온다.
int puzzle(int* rec, int i)
{
	if (i < 0)
		return 0;

	if (rec[i] != 0)
		return rec[i];

	rec[i] = (puzzle(rec, i - 2) + puzzle(rec, i - 1)) % 10007;

	return rec[i];
}
