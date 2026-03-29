//Floor : by default cpp truncates the decimal part hence giving floor by default
int floor(int a,int b){
      return a/b;
}

//Ceil
//if a and b are positive numbers then Ceil(a/b) is given by floor(a+(b-1))/b
int ceil_(int a,int b){
      return (a+b-1)/b;
}


//round : calculated as floor((2a+b)/(2b))
int round(int a,int b){
      return (2*a+b)/(2*b);
}

