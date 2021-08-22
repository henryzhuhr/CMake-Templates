#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>

#define NONE_COLOR   "\033[0m"
#define BLACK        "\033[30m"
#define RED          "\033[31m"
#define LIGHT_RED    "\033[1;31m"
#define BOLD_RED     "\033[1m\033[31m"
#define GREEN        "\033[32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BOLD_GREEN   "\033[1m\033[32m"
#define YELLOW       "\033[33m"
#define BLUE         "\033[34m"
#define LIGHT_BLUE   "\033[1;34m"
#define BOLD_BLUE    "\033[1m\033[34m"
#define MAGENTA      "\033[35m"
#define CYAN         "\033[36m"
#define LIGHT_CYAN   "\033[1;36m"
#define WHITE        "\033[37m"
#define BOLD_BLACK   "\033[1m\033[30m"
#define DARY_GRAY    "\033[1;30m"
#define LIGHT_GRAY   "\033[0;37m"
#define BOLD_YELLOW  "\033[1m\033[33m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN    "\033[1m\033[36m"
#define BOLD_WHITE   "\033[1m\033[37m"
#define BROWN        "\033[0;33m"

template <class T> struct SingleNode
{
    T              data;
    SingleNode<T>* next = NULL;
};
template <class T> class LinkedList_Interface
{
  public:
    virtual ~LinkedList_Interface(){};

  public:
    virtual void TravelLinkedList()                           = 0;
    virtual void SetMaxLength(const int maxLength = -1)       = 0;
    virtual bool Append(const T data)                         = 0;
    virtual bool Insert(const T data, const int index)        = 0;
    virtual bool GetDataByIndex(T& data, const int index = 0) = 0;
    virtual bool Remove(const int index = 0)                  = 0;
    virtual bool Clear()                                      = 0;
};

namespace DataStruture
{
template <class T> class LinkedList : public LinkedList_Interface<T>
{
  private:
    SingleNode<T>* head;
    SingleNode<T>* ptail;
    int            maxLength;
    int            length;

  public:
    /**
     * @brief Construct a new Linked List object
     *
     * @param maxLength
     */
    LinkedList(const int maxLength = -1); // -1 mean no limit to length
    /**
     * @brief Destroy the Linked List object
     *
     */
    ~LinkedList();

  public:
    /**
     * @brief
     *
     */
    void TravelLinkedList() override;

  public:
    /**
     * @brief Set the Max Length object
     *
     * @param maxLength
     */
    void SetMaxLength(const int maxLength = -1) override;

  public:
    /**
     * @brief
     *
     * @param data
     * @return true
     * @return false
     */
    bool Append(const T data) override;
    /**
     * @brief
     *
     * @param data
     * @param index
     * @return true
     * @return false
     */
    bool Insert(const T data, const int index) override; // insert data in index i
  public:
    /**
     * @brief Get the Data By Index object
     *
     * @param data
     * @param index
     * @return true
     * @return false
     */
    bool GetDataByIndex(T& data, const int index = 0) override;

  public:
    /**
     * @brief
     *
     * @param index
     * @return true
     * @return false
     */
    bool Remove(const int index = 0) override;
    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool Clear() override;
};


template <class T> LinkedList<T>::LinkedList(const int maxLength)
{
    if (maxLength < 0)
        this->maxLength = -1;
    else
        this->maxLength = maxLength;

    this->length     = 0;
    this->head       = new SingleNode<T>;
    this->head->next = NULL;
    this->ptail      = this->head;
}
template <class T> LinkedList<T>::~LinkedList()
{
    this->Clear();
    delete this->head;
}

template <class T> void LinkedList<T>::TravelLinkedList()
{
    printf("List [len %d] : ", this->length);

    SingleNode<T>* p = this->head;
    int            i = -1;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
        // -----  Process  --------------------
        printf(" [%d]%d ", i, p->data);
        // ------------------------------------
    }

    std::cout << std::endl;
}

template <class T> void LinkedList<T>::SetMaxLength(const int maxLength)
{
    if (maxLength < 0)
        this->maxLength = -1;
    else
        this->maxLength = maxLength;
}

template <class T> bool LinkedList<T>::Append(const T data)
{
    SingleNode<T>* newNode = new SingleNode<T>;
    newNode->data          = data;
    newNode->next          = NULL;

    this->ptail->next = newNode;
    this->ptail       = newNode;
    this->length += 1;

    // TODO: add try{}catch{}

    return true;
}
template <class T> bool LinkedList<T>::Insert(const T data, int index)
{
    if (index >= length)
    {
        std::cout << YELLOW;
        std::cout << "[WARNING] index out of length, insert data in index: ";
        std::cout << length;
        std::cout << NONE_COLOR << std::endl;

        SingleNode<T>* newNode = new SingleNode<T>;
        newNode->data          = data;
        newNode->next          = NULL;

        this->ptail->next = newNode;
        this->ptail       = newNode;
        this->length += 1;
        return true;
    }
    else if (index >= 0 && index < length)
    {
        int            i = 0;
        SingleNode<T>* p = this->head;
        while (p->next != NULL)
        {
            if (i == index)
            {
                SingleNode<T>* newNode = new SingleNode<T>;
                newNode->data          = data;
                newNode->next          = p->next;
                p->next                = newNode;
                this->length += 1;
                return true;
            }
            p = p->next;
            i += 1;
        }

        return false;
    }
    else if (index < 0)
    {
        std::cout << YELLOW << "[WARNING] index < 0, insert data in index 0 " << NONE_COLOR << std::endl;
        SingleNode<T>* newNode = new SingleNode<T>;
        newNode->data          = data;
        newNode->next          = head->next;
        head->next             = newNode;
        this->length += 1;
        return true;
    }
    return false;
}

template <class T> bool LinkedList<T>::GetDataByIndex(T& data, const int index)
{
    /**
     * if index < 0         return list[0]
     * if index >= length   return list[length-1]
     * if length==0         no process
     */
    if (this->length > 0)
    {
        if ((index <= 0) && (this->length > 0))
        {
            data = this->head->next->data;
            return true;
        }
        else if (index >= length)
        {
            data = this->ptail->data;
            return true;
        }
        else
        {
            int            i = -1;
            SingleNode<T>* p = this->head;
            while (p->next != NULL)
            {
                if (i == index)
                {
                    data = p->data;
                    return true;
                }
                p = p->next;
                i += 1;
            }
            data = p->data;
            return true;
        }
    }
    else
        return false;
}

template <class T> bool LinkedList<T>::Remove(const int index)
{
    if ((index < this->length) && (index >= 0) && (this->length > 0) && (head->next != NULL))
    {
        int            i = 0;
        SingleNode<T>* p = this->head->next;
        SingleNode<T>* q = this->head;

        while (p->next != NULL)
        {
            if (i == index)
            {
                q->next = p->next;
                delete p;
                return true;
            }
            p = p->next;
            q = q->next;
            i += 1;
        }
    }

    return false;
}
template <class T> bool LinkedList<T>::Clear()
{
    while (this->head->next != NULL)
    {
        SingleNode<T>* p = this->head->next;
        this->head->next = p->next;
        // printf("delete %-2d ", p->data);
        delete p;
        this->length -= 1;
        // this->TravelLinkedList();
    }
    return true;
}

/*
template <class T>
void LinkedList<T>::InitLinkedList()
{

}
*/
} // namespace DataStruture

#endif