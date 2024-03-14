#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *request, const struct timespec *remaining);
unsigned int sleep(unsigned int sec);

#ifdef __cplusplus
}
#endif

#endif
