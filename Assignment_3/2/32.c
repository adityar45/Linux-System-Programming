//2.Write a program which accepts directory name from user and print all file names and its types from that directory.

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
 DIR *dir;
 struct dirent *ret;
 
 if(argc!=2)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 
 //Open the directory
 if((dir = opendir(argv[1])) == NULL)
 {
  printf("Unable to open the file\n\n");
  return -1;
 }
 
 printf("Contents of directory '%s' are :\n", argv[1]);
 printf("File name  |  File type\n\n");
 
 
 //read the directory
 while((ret=readdir(dir)) != NULL)
 {
  printf("%s\t",ret->d_name);
  
  if(ret->d_type == DT_REG)
  printf("Regular file\n");
  if(ret->d_type == DT_BLK)
  printf("Block device\n");
  if(ret->d_type == DT_CHR)
  printf("Character device\n");
  if(ret->d_type == DT_DIR)
  printf("Directory\n");
  if(ret->d_type == DT_FIFO)
  printf("Named pipe(FIFO)\n");
  if(ret->d_type == DT_LNK)
  printf("Symbolic link\n");
  if(ret->d_type == DT_SOCK)
  printf("Socket\n");
  if(ret->d_type == DT_UNKNOWN)
  printf("Unknown\n");
 } 
 
 closedir(dir);
 return 0;
}
