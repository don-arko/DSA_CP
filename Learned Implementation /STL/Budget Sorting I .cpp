
//without query                     : O(NlogN)
int maxitem(vector<int>& price,int B){
    sort(price.begin(),price.end());
    int item=0;
    for(int i=0;i<price.size();i++){
        if(price[i]<B){
            B-=price[i];
            item++;
        }else break;
    }return item;
}


