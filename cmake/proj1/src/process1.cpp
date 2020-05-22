#include "component.h"
#include "io.h"

int main()
{
	cout << "This is P1: square_root" << endl;

	double x, res;
	cin >> x;
	res = square_root(x);
	cout << res << endl;

	return 0;
}
