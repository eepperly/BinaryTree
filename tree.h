#ifndef _TREE_H
#define _TREE_H

template <class Item>
class Tree{
 public:
  Tree();
  Tree(Item data);

  void deep_copy_from(Tree<Item>& copyme);
  void clean_up(); // clear all dynamic memory

  ~Tree();
  Tree<Item> operator=(Tree<Item>& rside);
  Tree(Tree<Item>& orig);

  Item getContent();
  void setContent(Item data);
  
  bool hasLChild();
  Item getLChild();
  Tree<Item>* getLSubtree();
  bool hasRChild();
  Item getRChild();
  Tree<Item>* getRSubtree();

  Item getParent();
  Tree<Item>* getParentTree();
  bool hasParent();

 private:
  Item data;
  Tree<Item>* parent;
  Tree<Item>* lchild;
  Tree<Item>* rchild;
};

#include <cstddef>

template <class Item>
Tree<Item>::Tree(){
  this->parent = NULL;
  this->lchild = NULL;
  this->rchild = NULL;
}

template <class Item>
Tree<Item>::Tree(Item data){
  this->data = data;
  this->parent = NULL;
  this->lchild = NULL;
  this->rchild = NULL;
}

template <class Item>
void Tree<Item>::deep_copy_from(Tree<Item>& copyme){
  this->data = copyme.data;
  this->parent = NULL;
  this->lchild = new Tree<Item>(this->getLSubtree());
  this->lchild->parent = this;
  this->rchild = new Tree<Item>(this->getRSubtree());
  this->rchild->parent = this;
}

template <class Item>
void Tree<Item>::clean_up(){
  delete *(this->data);
  this->lchild->clean_up();
  this->rchild->clean_up();
  delete this->lchild;
  delete this->rchild;
}

template <class Item>
Tree<Item>::~Tree(){
  clean_up();
}

template <class Item>
Tree<Item> Tree<Item>::operator=(Tree<Item>& rside){
  clean_up();
  deep_copy_from(rside);
  return rside;
}

template <class Item>
Tree<Item>::Tree(Tree<Item>& orig){
  deep_copy_from(orig);
}

template <class Item>
Item Tree<Item>::getContent(){
  return this->data;
}

template <class Item>
void Tree<Item>::setContent(Item data){
  this->data = data;
}

template <class Item>
bool Tree<Item>::hasLChild(){ return this->lchild != NULL; }

template <class Item>
Item Tree<Item>::getLChild(){ return this->lchild->data; }

template <class Item>
Tree<Item>* Tree<Item>::getLSubtree(){ return this->lchild; }

template <class Item>
bool Tree<Item>::hasRChild(){ return this->rchild != NULL; }

template <class Item>
Item Tree<Item>::getRChild(){ return this->rchild->data; }

template <class Item>
Tree<Item>* Tree<Item>::getRSubtree(){ return this->rchild; }

template <class Item>
bool Tree<Item>::hasParent(){ return this->parent != NULL; }

template <class Item>
Item Tree<Item>::getParent(){ return this->parent->data; }

template <class Item>
Tree<Item>* Tree<Item>::getParentTree(){ return this->parent; }

#endif // _TREE_H
