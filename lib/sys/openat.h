#include <bits/syscall.h>
#include <syscall.h>

inline static long sysopenat(int dir, const char* path, int flags)
{
	return syscall3(__NR_openat, dir, (long)path, flags);
}