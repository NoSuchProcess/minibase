#include <bits/types.h>

#define MAX_CONFIG_SIZE 4092

#define NBDEVS 10
#define NPARTS 20

/* bdev.how */
#define BY_NAME 0
#define BY_PG80 1
#define BY_CID  2
#define BY_MBR  3
#define BY_GPT  4

/* bdev.mode */
#define NONE    0
#define PARTS   1
#define WHOLE   2

struct bdev {
	short how;
	short mode;
	short here;
	char id[50];
	char name[30];
};

struct part {
	short devidx;
	short here;
	char part[10];
	char label[20];
	char name[30];
	uint64_t rdev;
	uint64_t size;
	int dmi;
};

extern struct bdev bdevs[NBDEVS];
extern struct part parts[NPARTS];

extern int nbdevs;
extern int nparts;

void load_config(void);

void open_udev(void);
void scan_devs(void);
void wait_udev(void);
int any_missing_devs(void);
int any_encrypted_parts(void);
void link_parts(void);

int match_dev(char* name);
void match_part(char* name);
int check_partitions(void);
void link_parts(void);

int error(const char* msg, char* arg, int err) noreturn;
int check_keyindex(int keyidx);
void quit(const char* msg, char* arg, int err) noreturn;
