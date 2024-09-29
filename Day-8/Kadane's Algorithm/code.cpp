#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout<<"All Sub-Arrays: "<<endl;
    for (int st = 0; st < size; st++)
    {
        for (int end = st; end < size; end++)
        {
            for (int i = st; i <= end; i++)
            {
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;  
}