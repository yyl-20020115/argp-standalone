#ifndef __ARG_P_UTIL_H__
#define __ARG_P_UTIL_H__
#ifdef _WIN32
#define fwrite_unlocked fwrite
#define putc_unlocked putc
#define fputs_unlocked fputs
#define __attribute__(x) 
#define strcasecmp(x,y) _stricmp(x,y)
#define mempcpy memcpy
#  define dgettext(domain, msgid) (msgid)

int random(void);
int sleep(int n);
char* strndup(const char* s, size_t n);
char* strchrnul(const char* str, int c);
#endif
#endif