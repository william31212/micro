#include <stdio.h>

#define PROBLEM "p2"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

char output[32];

void init()
{
	for(int i = 0; i < 32; i++)
		output[i] = '0';
}

void printBinary(unsigned int n)
{
	static char BIN[2] = "01";
	int index = 31;
	while (n > 0)
	{
		output[index--] = BIN[(n & 0x1)];
		n >>= 1;
	}
	for (int i = 0; i < 32; i++)
		printf("%c",output[i]);
	puts("");
}
void printOctal(unsigned int n)
{
	static char OCT[8] = "01234567";
	int index = 11;
	while (n > 0)
	{
		output[index--] = OCT[(n & 0x7)];
		n >>= 3;
	}
	for (int i = 0; i < 12; i++)
		printf("%c", output[i]);
	puts("");
}
void printHexidecimal(unsigned int n)
{
	static char HEX[16] = "0123456789ABCDEF";
	int index = 7;
	while(n > 0)
	{
		output[index--] = HEX[(n & 0xF)];
		n >>= 4;
	}
	printf("0x");
	for(int i = 0; i < 8; i++)
			printf("%c",output[i]);
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
		printf("Case %d: %u\n",kase++,n);
		init();
		printBinary(n);
		init();
		printOctal(n);
		init();
		printHexidecimal(n);
		puts("");
	}
	return 0;
}