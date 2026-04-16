struct mean{
    int sum,cnt;
    mean(){  //constructor shouldn't have a return type
        sum=0;cnt=0;
    }
    void insert(int x){    //O(1)
        sum+=x;cnt++;
    }
    void remove(int x){     //O(1)
        sum-=x;cnt--;
    }
    double get_mean(){        //O(1)
        return 1.0*sum/cnt; // intermediate variable != int hence decimal part not truncated
    }
};
