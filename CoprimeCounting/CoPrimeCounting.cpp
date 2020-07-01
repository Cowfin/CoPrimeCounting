/*
CoPrimeCounting
Kelvin Wong
*/

#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono;

unsigned countCoprime(unsigned N) {
	vector<bool> isCoprime((N * N), true); // initialises the coprime and prime vector
	vector<bool> isPrime(N + 1, true);
	unsigned result = 0;

	for (unsigned i = 2; i <= N; i++) { // sets up prime vector by removing all multiples of prime numbers
		if (isPrime[i] == true) {
			for (unsigned j = i * 2; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (unsigned y = 1; y < N; y++) { // sets all guaranteed false values
		for (unsigned x = 0; x < N; x++) {
			if (x <= y) {
				isCoprime[x + y * N] = false;
			}
		}
	}

	for (unsigned i = 1; i < N; i++) {
		if (isPrime[i + 1] == true) { // loop sets all prime multiples from the prime number's row in the vector to false
			for (unsigned j = i; j < N; j += i + 1) {
				isCoprime[j + i * N] = false;

				for (unsigned k = j; k < N; k += i + 1) { // loop sets all prime multiples from rows that aren't prime numbers top false
					isCoprime[k + j * N] = false;
				}
			}
		}
	}

	/*
	// displays result as a table
	cout << "  ";
	for (int col = 1; col <= N; col++) {
		cout << col << " ";
	}
	cout << endl;

	for (unsigned y = 0; y < N; y++) {
		cout << (y+1) << " ";
		for (unsigned x = 0; x < N; x++) {
			cout << isCoprime[x + y * N] << " ";
		}
		cout << endl;
	}
	*/

	for (unsigned y = 0; y < N; y++) { // counts all true values in coprime vector
		for (unsigned x = 0; x < N; x++) {
			if (x >= y) {
				if (isCoprime[x + y * N] == true) {
					result++;
				}
			}
		}
	}
	return result;
}

int main() {
	unsigned N;
	cout << "Enter the maximum number:" << endl;
	cin >> N; // requests user input for maximum number

	auto start = high_resolution_clock::now(); // starts timer

	unsigned count = countCoprime(N);

	auto stop = high_resolution_clock::now(); // ends timer
	auto duration = duration_cast<microseconds>(stop - start); // meadures how long the algorithm took to run

	cout << "\nThe sum of coprime numbers from 0 to " << N << ": " << count << endl; // outputs results
	cout << "Time taken: " << duration.count() << " microseconds" << endl;
}