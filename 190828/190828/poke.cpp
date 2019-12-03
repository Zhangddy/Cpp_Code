#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//1、声明一个扑克牌类，拥有方法：传入花色和点数生成扑克牌、打印扑克牌。
//2、声明一个玩家类，每人拥有18张扑克牌。拥有方法：
//	 增加手牌（摸牌）、展示手牌，其中展示手牌要求降序排序展示。
//完成程序：
//1、随机生成18张扑克牌，当做一个玩家的手牌。
//2、用54张不同的扑克牌构成牌堆，发给3个玩家。
enum {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,
	JOKER
};
//全局变量g_ 局部静态变量s_ 成员变量m_
class Poker
{
private:
	char m_type;
	int m_point;
public:
	void makePoker(char t, int p);
	void outputpoker();

};

void Poker::makePoker(char type, int point)
{
	m_type = type - 'a';
	m_point = point;
}
void Poker::outputpoker()
{
	const char *type[5] = { "黑桃", "红桃", "梅花", "方片", "" };
	const char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };

	printf("%s%s\n", type[m_type], point[m_point]);
}

class Player
{
	Poker m_HandCard[18];
	int m_size;
public:
	Player() : m_size(0) {};
	void getCard(Poker newCard)
	{
		Poker tmp = m_HandCard[m_size];
		for (i = m_size; i > 0 && ;i--)
		m_size++;
	}
};

bool cmppoker(Poker tmp)
{
	return (a.m_point < b.m_point) ||
		(a.m_point == b.m_point && a.m_type > b.m_type);
}