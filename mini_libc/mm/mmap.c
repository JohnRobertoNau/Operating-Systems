// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long rez = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (rez > 0) {
		return (void *)rez;
	}
	errno = -rez;
	return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	void *rez = (void *) syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (rez != MAP_FAILED) {
		return rez;
	}
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	int rez = (int) syscall(__NR_munmap, addr, length);
	if (rez != -1) {
		return rez;
	}
	errno = -rez;
	return -1;
}
