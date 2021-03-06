#include <stdio.h>
#include <sys/epoll.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <icl_net_tcp_base.h>

#define MAX_EVENTS 10

#define handle_error(msg) \
	do { perror(msg);exit(-1);} while (0)


/*
 * setnonblocking - 设置句柄为非阻塞方式
 * */
int setnonblocking(int sockfd)
{
	if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK) == -1) {
		return -1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int n;
	char buf[MAXLINE];
	struct epoll_event ev, events[MAX_EVENTS];
	int listen_sock, conn_sock, nfds, epollfd;
	/* Set up listening socket, 'listen_sock' (socket(),
	   bind(), listen()) */
	listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr, local;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(7744);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(servaddr.sin_zero),8);
	int ret = bind(listen_sock, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
	if (ret < 0) {
		handle_error("bind error port 7744:");
		return -1;
	}
	ret = listen(listen_sock, 1024);
	if (ret < 0) {
		printf("listen error\n");
		return -1;
	}
	/////////////////////////////////////////

	epollfd = epoll_create(10);
	if (epollfd == -1) {
		perror("epoll_create");
		exit(EXIT_FAILURE);
	}

	ev.events = EPOLLIN;
	ev.data.fd = listen_sock;
	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
		perror("epoll_ctl: listen_sock");
		exit(EXIT_FAILURE);
	}
	for (;;) {
		nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		if (nfds == -1) {
			perror("epoll_pwait");
			exit(EXIT_FAILURE);
		}

		for (n = 0; n < nfds; ++n) {
			if (events[n].data.fd == listen_sock) {
				int sock_len = sizeof(struct sockaddr);
				conn_sock = accept(listen_sock, (struct sockaddr *) &local, (socklen_t *)&sock_len);
				if (conn_sock == -1) {
					perror("accept");
					exit(EXIT_FAILURE);
				}
				setnonblocking(conn_sock);
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = conn_sock;
				if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
					perror("epoll_ctl: conn_sock");
					exit(EXIT_FAILURE);
				}
			} else {
				ev = events[n];
				char rbuffer[MAXLINE];
				int n = read(ev.data.fd, rbuffer, MAXLINE);
				if (n <= 0) {
					if (epoll_ctl(epollfd, EPOLL_CTL_DEL, ev.data.fd, &ev) == -1) {
						perror("epoll_ctl: fd");
						exit(EXIT_FAILURE);
					}
					close(ev.data.fd);
				}
				else {
					rbuffer[n] = 0;
					printf("read ok, rbuffer:%s\n", rbuffer);
					write(ev.data.fd, rbuffer, n);
					printf("send ok!\n");
				}
			}
		}
	}
	return 0;
}
