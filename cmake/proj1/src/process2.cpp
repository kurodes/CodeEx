#include "component.h"
#include "io.h"

int main()
{
	cout << "This is P2: square" << endl;

	double x, res;
	cin >> x;
	res = square(x);
	cout << res << endl;
	
	return 0;
}
