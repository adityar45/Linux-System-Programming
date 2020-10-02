//4.Write a program which accepts file name from user and print all information about that file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char *argv[])
{
 int ret , fd;
 struct stat fileinfo; //structure to store info abt file.
 
 if(argc!=2)
 {
  printf("Error: insufficient arguments\n");
  return -1;
 } 
 
 ret = stat(argv[1],&fileinfo);
 
 if(ret==-1)
 {
  printf("Unable to get the info about file\n");
  return -1;
 }
 
 
 //Main information about file
 printf("File size:\t%d bytes\n",(int)fileinfo.st_size);
 printf("Link Count:\t%d\n",(int)fileinfo.st_nlink);
 printf("Inode number:\t%d\n",(int)fileinfo.st_ino);
 printf("ID of device containing file:\t%d\n",(int)fileinfo.st_dev);
 printf("File mode :\t%o\n",fileinfo.st_mode);
 printf("UID:\t%d\n",fileinfo.st_uid);
 printf("GID:\t%d\n",fileinfo.st_gid);
 printf("Block size:\t%ld\n",fileinfo.st_blksize);
 printf("No. of blocks allocated:\t%ld\n\n", fileinfo.st_blocks);
 
 //File mode
 printf((S_ISDIR(fileinfo.st_mode))?"d":"-");
 printf((fileinfo.st_mode & S_IRUSR)?"r":"-");
 printf((fileinfo.st_mode & S_IWUSR)?"w":"-");
 printf((fileinfo.st_mode & S_IXUSR)?"x":"-");
 printf((fileinfo.st_mode & S_IRGRP)?"r":"-");
 printf((fileinfo.st_mode & S_IWGRP)?"w":"-");
 printf((fileinfo.st_mode & S_IXGRP)?"x":"-");
 printf((fileinfo.st_mode & S_IROTH)?"r":"-");
 printf((fileinfo.st_mode & S_IWOTH)?"w":"-");
 printf((fileinfo.st_mode & S_IXOTH)?"x":"-");
 
 //Check for symbolic link
 if(S_ISLNK(fileinfo.st_mode))
 {
  printf("\n\nIt is symbolic link\n");
 }
 else
 {
  printf("\n\nIt is not a symbolic link\n");
 }
 //To check access time
 printf("Last status change:%s\t\n", ctime(&fileinfo.st_ctime));
 printf("Last file access:%s\t\n", ctime(&fileinfo.st_atime));
 printf("Last file modification:%s\t\n\n", ctime(&fileinfo.st_mtime));
 
 
 //File type
 printf("File type is:\t");
 
 switch(fileinfo.st_mode & S_IFMT)
 {
  case S_IFBLK:
  printf("Block device\n");
  break; 
  case S_IFCHR:
  printf("Character device\n");
  break; 
  case S_IFDIR:
  printf("Directory\n");
  break; 
  case S_IFIFO:
  printf("FIFO/Pipe\n");
  break; 
  case S_IFLNK:
  printf("Symlink\n");
  break; 
  case S_IFREG:
  printf("Regular file\n");
  break; 
  case S_IFSOCK:
  printf("Socket\n");
  break; 
  default: printf("Unknown\n");
 }
return 0;
}
