/*
CoPrimeCountingBrute
Kelvin Wong
*/

#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

unsigned gcd(unsigned i, unsigned n) {
	if (i == 0) {
		return n;
	}
	return gcd(n % i, i);
}


unsigned phi(unsigned n) {
	unsigned result = 1;

	for (int i = 2; i < n; i++) {
		if (gcd(i, n) == 1) {
			result++;
		}
	}
	return result;
}


int main() {
	int max, buffer;
	int count = 0;

	cout << "Enter the maximum value:" << endl;
	cin >> max;
	max++;

	auto start = high_resolution_clock::now();

	for (int n = 1; n < max; n++) {
		buffer = phi(n);
		count += buffer;
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "The sum of coprime numbers from 0 to " << max-1 << ": " << count << endl;
	cout << "Time taken: " << duration.count() << " microseconds" << endl;
}