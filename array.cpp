#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << "Sum: " << sum << endl;
    return 0;
}