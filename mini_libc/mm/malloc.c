// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (mem_list_num_items() == 0) {
		mem_list_init();
	}
	void *memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (memory != MAP_FAILED && mem_list_add(memory, size) == 0) {
		return memory;
	}
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *memory = malloc(size);
	if (memory != NULL) {
	 	memset(memory, 0, nmemb);
	 	return memory;
	}
	return NULL;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *item = mem_list_find(ptr);
	munmap(ptr, item->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *item = mem_list_find(ptr);
	void *rez = mremap(ptr, item->len, size, MREMAP_MAYMOVE);
	if (rez != NULL) {
		item->len = size;
		item->start = rez;
		return rez;
	}
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	malloc(nmemb * size);
	realloc(ptr, nmemb * size);
	if (ptr != NULL) {
		return ptr;
	}
	return NULL;
}
