#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
		return 1;
	}

	pid_t pid = atoi(argv[1]);
	if (kill(pid, SIGINT) == -1) {
		perror("kill");
		return 1;
	}

	printf("Sent SIGTERM to process %d\n", pid);
	return 0;
}
