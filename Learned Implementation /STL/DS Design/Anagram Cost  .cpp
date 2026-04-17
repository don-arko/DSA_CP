//Time Complexity : O(1)  ∀ operation
struct Ds{
    //Data structure
    int freq[26]={0}; // vector<int> freq(26,0) won't work inside struct
    int cost=0; //maintains the curr cost
    //behaves as freq array for every m len window of string S

    //methods
    void insert(char ch){    //O(1)
        cost-=max(0,freq[ch-'a']-const_freq[ch-'a']); //remove the prev contribution of ch from prev ans
        freq[ch-'a']++;                               //update the freq of ch
        cost+=max(0,freq[ch-'a']-const_freq[ch-'a']); //add the new contribution to ans
    }
    void erase(char ch){     //O(1)
        cost-=max(0,freq[ch-'a']-const_freq[ch-'a']); //remove the prev contribution of ch from prev ans
        freq[ch-'a']--;                               //update the freq of ch
        cost+=max(0,freq[ch-'a']-const_freq[ch-'a']); //add the new contribution to ans
    }
    int getcost(){          //O(1)
        return cost;
    }
};
