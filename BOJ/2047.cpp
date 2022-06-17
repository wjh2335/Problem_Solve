#include <stdio.h>
typedef struct pnt
{
	int x, y;
}PNT;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int h, w, cnt = 0, visited[97][97], head = 0, tail = 1;
		char map[97][97];
		PNT que[10000], d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

		scanf("%d %d", &h, &w);
		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				visited[i][j] = 0;
				scanf(" %c", &map[i][j]);
				if(map[i][j] == 's') { que[0].x = j; que[0].y = i; }
			}
		}
		
		while(head != tail)
		{
			PNT now = que[head++];
			visited[now.y][now.x] = 1;
			for(int i = 0; i < 4; ++i)
			{
				PNT next;
				next.x = now.x + d[i].x;
				next.y = now.y + d[i].y;
				if(map[next.y][next.x] == '.' && visited[next.y][next.x] == 0)
				{
					que[tail++] = next;
					++cnt;
				}
			}
		}
		printf("%d.00\n", cnt + 1);
	}
	return 0;
}
