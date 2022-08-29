#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int m,n;
    while(cin>>m>>n){
            int t=0;
        for(int i=m; i<=n; i++){
            int a=i/100;
            int b=i%100/10;
            int c=i%10;
            
            if(i==a*a*a+b*b*b+c*c*c && t==0){
                printf("%d ",i);
                t++;
            }
            else if(i==a*a*a+b*b*b+c*c*c && t==1){
                printf("%d ",i);
            }
        }
        if(t!=0){ printf("\n"); }
        if(t==0){ printf("no\n"); }
    }
    return 0;
}


#include<stdio.h>

int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
            int t=0;
        for(int i=m; i<=n; i++){
            int a=i/100;
            int b=i%100/10;
            int c=i%10;
            
            if(i==a*a*a+b*b*b+c*c*c && t==0){
                printf("%d ",i);
                t++;
            }
            else if(i==a*a*a+b*b*b+c*c*c && t==1){
                printf("%d ",i);
            }
        }
        if(t!=0){ printf("\n"); }
        if(t==0){ printf("no\n"); }
    }
    return 0;
}
