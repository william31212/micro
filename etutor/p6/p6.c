#include <stdio.h>
#include <math.h>
#include <string.h>

#define PROBLEM "p6"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define UI unsigned int

static char num[16] = "0123456789ABCDEF";

int bin[32];


void message(unsigned int n)
{
	printf("%u = ", n);
}

UI fast_mi(UI a, UI b)
{
	if (b == 0)
		return 1;
	UI s = fast_mi(a,b/2);
	if(b % 2)
		return s * s * a;
	else
		return s * s;
}


UI dec_to_bin(UI n)
{
	for(int i = 0; i < 32; i++)
	{
		UI tmp = n;		
		tmp <<= i;
		tmp >>= 31;
		if ((i + 1) % 8 == 0)
			printf("%c ", num[tmp & 0x1]);
		else
			printf("%c", num[tmp & 0x1]);

		bin[i] = num[tmp&0x1] - '0';
	}
}

UI rev()
{
	UI ans = 0;

	for(int i = 31; i >= 0; i--)
		ans += bin[i] * fast_mi(2,i);
	message(ans);
	for (int i = 31; i >= 0; i--)
		if (i % 8 == 0)
			printf("%d ", bin[i]);
		else
			printf("%d", bin[i]);
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	UI k;
	while(~scanf("%u",&k))
	{
		memset(bin,0,sizeof(bin));
		puts("Before bits are reversed:");
		message(k);
		dec_to_bin(k);
		puts("\n");
		puts("After bits are reversed:");
		rev();
		puts("");

	}
	return 0;
}