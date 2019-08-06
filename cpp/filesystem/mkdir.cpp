#include <iostream>
#include <sys/stat.h>
using namespace std;
int main() {
	if (mkdir("test", 0777)==-1) {
		cout<<"Failed"<<endl;
	} else {
		cout<<"Success"<<endl;
	}
	if (rename("test", "tt")==-1) {
		cout<<"Failed"<<endl;
	} else {
		cout<<"Success"<<endl;
	}
	return 0;
}
