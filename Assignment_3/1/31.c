//1.Write a program which accept directory name from user and print all the file names from that directory.

#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
 DIR *dir;
 struct dirent *ret;
 
 if(argc!=2)
 {
  printf("Error: Insufficient arguments\n");
  return -1;
 }
 
 if((dir=opendir(argv[1]))==NULL)
 {
  printf("Unable to open specified directory\n");
  return -1;
 }
 
 printf("Cotents of the directory are :\n");
 
 while((ret = readdir(dir)) != NULL)
 {
 printf("Name: %s  \t Inode: %ld\n", ret->d_name,ret->d_ino);
 }
 
 closedir(dir);
 return 0; 
}
