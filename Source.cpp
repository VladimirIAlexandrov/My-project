#include "TMyList.h"
#include "TMyItem.h"
#include <string>
#include <iostream>

typedef TMyList<TMyItem> Tist;
typedef TMyList<Tist> TMatrix;

int main(void) {
	TMyItem* p = nullptr;
	TMatrix* m = new TMatrix();
	for (int i = 1; i <= 5; i++) {
		m->Add();
		for (int j = 1; j <= 3; j++) {
			(*m)[i]->Value.Add();
			(*(*m)[i]->Value[j]).Value.i = i*100+j;
			(*(*m)[i]->Value[j]).Value.s = "["+std::to_string(i)+","+ std::to_string(j) + "]-é";
		}
	}
	for (int i = 1; i <= 5; i++) {
		std::cout << std::endl;
		for (int j = 1; j <= 3; j++)
			std::cout << (*((*m)[i]->Value)[j]).Value.s;
	}
	delete m;
}