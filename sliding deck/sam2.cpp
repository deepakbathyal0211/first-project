void swap(int *a,int *b){
     int temp;
     temp=*a;
     *a=*b;
     *b=temp;
}

int *sort(int *a,int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=0;j<n;j++){
           if(a[j]<a[k])
           k=j;
        }
        swap(&a[k],&a[i]);
    }
    return a;
}
