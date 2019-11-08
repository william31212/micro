#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PROBLEM "p3"
#define TESTC ""
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int arr[32];
int idx = 0;

int Binary_checker(unsigned int n)
{
	int BIN[2] = {0,1};
	int j = 0;
	int all_bits = 1;
	int exist_bits = 0;
	int bits[32];
	memset(bits,0,sizeof(bits));
	while (n > 0)
	{
		bits[j++] = BIN[(n & 0x1)];
		n >>= 1;
	}
	for (int i = 0; i < 32; i++)
	{
		if(arr[i])
			if(!bits[i])
				all_bits = 0;
			else
				exist_bits = 1;
	}

	if(all_bits == 0)
	{
		printf("false(all bits 1)\n");
	}
	else
	{
		printf("true(all bits 1)\n");
	}
	if(exist_bits == 0)
	{
		printf("false(exist bits 1)\n");
	}
	else
	{
		printf("true(exist bits 1)\n");
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n;
	int kase = 1;

	memset(arr,0,sizeof(arr));
	
	for(int i = 0; ; i++)
	{
		scanf("%d",&n);
		arr[n] = 1;
		if(n <= -1)
			break;
	}
	for (int i = 0; i < 32; i++)
		if (arr[i] == 1)
		{
			printf("%d ", i);
		}
	puts("");
	unsigned int n2 = 0;

	while(~scanf("%u",&n2))
	{
		printf("Case %d: %u\n", kase++, n2);
		Binary_checker(n2);
	}

	return 0;
}