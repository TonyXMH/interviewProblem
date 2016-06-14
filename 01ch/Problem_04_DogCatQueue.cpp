#include<queue>
#include<string>
#include<iostream>
using namespace std;
//pet类是父类
class Pet
{
    private:
        string type;
    public:
        Pet(){}
        
        Pet(string type)
        {
            this->type = type;
        }
        string getPetType()
        {
            return this->type;
        }
        //需要添加=的重载
       /* Pet & operator=(const Pet& pet) const
        {
            this->type = pet.getPetType();
            return *this;
        }*/
};

class Dog : public Pet
{
    public:
       Dog(): Pet("dog"){}
};
class Cat : public Pet
{
    public:
        Cat() : Pet("cat") {}
};
//这是自己写一个类，父类成员加上时间戳
class PetEnterQueue
{
    private:
        Pet pet;        //父类成员
        long count;     //时间戳
    public:
        PetEnterQueue(Pet pet, long count)
        {   //这里需要重载运算符=？
            this->pet = pet;
            this->count = count;
        }
        Pet getPet()
        {
            return this->pet;
        }
        long getCount()
        {
            return this->count;
        }
       // public string getEnterPetType()自己想什么这是c++
        string getEnterPetType()
        {
            return this->pet.getPetType();
        }
    
};
class DogCatQueue
{
    private:
        queue<PetEnterQueue> dogQ;
        queue<PetEnterQueue> catQ;
        long count;
    public:
        DogCatQueue():count(0){}
        
        //让pet实例入队
        void push(Pet pet)
        {
            if(pet.getPetType() == "dog")
                this->dogQ.push(new PetEnterQueue(pet, this->count++));
            else if(pet.getPetType() == "cat")
                this->catQ.push(new PetEnterQueue(pet, this->count++));
            else
                return ;        //最好是抛出异常

        }
        //让cat或dog类的实例按照入队的次序出队
        void popAll()
        {
           if(!this->dogQ.empty() && !this->catQ.empty())
           {//时间戳小的先进队列
               if(this->dogQ.front().getCount() < this->catQ.front().getCount())
                   this->dogQ.pop();
               else
                   this->catQ.pop();
           }//下面的两个条件是对上面条件的补充
           else if(!this->dogQ.empty())
               this->dogQ.pop();
           else if(!this->catQ.empty())
               this->catQ.pop();
           else
               return;      //异常
        }
        //获取队首元素
        Pet frontAll()
        {
           if(!this->dogQ.empty() && !this->catQ.empty())
           {//时间戳小的先进队列
               if(this->dogQ.front().getCount() < this->catQ.front().getCount())
                   this->dogQ.front();
               else
                   this->catQ.front();
           }//下面的两个条件是对上面条件的补充
           else if(!this->dogQ.empty())
               this->dogQ.front();
           else if(!this->catQ.empty())
               this->catQ.front();
         //  else
           //    return;      //异常
        }
        //dog实例出队
        void pollDog()
        {
            if(!this->dogQ.empty())
                this->dogQ.pop();
            else
                return;
        }
        //dog队列队首元素
        Pet frontDog()
        {
            if(!this->dogQ.empty())
                this->dogQ.front();
        //  else
          //    return;
        }
        
        void pollCat()
        {
            if(!this->catQ.empty())
                this->catQ.pop();
            else
                return;
        }

        Pet frontCat()
        {
            if(!this->catQ.empty())
                this->catQ.front();
        //  else
          //    return;
        }
        //整个队列是否是为空
        bool isEmpty()
        {
            return this->dogQ.empty() && this->catQ.empty();
        }
        bool isDogQueueEmpty()
        {
            return this->dogQ.empty();
        }
        bool isCatQueueEmpty()
        {
            return this->catQ.empty();
        }
};
int main(void)
{
    DogCatQueue test;
    Pet * dog1 = new Dog();
    Pet * cat1 = new Cat();
    Pet * dog2 = new Dog();
    Pet * cat2 = new Cat();
    Pet * dog3 = new Dog();
    Pet * cat3 = new Cat();
    test.push(*dog1);
    test.push(*cat1);
    test.push(*dog2);
    test.push(*cat2);
    test.push(*dog3);
    test.push(*cat3);
    //测试同一个对象能否多次入队
    test.push(*dog1);
    test.push(*cat1);
    test.push(*dog2);
    test.push(*cat2);
    test.push(*dog3);
    test.push(*cat3);

    test.push(*dog1);
    test.push(*cat1);
    test.push(*dog2);
    test.push(*cat2);
    test.push(*dog3);
    test.push(*cat3);
    while(!test.isEmpty())
    {
        cout << test.frontAll().getPetType() << endl;
        test.popAll();
    }
    return 0;
}
