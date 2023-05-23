#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

class BoolVector
{
	int n;
	bool* vector;
public:
	BoolVector();
	BoolVector(int k);
	BoolVector(int k, int array[]);
	BoolVector(const BoolVector& vect);
	~BoolVector() {
		delete[]vector;
	};

	int get_dim();
	bool* getVector();
	void conjunction(BoolVector vect);
	void disjunction(BoolVector vect);
	void negation();
	void show(bool Endl = true);
	bool getcoord(BoolVector vect);
	void giveMemory(int k);
	void set(int k, int* array);

	int calc_0();
	int calc_1();
	BoolVector operator & (BoolVector vect);
	BoolVector operator = (BoolVector vect);
	BoolVector operator | (BoolVector vect);
	BoolVector operator ~ ();
	bool operator > (BoolVector vect);
	bool operator < (BoolVector vect);
	bool operator == (BoolVector vect);
};

int BoolVector::get_dim() {
	return n;
};

bool* BoolVector::getVector() {
	return vector;
};

BoolVector::BoolVector()
{
	n = rand() % 10 + 1;
	vector = new bool[n + 1];
	if (!vector) {
		cout << "Error";
		_getch();
		return;
	}
	for (int i = 0; i < n; i++)
		vector[i] = rand() % 2;
}
BoolVector::BoolVector(int k)
{
	n = k;
	vector = new bool[n + 1];
	if (!vector) {
		cout << "Error";
		_getch();
		return;
	}
	for (int i = 0; i < n; i++)
		vector[i] = rand() % 2;
}
BoolVector::BoolVector(const BoolVector& vect)
{
	n = vect.n;
	vector = new bool[n + 1];
	if (!vector) {
		cout << "Error";
		_getch();
		return;
	}
	for (int i = 0; i <= n; i++)
		vector[i] = vect.vector[i];
}
BoolVector::BoolVector(int k, int array[]) {
	n = k;
	vector = new bool[n + 1];
	if (!vector) {
		cout << "Error";
		_getch();
		return;
	}
	for (int i = 0; i < n; i++)
		vector[i] = array[i];
}
void BoolVector::show(bool Endl)
{
	for (int i = 0; i < n; i++)
		cout << vector[i];
	if (Endl)
		cout << endl;
}
void BoolVector::giveMemory(int k) {
	if (vector)
		delete[]vector;
	vector = new bool[k + 1];
	if (!vector) {
		cout << "Error";
	}
}

void BoolVector::set(int dim, int* array) {
	n = dim;
	if (vector)
		delete[]vector;
	vector = new bool[n + 1];
	for (int i = 0; i < n; i++)
		vector[i] = array[i];
}

int BoolVector::calc_0() {
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		if (!vector[i])
			z++;
	}
	return z;
}
int BoolVector::calc_1() {
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (vector[i])
			k++;
	}
	return k;
}

void BoolVector::conjunction(BoolVector vect) {
	if (n != vect.n)
	{
		cout << "Ops... Different dimensions\n";
		return;
	}
	cout << "conjunction a&b: ";
	for (int i = 0; i < n; i++)
		cout << (vector[i] & vect.vector[i]);
	cout << endl;
}

void BoolVector::disjunction(BoolVector vect) {
	if (n != vect.n)
	{
		cout << "Ops... Different dimensions\n";
		return;
	}
	cout << "disjunction aVb: ";
	for (int i = 0; i < n; i++)
		cout << (vector[i] | vect.vector[i]);
	cout << endl;
}

void BoolVector::negation() {
	cout << "negation: ";
	for (int i = 0; i < n; i++)
		cout << !vector[i];
	cout << endl;
}

BoolVector BoolVector::operator & (BoolVector vect)
{
	if (n != vect.n)
	{
		cout << "Ops... Different dimensions\n";
		return 0;
	}
	BoolVector temp(n);
	temp.giveMemory(n);
	temp.n = n;
	for (int i = 0; i < n; i++)
		temp.vector[i] = (vector[i] & vect.vector[i]);
	return temp;
}

BoolVector BoolVector::operator=(BoolVector vect)
{
	n = vect.get_dim();
	vect.giveMemory(n);
	for (int i = 0; i < n; i++)
		vect.vector[i] = vector[i];
	return BoolVector();
}

BoolVector BoolVector::operator|(BoolVector vect)
{
	if (n != vect.n)
	{
		cout << "Ops... Different dimensions\n";
		return 0;
	}
	BoolVector temp(n);
	temp.giveMemory(n);
	for (int i = 0; i < n; i++)
		temp.vector[i] = (vector[i] | vect.vector[i]);
	return temp;
}

BoolVector BoolVector::operator~()
{
	for (int i = 0; i < n; i++)
		vector[i] = !vector[i];
	return *this;
}

bool BoolVector::operator>(BoolVector vect)
{
	for (int i = 0; i < n; i++)
		if (vector[i] < vect.vector[i])
			return true;
		else
			if(vector[i] > vect.vector[i])
			return false;
}

bool BoolVector::operator<(BoolVector vect)
{
	for (int i = 0; i < n; i++)
		if (vector[i] > vect.vector[i])
			return true;
		else
			if (vector[i] < vect.vector[i])
				return false;
}

bool BoolVector::operator==(BoolVector vect)
{
	int k = 0;
	if (n = vect.n) {
		for (int i = 0; i < n; i++)
			if (vector[i] == vect.vector[i])
				k++;
		if (k == n)
			return true;
	}
	else {
		for (int i = 0; i < n; i++)
			if (vector[i] == 0 && vect.vector[i] == 0)
				break;
			else
				if (vector[i] == vect.vector[i])
					k++;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");

	int dim = 5;
	BoolVector a(dim), b(dim);
	cout << "a = "; a.show();
	cout << "b = "; b.show();
	cout << "-----------------------------------------\n";
	cout << "Методы класса:\n";
	cout << "Количество нулей в a=" << a.calc_0() << ", в b=" << b.calc_0() << endl;
	cout << "Количество единиц в a=" << a.calc_1() << ", в b=" << b.calc_1() << endl;
	a.conjunction(b);
	a.disjunction(b);
	a.negation();
	b.negation();
	cout << "-----------------------------------------\n";
	cout << "Перегруженные операции:\n";
	cout << "a&b= "; (a & b).show();
	cout << "aVb= "; (a | b).show();
	cout << "-a= "; (~a).show();
	cout << "-b= "; (~b).show();
	cout << "(a > b)? " << (a > b) << endl;
	cout << "(a < b)? " << (a < b) << endl;
	cout << "(a == b)? " << (a == b) << endl;
	cout << "(a == a)? " << (a == a) << endl;
	cout << "-----------------------------------------\n";

	const int n = 10;
	BoolVector* A[n];
	BoolVector* B[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = new BoolVector(dim);
		B[i] = new BoolVector(dim);
	}
	cout << setw(dim + 2) << left << "A" << setw(dim + 2) << left << "B" << setw(dim + 2) << left << "-B" << " A V -B" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i]->show(false); cout << "  ";
		B[i]->show(false); cout << "  ";
		*B[i] = ~*B[i]; B[i]->show(false); cout << " | ";
		(*A[i] | *B[i]).show();
	}
	for (int i = 0; i < n; i++)
	{
		delete A[i];
		delete B[i];
	}


	return 0;
}
