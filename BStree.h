//
// Created by jiachangkun on 24-11-2.
//

#ifndef BSTREE_H
#define BSTREE_H

#endif //BSTREE_H
#pragma once


template<class K>
struct BStreenode
{
    BStreenode<K>* _left;
    BStreenode<K>* _right;
    K _key;

    BStreenode(const K& key)
        :_left(nullptr)
         ,_right(nullptr)
         ,_key(key)
    {

    }

};

template<class K>
class BStree
{
    typedef BStreenode<K> node;
public:
    bool insert(const K& val)
    {
        if (_root==nullptr)
        {
            _root=new node(val);
            return true;
        }
        node* parent=nullptr;
        node* cur=_root;
        while (cur)
        {
            if (cur->_key>val)
            {
                parent=cur;
                 cur=cur->_left;
            }
            else if (cur->_key<val)
            {
                parent=cur;
                cur=cur->_right;
            }
            else
            {//有相同的值了  不用再插入了
                return false;
            }

        }

        
        cur=new node(val);
        if (parent->_key>cur->_key)
        {
                parent->_left=cur;
        }
        else
        {
            parent->_right=cur;
        }
        return true;
    }

    void _inorder(node* root)
    {
        if (root==nullptr)
        {
            return;
        }
        _inorder(root->_left);
        std::cout<<root->_key<<" ";
        _inorder(root->_right);
    }
    void inorder()
    {
        _inorder(_root);
        std::cout<<std::endl;
    }

    bool Find(const K& key)
    {
        node* cur=_root;
        while (cur)
        {
            if (cur->_key<key)
            {
                cur=cur->_right;
            }
            else if (cur->_key>key)
            {
                cur=cur->_left;
            }else
            {
                return true;
            }
        }
        return false;
    }


    
    bool erase_key(const K& key)
    {
        node* parent=nullptr;
        node* cur=_root;
        if (key==cur->_key)
        {
            
        }

        
    }

private:
    node* _root=nullptr;
};


void testBStree()
{
    BStree<int> bst;
    int a[]={9,4,6,5,7,8};
    for (auto a1 : a)
    {
        bst.insert(a1);
    }

    bst.inorder();
}
