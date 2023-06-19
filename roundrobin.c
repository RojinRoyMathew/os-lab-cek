#include<stdio.h>
#include<stdlib.h>
struct rr{
int pid,bt,ct,at,tat,wt,rt;
}p[10];
void main(){
struct rr temp;
int n,i,j,t,flag=0,time=0;
double total_tat=0,total_wt=0;
puts("Enter the no of processess");
scanf("%d",&n);
int y=n;
for(i=0;i<n;i++){
puts("|Pid  |Bt  |At  |");
scanf("%d%d%d",&p[i].pid,&p[i].bt,&p[i].at);
p[i].rt=p[i].bt;
}
puts("Enter the silece");
scanf("%d",&t);
int sum;
for(sum=0,i=0;y!=0;){
if(p[i].rt<=t && p[i].rt>0){
sum=sum+p[i].rt;
p[i].ct=sum;
p[i].rt=0;
y--;
}else if(p[i].rt>0){
p[i].rt=p[i].rt-t;
sum=sum+t;
p[i].ct=sum;
}
if(i==n-1){
i=0;
}else if(p[i+1].at<=sum){
i++;
}else{
i=0;
}
}
for(i=0;i<n;i++){
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
}
puts("------------------------------------");
puts("|Pid  |Bt  |At  |Ct  |Tat  |Wt  |");
puts("------------------------------------");
for(i=0;i<n;i++){
total_tat=total_tat+p[i].tat;
total_wt=total_wt+p[i].wt;
printf("|P%d  |%d  |%d  |%d  |%d  |%d  |\n",p[i].pid,p[i].bt,p[i].at,p[i].ct,p[i].tat,p[i].wt);
}
puts("------------------------------------");
printf("AVERAGE TURN AROUND TIME : %f\n",total_tat/n);
printf("AVERAGE WAITIING TIME : %f",total_wt/n);
}
