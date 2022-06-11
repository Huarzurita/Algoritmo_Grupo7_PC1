#include "Capp.h"
template<class Generic>
class AdvanceSort {
    vector <Generic>vec;
    size_t size;
    void (*imprimir)(Generic);
    bool (*comparar)(Generic, Generic);
public:
    AdvanceSort(vector<Generic>vec, size_t size, void (*imprimir)(Generic), bool (*comparar)(Generic, Generic))
        :vec(vec), size(size), imprimir(imprimir), comparar(comparar) {}
    void print() {
        for (size_t i = 0; i < size; ++i) {
            imprimir(vec.at(i));
        }
        cout << "\n";
    }
    void mergesort() {
        _mergeSort(0, size - 1);
    }
    void radixsort() {
        long max = getMax();
        for (long place = 1; max / place > 0; place *= 10)
            countingSort(place);
    }
    ~AdvanceSort();
private:
    void _mergeSort(int i, int f) {
        if (i == f)
            return;
        size_t middle = (i + f) / 2;
        _mergeSort(i, middle);
        _mergeSort(middle + 1, f);
        merge(i, middle, f);
    }
    void merge(int i, int middle, int f) {
        size_t size = (f - i) + 1;
        Generic* aux = new Generic[size];
        size_t l = i, r = middle + 1, k = 0;
        while (l <= middle && r <= f) {
            if (comparar(vec[l], vec[r]))
                aux[k++] = vec[l++];
            else
                aux[k++] = vec[r++];
        }
        while (l <= middle)
            aux[k++] = vec[l++];
        while (r <= f)
            aux[k++] = vec[r++];
        for (size_t j = 0; j < size; ++j)
            this->vec[i + j] = aux[j];
        delete[] aux;
    }
    long getMax()
	{
		long max = vec[0];
		for (size_t i = 1; i < size; i++)
			if (comparar(vec[i],max))
				max = vec[i];
		return max;
	}
	void countingSort(long place) {
		const int max = 10;
		long *output=new long [size];
		long count[max];
		for (long i = 0; i < max; ++i)
			count[i] = 0;
		for (long i = 0; i < size; i++)
			count[(vec[i] / place) % 10]++;
		for (long i = 1; i < max; i++)
			count[i] += count[i - 1];
		for (long i = size - 1; i >= 0; i--) {
			output[count[(vec[i] / place) % 10] - 1] = vec[i];
			count[(vec[i] / place) % 10]--;
		}
		for (long i = 0; i < size; i++) {
			vec[i] = output[i];
		}
	}


};