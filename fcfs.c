#include<stdio.h>
struct fcfs{
int pid,bt,ct,at,tat,wt;
}p[10];
void main(){
int n,i;
double total_tat=0,total_wt=0;
puts("Enter the no of processess");
scanf("%d",&n);
for(i=0;i<n;i++){
puts("|Pid  |Bt  |At  |");
scanf("%d%d%d",&p[i].pid,&p[i].bt,&p[i].at);
p[i].ct=p[i-1].ct+p[i].bt;
p[i].tat=p[i].ct-p[i].at;
total_tat=total_tat+p[i].tat;
p[i].wt=p[i].tat-p[i].bt;
total_wt=total_wt+p[i].wt;
}
puts("------------------------------------");
puts("|Pid  |Bt  |At  |Ct  |Tat  |Wt  |");
puts("------------------------------------");
for(i=0;i<n;i++){
printf("|P%d  |%d  |%d  |%d  |%d  |%d  |\n",p[i].pid,p[i].bt,p[i].at,p[i].ct,p[i].tat,p[i].wt);
}
puts("------------------------------------");
printf("AVERAGE TURN AROUND TIME : %f\n",total_tat/n);
printf("AVERAGE WAITIING TIME : %f",total_wt/n);
}
