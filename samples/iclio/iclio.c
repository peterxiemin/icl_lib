#include <stdio.h>
#include <stdlib.h>
#include <icl_file_opt.h>
#include <icl_time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define SIZE 1024*1024*1024
int main(int argc, char *argv[])
{
	int ret;
	char *buf = (char *)malloc(SIZE);
	FILE *fd = icl_fopen("/tmp/test", "r");
//	int fd = icl_open("/tmp/test", O_RDWR);
	icl_prtnow();
	ret = icl_fread(buf, SIZE, 1, fd);
//	ret = icl_read(fd, buf, SIZE);
	if (ret < 0) {
		printf("icl_read: ret: %d \n", ret);
	}
	icl_prtnow();
//	close(fd);
	fclose(fd);
	free(buf);
	return 0;
}
