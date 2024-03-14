// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	long rez = syscall(__NR_open, filename, flags);
	if (rez >= 0) {
		return (int)rez;
	}

	errno = -rez;
	return -1;
}
