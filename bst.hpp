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

 void insert(T data)
    { 
    Node<T>* temp; 
        counter++;
        if(root ==NULL)
        {
            root=new Node<T>(data);
            return;
        }
        temp = move(root, data);
        if(data< temp->getData())
        {
            temp->setLeft(new Node<T>(data));
            return;
        }
        else 
        {
            temp->setRight(new Node<T>(data));
            return;
        }
}

    Node<T>* move(Node<T>* cur, T data)
    {
        if(cur->getData()==data)
        {
            return cur;
        }
        if(data < cur->getData()) 
        {    
            if(cur->getLeft()== NULL)
            {
                return cur;
            }
            cur=cur->getLeft();
            in<<"->left("<<cur->getData()<<")";
            out<<"->left("<<cur->getData()<<")";
            return move(cur,data);
        }
        else
        {
            if(cur->getRight()== NULL )
            {
                return cur;
            }
            cur=cur->getRight();
            in<<"->right("<<cur->getData()<<")";
            out<<"->right("<<cur->getData()<<")";
            return move(cur,data);
        }
    }
    bool contains (T data)
    {
         Node<T>* temp;
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
        in.str("");
        in.clear();
        out.str("");
        out.clear();
        Node<T>* temp;
        temp=root;
        
        if(temp->getData()==data)
        {
            in<<"Found: "<<"root("<<temp->getData()<<")";
            out<<"Not found: "<<"root"<<temp->getData()<<")"; 
        }
        else {
            if(temp->getData()>data) //left bit
        {
            in<<"Found: "<<"root("<<temp->getData()<<")";
            out<<"Not found: "<<"root("<<temp->getData()<<")";
            temp=move(temp,data);        
        }
         else//right bit
        {
            in<<"Found: "<<"root("<<temp->getData()<<")";
            out<<"Not found: "<<"root("<<temp->getData()<<")";
            temp=move(temp,data);
        }
        }

            if(temp->getData()==data)
            {
                return in.str();
            }
            else
            {
                return out.str();             
            } 
    } 
    int count(void)
    {
        return counter;
    }
    private: 
    std::stringstream in;
    std::stringstream out ;
    int counter =0;
    Node<T>* root; 

};

#endif