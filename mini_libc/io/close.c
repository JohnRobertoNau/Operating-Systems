// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	long rez = syscall(__NR_close, fd);
	if (rez >= 0) {
		return (int)rez;
	}
	errno = -rez;
	return -1;
}
