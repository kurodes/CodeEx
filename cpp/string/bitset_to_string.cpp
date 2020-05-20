#include <iostream>
#include <string>
#include <bitset>

int main () {

	/**
	 * Way_1:
	 * 		add prefix 0x00, then use(char *)
	 */
	std::bitset<16> a(0x4142);

	std::bitset<24> tmpb;
	for (int i = 0; i < 16; ++i)
	{
		tmpb[i] = a[i];
	}
	for (int i = 16; i < 24; ++i)
	{
		tmpb[i] = 0;
	}
	std::cout<<tmpb<<std::endl;
	std::string aa;
	aa.append((char *) &tmpb);
	std::cout<<aa<<std::endl;

	/**
	 *  Way_2: only for 8bit
	 *  	static_cast
	 */
	std::bitset<8> b(0x41);
	char bb = static_cast<char>( b.to_ulong() );
	//unsigned char bb = static_cast<unsigned char>( b.to_ulong() );
	std::cout<<bb<<std::endl;
	return 0;
}
