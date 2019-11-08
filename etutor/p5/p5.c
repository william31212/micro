#include <stdio.h>

#define PROBLEM "p5"
#define TESTC ""
static char num[16] = "0123456789ABCDEF";

void message(unsigned int n)
{
	printf("%u = ",n);
}

unsigned int dec_to_bin(unsigned int n)
{
	for(int i = 0; i < 32; i++)
	{
		unsigned int tmp = n;
		tmp <<= i;
		tmp >>= 31;

		if((i + 1) % 8 == 0)
			printf("%c ",num[tmp&0x1]);
		else
			printf("%c",num[tmp&0x1]);
	}
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	unsigned int n;

	unsigned int arr[4] = { 0xFF000000, 0xFF0000, 0xFF00, 0xFF };

	while (~scanf("%u", &n))
	{
		puts("The packed character representation is:");
		message(n);
		dec_to_bin(n);
		puts("");
		puts("");
		for(int i = 0; i < 4; i++)
		{
			unsigned int t = n & arr[i];
			t >>= 8 * (4 - i - 1);
			message(t);
			dec_to_bin(t);
			puts("");
		}
	}
	return 0;
}