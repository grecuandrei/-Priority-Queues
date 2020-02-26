#include "algo2.cpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	argc = argc;
    ifstream file1(argv[1]);
	ofstream file2(argv[2]);

	int M; /// nr de getMax() si de pop-uri
	file1>>M;
	int N; /// nr de elemenete de adaugat
	file1>>N;

	MaxHeap h;
	int x;

    for(int i = 0; i < N; ++i) {
		file1>>x;
    	h.push(x);
    }
    file2<<N<<" numere inserate in Max Heap"<<endl;
	for(int i = 0; i < M; ++i) {
		file2<<i<<" Max: "<<h.top()<<endl;
		h.pop();
	}

    file1.close();
	file2.close();
    return 0;
}
