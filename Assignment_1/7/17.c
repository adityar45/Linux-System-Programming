//7.Write a program which accept file name from user and read first 5 characters from it.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
 int fd=0,ret=0;
 char buffer[11];
 
 if(argc!=2)
 {
  printf("Error : Insufficient argument\n");
  return -1;
 }
 
 fd=open(argv[1],O_RDONLY);
 
 if(fd==-1)
 {
  printf("Error : unable to open file\n");
  return -1;
 }
 printf("File gets opened with fd : %d", fd);
 
 ret=read(fd,buffer,5);
 
 if(ret==-1)
 {
  printf("Unable to read \n");
  return -1;
 }
 
 printf("Data read from file is : %s\n", buffer);
 return 0;
}
