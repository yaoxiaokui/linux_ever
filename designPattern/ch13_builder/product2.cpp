/*************************************************************************
	> File Name: product.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jun 2016 09:11:39 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <list>
using namespace std;


//产品类
class Product
{
private:
    list<string> parts;//包含产品的全部部件

public:
    void add(const string &part){
        parts.push_back(part);
    }

    void show(){
        cout << "所有部件: ";
        for(list<string>::iterator it = parts.begin(); it != parts.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
};

//抽象建造者类
class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product * getResult() = 0;
};

//ConcreteBuilder1具体建造类
class ConcreteBuilder1 : public Builder
{
private:
    Product * product; 

public:
    ConcreteBuilder1(){
        product = new Product();
    }

    void BuildPartA(){
        product->add("部件A");
    }

    void BuildPartB(){
        product->add("部件B");
    }

    Product * getResult(){
        return product;
    }

};

//ConcreteBuilder2具体建造类
class ConcreteBuilder2 : public Builder
{
private:
    Product * product; 

public:
    ConcreteBuilder2(){
        product = new Product();
    }

    void BuildPartA(){
        product->add("部件X");
    }

    void BuildPartB(){
        product->add("部件Y");
    }

    Product * getResult(){
        return product;
    }
};


//Director指挥者类
class Director
{
public:
    void construct(Builder *builder){
        builder->BuildPartA();
        builder->BuildPartB();
    }
};


//客户端测试
int main()
{
    Director * director = new Director();

    Builder * builder1 = new ConcreteBuilder1();
    director->construct(builder1);
    Product * product1 = builder1->getResult();
    cout << "产品1: ";
    product1->show();
    
    Builder * builder2 = new ConcreteBuilder2();
    director->construct(builder2);
    Product * product2 = builder2->getResult();
    cout << "产品2: ";
    product2->show();

    delete director;
    delete builder1;
    delete builder2;
    delete product1;
    delete product2;

    return 0;
}



