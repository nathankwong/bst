

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
        temp = move(root, data);
        if(data< temp->getData())
        {
           // std::cout<<"SET LEFT=================================="<<std::endl;
            temp->setLeft(new Node<T>(data));
            return;
        }
        else 
        {
           // std::cout<<"SET RIGHT=================================="<<std::endl;
            temp->setRight(new Node<T>(data));
            return;
        }
}

    Node<T>* move(Node<T>* cur, T data)
    {
       // std::cout<<"MOVES=================================="<<std::endl;
        if(cur->getData()==data)
        {
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
        std::cout<<"SEARCH=================================="<<std::endl;
         int found =0;
         int notfound=0;
        Node<T>* temp;
        temp=root;
        if(temp->getData()==data)
        {
            std::cout<<"ROOT-------------------------------"<<std::endl;
            in<<"Found: "<<"root("<<temp->getData()<<")";
            found=1;
        }
        else {
        if(temp->getData()>data) //left bit
        {
            temp=move(temp,data);
            in<<"->left("<<temp->getData()<<")";
            found=1;
        }
        else if(temp->getData()<data) //right bit
        {
            temp=move(temp,data);
            in<<"->right("<<temp->getData()<<")";
            found=1;
        }
        }
            if(found==1)
            {
                std::cout<<"PRINT"<<std::endl;
                return in.str();
            }
            else
            {
                return out.str();
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