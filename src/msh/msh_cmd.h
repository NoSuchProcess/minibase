#ifndef CMD
#define CMD(name) int cmd_##name(struct sh* ctx);
#endif

CMD(cd)
CMD(chroot)
CMD(close)
CMD(die)
CMD(dupfd)
CMD(echo)
CMD(exec)
CMD(exit)
CMD(export)
CMD(groups)
CMD(invoke)
CMD(mkdir)
CMD(onexit)
CMD(prctl)
CMD(reopen)
CMD(rlimit)
CMD(setcaps)
CMD(setenv)
CMD(setgid)
CMD(setprio)
CMD(setuid)
CMD(sleep)
CMD(stderr)
CMD(stdin)
CMD(stdout)
CMD(stdtwo)
CMD(umask)
CMD(unlink)
CMD(unset)
CMD(waitfor)
CMD(warn)
CMD(write)

#undef CMD
