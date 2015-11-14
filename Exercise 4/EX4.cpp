/***
 Author: Yan Zhengyang at 2015-11-8
 in.txt 输入文档及范例
 out.txt 输出文档及范例
 G.png 输入范例图
***/
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#pragma warning(disable:4996)

using namespace std;


//取得实参的第一个字符并删去实参的第一个字符
string get_first_char(string& str)
{
	if (str.length()<2)
	{
		string strs = str;
		str = "";
		return strs;
	}
	else
	{
		string strs = str.substr(0, 1);
		str = str.substr(1, str.length() - 1);
		return strs;
	}
}

//是否能着某色
bool can_color(map<string, vector<string>* > G, map<string, int > &colorlist, map<string, int>::iterator iter,int color)
{
	vector<string> *connect_list = G[iter->first];

	for (vector<string>::iterator i= connect_list->begin(); i != connect_list->end(); i++)
	{
		if(colorlist[*i] == color)		//如果相邻两节点颜色相同
		{
			return false;
		}
	}
	return true;


}

//尝试着色所有节点
bool color_all(map<string, vector<string>* > G, map<string, int > &colorlist, int color, int M) //给当前状态下为某节点着某色
{

	if(color>M)	//超出判断
	{
		return false;
	}



	map<string, int>::iterator iter = colorlist.begin();

	while(iter != colorlist.end())
	{
		if (iter->second ==0)
		{
			break;
		}

		iter++;

	}

	if(iter == colorlist.end())
	{
		return true;
	}

	//所有节点都着色那么就表示成功

	if(can_color(G,colorlist,iter,color)) 			//如果能着color色 就着色然后继续着下一个节点1色
	{
		iter->second = color;
		return color_all(G,colorlist,1,M);
	}
	else
	{
		return color_all(G,colorlist,color+1,M);	//否则着color+1色
	}

}




int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int M;	//M值

	cin >> M;

	//输入邻接表

	map<string, vector<string>* > G; 	//存储图的邻接表

	map<string, int > colorlist;			//存储染色情况

	string str;
	while (cin >> str)
	{
		string node = get_first_char(str);
		G[node] = new vector<string>();
		colorlist[node] = 0;

		while (str != "")
		{
			G[node]->push_back(get_first_char(str));
		}
	}

	//回溯法

	cout << "用" << M << "种颜色" << (color_all(G,colorlist,1,M)?"能":"不能") << "染色" << endl;

	//输出着色情况

	cout << "着色情况如下：" << endl;

	for(map<string, int>::iterator iter = colorlist.begin(); iter != colorlist.end(); iter++)
	{
		cout << iter->first << " => " << iter->second << endl;
	}

}
