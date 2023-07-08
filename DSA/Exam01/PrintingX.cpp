#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mid = n / 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == mid && i == mid)
            {
                cout << "X";
            }
            else if (j == i)
            {
                cout << "\\";
            }
            else if (j == n - i - 1)
            {
                cout << "/";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     int mid = N / 2;  // Calculate the midpoint of the pattern
//     int spaces = 0;  // Number of spaces before and after the slashes

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < spaces; j++) {
//             cout << " ";
//         }

//         if (i == mid) {
//             cout << "X";  // Print the X in the middle row
//         } else {
//             cout << "\\";  // Print the left slash
//             for (int k = 0; k < N - 2 * spaces - 2; k++) {
//                 cout << " ";  // Print the spaces between the slashes
//             }
//             cout << "/";  // Print the right slash
//         }

//         for (int j = 0; j < spaces; j++) {
//             cout << " ";
//         }

//         cout << endl;

//         if (i < mid) {
//             spaces++;  // Increase the number of spaces for each row until the middle row
//         } else {
//             spaces--;  // Decrease the number of spaces for each row after the middle row
//         }
//     }

//     return 0;
// }
