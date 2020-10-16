//6.Write a program which accepts two directory name and move all files from source directory to destination directory

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
 DIR *dir;
 struct dirent *ret;
 char old[300]={'\0'};
 char new[300]={'\0'};
 
 if(argc!=3)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 
 if((dir=opendir(argv[1]))==NULL)
 {
  printf("Unable to open the specified directory\n");
  return -1;
 }
 
 while((ret=readdir(dir))!=NULL)
 {
  sprintf(old,"%s/%s",argv[1],ret->d_name);
  sprintf(new,"%s/%s",argv[2],ret->d_name);
  
  
  rename(old,new);
  //memset(&old,0,sizeof(old));
  //memset(&new,0,sizeof(new));
  
  
 }
 
 printf("File from the '%s' directory moved successfully\n",argv[1]);
 
 closedir(dir);
 return 0;
}

