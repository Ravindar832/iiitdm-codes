#include<stdio.h>

void fcfs()
{
    

    float avarage_waiting_time=0,avarage_turn_around_time=0;
    
    int n,temp,i,j;
    printf("enter the number of process   :");
    scanf("%d",&n);
    
    int p_id[n],arr_time[n],burst_time[n],comp_time[n],turnarnd_time[n],waiting_time[n];
     
    for(i=0; i<n; i++)
    {
         
         printf(" enter p_id = %d:",i+1);
         scanf("%d",&p_id[i]);
         
         printf("enter arrival time %d:", i+1 );
         scanf("%d",&arr_time[i]);

         printf("enter burst time   %d:", i+1);
         scanf("%d",&burst_time[i]);
    }
    
    for(i=0; i<n; i++){
        for(j=0;j<(n-1); j++){ 
            if(arr_time[j]>arr_time[j+1]){
                temp = p_id[j+1];
                p_id[j+1] = p_id[j];
                p_id[j] = temp;
                
                temp = arr_time[j+1];
                arr_time[j+1] = arr_time[j];
                arr_time[j] = temp;
                
                temp = burst_time[j+1];
                burst_time[j+1] = burst_time[j];
                burst_time[j] = temp;
                
            }
        }
    }
    comp_time[0] = arr_time[0]+burst_time[0];
    
    for(i=1; i<n; i++){
        temp = 0;
        if(comp_time[i-1]<arr_time[i]){
            temp = arr_time[i] - comp_time[i-1];
        }
        comp_time[i] = comp_time[i] + burst_time[i] + temp; 
    }
    
    for(i=0; i<n; i++){
       turnarnd_time[i] = comp_time[i]-arr_time[i];
       waiting_time[i] = turnarnd_time[i] - burst_time[i];
       
       avarage_turn_around_time += turnarnd_time[i];
       avarage_waiting_time +=  waiting_time[i];
        
    }
    
    avarage_turn_around_time = avarage_turn_around_time/n;
    avarage_waiting_time = avarage_waiting_time/n;
    
    printf("p_id\tarr_time\tburst_time\tcomp_time\tturnarnd_time\twaiting_time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p_id[i],arr_time[i],burst_time[i],comp_time[i],turnarnd_time[i],waiting_time[i]);
    }
    
    printf("avarage waiting time : %f\n", avarage_waiting_time );
    printf("avarage turn around time : %f\n", avarage_turn_around_time );
    
    printf("time complexity = O(n^2)");
    
    
}

void sjf()
{
    float avarage_waiting_time=0,avarage_turn_around_time=0;
    int n,temp,i,j,pos,total,totalT;
    printf("enter the number of process   :");
    scanf("%d",&n);
    int p_id[n],arr_time[n],burst_time[n],comp_time[n],turnarnd_time[n],waiting_time[n];
    for(i=0; i<n; i++)
    {
         
         printf(" enter p_id = %d:",i+1);
         scanf("%d",&p_id[i]);
         
         printf("enter arrival time %d:", i+1 );
         scanf("%d",&arr_time[i]);

         printf("enter burst time   %d:", i+1);
         scanf("%d",&burst_time[i]);
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp=p_id[i];
        p_id[i]=p_id[pos];
        p_id[pos]=temp;
    }
 
    waiting_time[0]=0;
    
     //finding the waiting time of all the processes
    for(i=1;i<n;i++)
    {
         waiting_time[i]=0;
        for(j=0;j<i;j++)
             //individual  waiting_time by adding BT of all previous completed processes
             waiting_time[i]+=burst_time[j];
 
        //total waiting time
        total+= waiting_time[i];   
    }
 
    //average waiting time
    avarage_waiting_time =(float)total/n;  
 
    
    for(i=0;i<n;i++)
    {
        //turnaround time of individual processes
        turnarnd_time[i]=burst_time[i]+ waiting_time[i]; 
 
        //total turnaround time
        totalT+=turnarnd_time[i];      
       
    }
    
    avarage_turn_around_time = totalT/n;
    // avarage_waiting_time = avarage_waiting_time/n;
    
    printf("p_id\tarr_time\tburst_time\tcomp_time\tturnarnd_time\twaiting_time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p_id[i],arr_time[i],burst_time[i],comp_time[i],turnarnd_time[i],waiting_time[i]);
    }
    
    printf("avarage waiting time : %f\n", avarage_waiting_time );
    printf("avarage turn around time : %f\n", avarage_turn_around_time );
    
    printf("time complexity = O(n^2)");
    
   
    
}

int main()
{
    int k=0;
    printf("enter k=0 for fcfs \n");
    printf("enter k=1 for sjf \n");
    
    scanf("%d",&k);
    
    if(k==0)
    {
        printf("fcfs\n");
        fcfs(k);
    }
    
    if(k==1){
        {
        printf("sjf\n");
        sjf(k);
    }
    }
    
    return 0;
}