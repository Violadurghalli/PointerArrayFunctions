#ifndef ARRAY_FUNCTIONS
#define ARRAY_FUNCTIONS
using namespace std;

const int MINIMUM_CAPACITY = 3;



//-----------------  FUNCTION Declarations -----------------

template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY);            //allocate 'capacity' 
                                                        //      elements. 
                                                        //  return array

template<class T>
T* reallocate(T* a, int size, int capacity);            //take array, resize it 
                                                        //  return new array. 
                                                        //  delete old array

template<class T>
void print_array(T* a, int size, 
            int capacity = 0, ostream& outs = cout);    //prints 
                                                        //  (size/capacity)
                                                        //  for debugging

template <class T>
void print(T* a, unsigned int how_many, 
                                ostream& outs = cout);  //print array

template<class T>
T* search_entry(T* a, int size, const T& find_me);      //search for 'find me'

template <class T>
int search(T* a, int size, const T& find_me);           //search for 'find_me' 

template <class T>
void shift_left(T* a, int& size, int shift_here);       //shift left @ pos:
                                                        //    erases @ pos
template <class T>
void shift_left(T* a, int& size, T* shift_here);        //shift left @ pos: 
                                                        //    erases @ pos

template <class T>
void shift_right(T *a, int &size, int shift_here);      //shift right: 
                                                        //      make a hole

template <class T>
void shift_right(T *a, int &size, T* shift_here);       //shift right: 
                                                        //   make a hole

template<class T>
void copy_array(T *dest, const T* src, 
                                int many_to_copy);      //copy from src to dest

template <class T>
T* copy_array(const T *src, int size);                  //return a 
                                                        //  copy of src

template <class T>
string array_string(const T *a, int size); 








//-----------------  FUNCTION Definitions -----------------




template<class T>
T* allocate(int capacity)
{
    T *int_ptr = new T[capacity]; // this line initializes the pointer and a dynamic array 
                                    // and sets the pointer to the location of array
    return int_ptr; //int_ptr returns the address of the first element of the array

}          //allocate 'capacity' elements then return array

template<class T>
T* reallocate(T* a, int size, int capacity)
{
    //T *b = new T[capacity]; creates a new array with the new capacity 
    T *b = allocate<T>(capacity); 

    T* walker_a = a; //creates a walker to walk through the old array
    T* walker_b = b; // is meant to set the old arrays values to the new array
    for(int i = 0; i < size; i++)
    {
        *walker_b = *walker_a;
        walker_a++;
        walker_b++;
    }

    delete[] a; //deletes the old array
    return b;
}   //take array, resize it, return new array, delete old array


template <class T>
void print(T* a, unsigned int how_many, ostream& outs)
{
    int* walker_a = a;
    for(int i= 0; i < how_many; i++)
    {
        cout << walker_a << " ";
        walker_a++;
    }
    cout << endl;
}

template<class T>
T* search_entry(T* a, int size, const T& find_me) //this returns the address of find_me in the array
{
    int *walker = a;
    for(int i = 0; i < size; i++)
    {
        if(*walker == find_me)
        {
            return walker;
        }
        walker++;
    }
    return nullptr; 
}

template <class T>
int search(T* a, int size, const T& find_me) //this returns the index of find_me in the array
{
    T *walker = a;
    for(int i = 0; i < size; i++)
    {
        if(*walker == find_me)
        {
            return i;
        }
        walker++;
    }
    return -1;
}

template <class T>
void shift_left(T* a, int& size, int shift_here)
{
    T *walkerCopyFrom = a + shift_here + 1;
    T *walkerCopyTo = a + shift_here;
    for(int i = shift_here + 1; i < size; i++)
    {
        //if garbage is present at end of array, set for loop to stop if i < size - 1
        *walkerCopyTo = *walkerCopyFrom;
        walkerCopyTo++;
        walkerCopyFrom++;
    }   
    size--;
}
template <class T>
void shift_left(T* a, int& size, T* shift_here)
{
    int index = shift_here - a;
    shift_left(a, size, index);
}

template <class T>
void shift_right(T *a, int &size, int shift_here)
{
    T *walkerCopyFrom = a + size - 1;
    T *walkerCopyTo = a + size;
    for(int i = size; i > shift_here; i--)
    {
        *walkerCopyTo = *walkerCopyFrom;
        walkerCopyTo--;
        walkerCopyFrom--;
    }
    size++;
}

template <class T>
void shift_right(T *a, int &size, T* shift_here)
{
    int index = shift_here - a;
    shift_right(a, size, index);
}

template<class T>
void copy_array(T *dest, const T* src, int many_to_copy)
{
    dest = copy_array(src, many_to_copy);
}

template <class T>
T* copy_array(const T *src, int size)
{
    T *c = allocate<T>(size);
    T *walker = c;
    const T *walker2 = src;
    for(int i = 0; i < size; i++)
    {
        *walker = *walker2;
        walker++;
        walker2++;
    }
    return c;
}

template <class T>
string array_string(const T *a, int size)
{
    string s = ""; 
    const T *walker = a;
    for(int i = 0; i < size; i++)
    {
        s += *walker;
        walker++;
    }
}

template <class T>
void print_array(T* a, int size, int capacity, ostream& outs)
{
    int *b = a;

    for(int i = 0; i < size; i++)
    {
        cout << *b << " ";
        b++;
       
    }
    cout << "\n capacity: " << capacity << " out of " << size << endl; //not tested
}



// command s to save
//in terminal type in : cmake --build build   this will compile it
// to run it: ./build/bin/testB or whatever you want to run instead of testB

#endif