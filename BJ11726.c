//��ǻ�������� 20230779 �輭��

/*
2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Ʒ� �׸��� 2��5 ũ���� ���簢���� ä�� �� ���� ����� ���̴�.



�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.
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

	//��ü�簢�� ����
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
		printf("����! : %d, %lld\n", i, rec[i]);
		return 0;
		}
	return rec[i];
}
