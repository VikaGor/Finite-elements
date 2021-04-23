#pragma once
#include <iostream>

using namespace std;

class GridMethod;
class node_splitting
{
protected:
	//l/r/t/b=-1; // Не принадлежит ни одному из типов (вне тела)
	//type=0; // внутренняя точка // insideNode
	//type=1; // ГУ 2-го рода -- тепловой поток // heatFlowNode
	//type=2; // ГУ 3-го рода -- среда // environmentNode
	//type=3; // Изоляция // insulationNode
	//type=4; // Угловая точка // cornerNode

	int number;// Номер узла
	int type;// Тип 

	friend GridMethod calculator(GridMethod Obj);
	//Номера узлов (по бокам)
	int left;
	int right;
	int top;
	int bottom;

	// Длины до соседних узлов
	double left_length;
	double right_length;
	double top_length;
	double bottom_length;

	// Температура
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

