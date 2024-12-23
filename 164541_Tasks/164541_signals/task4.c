#include <setjmp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	sigjmp_buf env;
	int val = sigsetjmp(env, 1);
	printf("val is %d\n", val);
	printf("new val (0 to exit): ");
	scanf("%d", &val);
	if (val != 0)
		siglongjmp(env, val);
}
