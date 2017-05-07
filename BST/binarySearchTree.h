#ifndef binarySearchTree_H_
#define binarySearchTree_H_
//--------------------------------------------------------------------------------------------------
/// @file binarySearchTree.h
/// @class BinarySeartTree, BSTNode
//--------------------------------------------------------------------------------------------------
#include <iostream>

class BSTNode
{
	double value;
	
	BSTNode* left;
	BSTNode* right;
	
	public: 
		BSTNode(double val)
		{
			value = val;
			left = NULL;
			right = NULL;
		}
		
		const double value() const
		{
			return value;
		}
		
		void add	
			(
			const double& value
			);
			
		bool lookup
			(
			const double& value
			);
		
};

class BinarySeartTree
{
	BSTNode* root;
	
	public: 
		BinarySearhTree()
		{
			root = NULL;
		}
		
		void add
			(
			const double& value
			);
			
		bool lookup
			(
			const double& value
			);
			
	
}




#endif // binarySearchTree_H_