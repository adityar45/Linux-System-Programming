//4.Write a program which accepts two file name from user and copy the contents of an existing file into newly created file.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
 int fd=0,ret=0;
 int rd;
 char buffer[200];
 
 fd=open("Demo.txt", O_RDONLY);
 
 if(fd==-1)
 {
  printf("Unable to open the file\n");
  return -1;
 }
 
 ret=creat(argv[2],0777);
 if(ret==-1)
 {
  printf("Unable to create the file\n");
 }
 
 rd=read(fd,buffer,200);
 
 if(rd==-1)
 {
  printf("Unable to read the data\n");
  return -1;
 }
 
 write(ret,buffer,strlen(buffer));
 
 printf("Content gets copied successfully\n");
 
 close(ret);
 close(fd);
 
 return 0;
}
