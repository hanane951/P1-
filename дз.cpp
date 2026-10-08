#include <iostream>
#include <stdexcept>

int loc_max(int* a, int n)
{
    int count = 0;

    std::cout << "Local maxima: ";

    for (int i = 1; i < n - 1; ++i)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            std::cout << a[i] << " ";
            ++count;
        }
    }

    std::cout << std::endl;

    return count;
}

int loc_min(int* a, int n)
{
    int count = 0;

    std::cout << "Local minima: ";

    for (int i = 1; i < n - 1; ++i)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            std::cout << a[i] << " ";
            ++count;
        }
    }

    std::cout << std::endl;

    return count;
}

int main()
{
    try
    {
        int* a = nullptr;
        int n = 0;
        int x;

        std::cin >> x;

        if (std::cin.fail())
        {
            throw std::runtime_error("Input error");
        }

        while (x != 0)
        {
            int* temp = new int[n + 1];

            for (int i = 0; i < n; ++i)
            {
                temp[i] = a[i];
            }

            temp[n] = x;

            delete[] a;
            a = temp;

            ++n;

            std::cin >> x;

            if (std::cin.fail())
            {
                delete[] a;
                throw std::runtime_error("Input error");
            }
        }

        if (n == 0)
        {
            delete[] a;
            throw std::runtime_error("Empty sequence");
        }

        int max_count = loc_max(a, n);
        int min_count = loc_min(a, n);

        std::cout << "Number of local maxima: "
                  << max_count << std::endl;

        std::cout << "Number of local minima: "
                  << min_count << std::endl;

        delete[] a;

        return 0;
    }
    catch (const std::exception&)
    {
        return 2;
    }
}