/* 
 * File:   Structures.cpp
 * Author: illyagron
 * 
 * Created on November 25, 2017, 3:11 PM
 */

#include "Structures.h"

/*
	Constructors
*/

BinTree::BinTree()
{
	site.x = 0;
        site.y = 0;
	isLeaf	= false;
	cEvent	= nullptr;
	edge	= nullptr;
	parent	= nullptr;
}

BinTree::BinTree(Point * s)
{
	site.x = 0;
        site.y = 0;
	isLeaf	= true;
	cEvent	= nullptr;
	edge	= nullptr;
	parent	= nullptr;
}

/*
	Tree operations (described in the header file)
*/

BinTree * BinTree::GetLeft (BinTree * p)
{
	return GetLeftChild(GetLeftParent(p));
}


BinTree * BinTree::GetRight (BinTree * p)
{
	return GetRightChild(GetRightParent(p));
}

BinTree * BinTree::GetLeftParent	(BinTree * p)
{
	BinTree * par		= p->parent;
	BinTree * pLast	= p;
	while(par->Left() == pLast) 
	{ 
		if(!par->parent) return nullptr;
		pLast = par; 
		par = par->parent; 
	}
	return par;
}

BinTree * BinTree::GetRightParent	(BinTree * p)
{
	BinTree * par		= p->parent;
	BinTree * pLast	= p;
	while(par->Right() == pLast) 
	{ 
		if(!par->parent) return nullptr;
		pLast = par; par = par->parent; 
	}
	return par;
}

BinTree * BinTree::GetLeftChild		(BinTree * p)
{
	if(!p) return nullptr;
	BinTree * par = p->Left();
	while(!par->isLeaf) par = par->Right();
	return par;
}

BinTree * BinTree::GetRightChild	(BinTree * p)
{
	if(!p) return nullptr;
	BinTree * par = p->Right();
	while(!par->isLeaf) par = par->Left();
	return par;
}