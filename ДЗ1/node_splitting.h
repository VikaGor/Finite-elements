#pragma once
#include <iostream>

using namespace std;

class GridMethod;
class node_splitting
{
protected:
	//l/r/t/b=-1; // �� ����������� �� ������ �� ����� (��� ����)
	//type=0; // ���������� ����� // insideNode
	//type=1; // �� 2-�� ���� -- �������� ����� // heatFlowNode
	//type=2; // �� 3-�� ���� -- ����� // environmentNode
	//type=3; // �������� // insulationNode
	//type=4; // ������� ����� // cornerNode

	int number;// ����� ����
	int type;// ��� 

	friend GridMethod calculator(GridMethod Obj);
	//������ ����� (�� �����)
	int left;
	int right;
	int top;
	int bottom;

	// ����� �� �������� �����
	double left_length;
	double right_length;
	double top_length;
	double bottom_length;

	// �����������
	double temperature;
public:
	friend GridMethod;

	node_splitting();
	node_splitting(int number_, int type_, int left_, int right_, int top_, int bottom_, double left_length_, double right_length_, double top_length_, double bottom_length_, double temperature_);
	node_splitting(node_splitting &Obj);
	node_splitting operator =(node_splitting &Obj);
	double get();
	friend ostream &operator<<(ostream& out, const node_splitting Obj);
	void put(double T_new);


	~node_splitting();
};

