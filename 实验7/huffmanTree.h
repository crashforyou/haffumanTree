#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;


struct treeNode
{
	char data;//�洢�ַ�
	int  weight;//Ȩֵ
	string code;//�洢����
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
	//����Ȩֵ��С��������
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
	haffmanTree();//�޲ι��������Ĺ���
	haffmanTree(string target);
	treeNode* haffinit(string target);//����һ���ַ����������ַ�����Ƶ�ʹ�����������
	bool empty();//�жϹ��������Ƿ�Ϊ��
	void huffCode(treeNode*sroot,string code);//�ݹ�ʵ�ֹ�����������
	void displayCode(treeNode*sroot);//���ÿ���ַ���Ӧ�Ĺ�����������
	treeNode* getRoot();
	void getW();
	void decodeTree(string information);//����Ϣ�����н���
	void compressRation(string target);//����ѹ����
	void buildRation(treeNode* sroot);
};

class Mycustom {
public:
	bool operator()(const treeNode* A, const treeNode* B) const {
		return A->weight < B->weight;
	}
};

