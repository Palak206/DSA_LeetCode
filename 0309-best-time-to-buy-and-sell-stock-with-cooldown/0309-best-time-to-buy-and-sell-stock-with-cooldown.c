

int maxProfit(int* prices, int pricesSize) {
    int max(int a, int b){
    return a>b?a:b;
   }
    if(pricesSize<2){
        return 0;
    }
    int* buy=(int*)calloc((pricesSize+1),sizeof(int));
    int* sell=(int*)calloc((pricesSize+1),sizeof(int));
    buy[1]=-prices[0];
    for(int i=2;i<=pricesSize;i++){
        buy[i]=max(sell[i-2]-prices[i-1],buy[i-1]);
        sell[i]=max(sell[i-1],buy[i-1]+prices[i-1]);
    }
    return sell[pricesSize];
}
                                                                                                                                                                                                                                      