#include "node_splitting.h"
#pragma once

class node_splitting;
class GridMethod
{
	double heat_flow = 150;//q
	double heat_transfer_coeff = 10;//alf
	double T_amb=22;//T
	double coeff_therm_conduct = 75;//ë

	int kol;
	node_splitting *Splitting;
public:
	friend node_splitting;
	GridMethod();
	GridMethod(int kol_, int *number_, int *type_, int *left_, int *right_, int *top_, int *bottom_, double *left_length_, double *right_length_, double *top_length_, double *bottom_length_, double *temperature_);
	GridMethod(int kol_, int *number_, int *type_, int *left_, int *right_, int *top_, int *bottom_, double *left_length_, double *right_length_, double *top_length_, double *bottom_length_);
	GridMethod(GridMethod &Obj);
	GridMethod operator =(GridMethod &Obj);

	double tau(int j_);

	double insideNode(int j_);

	double heatFlowNode(int j_);
	double environmentNode(int j_);
	double insulationNode(int j_);
	double cornerNode(int j_);
	double averageT();

	friend GridMethod calculator(GridMethod Obj);

	friend ostream &operator<<(ostream& out, const GridMethod Obj);

	~GridMethod();
};

