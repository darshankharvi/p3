#include<stdio.h>
#include<time.h>
int main(){
    int i,n,a[1000],key,bottom,top,mid,j,temp;
    double clk;
    clock_t starttime,endtime;
    printf("Enter the number of project :\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i]=rand()%100;
        printf("The product ID are:%d \n",a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted Product ID list: \n");
    for(i=0;i<n;i++)
    printf("%d \t",a[i]);
    printf("\nEnter the product ID to be searched :\n");
    scanf("%d",&key);
    starttime=clock();
    bottom=1;
    top=n;
    do{
        mid=(bottom+top)/2;
        if(key < a[mid]) top=mid-1;
        else if(key >a[mid])
        bottom=mid+1;
    }while(key !=a[mid] && bottom <=top);
    if(key==a[mid]){
        printf("Product found :\n");
        printf("Product  %d found in position %d \n",key,mid+1);
    }
    else{printf("Search failed key not found!");
    }
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("%f\n",clk);
}
