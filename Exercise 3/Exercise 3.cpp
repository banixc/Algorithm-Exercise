/***
 Author: Yan Zhengyang at 2015-11-8
 in.txt 输入文档及范例
 out.txt 输出文档及范例
 G.png 输入范例图
***/
#include <iostream>
#include <stack>
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

//判断两节点是否相连
bool connect(vector<string>* node, vector<string>* collection)
{
	if (collection->size() == 0) return false;
	for (vector<string>::iterator iter = node->begin(); iter != node->end(); iter++)
	{
		for (vector<string>::iterator i = collection->begin(); i != collection->end(); i++)
		{
			if (*iter == *i)
			{
				return true;
			}
		}
	}
	return false;
}




int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	map<string, vector<string>* > G;
	string str;
	while (cin >> str)
	{
		string node = get_first_char(str);
		G[node] = new vector<string>();

		while (str != "")
		{
			G[node]->push_back(get_first_char(str));
		}
	}


	// 输出图 

	cout << "您输入的图的节点邻接关系如下："<< endl;

	for (map<string, vector<string>*>::iterator iter = G.begin(); iter != G.end(); iter++)
	{
		cout << iter->first << " => ";
		for (vector<string>::iterator i = iter->second->begin(); i != iter->second->end(); i++)
		{
			cout << *i << " ";
		}

		cout << endl;

	}

	//贪心算法，每次选择度最大的节点加入到子集中 不能就选择次大的节点加入

	//输出节点按度大小排列

	vector<string>* node_list = new vector<string>();

	map<string, vector<string> *>::iterator map_iter = G.begin();

	node_list->insert(node_list->begin(), map_iter->first);

	map_iter++;

	while (map_iter != G.end())
	{

		vector<string>::iterator iter = node_list->begin();
		while (map_iter->second->size()<G[*iter]->size())
		{
			iter++;
			if (iter == node_list->end())
			{
				break;
			}
		}
		//cout << map_iter->first << endl;
		node_list->insert(iter, map_iter->first);
		map_iter++;
	}

	//输出节点按度大小的排列

	cout << "节点按度大小的排列："<< endl;

	for (vector<string>::iterator i = node_list->begin(); i != node_list->end(); i++)
	{
		cout << *i << " => " << G[*i]->size() << endl;
	}


	vector<vector<string>*>* collection = new vector<vector<string>*>();		//存储划分的子集


	//依次从度最大的节点中判断是否能加入


	while (node_list->size() != 0)
	{
			

		vector<string>* now_collection = new vector<string>(); 					//新建立一个集合


		for (vector<string>::iterator i = node_list->begin(); i != node_list->end();)
		{
			if (!connect(G[*i], now_collection))								//如过不相连则在集合中插入该节点
			{
				now_collection->push_back(*i);
				i = node_list->erase(i);										//返回删去元素的下一个指针
				continue;

			}
			else
			{
				i++;
			}

		}

		collection->push_back(now_collection);

	}

	//输出划分集合

	cout << "划分集合：" << endl;


	for (vector<vector<string>*>::iterator iter = collection->begin(); iter != collection->end(); iter++)
	{
		cout << "{ ";
		vector<string>* now_collection = *iter;


		for (vector<string>::iterator i = now_collection->begin(); i != now_collection->end(); i++)
		{
			cout << *i << " ";
		}

		cout << "}" << endl;
	}


}



