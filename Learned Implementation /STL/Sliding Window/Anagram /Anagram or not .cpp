//Problem         : Detect Anagram or not
//Time Complexity : O(nlog26)

bool anagram(string s,string t){
     map<char,int> ms,mt;
    //build freq map for s,t
    for(auto ch:s)ms[ch]++;
    for(auto ch:t)mt[ch]++;

    //compare both the maps
    for(pair<char,int> p:ms){
        if(p.second!=mt[p.first]) return false;
    }
    return true;
}
