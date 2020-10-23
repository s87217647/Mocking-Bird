#ifndef MOCKING_BIRD_BST_H
#define MOCKING_BIRD_BST_H
#include <string>
using namespace std;
#define COUNT 10
/*--
 *Initial comment:
 *Knowing the implement details and the state that you desire is important.
 *
 * What you&the professor want? A AVL tree that balance itself'
 *
 * After the implement the implementation of this class, Lazy one should roll out like that "snap!"
 *
 * Ordering
 * 1.to_string() --- have a print() now
 * 2.Insert need Rotate it while inserting
 * 3.Remove
 *
 *
 *------------------------Read Me-------------------------
 * When left, all the copied tasks haven't been test, thinking about to_string and recursive_delete().
 * Found notes on stack overflow
 *
 */


template <typename T>
class BST{
private:
    struct Node {
        T _data;
        Node *_left, *_right;

        Node(const T &d, Node *l = nullptr, Node *r = nullptr) : _data(d), _left(l), _right(r) {}
    };

    Node *_root;
    size_t _size;

    // Helpers
    static Node *_deep_copy(const Node *p);
    bool _insert(Node *&p, const T &elem)
    {
        if (p == NULL)
        {
            p = new Node(elem, NULL, NULL);
            this->_size ++;
            return true;
        }
        else if (elem < p->_data)
            return _insert(p->_left, elem);
        else if (p->_data < elem)
            return _insert(p->_right, elem);

        return false; // duplicate ? Does this mean, exist elements will not exist?
    };
    bool _remove(Node *&p, const T &elem){
        if (p == NULL)
            return false;

        if (elem < p->_data)
            return _remove(p->_left, elem);
        if (p->_data < elem)
            return _remove(p->_right, elem);

        // found the node
        if (p->_left != NULL && p->_right !=NULL)
        {
            const Node *minNode = _find_min(p->_right);  //find min not yet implemented
            p->_data = minNode->_data;
            _remove(p->_right, minNode->_data);
        }
        else
        {
            Node *nodeToRemove = p;
            p = (p->_left != NULL)? p->_left : p->_right;
            delete nodeToRemove;
        }
        this->_size --;
        return true;
    };
    bool _recursive_delete(Node *&p){return true;};
    const Node *_find_min(Node *p) const// Reading modules have a findMax, you might want to consider.
    {
        if(this->_root == NULL)
            throw Not_found_exception();

        if (p == NULL)
            return NULL;
        if (p->_left == NULL)
            return p;
        return _find_min(p->_left);
    };

    Node *_find(Node *p, const T &elem) const{return NULL;};
    string _to_string(const Node *p) const{return " ";};

public:
    BST(): _root(nullptr), _size(0){}
    virtual  ~BST(){_recursive_delete(_root);}
    virtual  size_t get_size() const {return _size;};
    virtual bool insert(const T &elem){return  _insert(_root, elem);}
    virtual bool remove(const T &elem){return  _remove(_root, elem);}
    virtual bool clear(){return false;}; // Don't know exactly what it does
    virtual bool contains(const T &elem) const {return  _find(_root,elem) != nullptr;}
    virtual T &find(const T &elem) const{return _find(_root,elem)->_data;};
    virtual string to_string() const{return _to_string(NULL);};

    class Not_found_exception : public exception{public:string to_string() {return "Not found exception";}};
    friend class Tests;


    /*-------------------------Functions below are are included in the pdf-----------------------------*/

    //Helper method from geek to geek, used to print tree structure help debugging.
    Node * getRoot(){
        return this->_root;
    }

    void print2D(Node *root, int space = 0)
    {
        //Added this root by default


        // Base case
        if (root == NULL) {
// Three lines below is Jie try to express empty leaf
//            for (int i = COUNT; i < space; i++)
//                printf(" ");
//            printf("*");
            return;
        }


        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print2D(root->_right, space);

        // Print current node after space
        // count
        printf("\n");
        for (int i = COUNT; i < space; i++)
            printf(" ");
        printf("%d\n", root->_data);

        // Process left child
        print2D(root->_left, space);
    }


};



#endif //MOCKING_BIRDBST_H
