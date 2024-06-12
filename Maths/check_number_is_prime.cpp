#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}



/*-------------------Write code downwards--------------------------------------------------------------*/

/*
Time complexity: O(N)
Space complexity: O(1)
*/
void checkPrime_method1(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			cout << "Not a prime number" << endl;
			return;
		}
	}
	cout << "a prime number" << endl;
	return;
}

/*
Time complexity: O(sqrt(N))
Space complexity: O(1)
*/

void checkPrime_method2(int num) {
	for (int i = 2; (i * i <= num); i++) {
		if (num % i == 0) {
			cout << "Not a prime number" << endl;
			return;
		}
	}
	cout << "a prime number" << endl;
	return;
}

/*
Time complexity: O(Nlog(N))
Space complexity: O(1)

Technique called: Sieve of Eratosthenes
*/

void checkPrime(int num) {
	vector<bool>isPrime(num + 1, true); //marked all are prime numbers
	isPrime[0] = isPrime[1] = false; //since 0 and 1 are not prime numbers

	for (int i = 2; (i * i <= num); i++) {
		if (isPrime[i] == true) {
			for (int j = 2 * i; j <= num; j += i) {
				isPrime[j] = false;
			}
		}
	}
	if (isPrime[num] == true)
		cout << "a prime number" << endl;
	else
		cout << "Not a prime number" << endl;
	return;
}
void checkPrime_method3(int num) {
	return checkPrime(num);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
	Take Input here if needed
	*/
	int num; cin >> num;
	// checkPrime_method1(num);
	// checkPrime_method2(num);
	checkPrime_method3(num);

}