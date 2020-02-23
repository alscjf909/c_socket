#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 100

void error_handling(char* message);

int main(void)
{
	int fd;//fd : 파일 디스크립터(소켓에 정수 값을 붙여주는것)
	char buf[BUF_SIZE];
	
	fd=open("data.txt", O_RDONLY);//data.txt읽기
	if( fd==-1)//파일 열기 이름, 매개변수 flag or을 통해서 묶어서 전달가능
		error_handling("open() error!");
	
	printf("file descriptor: %d \n" , fd);
	
	if(read(fd, buf, sizeof(buf))==-1)//성공 시 수신한 바이트수, 실패 시 -1반환
		error_handling("read() error!");

	printf("file data: %s", buf);
	
	char buf2[BUF_SIZE];
	
	fd=open("data2.txt", O_RDONLY);//data2.txt읽기
	if( fd==-1)
		error_handling("open() error!");
	
	printf("file descriptor: %d \n" , fd);
	
	if(read(fd, buf2, sizeof(buf2))==-1)
		error_handling("read() error!");

	printf("file data: %s", buf2);
	
	close(fd);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/*
root@com:/home/swyoon/tcpip# gcc low_read.c -o lread
root@com:/home/swyoon/tcpip# ./lread
file descriptor: 3 
file data: Let's go!
root@com:/home/swyoon/tcpip# 
*/
