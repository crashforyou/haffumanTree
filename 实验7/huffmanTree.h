#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;


struct treeNode
{
	char data;//存储字符
	int  weight;//权值
	string code;//存储编码
	treeNode* left;
	treeNode* right;
	treeNode() {
		data = ' ';
		weight = 0;
		left = 0;
		//code = "";
		right = 0;
	}
	treeNode(int weight) {
		data = ' ';
		this->weight = weight;
		left = 0;
		//code = "";
		right = 0;
	}
	treeNode(char leave,int Weight) {
		data = leave;
		weight = Weight;
		left = 0;
		//code = "";
		right = 0;
	}
	/*
	//按照权值从小到大排序
	friend bool operator<(const treeNode  A, const treeNode B) {
		return (bool)(A.weight < B.weight);
	}
	*/
};


class haffmanTree {
private:
	treeNode* root;
	double rate = 0;
public:
	haffmanTree();//无参哈夫曼树的构建
	haffmanTree(string target);
	treeNode* haffinit(string target);//输入一个字符串，根据字符出现频率构建哈夫曼树
	bool empty();//判断哈夫曼树是否为空
	void huffCode(treeNode*sroot,string code);//递归实现哈夫曼树编码
	void displayCode(treeNode*sroot);//输出每个字符对应的哈夫曼树编码
	treeNode* getRoot();
	void getW();
	void decodeTree(string information);//对信息传进行解码
	void compressRation(string target);//计算压缩比
	void buildRation(treeNode* sroot);
};

class Mycustom {
public:
	bool operator()(const treeNode* A, const treeNode* B) const {
		return A->weight < B->weight;
	}
};

