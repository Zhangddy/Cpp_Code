#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//1������һ���˿����࣬ӵ�з��������뻨ɫ�͵��������˿��ơ���ӡ�˿��ơ�
//2������һ������࣬ÿ��ӵ��18���˿��ơ�ӵ�з�����
//	 �������ƣ����ƣ���չʾ���ƣ�����չʾ����Ҫ��������չʾ��
//��ɳ���
//1���������18���˿��ƣ�����һ����ҵ����ơ�
//2����54�Ų�ͬ���˿��ƹ����ƶѣ�����3����ҡ�
enum {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,
	JOKER
};
//ȫ�ֱ���g_ �ֲ���̬����s_ ��Ա����m_
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
	const char *type[5] = { "����", "����", "÷��", "��Ƭ", "" };
	const char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };

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