/* definition of strcpy
 */

char *my_strcpy(char *dst, const char* src){
    assert(dst != NULL);
    assert(src != NULL);
    char *ret = dst;
    while( (* dst++ = * src ++) != '\0' );
    return ret;
}

//Think of memory overloap
char* my_strcpy(char *dst, const char* src){
    assert(dst != NULL);
    assert(src != NULL);
    char *ret = dst;
    memcpy(dst, src, str(src)+1);
    return ret;
}
