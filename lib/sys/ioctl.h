#include <bits/syscall.h>
#include <syscall.h>

inline static long sysioctl(int fd, unsigned long request, long arg)
{
	return syscall3(__NR_ioctl, fd, request, arg);
}