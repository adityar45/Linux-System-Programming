//9.Write a program which accept file name and string from user and write that string into file.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
 int fd=0,ret=0;
 char buffer[20];
 
 if(argc!=2)
 {
  printf("Error : Insufficient argument\n");
  return -1;
 }
 
 fd=open(argv[1],O_WRONLY);
 
 if(fd==-1)
 {
  printf("Error : unable to open file\n");
  return -1;
 }
 printf("File gets opened with fd : %d\n", fd);
 
 printf("Enter the string you want to write in the file :\t");
 scanf("%s", buffer);
 
 write(fd,buffer,strlen(buffer));
 
 return 0;
}
