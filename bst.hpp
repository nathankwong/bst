#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"
#include <sstream> 

template <typename T>
class BST 
{
    public: BST()
    {
        root=NULL;
    }
   // ~BST();

 void insert(T data)
    { 
    Node<T>* temp;
     // std::cout<<"INSERT=================================="<<std::endl;  
        counter++;

        if(root ==NULL)
        {
            root=new Node<T>(data);
            return;
        }
        //std::cout<<"root:"<<root->getData()<<std::endl;
        temp = move(root, data);
        if(data< temp->getData())
        {
           // std::cout<<"SET LEFT=================================="<<std::endl;
            temp->setLeft(new Node<T>(data));
       // std::cout<<"temp:"<<temp->getData()<<std::endl;
            return;
        }
        else 
        {
           // std::cout<<"SET RIGHT=================================="<<std::endl;
            temp->setRight(new Node<T>(data));
             //std::cout<<"temp:"<<temp->getData()<<std::endl;
            return;
        }
}

    Node<T>* move(Node<T>* cur, T data)
    {
        //Node<T>* temp;
       // std::cout<<"MOVES=================================="<<std::endl;
        if(cur->getData()==data)
        {
           // std::cout<<"cur:"<<cur->getData() <<std::endl;
        //    in<<"root("<<cur->getData()<<")";
        //    out<<"root("<<cur->getData()<<")";
            return cur;
        }
        if(data < cur->getData()) 
        {    
           // std::cout<<"MOVES LEFT=================================="<<std::endl;
            if(cur->getLeft()== NULL)
            {
                return cur;
            }
            cur=cur->getLeft();
            // in<<"->left("<<cur->getData()<<")";
            // out<<"->left("<<cur->getData()<<")";
            return move(cur,data);
        }
        else
        {
            //std::cout<<"MOVES RIGHT =================================="<<std::endl;
            if(cur->getRight()== NULL )
            {
                return cur;
            }
            cur=cur->getRight();
            // in<<"->right("<<cur->getData()<<")";
            // out<<"->right("<<cur->getData()<<")";
            return move(cur,data);
        }
    }
    bool contains (T data)
    {
         Node<T>* temp;
       // std::cout<<"CONTAINS=================================="<<std::endl;
        temp= root;
        temp=move(root, data);
        if(temp->getData()==data)
        {
            return true;
        }
        else
        {
            return false;
        }


    }
     std::string search (T data)
     {
       // std::cout<<"SEARCH=================================="<<std::endl;
                in.str("");
                in.clear();
         int found =0;
         int notfound=0;
        Node<T>* temp;
        temp=root;
        
        if(temp->getData()==data)
        {
            std::cout<<"ROOT-------------------------------"<<std::endl;
            in<<"Found: "<<"root("<<temp->getData()<<")";
            out<<"Not found: "<<"root"<<temp->getData()<<")";
            found=1;
        }
        else {
        if(temp->getData()>data) //left bit
        {
            std::cout<<"LEFT-------------------------------"<<std::endl;
            in<<"Found: "<<"root("<<temp->getData()<<")";
            out<<"Not found: "<<"root("<<temp->getData()<<")";
            temp=move(temp,data);
            in<<"->left("<<temp->getData()<<")";
            out<<"->left("<<temp->getData()<<")";
            temp=move(temp,data);
            found=1;
        }
         if(temp->getData()<data) //right bit
        {
            std::cout<<"RIGHT-------------------------------"<<std::endl;
            in<<"Found: "<<"root("<<temp->getData()<<")";
            out<<"Not found: "<<"root("<<temp->getData()<<")";
            temp=move(temp,data);
            in<<"->right("<<temp->getData()<<")";
            out<<"->right("<<temp->getData()<<")";
            temp=move(temp,data);
            found=1;
        }
        }
            if(contains(data)==1)
            {
                std::cout<<"PRINT============================="<<std::endl;
                return in.str();
                
            }
            else
            {
                std::cout<<" NOT PRINT============================="<<std::endl;
                return out.str();
                out.clear();
             
            } 
    } 
    int count(void)
    {
        //std::cout<<"COUNT=================================="<<std::endl;
        return counter;
    }
    private: 
    std::stringstream in;
    std::stringstream out ;
    int counter =0;
    Node<T>* root; 

};

#endif