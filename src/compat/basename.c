#include <sys/write.h>
#include <string.h>

/* XXX: should we support suffix-stripping and \0 termination? */

void dumpbname(char* path)
{
	int len = strlen(path);
	char* p;
	char* q;

	/* Strip trailing slashes */
	for(p = path + len - 1; p >= path; p--)
		if(*p == '/')
			*p = '\0';
		else
			break;

	/* Strip leading directories */
	for(q = p = path; *p;)
		if(*p++ == '/')
			q = p;

	*p++ = '\n';

	syswrite(1, q, p - q);
}

int main(int argc, char** argv)
{
	int i;

	for(i = 1; i < argc; i++)
		dumpbname(argv[i]);

	return 0;
}
