#include"huffmanTree.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;

haffmanTree::haffmanTree() {
	root = 0;
}

haffmanTree::haffmanTree(string target)
{
	root=haffinit(target);
}

bool haffmanTree::empty() {
	return root == 0;
}

void haffmanTree::huffCode(treeNode*sroot, string code)
{
	if (sroot) {
		sroot->code = code;
		huffCode(sroot->left, code + "0");
		huffCode(sroot->right, code + "1");
	}
}

void haffmanTree::displayCode(treeNode*sroot)
{
	if (sroot) {
		if (sroot->data != ' ') {
			cout << sroot->data << "    " << "权值为："<<sroot->weight << "   " << "编码为："<<sroot->code << endl;
		}
		displayCode(sroot->left);
		displayCode(sroot->right);
	}
}

void haffmanTree::buildRation(treeNode* sroot)
{
	if (sroot) {
		if (sroot->data != ' ') {
			rate += sroot->weight * sroot->code.length();
		}
		buildRation(sroot->left);
		buildRation(sroot->right);
	}
}


void haffmanTree::compressRation(string target)
{
	buildRation(getRoot());
	int length = target.length();
	int i;
	for(i=0;pow(2,i)<length;i++){}
	double rr = (i - rate / length) / i;
	cout << target << "的压缩比为" << setprecision(3) << rr << endl;
}



treeNode*haffmanTree::getRoot()
{
	return root;
}

void haffmanTree::getW()
{
	cout << root->weight;
}

void haffmanTree::decodeTree(string information)
{
	int length = information.length();
	treeNode* ptr = root;
	cout << information << "的解码结果为：";
	for (int i = 0; i < length; i++) {
		if (information[i] == '0') {
			ptr = ptr->left;
			if (ptr->data != ' ') {
				cout << ptr->data ;
				ptr = root;
			}
		}
		else {
			ptr = ptr->right;
			if (ptr->data != ' ') {
				cout << ptr->data ;
				ptr = root;
			}
		}
	}
	cout << endl;
}



treeNode *haffmanTree::haffinit(string target) {
	int length = target.length();
	multiset<treeNode*,Mycustom> sChar;//按照自定义的Mycustom排序
	int iCount;
	set<char>charSet;//存放字符的set，避免字符重复
	set<char>::iterator it;
	for (int i = 0; i < length; i++) {
		charSet.insert(target[i]);
	}
	
	//sChar内根据权值排序
	for (it = charSet.begin(); it != charSet.end(); it++) {
		iCount = count(target.begin(), target.end(), *it);
		treeNode *leave=new treeNode(*it, iCount);
		sChar.insert(leave);
	}

	//哈夫曼树权值越小的深度越深，运用set集合来处理数据，
	//避免了数据重复的情况，并且set是有序集合，可以运用这一特性来找到权值最小的两个点
	int frec;
	treeNode* leftLeave;
	treeNode* rightLeave;
	treeNode* newLeave;
	root = 0;
	multiset<treeNode*>::iterator frontIt;
	
	while (sChar.size() >= 2) {
		frec = 0;
		frontIt = sChar.begin();
		frec+=(*frontIt)->weight;
		leftLeave = *frontIt;
		sChar.erase(sChar.begin());

		frontIt = sChar.begin();
		frec+=(*frontIt)->weight;
		rightLeave = *frontIt;
		sChar.erase(sChar.begin());
		
		newLeave = new treeNode(frec);
		newLeave->left =leftLeave;
		newLeave->right = rightLeave;
		sChar.insert(newLeave);
	}
	return *sChar.begin();
}