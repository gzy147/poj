//卡时间常数故意难为人的一道题。异常恶心。改了很多次才不tle。
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int num;
	cin >> num;
	map<int,int> result;
	int i;
		for (i = 0; i < num; i++)
		{
			string str;
			cin >> str;
			int Phone_Num=0;
			int j;
			int length=str.length();
			for (j=0;j<length;j++)
			{
				if(str[j]>=65&&str[j]<=89&&str[j]!=81)
				{
					Phone_Num=Phone_Num*10+(str[j]+1-str[j]/82)/3-20;
				}
				else if(str[j]>=48&&str[j]<=57)
				{
					Phone_Num=Phone_Num*10+(str[j]-48);
				}
			}
			++result[Phone_Num];
		}
	bool exist=0;
		map<int,int>::iterator j;
		int a;
		map<int,int>::iterator Result_End=result.end();
		for (j=result.begin();j!=Result_End;j++)
		{
			if (j->second > 1)
			{
				a=j->first;
				cout<<a/1000000<<(a/100000)%10<<(a/10000)%10<<'-'<<(a/1000)%10<<(a/100)%10<<(a/10)%10<<a%10<<' '<<j->second<<'\n';
				exist=1;
			}
		}
		if(!exist)
		{
			cout << "No duplicates.";
		}
	return 0;
}
