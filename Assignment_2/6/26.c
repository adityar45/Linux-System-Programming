//6.Write a program which accepts file name from the user and read whole file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
 int fd=0,ret=0;
 char arr[256];
 
 if(argc!=2)
 {
 printf("Error: Insufficient arguments\n");
 return -1;
 }
 //open the file
 fd=open(argv[1],O_RDONLY);
 
 if(fd==-1)
 {
  printf("Error: Unable to open file\n");
  return -1;
 }
 printf("File gets open with FD : %d\n", fd);
 
 
 //read the data
 //ret=read(fd,arr,256)
 
 /*if(ret==-1)
 {
  printf("Unable to read the file\n");
  return -1;
 }
 */
 
 printf("The data from the file is :\t");
 while(read(fd,arr,256)!=0)
 {
  printf("%s",arr);
 }
 
 close(fd);
 return 0;

}
