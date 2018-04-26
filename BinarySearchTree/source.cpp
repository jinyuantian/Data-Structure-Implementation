#include "BinarySearchTree.h"

int main(){
	BinarySearchTree<int> tree;
	tree.insert(6);
	tree.insert(3);
	tree.insert(1);
	tree.insert(4);
	tree.insert(10);
	tree.insert(8);
	tree.insert(11);
	tree.printTree();
	tree.remove(6);
	tree.printTree();
}