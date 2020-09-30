//5.Write a program which accepts file name from user and open that file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
 int fd=0;
 int ret=0;
 
 if(argc!=2)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 
 fd=open(argv[1],O_WRONLY);
 if(fd!=-1)
 {
 printf("File gets successfully opened with FD : %d\n\n", fd);
 }
 return 0;
} 
