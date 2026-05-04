template<typename T>
class priority_queue{
private:
    //data structures
    T* data;
    size_t capacity;
    size_t count;
    //resize the underlying array
    void resize(size_t new_capacity){
        T* new_data=new T[new_capacity];

        //copy the elements from old array to this new array
        for(int i=0;i<count;i++){
            new_data[i]=data[i];
        }
        delete[] data;
        data=new_data;
        capacity=new_capacity;
        //count remains unchanged in resize op
    }
    //shift up operation 
    void shiftup(size_t idx){
        //parent = ⌊(idx-1)/2⌋
        //idx>0 means ∃ a parent node
        while(idx>0 && data[(idx-1)/2]<data[idx]){ //data[parent]>= data[boths its child]
            swap(data[(idx-1)/2],data[idx]);
            idx=(idx-1)/2;
        }
    }
    void shiftdown(size_t idx){
        size_t left=2*idx+1;
        size_t right=2*idx+2;
        size_t largest = idx; //stores the idx of largest node  among the three
        
        //idea is to swap parent with the largest node among boths its child 
        //id parent is the largest no need to swap

        if(left<count && data[left]>data[largest]){
            largest=left;
        }
        if(right<count && data[right]>data[largest]){
            largest=right;
        }
        //at this point we get the largest idx finalised
        if(largest!=idx){ //if parent is not the largest node i.e. data[parent]<data[child]
            swap(data[idx],data[largest]);
            shiftdown(largest);
        }

    }
public:
    //default constructor
    priority_queue(){
        count=0;
        capacity=4;
        data=new T[capacity];
    }
    //copy constructor 
    priority_queue(const priority_queue& other){
        count=other.count;
        capacity=other.capacity;
        data=new T [capacity];
        for(int i=0;i<count;i++){
            data[i]=other.data[i];
        }        
    }
    //destructor : to automate heap cleanup
    ~priority_queue(){
        delete[] data;
    }
    //push an element onto the priority queue
    void push(const T& x){
        if(count==capacity) resize(2*capacity);
        data[count]=x;
        shiftup(count);
        count++;
    }
    //pop an element from the priority queue
    void pop(){
        if(count==0) return ;
        swap(data[0],data[count-1]);
        count--; //delete the last element 
        shiftdown(0);
    }
    T top()const {
        if(count==0){
            throw std::out_of_range("Priority_Queue is Empty");
        }
        return data[0];
    }
    size_t size(){
        return count;
    }
    bool empty(){
        return count==0;
    }
};
