#include "node_splitting.h"
#include "GridMethod.h"


class node_splitting;
class GridMethod;
GridMethod::GridMethod()
{
}

GridMethod::GridMethod(int kol_, int *number_, int *type_, int *left_, int *right_, int *top_, int *bottom_, double *left_length_, double *right_length_, double *top_length_, double *bottom_length_, double *temperature_) {
	kol = kol_;
	Splitting = new node_splitting[kol];
	for (int i = 0; i < kol; i++) {
		node_splitting temp(number_[i], type_[i], left_[i], right_[i], top_[i], bottom_[i], left_length_[i], right_length_[i], top_length_[i], bottom_length_[i], temperature_[i]);
		Splitting[i] = temp;
	}
}

GridMethod::GridMethod(int kol_, int *number_, int *type_, int *left_, int *right_, int *top_, int *bottom_, double *left_length_, double *right_length_, double *top_length_, double *bottom_length_) {
	kol = kol_;
	Splitting = new node_splitting[kol];
	for (int i = 0; i < kol; i++) {
		node_splitting temp(number_[i], type_[i], left_[i], right_[i], top_[i], bottom_[i], left_length_[i], right_length_[i], top_length_[i], bottom_length_[i], 0);
		Splitting[i] = temp;
	}

	for (int i = 0; i < kol; i++) {
		if (Splitting[i].type == 1) {
			Splitting[i].temperature = heatFlowNode(i);
		}
		if (Splitting[i].type == 2) {
			Splitting[i].temperature = environmentNode(i);
		}
		if (Splitting[i].type == 3) {
			Splitting[i].temperature = insulationNode(i);
		}
		if (Splitting[i].type == 4) {
			Splitting[i].temperature = cornerNode(i);
		}
	}
}

GridMethod::GridMethod(GridMethod &Obj) {
	kol = Obj.kol;
	Splitting = new node_splitting[kol];
	for (int i = 0; i < kol; i++) {
		Splitting[i] = Obj.Splitting[i];
	}
}
GridMethod GridMethod:: operator =(GridMethod &Obj) {
	kol = Obj.kol;
	Splitting = new node_splitting[kol];
	for (int i = 0; i < kol; i++) {
		Splitting[i] = Obj.Splitting[i];
	}
	return *this;
}

double GridMethod::tau(int j_) {
	double C = 1;
	double hx2 = (Splitting[j_].left_length*Splitting[j_].left_length + Splitting[j_].right_length*Splitting[j_].right_length) / 2.0;
	double hy2 = (Splitting[j_].top_length*Splitting[j_].top_length + Splitting[j_].bottom_length*Splitting[j_].bottom_length) / 2.0;

	double tau_ = C * hx2*hy2 / (2 * coeff_therm_conduct*(hx2 + hy2));

	return tau_;
}

double GridMethod::insideNode(int j_) {
	double tau_ = tau(j_);
	double T_km = Splitting[j_].temperature;
	double T_r = Splitting[Splitting[j_].right].temperature;
	double T_l = Splitting[Splitting[j_].left].temperature;
	double T_t = Splitting[Splitting[j_].top].temperature;
	double T_b = Splitting[Splitting[j_].bottom].temperature;

	double hx2 = (Splitting[j_].left_length*Splitting[j_].left_length + Splitting[j_].right_length*Splitting[j_].right_length) / 2.0;
	double hy2 = (Splitting[j_].top_length*Splitting[j_].top_length + Splitting[j_].bottom_length*Splitting[j_].bottom_length) / 2.0;

	double T = T_km + coeff_therm_conduct * tau_*((T_r - 2 * T_km + T_l) / hx2 + (T_t - 2 * T_km + T_b) / hy2);

	return T;
}

double GridMethod::heatFlowNode(int j_) {
	double T;
	if (Splitting[j_].right < 0) {
		double T_l = Splitting[Splitting[j_].left].temperature;
		double h = Splitting[j_].left_length;
		T = (heat_flow / coeff_therm_conduct)*h + T_l;
	}
	if (Splitting[j_].left < 0) {
		double T_r = Splitting[Splitting[j_].right].temperature;
		double h = Splitting[j_].right_length;
		T = (heat_flow / coeff_therm_conduct)*h + T_r;
	}
	if (Splitting[j_].top < 0) {
		double T_b = Splitting[Splitting[j_].bottom].temperature;
		double h = Splitting[j_].bottom_length;
		T = (heat_flow / coeff_therm_conduct)*h + T_b;
	}
	if (Splitting[j_].bottom < 0) {
		double T_t = Splitting[Splitting[j_].top].temperature;
		double h = Splitting[j_].top_length;
		T = (heat_flow / coeff_therm_conduct)*h + T_t;
	}
	return T;
}

double GridMethod::environmentNode(int j_) {
	double T;
	if (Splitting[j_].right < 0) {
		double T_l = Splitting[Splitting[j_].left].temperature;
		double h = Splitting[j_].left_length;
		T = (h* heat_transfer_coeff*T_amb/ coeff_therm_conduct+T_l)/(1+ heat_transfer_coeff*h/ coeff_therm_conduct);
	}
	if (Splitting[j_].left < 0) {
		double T_r = Splitting[Splitting[j_].right].temperature;
		double h = Splitting[j_].right_length;
		T = (h* heat_transfer_coeff*T_amb / coeff_therm_conduct + T_r) / (1 + heat_transfer_coeff * h / coeff_therm_conduct);
	}
	if (Splitting[j_].top < 0) {
		double T_b = Splitting[Splitting[j_].bottom].temperature;
		double h = Splitting[j_].bottom_length;
		T = (h* heat_transfer_coeff*T_amb / coeff_therm_conduct + T_b) / (1 + heat_transfer_coeff * h / coeff_therm_conduct);
	}
	if (Splitting[j_].bottom < 0) {
		double T_t = Splitting[Splitting[j_].top].temperature;
		double h = Splitting[j_].top_length;
		T = (h* heat_transfer_coeff*T_amb / coeff_therm_conduct + T_t) / (1 + heat_transfer_coeff * h / coeff_therm_conduct);
	}
	return T;
}

double GridMethod::insulationNode(int j_) {
	double T;
	if (Splitting[j_].right < 0) {
		T = Splitting[Splitting[j_].left].temperature;
	}
	if (Splitting[j_].left < 0) {
		T = Splitting[Splitting[j_].right].temperature;
	}
	if (Splitting[j_].top < 0) {
		T = Splitting[Splitting[j_].bottom].temperature;
	}
	if (Splitting[j_].bottom < 0) {
		T = Splitting[Splitting[j_].top].temperature;
	}
	return T;
}

double GridMethod::cornerNode(int j_) {
	double T=0;
	int N_ = 0;

	if (Splitting[j_].left > 0) {
		T = T + Splitting[Splitting[j_].left].temperature;
		N_++;
	}
	if (Splitting[j_].right > 0) {
		T = T + Splitting[Splitting[j_].right].temperature;
		N_++;
	}
	if (Splitting[j_].top > 0) {
		T = T + Splitting[Splitting[j_].top].temperature;
		N_++;
	}
	if (Splitting[j_].bottom > 0) {
		T = T + Splitting[Splitting[j_].bottom].temperature;
		N_++;
	}

	int fl=0;
	double h_delt = 0;

	if (Splitting[Splitting[j_].right].type == 1) {
		fl++;
		h_delt = h_delt + Splitting[j_].right_length;
	}
	if (Splitting[Splitting[j_].left].type == 1) {
		fl++;
		h_delt = h_delt + Splitting[j_].left_length;
	}
	if (Splitting[Splitting[j_].top].type == 1) {
		fl++;
		h_delt = h_delt + Splitting[j_].top_length;
	}
	if (Splitting[Splitting[j_].bottom].type == 1) {
		fl++;
		h_delt = h_delt + Splitting[j_].bottom_length;
	}
	if (fl>1) {
		T = T / N_ + heat_flow * (h_delt) / (fl*coeff_therm_conduct);
	}
	if (fl == 1) {
		T = (T / N_ + heat_flow * (h_delt) / (fl*coeff_therm_conduct))/2;
	}
	else T= T / N_;

	return T;
}

double GridMethod::averageT() {
	double AT = 0;
	for (int i = 0; i < kol; i++) {
		AT = AT + Splitting[i].temperature;
	}
	return AT / kol;
}

GridMethod calculator(GridMethod Obj) {
	GridMethod Prev = Obj;
	GridMethod Temp = Obj;
	double AT = 1;
	double AT_prev = 0;
	double eps = 0.0000000000001;

	while (fabs(AT - AT_prev) > eps) {
		for (int i = 0; i < Temp.kol; i++) {
			if (Temp.Splitting[i].type == 0) {
				Temp.Splitting[i].temperature = Prev.insideNode(i);
			}
		}

		for (int i = 0; i < Temp.kol; i++) {
			if (Temp.Splitting[i].type == 1) {
				Temp.Splitting[i].temperature = Temp.heatFlowNode(i);
			}
			if (Temp.Splitting[i].type == 2) {
				Temp.Splitting[i].temperature = Temp.environmentNode(i);
			}
			if (Temp.Splitting[i].type == 3) {
				Temp.Splitting[i].temperature = Temp.insulationNode(i);
			}
		}

		for (int i = 0; i < Obj.kol; i++) {
			if (Temp.Splitting[i].type == 4) {
				Temp.Splitting[i].temperature = Temp.cornerNode(i);
			}
		}
		AT = Temp.averageT();
		AT_prev = Prev.averageT();
		Prev = Temp;
		//cout << Obj;
	}
	Obj = Temp;
	cout << Obj;
	return Temp;
}

ostream &operator<<(ostream& out, const GridMethod Obj) {
	for (int i = 0; i < Obj.kol; i++) {
		cout << Obj.Splitting[i];
	}
	return out;
}

GridMethod::~GridMethod()
{
}
