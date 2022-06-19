#include <stdio.h>
int main()
{
	int max = -1, x, y;
	for(int i = 1; i <= 9; ++i)
	{
		for(int j = 1; j <= 9; ++j)
		{
			int n;
			scanf("%d", &n);
			if(max < n) { max = n; x = j; y = i; }
		}
	}
	printf("%d\n%d %d", max, y, x);
	return 0;
}
