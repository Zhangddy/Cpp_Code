#include<iostream>
using namespace std;
// ��С��ǰ�Ƶ���һ�γ���������ҳ�3öӲ���еļٱң����γ���������ҵ�9ö......
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