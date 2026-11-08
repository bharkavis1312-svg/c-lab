#include <iostream>
#include <vector>
#include <ranges>
#include <concepts>

using namespace std;

// Define Numeric Concept
template <typename T>
concept Numeric = integral<T> || floating_point<T>;

// Generic Data Processing Function
template <Numeric T>
vector<T> processData(const vector<T>& data)
{
    vector<T> result;

    // Filter positive values and double them
    auto pipeline = data
        | views::filter([](T value)
        {
            return value > 0;
        })
        | views::transform([](T value)
        {
            return value * 2;
        });

    // Store processed values
    for (T value : pipeline)
    {
        result.push_back(value);
    }

    return result;
}

int main()
{
    // Input data
    vector<int> data = {-5, 10, 20, -3, 15, 30};

    // Process the data
    vector<int> result = processData(data);

    cout << "Original Data: ";

    for (int value : data)
    {
        cout << value << " ";
    }

    cout << endl;

    cout << "Processed Data: ";

    for (int value : result)
    {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}