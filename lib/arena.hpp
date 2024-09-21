#ifndef ARENA_HPP
#define ARENA_HPP
  
#include <cstddef>

constexpr unsigned int pointerSize=sizeof(std::byte*);

template<typename T>
class Arena{
  private:
    std::byte* memory_;
    std::byte* head_;
    unsigned int count_;
    unsigned int blockSize_;
    const unsigned int ptrSize_=pointerSize;
  
  public:
    Arena(unsigned int dataSize){
      count_=dataSize;
      blockSize_=(count_+ptrSize_);
      memory_=new std::byte[count_*blockSize_];
      head_=memory_;
    }

    void allocate(){
      std::byte** ptr;
      std::byte* it=head_;
      for(unsigned int i=0;i<count_-1;i++){
        std::byte* nextRawPtr=(it+blockSize_);
        ptr=reinterpret_cast<std::byte**>(it);
        *ptr=nextRawPtr;
        it=nextRawPtr;
      }
      ptr=reinterpret_cast<std::byte**>(it);
      *ptr=nullptr;
    }

      T* give(){
      if(head_==nullptr)
        return nullptr;
      std::byte** ptr=reinterpret_cast<std::byte**>(head_);
      std::byte* it=head_;
      std::byte* block=(head_+ptrSize_);
      head_=*ptr;
      return (T*)block;  
      }
      
    //não vou criar lógica para destrutor ou desalocador =( talvez em um outro commit
};


#endif
