#include <iostream>
#include <chrono>
using namespace std;

constexpr int arraySize = 100;

uint32_t getNanos();
void Fillarray(int arrayToFill[], int sizeOfArray);
void BubbleSort(int arrayToSort[], int sizeOfArray);

int main()
{
	int DataSet[arraySize];

	srand(time(nullptr));
	Fillarray(DataSet, arraySize);
	uint32_t startNanos = getNanos();
	BubbleSort(DataSet, arraySize);
	uint32_t endNanos = getNanos();

	cout << "BubbleSort took " << endNanos - startNanos << " ns to sort an array of size " << arraySize << endl;

}
void Fillarray(int arrayToFill[], int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		arrayToFill[i] = rand() % sizeOfArray + 1;
	}
}

void BubbleSort(int arrayToSort[], int sizeOfArray) {
	for (int pass = 0; pass < sizeOfArray; ++pass) {
		for (int i = 0; i < sizeOfArray - 1; ++i) {
			if (arrayToSort[i] < arrayToSort[i + 1]) {
				int temp = arrayToSort[i];
				arrayToSort[i] = arrayToSort[i + 1];
				arrayToSort[i + 1] = temp;
			}
		}
	}
}

uint32_t getNanos() {
	using namespace chrono;
	return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}