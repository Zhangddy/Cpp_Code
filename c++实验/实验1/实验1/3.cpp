#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
//����һ��¥������BuildingΪ���࣬���ڴ洢��ַ��¥�ţ�
//����סլ��House�̳�Building�������洢���ź������
//���⽨���칫����Office�̳�Building���洢�칫�����ƺ͵绰���롣
//����Ҫ��
//����Ӧ�ó��򣬽���סլ�Ͱ칫�Ҷ������֮������й������ύ����

class Building
{
protected:
	string Adress;
	size_t BuildNo;
public:
	Building()
	{
		cout << "Building::Building()" << endl;
	}
	~Building()
	{
		cout << "Building::~Building" << endl;
	}
};

class House:public Building
{
protected:
	size_t HouseNo;
	size_t HouseArea;
public:
	House():Building()
	{
		cout << "House::House()" << endl;
	}
	~House()
	{
		cout << "House::~House()" << endl;
	}
};
class Office : public Building
{
protected:
	size_t OfficeNo;
	size_t TelephoneNo;
public:
	Office():Building()
	{
		cout << "Office::Office()" << endl;
	}
	~Office()
	{
		cout << "Office::~Office()" << endl;
	}
};  
int main3()
{
	House h;
	Office o;
	system("pause");
	return 0;
}
