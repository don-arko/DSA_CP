//Approach 1 : Using freq map
//Time Complexity :  O(nlog26)

int cost(string s,string t){
    if(s.length()!=t.length()) return -1;
    map<char,int> ms,mt;
    //build the map
    for(char ch:s)ms[ch]++;    //O(nlog26)
    for(char ch:t)mt[ch]++;    //O(mlog26)
    
    //compute cost
    //cost = sum of positive diff
    
    int sum=0;
    for(auto p:ms){                            //O(26log26)
        sum+=max(0,p.second-mt[p.first]);   v  //O(log26)
    }
    return sum;

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Approach 2 : Using freq Array
//Time Complexity : O(n+26) 

int a[26],b[26];                                //Global freq array
int cost(string s,string t){
    if(s.length()!=t.length()) return -1;

    //build the freq arr
    for(char ch:s)a[ch-'a']++;                  //O(n)
    for(char ch:t)b[ch-'a']++;                  //O(m)
 
    //cost = sum of positive diff  {as len can't change as operation = transform only }
    int sum=0;
    for(int i=0;i<26;i++){                       //O(26)
        sum+=max(0,a[i]-b[i]);
    }
    return cost;
}

