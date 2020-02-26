#include "algo.cpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	argc = argc;
    ifstream file1(argv[1]);
	ofstream file2(argv[2]);

	int M; /// numarul de getMax/Min si numarul de delete-uri
	file1>>M;
	int N; /// numarul de elemente de adaugat
	file1>>N;

	AVL a;
	int x;

    for (int i = 0; i < N; ++i) {
		file1>>x;
    	a.insertKey(x);
    }

    file2<<N<<" numere inserate in avl."<<endl;
	for (int i = 0; i < M; ++i) {
		file2<<i+1<<" ";
		int d = a.getMax();
		int e = a.getMin();
		file2<<"Max: "<<d<<"  ";
		file2<<"Min: "<<e<<endl;
		a.deleteKey(d);
		a.deleteKey(e);

	}

    file1.close();
	file2.close();
    return 0;
}
