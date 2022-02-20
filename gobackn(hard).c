#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    int i=1,win_size,frame_count;
    int ack_counter=0;
    int total_transmissions=0;
    printf("\nenter the number of frames to transmit");
    scanf("%d",&frame_count);

    printf("\nenter the window size");
    scanf("%d",&win_size);
    srand(time(0));
        
    while(i <= frame_count){
        
        for(int j=i;j<i+win_size && j<=frame_count;j++){
            printf("\nframe:%d sent",j);
            total_transmissions++;
        }
        for(int j=i;j<i+win_size && j<= frame_count;j++){
            if(rand()%2 == 0){
                printf("\nframe %d transmission failed",i);
                break;
            }
            else{
                printf("\nframe %d acknowledged",i);
                i++;
            }
            
        }
    }

    printf("total transmissions:%d",total_transmissions);

    return 0;
}