//5.Write a program which accepts file name and number of bytes from user and read that number of bytes from file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
 int fd=0;
 int ret=0;
 char *arr=NULL;
 
 if(argc!=3)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 //open the file
 fd=open(argv[1],O_RDONLY);
 
 if(fd == -1)
 {
  printf("Error: Unable to open\n");
  return -1;
 }
 else
 printf("File gets open successfully with FD : %d\n",fd);
 
 //Allocate memory for array
 arr=(char*)malloc(sizeof(char)*atoi(argv[2]));
 if(arr==NULL)
 {
  printf("Memory allocation fails\n");
  return -1;
 }
 
 //read the file
 ret=read(fd,arr,atoi(argv[2]));
 
 //if unable to read all the bytes
 if(ret != atoi(argv[2]))
 {
  printf("Unable to read all the bytes given\n");
  return -1;
 }
 
 printf("The data read from the file '%s' is : %s\n",argv[1],arr);
 
 close(fd);
 return 0;
}
