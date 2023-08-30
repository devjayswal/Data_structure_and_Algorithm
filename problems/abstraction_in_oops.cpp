// //wrote a program to demonstrate abstraction in oops

// #include<iostream>
// using namespace std;

// class AbstractEmployee
// {
//     virtual void AskForPromotion()=0;
// };

// class Employee:AbstractEmployee
// {
// private:
//     string Name;
//     string Company;
//     int Age;

// public:
//     void setName(string name)
//     {
//         Name=name;
//     }
//     string getName()
//     {
//         return Name;
//     }
//     void setCompany(string company)
//     {
//         Company=company;
//     }
//     string getCompany()
//     {
//         return Company;
//     }
//     void setAge(int age)
//     {
//         if(age>=18)
//         {
//             Age=age;
//         }
//     }
//     int getAge()
//     {
//         return Age;
//     }
//     void IntroduceYourself()
//     {
//         cout<<"Name - "<<Name<<endl;
//         cout<<"Company - "<<Company<<endl;
//         cout<<"Age - "<<Age<<endl;
//     }
//     Employee(string name,string company,int age)
//     {
//         Name=name;
//         Company=company;
//         Age=age;
//     }
//     void AskForPromotion()
//     {
//         if(Age>30)
//         {
//             cout<<Name<<" got promoted"<<endl;
//         }
//         else
//         {
//             cout<<Name<<" ,sorry no promotion for you"<<endl;
//         }
//     }
//     virtual void Work()
//     {
//         cout<<Name<<" is checking email,task backlog,performing tasks..."<<endl;
//     }
// };


// class Developer:public Employee
// {
// public:
//     string FavProgrammingLanguage;
//     Developer(string name,string company,int age,string favProgrammingLanguage)
//     :Employee(name,company,age)
//     {
//         FavProgrammingLanguage=favProgrammingLanguage;
//     }
//     void FixBug()
//     {
//         cout<<getName()<<" fixed bug using "<<FavProgrammingLanguage<<endl;
//     }
//     void Work()
//     {
//         cout<<getName()<<" is writing "<<FavProgrammingLanguage<<" code"<<endl;
//     }
// };

// class Teacher:public Employee
// {

// public:
//     string Subject;
//     void PrepareLesson()
//     {
//         cout<<getName()<<" is preparing "<<Subject<<" lesson"<<endl;
//     }
//     Teacher(string name,string company,int age,string subject)
//     :Employee(name,company,age)
//     {
//         Subject=subject;
//     }
//     void Work()
//     {
//         cout<<getName()<<" is teaching "<<Subject<<endl;
//     }
// };

// int main()
// {
//     Employee employee1=Employee("Saldina","YT-CodeBeauty",25);
//     Employee employee2=Employee("John","Amazon",35);
//     Developer d=Developer("Saldina","YT-CodeBeauty",25,"C++");
//     Teacher t=Teacher("Jack","Cool School",35,"History");
//     employee1.Work();
//     employee2.Work();
//     d.FixBug();
//     d.Work();
//     t.PrepareLesson();
//     t.Work();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;


class animal{
    public:
    virtual void speak()=0;
    virtual void run()=0;
};

class horse:public animal{
    public:
    void speak(){
        cout<<"neigh"<<endl;
    }
    void run(){
        cout<<"horse is running"<<endl;
    }
};

//define how to abstract a class animal
// answer: make all the functions pure virtual functions

int main(){
    // animal a;
    // a.speak();
    // a.run();
    horse h;
    h.speak();
    h.run();
    return 0;
}