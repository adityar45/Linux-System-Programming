//7.Write a program which accept file name from user and write the string into that file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
 int fd,ret;
 char arr[256];
 
 if(argc!=2)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
  
 //open the file
 fd=open(argv[1],O_WRONLY | O_RDONLY);
 if(fd==-1)
 {
  printf("Unable to open the file\n");
  return -1;
 }
 printf("File gets open successfully with FD : %d\n", fd);
 
 printf("Enter the string that you want to write i  file :\t");
 scanf("%s", arr);
 
 ret=write(fd,arr,strlen(arr));
 
 if(ret!=strlen(arr))
 {
  printf("Unable to write whole string\n");
  return -1;
 }
 close(fd);
 
 return 0;
}
