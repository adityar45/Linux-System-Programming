//Write a program which accept directory name from user and printf name of such a file having largest size.

#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
 DIR *dir;
 struct dirent *ret;
 struct stat fileinfo;
 int max=0;
 char FileName[256];
 char name[100]={'\0'};
 
 if(argc!=2)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 }
 
 //Open the directory
 if((dir=opendir(argv[1])) == NULL)
 {
  printf("Unable to open the file\n");
  return -1;
 }
 
 //Traverse directory
 while((ret=readdir(dir)) != NULL)
 {
  sprintf(name,"%s/%s",argv[1],ret->d_name);
  stat(name,&fileinfo);
  
  if(S_ISREG(fileinfo.st_mode))
  {
   if(max < (int)fileinfo.st_size)
   {
    memset(FileName,0,sizeof(FileName));
    strcpy(FileName,ret->d_name);
    max = (int)fileinfo.st_size;
   }
  }
  memset(&fileinfo,0,sizeof(fileinfo));
 }
 
 printf("File with maximum size: %s\n Size: %d\n",FileName,max);
 
 closedir(dir);
 return 0;

}
