#include<iostream>
using namespace std;
// 从小往前推导，一次称量最多能找出3枚硬币中的假币，二次称量最多能找到9枚......
int main()
{
	int N;
	while (cin >> N && N != 0)
	{
		int ans = 0;
		long long sum = 1;
		while (sum < N)
		{
			sum *= 3;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}