/* 
 * File:   Structures.h
 * Author: illyagron
 *
 * Created on November 25, 2017, 3:11 PM
 */

#include "vector"
#include "deque"

class Cell;
class Vertex;
class HalfEdge;

struct Point{
public:
    double x, y;
};

class Cell{
public:
    //getters & setters
private:
    HalfEdge *incidentEdge;
};

class Vertex{
public:
    //getters & setters
private:
    Point p;
    HalfEdge* incidentEdge;
};

class HalfEdge{
public:
    inline void setTwin(HalfEdge* newTwin) {
        this->twin = newTwin;
        newTwin->twin = this;
    };
    inline void setNext(HalfEdge* newNext) {
        this->next = newNext;
        newNext->prev = this;
    };
    inline void setPrev(HalfEdge* newPrev) {
        this->prev = newPrev;
        newPrev->next = this;
    };
    // all the other getters and setters as usual
private:
    HalfEdge* twin;
    HalfEdge* next;
    HalfEdge* prev;
    Vertex* origin;
    Cell* incidentFace;
};

class D{
public:
    void addVertex(Vertex* v);
    void addHalfEdge(HalfEdge* e);
    void addCell();
    //othr methods
  // all the other getters and setters as usual  
private:
   std::vector<Cell> cells; 
   std::vector<Vertex> vertices;
   std::vector<HalfEdge> edges;
};

class VEvent{
public:
    VEvent(bool);
    //getters and setters
private:
    Point p;
    bool cEvent;
};

class BinTree
{
public:

	bool isLeaf;
	Point site;
	HalfEdge* edge;
	VEvent*	cEvent;
	BinTree* parent;

	/*
		Constructors of the class (empty for edge, with focus parameter for an arch).
	*/
	
	BinTree	();
	BinTree	(Point* s);

	/*
		Access to the children (in tree).
	*/

	void SetLeft (BinTree* p) {_left  = p; p->parent = this;}
	void SetRight(BinTree* p) {_right = p; p->parent = this;}

	BinTree* Left () { return _left;  }
	BinTree* Right() { return _right; }

	/*
		Some useful tree operations

		GetLeft			: returns the closest left leaf of the tree
		GetRight		: returns the closest right leaf of the tree
		GetLeftParent	: returns the closest parent which is on the left
		GetLeftParent	: returns the closest parent which is on the right
		GetLeftChild	: returns the closest leave which is on the left of current node
		GetRightChild	: returns the closest leave which is on the right of current node
	*/

	static BinTree* GetLeft (BinTree * p);
	static BinTree* GetRight (BinTree * p);
	static BinTree* GetLeftParent (BinTree * p);
	static BinTree* GetRightParent (BinTree * p);
	static BinTree* GetLeftChild (BinTree * p);
	static BinTree* GetRightChild (BinTree * p);
	
private:

	BinTree * _left;
	BinTree * _right;
};


std::deque<VEvent> EventQueue;