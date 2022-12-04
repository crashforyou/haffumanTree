#include"huffmanTree.h"
#include<iostream>
#include<string>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;
int main() {
	haffmanTree t("casbcatbsatbat");
	t.huffCode(t.getRoot(), "");
	t.displayCode(t.getRoot());
	cout << endl;
	t.decodeTree("1101000");
	cout << endl;
	t.compressRation("casbcatbsatbat");
}