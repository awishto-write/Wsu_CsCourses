#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define DEVICE "/dev/chardev"

int main()
{
	int i,fd;
	char ch,write_buf[100],read_buf[100];

	fd=open(DEVICE,O_RDWR);

	if(fd==-1)
	{
    	printf("file %s either does not exist or has been locked by another process\n",DEVICE);
	    exit(-1);
	}
    
    read(fd,read_buf,sizeof(read_buf));
    printf("device: %s\n",read_buf);
   

	close(fd);

	return 0;
}