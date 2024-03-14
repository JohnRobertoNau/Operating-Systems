// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	if (!path || !buf) {
		return -1;
	}
	long rez = syscall(__NR_stat, path, buf);

	if (rez >= 0) {
		return 0;
	}
	errno = -rez;
	return -1;
}
