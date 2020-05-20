/**
 *	add prefix 0x00, then use(char *)
 */
#include <iostream>
#include <string>

int main () {
	/**
	 * 	!!!!!!
	 * 		beginnig byte must be '\0'
	 */

	// int64_t a = 0x4142434445464748;
	// int64_t b = 0x494a4b4c4d4e4f50;
	int64_t a = 0x01004344454647ee;
	int64_t b = 0x01004b4c4d4e4fdd;

	int64_t A[2];
	A[0] = a;
	A[1] = b;
	std::cout<<A[0]<<std::endl;
	std::cout<<A[1]<<std::endl;

	std::string re((char *)A, 16);

	std::cout<<re.size()<<std::endl;

	int64_t *B = (int64_t *)re;
	std::cout<<B[0]<<std::endl;
	std::cout<<B[1]<<std::endl;
	return 0;
}
