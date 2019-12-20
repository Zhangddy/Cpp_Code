#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
//建立一个楼房基类Building为基类，用于存储地址和楼号，
//建立住宅类House继承Building，用来存储房号和面积，
//另外建立办公室类Office继承Building，存储办公室名称和电话号码。
//基本要求
//编制应用程序，建立住宅和办公室对象测试之并输出有关数据提交程序。

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
