#include<stdio.h>
#include<fcntl.h>
#include<error.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
void read_sys();
void open_sys();
void write_sys();
void main(){
open_sys();
read_sys();
write_sys();
}
void open_sys(){
int fid =open("sys_a.txt",O_RDONLY |O_CREAT);
if(fid==-1){
puts("cant create file an error occurs");
}else{
puts("file create successfully");
}
}
void read_sys(){
int fid =open("sys_a.txt",O_RDONLY);
char buffer[100];
read(fid,&buffer,100);
printf("Data written in file is : %s",buffer);
}
void write_sys(){
int fid1 =open("sys_a.txt",O_RDWR);
char buff[100]="hai";
//printf("Enter the data written to file\n");
//scanf("%c",&buff);
write(fid1,buff,strlen(buff));
printf("data written to file is %s\n",buff);
close(fid1);
}

