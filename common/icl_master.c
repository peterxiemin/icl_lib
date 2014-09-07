/*
 * icl_master.c
 *
 *  Created on: 2014-1-23
 *  Modify  on: 2014-9-4
 *      Author: peterxmw
 */

#include "icl_master.h"

int icl_process() {
	int fd;
	int i, j, status;
	//pid_t pid;
	char buf[BUFFSIZE];

	//fd = open("./log", O_RDWR | O_CREAT);

//	for (i = 0; i < CHILDNUM; i++) {
//		switch (fork()) {
//		case 0:
//			/* child */
//		{
//			pid_t chd_pid = getpid();
//			sprintf(buf, "child id : %d\n", chd_pid);
//			//(void) write (fd, buf, strlen(buf));
//			printf("%s\n", buf);
//		}
//			while (1) {
//				sleep(1);
//			}
//		case -1:
//			assert(0);
//			break;
//		default:
//			/* parent */
//			break;
//		}
//	}

	do {
		pid_t pid;
		//pid = wait(NULL);
		sprintf(buf, "parent id : %d\n", pid);
		//write(fd, "parent wait ret pid : %d\n", pid);
		printf("%s\n", buf);
		j++;
		sleep(2);
	} while (j < 3);
	/* release file resource */
	close(fd);
	return 0;
}

