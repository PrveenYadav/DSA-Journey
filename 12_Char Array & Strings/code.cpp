#include <iostream>
using namespace std;

// Length
int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

//Reverse character Array
void reverse(char ch[], int n) {
    
    int st = 0, end = n-1;
    while (st <= end)
    {
        swap(ch[st], ch[end]);
        st++;
        end--;
    }
}

//Check Palindrome if char is not case sensetive
int tolowercase(char ch) {
    if (ch >= 'a' && ch <= 'z')
    {
       return ch;
    }else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool palindrome(char ch[], int n) {
    int st = 0, end = n-1;

    while (st <= end)
    {
        if (tolowercase(ch[st]) != tolowercase(ch[end]))
        {
            return 0;
        }else {
            st++;
            end--;
        }
    } 
    return 1;
}

int main() 
{
    char ch[10];

    cout<<"Enter Your Name: ";
    cin>>ch;
    int length = getLength(ch);

    cout<<"Your name is "<<ch<<endl;
    cout<<"Length is: "<<length<<endl;

    reverse(ch, length);
    cout<<"reverse is: "<<ch<<endl;

    cout<<"Palindrome or Not: "<<palindrome(ch, length)<<endl;
    return 0;
}