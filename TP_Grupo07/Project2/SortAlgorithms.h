template<class Generic>
class SortAlgorithms {
    Generic* arr;
    size_t size;
    void (*ptr)(Generic);
    bool (*compare)(Generic, Generic);
public:
    SortAlgorithms(Generic* arr, size_t size, void (*ptr)(Generic), bool (*compare)(Generic, Generic)) : arr(arr), size(size), ptr(ptr), compare(compare) {}
    void print() {
        for (size_t i = 0; i < size; ++i) {
            ptr(arr[i]);
        }
        cout << "\n";
    }
    void mergesort() {
        _mergeSort(0, size - 1);
    }
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
            if (compare(arr[l], arr[r]))
                aux[k++] = arr[l++];
            else
                aux[k++] = arr[r++];
        }
        while (l <= middle)
            aux[k++] = arr[l++];
        while (r <= f)
            aux[k++] = arr[r++];
        for (size_t j = 0; j < size; ++j)
            this->arr[i + j] = aux[j];
        delete[] aux;
    }
};