#include <sys/socket.h>
#include "ctx.h"

long nl_subscribe(struct netlink* nl, int id)
{
	int fd = nl->fd;
	int lvl = SOL_NETLINK;
	int opt = NETLINK_ADD_MEMBERSHIP;

	return sys_setsockopt(fd, lvl, opt, &id, sizeof(id));
}
