/**
 *  int snprintf(char *str, size_t size, const char *format, ...);
 */

#include <stdio.h>

int main()
{
    char buffer[20];

    char* s1 = "lalalalalala";
    int len1 = snprintf(buffer, 6, "%s", s1);
    printf("string:\n%s\ncharacter count = %d\n", buffer, len1);

    char* s2 = "lo";
    int len2 = snprintf(buffer, 6, "%s", s2);
    printf("string:\n%s\ncharacter count = %d\n", buffer, len2);

    char key[16];
    int tmp = 1;
    snprintf(key, 16, "%d", tmp);
    /*for (int i=0; i<16; i++) {
    	printf("%c\n", key[i]);
    }*/
    printf("%sEND\n", key);

    return 0;
}


