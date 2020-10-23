//
// Created by Administrator on 10/20/2020.
//

#ifndef MOCKING_BIRD_LAZY_BST_H
#define MOCKING_BIRD_LAZY_BST_H
#include <iostream>
using namespace std;
template <typename T>
class Lazy_BST{
protected:
    struct Node {
        T _data;
        Node *_left, *_right;
        bool _is_deleted;

        Node(const T &d, Node *l = nullptr, Node *r = nullptr) : _data(d), _left(l), _right(r), _is_deleted(false) {}
    };

    Node *_root;
    size_t _size, _real_size;

    // Helpers

    bool _recursive_delete(Node *&p);
    bool _insert(Node *&p, const T &elem);
    bool _remove(Node *&p, const T &elem);
    bool _collect_garbage(Node *&p);
    const Node *_find_min(Node *p) const;
    const Node *_find_real_min(Node *p) const;
    Node *_find(Node *p, const T &elem) const;
    bool _really_remove(Node *&p, const T &elem);
    string _to_string(const Node *p) const;

public:
    Lazy_BST(): _root(nullptr), _size(0){};
    ~Lazy_BST(){_recursive_delete(_root);}

    virtual  size_t get_size() const {return _size;};
    bool insert(const T &elem){return  _insert(_root, elem);}
    bool remove(const T &elem){return  _remove(_root, elem);}
    bool collect_garbage(){return _collect_garbage(_root);}
    bool contains(const T &elem) const {return  _find(_root,elem) != nullptr;}
    const T &find(const T &elem) const;
    string to_string() const;
    bool clear();

//    template
//    void traverse(Processor func) const { traverse(mRoot, func); } // might be useful

    class Not_found_exception : public exception{public:string what() {return "Not found exception";}};
    friend class Tests;
};


#endif //MOCKING_BIRD_LAZY_BST_H
