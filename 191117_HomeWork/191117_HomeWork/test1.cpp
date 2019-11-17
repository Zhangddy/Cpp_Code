class LCA {
public:
	int getLCA(int a, int b) 
	{
		// write code here
		int B = b;
		while (1)
		{
			while (b >= 1)
			{
				if (a * 2  == b || a * 2 + 1 == b)
				{
					return a;
				}
				else if (b * 2  == a || b * 2 + 1 == a)
				{
					return b;
				}
				b = b  / 2;
			}
			a = a  / 2;
			b = B;
		}
		return -1;
	}
};

int main()
{
	LCA l;
	int i = l.getLCA(1, 2);
	i = l.getLCA(4, 5);
	return 0;
}