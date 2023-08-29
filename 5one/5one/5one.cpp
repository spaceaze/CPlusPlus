#include <iostream>
using namespace std;

int main()
{
    int n, r, f;

    cout << "Enter Your Number:";
    cin >> n;


    // 1. Get the number
    // 2. Get the remainder and pass the next remaining digits
    // 3. Get the rightmost rightmost digit of the number use modulus (%)
    //     diving by 10 and add to the sum
    // 4. Divide the number by 10 to remove rightmost
    // 5. Base case is n  = 0
    // 6. Print and return the sum

     r = n % 10;

     cout << "This is r " << r << endl;
    
     f = n / 10;

     f += f; // 3456

     cout << "This is n " << n << endl;
     cout << "This is f " << f << endl;
   
     return 0;
    


   // system("PAUSE");
    
}
