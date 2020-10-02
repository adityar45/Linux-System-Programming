//3.Write a program which accept file name and mode and that program check whether our process can access that file in accepted mode or not.
/*First argument -- name of file
  second argument --mode(read,write,execute)*/
  
//This program demonstrate accessibility of files

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
 int mode=0;
 
 if(argc!=3)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 
 //to check whether the file exists or not
 if(access(argv[1], F_OK)!=0)
 {
  printf("The file doesn't exist\n");
  return -1;
 }
 
 
 if(strcmp(argv[2],"read")==0)
 {
  mode= R_OK;
 }
 else if(strcmp(argv[2],"read")==0)
 {
  mode= W_OK;
 }
 else if(strcmp(argv[2],"read")==0)
 {
  mode= X_OK;
 }
 
//access() --> check whether the calling process can access the file pathname. if pathname is a symbolic link , it is dereferenced.

if(access(argv[1], mode)<0)
{
 printf("Our process cannot access this file for %s\n\n",argv[2]);
}
else
{
 printf("The process has %s access\n\n",argv[2]);
}

return 0;

}  
