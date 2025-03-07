#include<stdio.h>
int main(){
        int pid[15],tt=0,t,bt[15],rt[15],r=0,n,p=0,c,at[15],ct[15],tat[15],wt[15],s=0;
        float avg;
        printf("Enter Number of Process :: ");
        scanf("%d",&n);
        printf("Enter %d Process Ids :: \n",n);
        for (int i = 0; i < n; i++)
        {
        scanf("%d",&pid[i]);
        }
        for(int i=0; i < n;i++){
                printf("Enter process %d Burst Time :: ",pid[i]);
                scanf("%d",&bt[i]);
        }
        printf("Enter the Time Quantam :: ");
        scanf("%d",&t);
        for(int i=0;i<n;i++){
            tt=tt+bt[i];
            rt[i]=bt[i];
        }
        ct[0]=0;
        while (r<tt)
        {
        for(int i=0;i<n;i++){
                if(rt[i]!=0){
                         if(rt[i]<t){
                                ct[i]=ct[p]+rt[i];
                                p=i;
                                r=r+rt[i];
                                rt[i]=0;
                                }
                         else{
                                ct[i]=ct[p]+t;
                                rt[i]=rt[i]-t; 
                                p=i; 
                                r=r+t;     
                                }
                }
        }
        }
                for(int i=0;i<n;i++){
                        wt[i]=ct[i]-bt[i];
                        s=s+wt[i];
                }
        printf("|        Process Id       |       Burst Time       |       Complete Time      |       Waiting Time      |\n");
        printf("|-------------------------|------------------------|--------------------------|-------------------------|\n");
        for(int i=0;i<n;i++){
                printf("|%25d|%24d|%26d|%25d|\n",pid[i],bt[i],ct[i],wt[i]);
        }
        avg=(float)s/n;
        printf("Average Waiting Time using Round Robin Technique :: %.2f",avg);
        
        printf("\n"); 
        return 0;
}
