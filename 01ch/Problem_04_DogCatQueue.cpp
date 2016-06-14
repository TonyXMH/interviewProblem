#include<queue>
#include<string>
#include<iostream>
using namespace std;
//pet类是父类
class Pet
{
    private:
        string m_type;          //给成员数据添加前缀
    public:
        Pet(){}
        
        Pet(const string & type)    //给构造函数传参修改了一点
        {
            m_type = type;
        }
        string getPetType()
        {
            return m_type;
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
        Pet m_pet;        //父类成员
        long m_count;     //时间戳
    public:
        PetEnterQueue( const Pet & pet, long count)
        {   //这里需要重载运算符=？
            m_pet = pet;
            m_count = count;
        }
        Pet getPet()
        {
            return m_pet;
        }
        long getCount()
        {
            return m_count;
        }
       // public string getEnterPetType()自己想什么这是c++
        string getEnterPetType()
        {
            return m_pet.getPetType();
        }
    
};
class DogCatQueue
{
    private:
        queue<PetEnterQueue> m_dogQ;
        queue<PetEnterQueue> m_catQ;
        long m_count;
    public:
        DogCatQueue():m_count(0){}
        
        //让pet实例入队
        void push(Pet & pet)
        {
            if(pet.getPetType() == "dog")
            {
                PetEnterQueue dogQ(pet, m_count++);
                m_dogQ.push(dogQ);
            }
            else if(pet.getPetType() == "cat")
            {
                PetEnterQueue catQ(pet, m_count++);
                m_catQ.push(catQ);
            }
            else
                return ;        //最好是抛出异常

        }
        //让cat或dog类的实例按照入队的次序出队
        void popAll()
        {
           if(!m_dogQ.empty() && !m_catQ.empty())
           {//时间戳小的先进队列
               if(m_dogQ.front().getCount() < m_catQ.front().getCount())
                   m_dogQ.pop();
               else
                   m_catQ.pop();
           }//下面的两个条件是对上面条件的补充
           else if(!m_dogQ.empty())
               m_dogQ.pop();
           else if(!m_catQ.empty())
               m_catQ.pop();
           else
               return;      //异常
        }
        //获取队首元素
        Pet frontAll()
        {
           if(!m_dogQ.empty() && !m_catQ.empty())
           {//时间戳小的先进队列
               if(m_dogQ.front().getCount() < m_catQ.front().getCount())
               {
                  // Pet pet = m_dogQ.front().getPet();
                   return m_dogQ.front().getPet();
               }
               else
                   return m_catQ.front().getPet();
           }//下面的两个条件是对上面条件的补充
           else if(!m_dogQ.empty())
               return m_dogQ.front().getPet();
           else if(!m_catQ.empty())
               return m_catQ.front().getPet();
         //  else
           //    return;      //异常
        }
        //dog实例出队
        void pollDog()
        {
            if(!m_dogQ.empty())
                m_dogQ.pop();
            else
                return;
        }
        //dog队列队首元素
        Pet frontDog()
        {
            if(!m_dogQ.empty())
                return m_dogQ.front().getPet();
        //  else
          //    return;
        }
        
        void pollCat()
        {
            if(!m_catQ.empty())
                m_catQ.pop();
            else
                return;
        }

        Pet frontCat()
        {
            if(!m_catQ.empty())
                return m_catQ.front().getPet();
        //  else
          //    return;
        }
        //整个队列是否是为空
        bool isEmpty()
        {
            return m_dogQ.empty() && m_catQ.empty();
        }
        bool isDogQueueEmpty()
        {
            return m_dogQ.empty();
        }
        bool isCatQueueEmpty()
        {
            return m_catQ.empty();
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
