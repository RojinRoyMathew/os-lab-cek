#include<stdio.h>
struct sje{
int pid,bt,ct,at,tat,wt;
}p[10];
void main(){
struct sje temp;
int n,i,j;
double total_tat=0,total_wt=0;
puts("Enter the no of processess");
scanf("%d",&n);
for(i=0;i<n;i++){
puts("|Pid  |Bt  |At  |");
scanf("%d%d%d",&p[i].pid,&p[i].bt,&p[i].at);
}
p[0].ct=p[0].bt;
p[0].tat=p[0].ct-p[0].at;
p[0].wt=p[0].tat-p[0].bt;
for(i=1;i<n-1;i++){
for(j=i+1;j<n;j++){
if(p[i].bt>p[j].bt){
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
for(i=1;i<n;i++){
p[i].ct=p[i-1].ct+p[i].bt;
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
