//returns true if lexiograhically a<b otherwise false
bool cmp(string a,string b){  
    int i=0;
    while(i<min(a.size(),b.size())){
        if(a[i]!=b[i]){
            if (a[i]<b[i]) return true;
            else return false;
        }
        else{
            i++; 
        }
    }
    //all char equal till min(a.size(),b.size())
    if(a.size()<=b.size()) return true;
    else return false;
}
