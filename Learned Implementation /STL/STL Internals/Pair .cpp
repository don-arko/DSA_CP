template<typename T1,typename T2>
class Pair{
public:
    //datastructures
    T1 first;           // data type of first is T1 {to generalise any datatype usage}
    T2 second;
    //methods

    //default constructor
    Pair(){
        first=T1();  //T1() is the zero element of datatype = T1 eg if T1=string then T1()=""
        second=T2();
    }

    //parameterised constructor
    Pair(const T1& f, const T2& s){
        first=f;    //here first  = (*this).first where this is the ptr to object on which is funct is called
        second=s;   
    }

    //Copy Constructor 
    Pair(const Pair& other){ //other is a alias to the pair being passed
        first=other.first;
        second=other.second;
    }

    //Assignment Operator

    //return by ref : (a=b).first+=10; modifies the actual pair 'a' as (a=b) returns the original variable 'a'
    //normal return : (a=b).first+=10; modifies a temporary pair variable and changes aren't reflected in 'a' as (a=b) returns a copy variable
    Pair& operator= (const Pair& other){  
        if(this!=&other){
            first=other.first;
            second=other.second;
        }
        return *this;  // the current object = a i.e. on which the function is called is returned by ref not its copy is returned
    }

    //Equality Operator 
    bool operator== (const Pair& other) const { //can't modify the curr obj i.e. *this
        return (first==other.first)&&(second==other.second);
    }

    //Inquality Operator 
    bool operator!= (const Pair& other) const {
        return !((*this)==other); //*this is the curr obj i.e. 'a' on this this function is called
    }

    //comparison operator 
    bool operator< (const Pair& other) const {
        //in case of tie on first smaller sec should be placed first
        if(first==other.first) return second<other.second; //false is returned in case of =
        return first<other.first;
    }
    
};
