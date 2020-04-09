
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

void  main()
{
	

int n=0;
int a=0;
	
pid_t p;

printf("Enter any positive number except zero :  "); 
scanf("%d", &a);	
		
p = fork();
if (p== 0)
{
			
	printf("%d\n",a);
	while (a!=1)
	{
		if (a%2 == 0)
		{
			a = a/2;
		}
		else if (a%2 == 1)
		{
			a = 3 * (a) + 1;
		}	
			
		printf("%d\n",a);
	}
		
	printf("Child process is completed\n");
}
else
{
	printf("Parent is waiting for child process to complete\n");
	wait();
	printf("Parent process is completed.\n");
}
	
}
