//--------------------------------------------------------------------------------------------------
/// @file binarySearchTree.cpp
//--------------------------------------------------------------------------------------------------

#include "binarySearchTree.h"


void BinarySearchTree::add
	(
	const double& value
	)
{
	if (root == NULL)
	{
		root = new BSTNode(value);
		return;
	}
	
	root->add(value);
	
}

bool BinarySearchTree::search
	(
	const double& value
	)
{
	if(root == NULL)
	{
		return false;
	}

	root->lookup(value);
		
}

void BSTNode::add
	(
	const double& value
	)
{
	if(this->value > value)
	{
		if(this->left == NULL)
		{
			this->left = new BSTNode(value);
			return;
		}
		
		this->left->add(value);
		
	}
	
	if(this->value < value)
	{
		if(this->right == NULL)
		{
			this->right = new BSTNode(value);
			return;
		}
		
		this->right->add(value);
	}
}
	
void BSTNode::lookup
	(
	const double& value
	)
{
	if (this->value == value)
	{
		return true;
	}
	
	if(this->value > value)
	{
		if(this->left == NULL)
		{
			return false;
		}
		return this->left->lookup(value);
	}
	
	if(this->value < value)
	{
		if(this->right == NULL)
		{
			return false;
		}
		return this->right->lookup(value);
	}
	
	return false;
}
	
	
	
