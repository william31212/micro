#include <stdio.h>
#include <stdlib.h>

#define PROBLEM "p4"
#define TESTC ""

#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

static char num[16] = "0123456789ABCDEF";
unsigned int ans = 0;

unsigned int packCharacters(char a,char b)
{
	unsigned int tmp = ans;
	tmp <<= 8;
	tmp += (unsigned int)a;
	tmp <<= 8;
	tmp += (unsigned int)b;

	return tmp;
}

void message(unsigned int n)
{
	printf("%c:\n",(char)n);
	printf("%u = ",n);
}

unsigned int displayBits(unsigned int n)
{
	for(int i = 0; i < 32; i++)
	{
		unsigned int tmp = n;
		tmp <<= i;
		tmp >>= 31;
		if(i == 31)
			printf("%c",num[tmp&0x1]);
		else if((i + 1) % 8 == 0)
			printf("%c ",num[tmp&0x1]);
		else
			printf("%c",num[tmp&0x1]);
	}
	printf("\n");
}



int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	char a,b,c,d;
	while(~scanf("%c %c %c %c\n",&a,&b,&c,&d))
	{
		ans = packCharacters(a, b);
		ans = packCharacters(c, d);

		message(a);
		displayBits(a);
		message(b);
		displayBits(b);
		message(c);
		displayBits(c);
		message(d);
		displayBits(d);
		printf("'%c' and '%c' and '%c' and '%c' packed in an unsigned int:\n",a,b,c,d);

		printf("%u = ", ans);
		displayBits(ans);

	}

	return 0;
}