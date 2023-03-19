#include <iostream>
#include <stack>
using namespace std;

int fak(int n) {
	if (n > 1)
		return n * fak(n - 1);
	else
		return 1;
}

class TowersOfHanoi
{
public:
	int N;
	stack<int>A;
	stack<int>B;
	stack<int>C;

	TowersOfHanoi(int N = 4)
	{
		this->N = N;
		for (int i = N; i > 0; i--)
		{
			A.push(i);
		}
	}

	void print()
	{
		stack<int>A = this->A;
		stack<int>B = this->B;
		stack<int>C = this->C;

		for (int i = N; i > 0; i--)
		{
			if (A.size() >= i)
			{
				cout << A.top() << "\t";
				A.pop();
			}
			else
			{
				cout << "|\t";
			}


			if (B.size() >= i)
			{
				cout << B.top() << "\t";
				B.pop();
			}
			else
			{
				cout << "|\t";
			}


			if (C.size() >= i)
			{
				cout << C.top() << endl;
				C.pop();
			}
			else
			{
				cout << "|" << endl;
			}
		}
	}

	void solve()
	{
		solve(A, C, B, N);
	}

	void moveDisk(stack<int>& from, stack<int>& to)
	{
		to.push(from.top());
		from.pop();
	}

	void solve(stack<int>& from, stack <int>& to, stack<int>& aux, int N)
	{
		if (N == 0) return;

		solve(from, aux, to, N - 1);
		moveDisk(from, to);
		solve(aux, to, from, N - 1);
	}

};

int main() {
	//cout << fak(3);

	TowersOfHanoi towers(4);
	/*cout << towers.A.size() << endl;*/

	towers.print();
	towers.solve();
	towers.print();


	return 0;
}