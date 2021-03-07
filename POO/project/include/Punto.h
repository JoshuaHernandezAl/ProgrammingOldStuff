#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
private:
	double x;
	double y;
public:
	~Punto() {
	};
	Punto() {
		x = 0.0;
		y = 0.0;
	};
	Punto(float a, float b) {
		x = a;
		y = b;
	};
	double dameTuX(void) {
		return x;
	}
	void modificaTuX(double x) {
		this->x = x;
	};
	double dameTuY(void) {
		return y;
	};
	void modificaTuY(double y) {
		this->y = y;
	};
};

#endif // PUNTO_H
