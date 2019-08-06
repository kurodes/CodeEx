#include "loco.pb.h"
#include <iostream>
#include <fstream>
using namespace std;

int write() {

	locofs::filename fname;
	fname.set_uuid(1000);
	fname.set_path("/a/b");

	fstream output("./log", ios::out | ios::trunc | ios::binary);
	if (!fname.SerializeToOstream(&output)) {
		cerr << "Failed to write fname." << endl;
		return -1;
	}

	return 0;
}

int read() {

	locofs::filename fname;

	fstream input("./log", ios::in | ios::binary);
    if (!fname.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    }

    cout << fname.uuid() << endl;
    cout << fname.path() << endl;

	return 0;
}

int main() {

	write();
	read();

	return 0;
}
