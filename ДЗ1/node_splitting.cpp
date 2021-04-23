#include "node_splitting.h"



node_splitting::node_splitting()
{

}

node_splitting::node_splitting(int number_, int type_, int left_, int right_, int top_, int bottom_, double left_length_, double right_length_, double top_length_, double bottom_length_, double temperature_) {
	number = number_;
	type = type_;

	left = left_;
	right = right_;
	top = top_;
	bottom = bottom_;

	left_length = left_length_;
	right_length = right_length_;
	top_length = top_length_;
	bottom_length = bottom_length_;

	temperature = temperature_;
}

node_splitting::node_splitting(node_splitting &Obj) {
	number = Obj.number;
	type = Obj.type;

	left = Obj.left;
	right = Obj.right;
	top = Obj.top;
	bottom = Obj.bottom;

	left_length = Obj.left_length;
	right_length = Obj.right_length;
	top_length = Obj.top_length;
	bottom_length = Obj.bottom_length;

	temperature = Obj.temperature;
}

node_splitting node_splitting::operator =(node_splitting &Obj) {
	number = Obj.number;
	type = Obj.type;

	left = Obj.left;
	right = Obj.right;
	top = Obj.top;
	bottom = Obj.bottom;

	left_length = Obj.left_length;
	right_length = Obj.right_length;
	top_length = Obj.top_length;
	bottom_length = Obj.bottom_length;

	temperature = Obj.temperature;

	return *this;
}

double node_splitting::get() {
	return this->temperature;
}

ostream &operator<<(ostream& out, const node_splitting Obj) {
	cout << Obj.number << " " << Obj.temperature << endl;
	//cout << Obj.temperature << endl;
	return out;
}

void node_splitting::put(double T_new) {
	temperature = T_new;
}

node_splitting::~node_splitting()
{
}
