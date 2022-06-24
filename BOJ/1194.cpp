#include <stdio.h>
#define min(a, b) a < b ? a:b
typedef struct
{
	int y, x;
}PNT;
char map[51][51];
int n, m, visited[65][51][51];
const PNT d[4]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(PNT now, int key)
{
	for(int i = 0; i < 4; ++i)
	{
		PNT next;
		next.y = now.y + d[i].y;
		next.x = now.x + d[i].x;
		char ch = map[next.y][next.x];
		
		if((0 <= next.y && next.y < n) && (0 <= next.x && next.x < m)) //범위 안 
		{
			if(ch != '#' && (!visited[key][next.y][next.x] || visited[key][now.y][now.x] + 1 < visited[key][next.y][next.x])) //갈 수 있는 곳
			{
				if('a' <= ch && ch <= 'f') //열쇠 획득
				{
					int nextKey = (key | 1 << (ch - 'a'));
					visited[nextKey][next.y][next.x] = visited[key][now.y][now.x] + 1;
					dfs(next, nextKey);
				}
				else if('A' <= ch && ch <= 'F') //문 만남
				{
					if((1 << (ch - 'A')) == (key & 1 << (ch - 'A'))) //문의 열쇠가 있으면
					{
						visited[key][next.y][next.x] = visited[key][now.y][now.x] + 1;
						dfs(next, key);
					}
				}
				else //그냥 길
				{
					visited[key][next.y][next.x] = visited[key][now.y][now.x] + 1;
					dfs(next, key);
				}
			}
		}
	}
}

int main()
{
	PNT start, end[2501];
	int cnt = 0;
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j] == '0') { start.y = i; start.x = j; }
			else if(map[i][j] == '1') { end[cnt].y = i; end[cnt++].x = j; }
		}
	}
	
	visited[0][start.y][start.x] = 1;
	dfs(start, 0);
	
	int ans = 0x7FFFFFFF;
	while(cnt--)
	{
		for(int i = 0; i <= 64; ++i)
		{
			if(visited[i][end[cnt].y][end[cnt].x] > 0) ans = min(ans, visited[i][end[cnt].y][end[cnt].x]);
		}
	}
	printf("%d", ans == 0x7FFFFFFF ? -1 : ans - 1);
	return 0;
}
