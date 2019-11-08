#include <stdio.h>
#include <string.h>

#define PROBLEM "p1"
#define TESTC ""

unsigned int index;
char output[8];

void init()
{
	index = 7;
	for(int i = 0; i < 8; i++)
		output[i] = '0';
}

void decToHex(unsigned int input)
{
	static char HEX[16] = "0123456789ABCDEF";
	while (input > 0)
	{
		output[index--] = HEX[(input & 0xF)];
		input >>= 4;
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	unsigned int n;
	int kase = 1;
	while(~scanf("%u",&n))
	{
		init();
		decToHex(n);
		printf("Case %d: %u\n",kase++,n);
		for(int i = 0; i < 8; i++)
			printf("%c ",output[i]);
		puts("");

	}
	return 0;
}