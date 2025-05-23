/*
 * Create an MD5 hex digest from a string.
 * 33-byte string is malloc'd by this function. The caller must free it.
 * When compiling, link to:  -l crypto
 */
#include <string.h>

 char *md5(const char *str, int length);
void md5String(char *input, char *output);

