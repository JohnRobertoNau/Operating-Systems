// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	if (!st) {
		errno = -1;
		return -1;
	}
	long rez = syscall(__NR_fstat, fd, st);
	if (rez >= 0) {
		return 0;
	}
	errno = -rez;
	return -1;
}
