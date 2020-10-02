//2.Write a program which accept file name and mode from user and them open that file in specified mode.
/* First argument -- name of file
   second argument -- mode in which user want to open the file
                      (read,write,readwrite,create,truncate)*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
 int fd=0;
 int mode=0;
 
 if(argc!=3)
 {
  printf("Error : insufficient arguments\n");
  return -1;
 }
 
 //mode in which user want to open the file.
 
 if(strcmp(argv[2],"read")==0)
 {
  mode= O_RDONLY;
 }
 else if(strcmp(argv[2],"write")==0)
 {
  mode= O_WRONLY;
 }
 else if(strcmp(argv[2],"read_write")==0)
 {
  mode= O_RDWR;
 }
 else if(strcmp(argv[2],"create")==0)
 {
  mode= O_CREAT;
 }
 else if(strcmp(argv[2],"truncate")==0)
 {
  mode= O_WRONLY | O_TRUNC;
 }
 else
 {
  printf("Invalid arguments\n");
  return -1;
 }
 
 fd=open(argv[1],mode);
 
 if(fd==-1)
 {
  printf("Unable to open the file\n");
 }
 else
 {
  printf("File is successfully opened with FD = %d and mode = %s", fd,argv[2]);
 }
 
 
 close(fd);
 return 0;
}
