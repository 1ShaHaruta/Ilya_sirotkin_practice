#include<iostream>
#include<memory>

template <class T>
class Shared{
private:
T* ptr;
int* counter;
public:
Shared();
Shared(const Shared& p);
Shared(Shared&& p);
Shared(T* p);

Shared& operator=(const Shared& p){
    if(ptr!=p.ptr){
        (*p.counter)++;
        this->~Shared();
        ptr=p.ptr;
        counter=p.counter;
    }
    return *this;
}

T* operator->();
T& operator*();
~Shared();
};

template<class T>
Shared<T>::Shared():ptr{nullptr}, counter{nullptr}{}

template<class T>
Shared<T>::Shared(T*p):ptr{p}{
    counter=new int{0};
}
template<class T>
Shared<T>::Shared(const Shared& p){
      ptr=p.ptr; 
      counter=p.counter;
      (*counter)++;
}

template<class T>
Shared<T>::~Shared(){
if(*counter){
    (*counter)--;
    this->ptr=nullptr;
}
else
{
    delete ptr;
    delete counter;
    }
}

template<class T>
Shared<T>::Shared(Shared&& p):ptr{p.ptr}, counter{p.counter}{
    p.ptr=nullptr;
    p.counter=nullptr;
}

template<class T>
T* Shared<T>::operator->(){
    if(ptr==nullptr)return nullptr;
return ptr; 
}

template<class T>
T& Shared<T>::operator*(){
if(ptr==nullptr)return -1;
    return *ptr;
}

int main(){
    int* x=new int;
    int *y=new int;
    Shared<int> er(y);
Shared<int> a(x);
Shared<int> b(a);
Shared<int> c(b);
Shared<int> f(c);
Shared<int> d(b);
Shared<int> g(nullptr);
c=er;
f=er;
    return 0;
}