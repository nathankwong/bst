#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
  public:
     Node(T data)
      : m_data(data)
    {
      Right=NULL;
      Left=NULL;
    }

    T getData(void)
    {
      return m_data;
    }

    Node<T>* getRight(void)
    {
      return Right;
    }

    Node<T>* getLeft(void)
    {
      return Left;
    }

    void setRight(Node<T>* next)
    {
      Right = next;
    }
    void setLeft(Node<T>* next)
    {
      Left = next;
    }

  private:
    Node<T>* Right;
    Node<T>* Left;
    
    T m_data;
};

#endif // NODE_HPP