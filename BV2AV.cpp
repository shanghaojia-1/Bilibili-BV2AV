#include<iostream>
using namespace std;
char table[59] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
char tr[150];
const long long Xor = 177451812;
const long long add = 8728348608;
const int s[] = { 11, 10, 3, 8, 4, 6 };
long long bv2av(char bv[])
{	
	long long r = 0;
	long long av = 0;
	for (int i = 0; i < 6; i++)
	{
		char temp = bv[s[i]];
		r += tr[temp] * pow(58, i);
	}
	return (r - add) ^ Xor;
}
char* av2bv(long long av)
{
	av = (av ^ Xor) + add;
	char bv[] = "BV1  4 1 7  ";
	for (int i = 0; i < 6; i++)
	{
		bv[s[i]] = table[(long long)(av/pow(58,i))%58];
	}
	return bv;
}
void shouMenu()
{
	cout << "请输入选项" << endl;
	cout << "1.BV转AV" << endl;
	cout << "2.AV转BV" << endl;
}
int main()
{	
	for (int i = 0; i < 58; i++)
	{
		tr[table[i]] = i;
	}
	while (1)
	{
		int choose = 0;
		shouMenu();
		cin >> choose;
		if (choose == 1)
		{
			cout << "请输入BV号" << endl;
			char bv[20];
			cin >> bv;
			cout << "av" << bv2av(bv) << endl;
		}
		else if (choose == 2)
		{
			cout << "请输入AV号" << endl;
			long long av;
			cin >> av;
			cout <<av2bv(av) << endl;
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
}
