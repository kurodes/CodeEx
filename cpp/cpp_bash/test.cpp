#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "run bash script" << endl;


	system("./output.sh > output");

	system("grep -oP 'IOPS=\s*\K.*?(?=,)' rados_r_16_4_16")

	ifstream myfile;
	myfile.open ("output");
	myfile.close();







	// Set ceph.conf













	return 0;
}
