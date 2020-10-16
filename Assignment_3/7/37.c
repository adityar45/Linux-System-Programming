//7.Write a program which accepts directory name from user and delete all empty files from that directory.

#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
 DIR *dir;
 struct dirent *ret;
 struct stat fileinfo;
 char name[100]={'\0'};
 
 if(argc!=2)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 
 if((dir=opendir(argv[1]))==NULL)
 {
  printf("Unable to open the directory\n");
  return -1;
 }
 
 while((ret=readdir(dir))!=NULL)
 {
  sprintf(name,"%s/%s",argv[1],ret->d_name);
  stat(name,&fileinfo);
  printf("%s\n",name);
  
  if(S_ISREG(fileinfo.st_mode))
  {
   if((int)fileinfo.st_size==0)
   {
    remove(name);
   }
  }
 }
 
 closedir(dir);
 return 0;
 
}





