#include <vector>
#include <thread>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;

vector<size_t> split(size_t parts, size_t n)
{
    vector<size_t>  ret(parts + 1);
    size_t          part_size = n / parts,
                    reminder = n % parts,
                    index = 0;
    for (size_t i = 0; i < parts; ++i) {
        ret[i] = index;
        index += part_size;
    }
    ret[parts] = index + reminder;
    return ret;
}

void part_sort(vector<double>& v, size_t left, size_t right)
{
    sort(v.begin() + left, v.begin() + right);
}

void parallel_merge(vector<double>& v, size_t i, size_t j, size_t l)
{
    inplace_merge(v.begin() + i, v.begin() + j, v.begin() + l);
}

void parallel_sort(vector<double>& v, size_t parts)
{
    vector<size_t>  bounds = split(parts, v.size());
    vector<thread>  threads;

    for (size_t i = 0; i < parts; ++i)
        threads.push_back(thread(part_sort, ref(v), bounds[i], bounds[i+1]));

    for (auto& t : threads)
        t.join();

    // reduce
    while (parts > 1) {
        vector<size_t>  limits;
        vector<thread>  threads2;

        for (size_t i = 0; i < parts-1; i += 2) {
            threads2.push_back(thread(parallel_merge, ref(v), bounds[i],
                bounds[i+1], bounds[i+2]));

            size_t  index = limits.size();
            if (index > 0) {
                if (limits[index - 1] != bounds[i])
                    limits.push_back(bounds[i]);

                limits.push_back(bounds[i+2]);
            } else {
                limits.push_back(bounds[i]);
                limits.push_back(bounds[i+2]);
            }

        }

        for (auto& t : threads2)
            t.join();

        parts /= 2;
        bounds = limits;
    }
}

template <typename T>
bool is_sorted(vector<T>& v) {
    for (size_t i = 0, len = v.size(); i < len - 1; ++i) {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

int main()
{
    size_t          parts = 8; // n threads
    size_t          v_size = 50000000;
    vector<double>  v(v_size);
    int             seed = time(nullptr);

    default_random_engine               engine(seed);
    uniform_real_distribution<double>   unif(0, 1);
    auto                                start = chrono::steady_clock::now();
    auto                                end = chrono::steady_clock::now();
    auto                                diff = end - start;

    for (auto& elem : v)
        elem = unif(engine);

    cout << "n = " << v_size << endl;

    start = chrono::steady_clock::now();
    parallel_sort(v, parts); // parallel sorting
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "parallel : " <<
        chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    cout << "is_sorted(v) : " << is_sorted(v) << endl;

    for (auto& elem : v)
        elem = unif(engine);

    start = chrono::steady_clock::now();
    sort(v.begin(), v.end()); // std::sort
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "std : " <<
        chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    cout << "is_sorted(v) : " << is_sorted(v) << endl;

    return 0;
}
