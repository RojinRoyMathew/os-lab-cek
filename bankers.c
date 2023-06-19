#include<stdio.h>
int max[10][10],work[10],need[10][10],allocation[10][10];
void main(){
int n,p,r,i,j;
puts("Enter the total no of processes");
scanf("%d",&p);
puts("Enter the total no of resources");
scanf("%d",&r);
puts("Enter the allocation");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
scanf("%d",&allocation[i][j]);
}}
puts("Enter the Max");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
scanf("%d",&max[i][j]);
}
}
puts("Enter the available");
for(i=0;i<r;i++){
scanf("%d",&work[i]);
}
for(i=0;i<p;i++){
for(j=0;j<r;j++){
need[i][j]=max[i][j]-allocation[i][j];
}
}
//----------------------------//
int f[p],ind=0,ans[p],y,k;
for(i=0;i<p;i++){
f[i]=0;
}
for(k=0;k<5;k++){
for(i=0;i<p;i++){
if(f[i]==0){
int flag=0;
for(j=0;j<r;j++){
if(need[i][j]>work[j]){
flag=1;
break;
}}
if(flag==0){
ans[ind++]=i;
for(y=0;y<r;y++){
work[y]+=allocation[i][y];
}
f[i]=1;
}
}
}
}

int flag=1;
for(i=0;i<p;i++){
if(f[i]==0){
flag=0;
puts("System is not safe");
break;
}
}
if(flag==1){
puts("safe sequence\n");
for(i=0;i<p;i++){
printf("P%d",ans[i]);
}
}
//----------------------------//
puts("|allocation |");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf("%d\t",allocation[i][j]);
}
puts("\n");
}
puts("| Max   |");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf("%d\t",max[i][j]);
}
puts("\n");
}
puts("| Need   |");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf("%d\t",need[i][j]);
}
puts("\n");
}
}
