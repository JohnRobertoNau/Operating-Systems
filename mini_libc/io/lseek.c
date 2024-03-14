// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
	long rez = syscall(__NR_lseek, fd, offset, whence);

	if (rez >= 0) {
		return (off_t)rez;
	}
	errno = -rez;
	return -1;
}
