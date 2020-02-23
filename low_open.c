#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handling(char* message);

int main(void)
{
	int fd;//fd : 파일 디스크립터(소켓에 정수 값을 붙여주는것)
	char buf[]="Let's go!\n";
	
	fd=open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);//파일 열기 이름, 매개변수 flag or을 통해서 묶어서 전달가능
	if(fd==-1)//성공시 0 실패 시 -1 반환
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);//파일 디스크립터 확인

	if(write(fd, buf, sizeof(buf))==-1)//파일에 데이터 쓰기, 성공시 전달한 바이트수, 실패시 -1반환)
		error_handling("write() error!");

	char buf2[]="Hello World!\n";
	
	fd=open("data2.txt", O_CREAT|O_WRONLY|O_TRUNC);
	if(fd==-1)
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);//닫지 않고 할시 4라는 다른 정수 입력됨

	if(write(fd, buf2, sizeof(buf2))==-1)
		error_handling("write() error!");

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
root@com:/home/swyoon/tcpip# gcc low_open.c -o lopen
root@com:/home/swyoon/tcpip# ./lopen
file descriptor: 3 
root@com:/home/swyoon/tcpip# cat data.txt
Let's go!
root@com:/home/swyoon/tcpip# 
*/
