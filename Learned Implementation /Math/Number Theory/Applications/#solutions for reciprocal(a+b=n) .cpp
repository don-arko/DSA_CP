//Time Complexity  :        O(√n)
//Constraint       :        n <= 1e12

//Eqn  :  1/a + 1/b = 1/n  ≡ (a-n).(b-n)=n^2   ≡   x.y = n^2

// #solutions of (a,b)=#solutions for (x,y) = d(n^2) or 2d(n^2)-1

//now as we have n with use we can calculate pfact(n^2) from pfact(n) only in O(√n) insted of O(n) if done for n^2


int solution(n){ //O(√n+logn)=O(√n)
    auto prime=pfact(n);     // O(√n)
    int d=1; //divisors of n^2 from pfact(n)
    for(auto p:prime){       //O(log n)
        d*=(1+2*p.second);  //2 is multiplied to convert pfact(n) to pfact(n^2)
    }
    int ans=2*d-1;
}

