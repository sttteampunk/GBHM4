#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include <cassert>
#include <iostream>

using namespace std;

void obzac()
{
    cout << "\n//============================================================================//\n\n";
};

//task1

template<typename T, typename N>
void insert_sorted(T& v, const N  n)
{
    const auto insert_pos(lower_bound(begin(v), end(v), n));
    v.insert(insert_pos, n);
}

template<typename T>
void inform(const T& v)
{
    for (const auto e : v) cout << e << ' ';
}

//tsk2

int GetRandomNum(int min, int max) {
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int> dis(min, max);
    return dis(generator);
}

int main()
{
    {
        obzac();

        vector<int> Vector{ 1, 2, 3, 4, 5, 6, 7, 9, 10 };
        cout << "your array\n";
        inform(Vector);
        cout << "\n\nyour array after function (insert_sorted)\n";
        assert(true == is_sorted(begin(Vector), end(Vector)));
        insert_sorted(Vector, 8);
        inform(Vector);

        obzac();
    }

    {
        obzac();
        const size_t SizeArr(10);

        vector<float> RealArray(SizeArr);
        generate(RealArray.begin(), RealArray.end(), []() { return float(GetRandomNum(1, 100)) + (float(GetRandomNum(1, 100)) / 100); });
        cout << "array of integer numbers\n";
        for (auto N : RealArray)
        {
            cout << N << "\t";
        }
        cout << endl;

        vector<int> IntegerArray;
        IntegerArray.reserve(SizeArr);
        transform(RealArray.begin(), RealArray.end(), back_inserter(IntegerArray), [](float f) {return int(f); });
        cout << "\narray of real numbers\n";
        for (auto N : IntegerArray)
        {
            cout << N << "\t";
        }

        cout << "\n\n[error]: " << inner_product(IntegerArray.begin(), IntegerArray.end(), RealArray.begin(), 0.f, plus<>(), [](float a, float d)
            {
                return (a - d) * (a - d);
            });

        obzac();    }
}