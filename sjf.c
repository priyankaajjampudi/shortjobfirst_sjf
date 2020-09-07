#include<stdio.h>
#include<stdlib.h>
/*creating a structure called sjf*/
struct sjf
{
char process_name[10];
int cpu_time;
int arr_time;
}s[10];
int c_time[10],w_time[10],t_time[10];
/*The function read is used to read the values of process_time,cpu_time,arrival_time*/
void read(int n)
{
int i;
for(i=0;i<n;i++)
{
printf("enter P_name,cpu_time,arr_time");
scanf("%s",s[i].process_name);
scanf("%d",&s[i].cpu_time);
scanf("%d",&s[i].arr_time);
}
}
/*The below function is used to sort the process according to their arrival times*/
void sort(int n)
{
int i,j;
struct sjf temp;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(s[j].arr_time<s[i].arr_time)
{
temp=s[i];
s[i]=s[j];
s[j]=temp;
}
}
}
printf("\nsorting completed\n");
}

/*The function cal is use to calculate completion_time,turn_around_time,waiting_times of all process*/
void cal(int n)
{ 
int i,count;
c_time[0]=0;
for(i=0;i<n;i++)
{
//count=search(n);
  if(i==0)
{
  c_time[i]=c_time[i]+s[i].cpu_time;
  t_time[i]=c_time[i]-s[i].arr_time;
  w_time[i]=t_time[i]-s[i].cpu_time;
}
 else
{
  c_time[i]=c_time[i-1]+s[i].cpu_time;
  t_time[i]=c_time[i]-s[i].arr_time;
  w_time[i]=t_time[i]-s[i].cpu_time;
}
}
printf("\ncalculation completed\n");
}
/*The function average is used to find averages of completio_time,turn_around_time,waiting_time*/
float average(int a[10],int n)
{
int i;
float sum=0.0,temp;
for(i=0;i<n;i++)
{
sum=sum+a[i];
}
temp=sum/n;
return temp;
}
/*The function display is used to display all parameters includeing process_name,arrival_time,burst_time,completion_time,turnaround_time,waiting_time and averages of them*/
void display(int no)
{
int i;
float m,n,o; 
m=average(c_time,no);
n=average(t_time,no);
o=average(w_time,no);
printf("process_name     cpu_time      arrival_time    completion_time   turnaround_time    waiting_time\n");
for(i=0;i<no;i++)
{
printf("%10s %10d %14d %14d %16d %16d\n",s[i].process_name,s[i].cpu_time,s[i].arr_time,c_time[i],t_time[i],w_time[i]);
}
printf("\t\t  \t\t  \t\t %8f %15f %15f",m,n,o);
}
int main()
{
struct sjf temp;
int n,i,j,k=1,completion_time=0,min;
printf("enter no of process");//reading no of processes
scanf("%d",&n);
read(n);
sort(n);//sorting according to their arrival times
//display(n);
/*sort according to the burst time if there are equal arrival times*/
for(i=0;i<n;i++)
{
 if((s[i].arr_time==s[i+1].arr_time)&&(s[i].cpu_time>s[i+1].cpu_time))
{
temp=s[i];
s[i]=s[i+1];
s[i+1]=temp;
}
}
//display(n);
/*sorting according to their completion_time*/
for(i=0;i<n;i++)
{
completion_time=completion_time+s[i].cpu_time;
min=s[k].cpu_time;
for(j=k;j<n;j++)
{
if(completion_time>=s[j].arr_time&&s[j].cpu_time<min)
{
temp=s[j];
s[j]=s[k];
s[k]=temp;
}
}
k++;
}
//display(n);
cal(n);
display(n);
}

