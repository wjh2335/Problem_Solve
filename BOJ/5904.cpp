#include <iostream>
using namespace std;
int S[28] = {3, };

char divide(int N, int K)
{
	if(!K) return (N == 1) ? 'm' : 'o';
	
	char ret;
	int left = S[K - 1],
        right = S[K - 1] + K + 3;
    
	if(N <= left) ret = divide(N, K - 1);
	else if(right < N) ret = divide(N - right, K - 1);
	else ret = (N - left == 1) ? 'm' : 'o';
	
	return ret;
}
int main()
{
	for(int i = 1; i <= 27; ++i) S[i] = 2 * S[i - 1] + i + 3;
	
	int N, K = 0;
	cin >> N;
	
	for(int i = 1; i <= 27; ++i)
	{
		if(S[i - 1] < N && N <= S[i]) K = i;
	}
	
	cout << divide(N, K);	
	return 0;
}
