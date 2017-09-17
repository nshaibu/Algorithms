//============================================================================
// Name        : dlinked_list.cpp
// Author      : nafiu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List lt;
	int i/*,j*/;
//	lt.insertList("nafiu");
//	lt.insertList("shaibu");
//	lt.insertList("nuru");
//	lt.insertList("abiba");
	//lt.insertList("ismael");
	//lt.insertList("yawson");
	//lt.insertList("kofi");
	//lt.insertList("saaka");
	//lt.insertList("fdf");
	//lt.insertList("vim");
	for (i=98; i > 66; i--) { lt.insertList(i); }
	List lv=lt;
	//for (j=30; j>20; j--) lv.insertList(j);
	lt.printForward();
	lt.printReverse();
	//lv.printForward();
	cout << lt.height_list() << " " <<lt.get_mid()->data << endl;
	return 0;
}
