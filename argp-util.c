#ifdef _WIN32
#include <windows.h>
#include "argp-util.h"
int sleep(int n) {
    Sleep(n * 1000);
    return 0;
}
int random(void) {
    return rand();
}
char* strndup(const char* s, size_t n)
{
    size_t len = strlen(s) > n ? n : strlen(s);
    char* new = (char*)malloc(len + 1);

    if (new == NULL)
        return NULL;

    new[len] = '\0';
    return (char*)memcpy(new, s, len);
}
char* strchrnul(const char* s, int c) {
    const char* found = strchr(s, c);
    if (found) {
        return (char*)found;
    }
    else {
        return (char*)s + strlen(s);
    }
}
#endif