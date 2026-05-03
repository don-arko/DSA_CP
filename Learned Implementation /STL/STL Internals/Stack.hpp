template<typename T>
class Stack{
private: 
    T* data;
    size_t capacity;
    int top_idx;
    void resize(size_t new_capacity){
        T* new_data=new T[new_capacity];

        //copy old contents into new dynamic array of double size
        for(int i=0;i<=top_idx;i++){
            new_data[i]=data[i];
        }

        //delete the old dynamic array
        delete[] data;
        data=new_data;
        //top_idx won't change in resize op
        capacity=new_capacity;
    }
public:
    //methods
    
    //default constructor
    Stack(){
        top_idx=-1; 
        capacity=4;
        data=new T[capacity];
    }
    //copy constructor
    Stack(const Stack& other){
        top_idx=other.top_idx;
        capacity=other.capacity;
        data=new T[capacity];
        for(int i=0;i<=top_idx;i++){
            data[i]=other.data[i];
        }
    }

    //destructor
    ~Stack(){
        delete[] data; //automate heap cleanup with scope end of stack obj
    }   

    //assignment operator
    Stack& operator= (const Stack& other){
        if(this!=&other){ //both the stack objs has diff address
            delete[] data;
            top_idx=other.top_idx;
            capacity=other.capacity;
            data=new T[capacity];
            for(int i=0;i<=top_idx;i++){
                data[i]=other.data[i];
            }
        }
        return *this; //returns the ref to curr obj on which this function is called 
    }

    //push
    void push(T x){
        if(top_idx==capacity-1){
            resize(2*capacity);
        }
        data[++top_idx]=x; //pre increment we inserted at top_idx+1
    }
    //pop
    void pop(){
        if(top_idx>-1){
            top_idx--;
        }
    }
    //top
    T top() const {
        if(top_idx<0){
            throw std::out_of_range("Stack is empty");
        }
        return data[top_idx];
    }

    //size()
    size_t size() const {
        return top_idx+1;
    }

    //empty()
    bool empty() const {
        return top_idx==-1;
    }

};
