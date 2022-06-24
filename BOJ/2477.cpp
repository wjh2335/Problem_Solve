#include <stdio.h>
int main()
{
	int k, n[6], width = 0, height = 0, hh, ww;
	scanf("%d", &k);
	for(int i = 0; i < 6; ++i)
	{
		int d;
		scanf("%d %d", &d, &n[i]);
		if(d == 3 || d == 4)
		{
			if(height < n[i])
			{
				height = n[i];
				hh = i;
			}
		}
		else
		{
			if(width < n[i])
			{
				width = n[i];
				ww = i;
			}
		}
	}
	printf("%d", k * (height * width - n[(hh + 3) % 6] * n[(ww + 3) % 6]));
	return 0;
}
