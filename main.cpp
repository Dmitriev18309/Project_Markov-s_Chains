#include <iostream>
#include "MarcovsChains.h"

using namespace std;
int main(int argc, char** argv){
	setlocale(LC_ALL, "Russian");
	Mchain a("test.txt");
	ofstream fout;
	fout.open("result.txt");
	a.generate(fout, 3);
	fout.close();
	return 0;
}
