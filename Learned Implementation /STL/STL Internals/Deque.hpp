template<typename T>
class Deque{
private: 
    //datastructures
    T* data;
    size_t capacity;
    size_t count;
    size_t front_idx;
    size_t back_idx;

    //methods
    //resize the underlying array
    void resize(size_t new_capacity){
        T* newdata= new T[new_capacity];
        //copy the elements from old array to new of twice size
        for(size_t i=0;i<count;i++){
            newdata[i]=data[(front_idx+i)%capacity];
        }

        delete[] data;
        data=newdata;
        capacity=new_capacity;
        front_idx=0;
        back_idx=count;
        //count variable won't change in resize();
    }
public:
    //default constructor
    Deque(){
        capacity=4;
        count=0;
        front_idx=0;
        back_idx=0;
        data=new T[capacity];
    }
    //copy constructor
    Deque(const Deque& other){
        capacity=other.capacity;
        count=other.count;
        data=new T[capacity];
        //copy the data
        for(size_t i=0;i<count;i++){
            data[i]=other.data[(other.front_idx+i)%capacity];
        }
        front_idx=0;
        back_idx=count;
    }
    //destructor : to automate heap cleanup
    ~Deque(){
        delete[] data;
    }

    //PUSH
    //push_front()
    void push_front(const T& x){
        if(count==capacity) resize(2*capacity);
        front_idx=(front_idx-1+capacity)%capacity; //modular subtraction :{front_idx/back_idx < capacity}
        data[front_idx]=x;
        count++;
    }
    //push_back()
    void push_back(const T& x){
        if(count==capacity) resize(2*capacity);
        data[back_idx]=x;
        back_idx=(back_idx+1)%capacity;
        count++;
    }
    //POP
    //pop_back()
    void pop_back(){
        if(count!=0) {back_idx=(back_idx-1+capacity)%capacity;count--;}
    }
    void pop_front(){
        if(count!=0) {front_idx=(front_idx+1)%capacity;count--;}
    }

    //view methods
    //front()
    T& front() const {
        if(count>0) return data[front_idx];
    }
    //back()
    T& back() const {
        if(count>0) return data[(back_idx-1+capacity)%capacity];
    }

    //acess operator
    T& operator[](const size_t idx){
        if(idx>=count) {
            throw std::out_of_range("Index out of range");
        }
        return data[(front_idx+idx)%capacity];
    }
    //assignment operator
    Deque& operator=(const Deque& other){
        if(this!=&other){ //adress of curr obj !=addres of obj to be copied means they are diff obj
            delete[] data;
            capacity=other.capacity;
            count=other.count;
            front_idx=0;
            back_idx=other.count;
            data=new T[other.capacity];

            //copy the data
            for(size_t i=0;i<other.count;i++){
                data[i]=other.data[(other.front_idx+i)%other.capacity];
            }
        }   
        return *this; //ref curr obj is returned ; it could be modified directly and not its copy is modified
    }
    size_t size() const {
        return count;
    }
    bool empty() const {
        return count==0;
    }
    T* data_ptr() const{
        return data;
    }
};
