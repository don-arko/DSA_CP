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

bool compare(string a,int b){
    return a<b ;                 // less than (<) operator is overloaded with lex comparison in strings
}

//min also gives the lex smaller string as is internally used less than operator
min("abe","b"); //return lex smaller string "abc"
