// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	while (*source) {
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	while (*source && i < len) {
		*destination = *source;
		source++;
		destination++;
		i++;
	}

	char *copie = destination;
	while (*source) {
		source++;
		destination++;
	}

	*destination = '\0';
	destination = copie;
	return destination;
}

char *strcat(char *destination, const char *source)
{
	while (*destination)
	{
		destination++;
	}

	while (*source) {
		*destination = *source;
		source++;
		destination++;
	}

	*destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	while (*destination)
	{
		destination++;
	}

	size_t i = 0;
	while (*source && i < len) {
		*destination = *source;
		source++;
		destination++;
		i++;
	}

	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2) {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }

    if (*str1) {
        return 1;
    } else if (*str2 == *str1) {
        return 0;
    }
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;

	while (*str1 && *str2 && i < len) {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
		i++;
    }

    if (i == len) {
        return 0;
    } else if (*str1) {
        return 1;
    }
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str) {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *copy = str;
	while (*copy)
	{
		if(*(++copy)) {
			copy++;
		}
	}

	while (copy != str)
	{
		if (*copy == c) {
			return (char *)copy;
		}
		copy--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	while (*haystack) {
		if (strncmp(haystack, needle, strlen(needle)) == 0) {
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *copy = haystack;
	while(*copy) {
		if (*(++copy)) {
			copy++;
		}
	}

	while (copy != haystack)
	{
		if (strncmp(copy, needle, strlen(needle)) == 0) {
			return (char *)copy;
		}
		copy--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	size_t i = 0;
	unsigned char *copy_dest = (unsigned char *)destination;
	unsigned char *copy_source = (unsigned char *)source;
	for (i = 0; i < num; i++) {
		copy_dest[i] = copy_source[i];
	}

	destination = (void *)copy_dest;
	return destination;
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	size_t i = 0;
	unsigned char *copy_dest = (unsigned char *)destination;
	unsigned char *copy_source = (unsigned char *)source;

	if (copy_dest == copy_source) {
		return destination;
	} else if (copy_dest < copy_source) {
		for (i = 0; i < num; i++) {
			copy_dest[i] = copy_source[i];
		}
	} else {
		for (i = num; i > 0; i--) {
			copy_dest[i - 1] = copy_source[i - 1];
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char *copy_ptr1 = (unsigned char *) ptr1;
	unsigned char *copy_ptr2 = (unsigned char *) ptr2;
	size_t i = 0;

	while (*copy_ptr1 && *copy_ptr2 && i < num) {
        if (*copy_ptr1 < *copy_ptr2) {
            return -1;
        } else if (*copy_ptr1 > *copy_ptr2) {
            return 1;
        }
        copy_ptr1++;
        copy_ptr2++;
		i++;
    }

    if (i == num) {
        return 0;
    } else if (*copy_ptr1) {
        return 1;
    }

	return -1;
}

void *memset(void *source, int value, size_t num)
{
	size_t i = 0;
	unsigned char *copy_source = (unsigned char *)source;
	for (i = 0; i < num; i++) {
		copy_source[i] = (unsigned char) value;
	}
	return source;
}
