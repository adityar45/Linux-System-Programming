//5.Write a program which accept directory name and file name from user and check whether the file is present in the directory or not.

#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
 DIR *dir;
 struct dirent *ret;
 
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
 
 while((ret=readdir(dir)) != NULL)
 {
   if(strcmp(argv[2],ret->d_name)==0)
   {
   printf("The file exists\n");
   return 0;
   }
  
 }
 
 printf("The file not exists\n");
 
 closedir(dir);

}


