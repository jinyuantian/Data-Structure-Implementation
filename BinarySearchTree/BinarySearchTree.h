#pragma once
#include <iostream> 

template <typename Comparable>
class BinarySearchTree{
public:
	BinarySearchTree()
		:root(nullptr){}

	BinarySearchTree(const BinarySearchTree& rhs)
		:root(nullptr){
			root = clone(rhs.root);
		}

	BinarySearchTree(BinarySearchTree&& rhs)
		:root(rhs.root)
		{rhs.root = nullptr;}

	~BinarySearchTree(){
		makeEmpty();
	}

	const Comparable& findMin() const{
		if(root)
			return findMin(root);
		else
			return Comparable{};
	}

	const Comparable& findMax() const{
		if(root)
			return findMax(root);
		else
			return Comparable{};
	}

	bool contains(const Comparable& x) const{
		return contains(x, root);
	}
	bool isEmpty() const{
		return root == nullptr;
	}
	void printTree(std::ostream& out = std::cout) const{
		printTree(root, out);
	}

	void makeEmpty(){
		makeEmpty(root);
	}
	void insert(const Comparable& x){
		insert(x, root);
	}
	void insert(Comparable&& x){
		insert(x, root);
	}
	void remove(const Comparable& x){
		remove(x, root);
	}

	BinarySearchTree& operator=(const BinarySearchTree& rhs){
		if(this != &rhs){
			BinarySearchTree temp = rhs;
			std::swap(*this, temp);
		}
		return *this;
	}

	BinarySearchTree& operator=(BinarySearchTree&& rhs){
		root = rhs.root;
		rhs.root = nullptr;
		return *this;
	}

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const Comparable& theElement, BinaryNode* lt=nullptr, BinaryNode* rt = nullptr)
			:element(theElement), left(lt), right(rt) { }

		BinaryNode(Comparable&& theElement, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr)
			:element(std::move(theElement)), left(lt), right(rt) {}

	};

	BinaryNode* root;

	void insert(const Comparable& x, BinaryNode*& t);
	void insert(Comparable&& x, BinaryNode*& t);
	void remove(const Comparable& x, BinaryNode*& t);
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode*& t);
	void printTree(BinaryNode* t, std::ostream& out) const;
	BinaryNode* clone(BinaryNode* t) const;
};

#include "BinarySearchTree.cpp"
