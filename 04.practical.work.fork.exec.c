#include <unistd.h>
#include <stdio.h>
int main()
{
	printf("the main that before we fork\n");
	int pid = fork();
	if (pid==0)
        {
		int pid2 = fork();
		if (pid2==0) {
			printf("The child is psing\n");
			char *args[] = {"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", args);
		}
		else 
        {
			printf("Child is freeing\n");
			char *args[] = {"free", "-h", NULL};
			execvp("free", args);
		}
	}
 

