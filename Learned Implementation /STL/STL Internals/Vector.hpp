template<typename T>
class Vector{
public: 
    T* data; //data is a ptr to base element of the dynamic array
    size_t size;     //pos where to do curr push_back
    size_t capacity; // size of the underlying array used

    void resize(size_t new_capacity){
        T* new_data=new T[new_capacity]; //new dynamic array

        //copy the contents of the old array into the new
        for(size_t i=0;i<size;i++){
            new_data[i]=data[i];
        }

        //delete the old array
        delete[] data;
        
        data=new_data;
        //size remains unchanged
        capacity=new_capacity;

    }

    //default constructor
    Vector(){
        size=0;
        capacity=4;
        data=new T[capacity]; // creates a dynamic array of size=capacity and returns its base addr which is stores in data
    }

    //destructor 
    ~Vector(){ // called automatically by compiler when scope of stack obj v ends
        //and we attached cleanup mem statement i.e. delete with that so our heap 
        //cleanup is now automated
        delete[] data;
    }

    //copy constructor
    Vector(const Vector& other){
        
        size=other.size;
        capacity=other.capacity;
        data=new T[capacity];
        
        //copy the vector
        for(size_t i=0;i<size;i++){
            data[i]=other.data[i]; //use. operator cause at this point [] operator is not defined for vector other while other.data is a array for this [] are defined
        }
    }

    //Assignment operator
    Vector& operator=(const Vector& other){
        if(this!=&other){ //both the vectors have diff address which means they are diff vectors
            delete[] data;
            size=other.size;
            capacity=other.capacity;
            data=new T[capacity];

            //copy the data
            for(size_t i=0;i<size;i++){
                data[i]=other.data[i];
            }
        }
        return *this; //return the curr vector obj 
    }

    //push_back
    void push_back(const T& x){
        if(size==capacity){
            resize(2*capacity);
        }
        data[size++]=x;
    }

    //pop_back
    void pop_back(){
        if(size>0) size--;
    }

    //random access
    T& at(const size_t& idx){
        if(idx>=size){
            throw std::out_of_range("Index out of range");
        }
        return data[idx];
    }
    T& operator[](const size_t& idx){
        if(idx>=size){
            throw std::out_of_range("Index out of range");
        }
        return data[idx];
    }

    //size method
    size_t _size(){
        return size;
    }

    //clear methods
    void clear(){
        size=0;
    }
    //empty methods
    bool empty(){
        return size==0;
    }
    //return the underlying data
    T* data_ptr(){
        return data;
    }
};
