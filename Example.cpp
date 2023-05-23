#include <iostream>
using namespace std;

class BoolVector
{
	int n;
	int vector[n];
public:
	BoolVector();
	BoolVector(const BoolVector& ob);
	~BoolVector();
	void conjunct(BoolVector vector);
	void disjunction(BoolVector vector);
	void negation(BoolVector vector);
	int calculate_0(BoolVector vector);
	int calculate_1(BoolVector vector);
private:
};

BoolVector::BoolVector()
{
}

BoolVector::~BoolVector()
{
}

int main()
{
	cout << "Hello World!\n";
}
