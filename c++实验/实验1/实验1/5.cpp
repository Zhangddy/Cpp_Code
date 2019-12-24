#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
    
// 1.创建一个文件输出流对象，通过构造函数指定磁盘文件名。
// 2.通过文件输出流对象，写入若干行文字。 
// 3.关闭文件输出流对象，然后观察磁盘文件内容。 
// 4.改用open函数创建文件输出流，并选择适当的文件操作方式。
// 5.在原内容的后面追加若干行新内容。 

int main5()
{
	// 1
	ofstream fout("D:\\CppExp.txt");
	// 2, 3
	fout << "衣带渐宽终不悔,";
	fout << "为伊消得人憔悴.";

	fout.close();
	// 4
	FILE* pFile;
	pFile = fopen("D:\\CppExp.txt", "r+");
	char a[1024];
	if (pFile != NULL)
	{
		fscanf(pFile, "%s", a);
	}
	puts(a);
	// 5
	fprintf(pFile, "---宋.柳永");

	fclose(pFile);
	return 0;
}