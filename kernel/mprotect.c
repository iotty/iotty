/*
 * Detect memory access using mprotect
 */
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static int alloc_size;
static char *memory;

void segv_handler(int signal_number)
{
	printf("memory accessed!\n");
	mprotect(memory, alloc_size, PROT_READ|PROT_WRITE);
}

int main()
{
	int fd;
	struct sigaction sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &segv_handler;
	sigaction(SIGSEGV, &sa, NULL);

	alloc_size = getpagesize();
	fd = open("/dev/zero", O_RDONLY);
	memory = mmap(NULL, alloc_size, PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);

	memory[0] = 0;
	mprotect(memory, alloc_size, PROT_NONE);

	memory[0] = 1;
	printf("all done\n");
	munmap(memory, alloc_size);

	return 0;
}
