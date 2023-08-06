#include <iostream>
using namespace std;

void move_forward(int* arr, int& a, int& b) {
    cout << "Moving forward..." << endl;
    *(arr + a * 7 + b) = 0;
    a++;
    *(arr + a * 7 + b) = 1;
}

void move_backward(int* arr, int& a, int& b) {
    cout << "Moving backward..." << endl;
    *(arr + a * 7 + b) = 0;
    a--;
    *(arr + a * 7 + b) = 1;
}

void move_left(int* arr, int& a, int& b) {
    cout << "Moving left..." << endl;
    *(arr + a * 7 + b) = 0;
    b--;
    *(arr + a * 7 + b) = 1;
}

void move_right(int* arr, int& a, int& b) {
    cout << "Moving right..." << endl;
    *(arr + a * 7 + b) = 0;
    b++;
    *(arr + a * 7 + b) = 1;
}

void move_forward_left(int* arr, int& a, int& b) {
    cout << "Moving forward-left..." << endl;
    *(arr + a * 7 + b) = 0;
    b--;
    a++;
    *(arr + a * 7 + b) = 1;
}

void move_forward_right(int* arr, int& a, int& b) {
    cout << "Moving forward-right..." << endl;
    *(arr + a * 7 + b) = 0;
    b++;
    a++;
    *(arr + a * 7 + b) = 1;
}

void move_backward_left(int* arr, int& a, int& b) {
    cout << "Moving backward-left..." << endl;
    *(arr + a * 7 + b) = 0;
    b--;
    a--;
    *(arr + a * 7 + b) = 1;
}

void move_backward_right(int* arr, int& a, int& b) {
    cout << "Moving backward-right..." << endl;
    *(arr + a * 7 + b) = 0;
    b++;
    a--;
    *(arr + a * 7 + b) = 1;
}

void display(int arr[][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}

void now_exit(int& m){
    m=0;
}

void askForMove(int *arr ,int &q, int &a, int &b) {
    int choice;
    cout << "Which move do you want to do?" << endl;
    cout << "1. Forward" << endl;
    cout << "2. Backward" << endl;
    cout << "3. Left" << endl;
    cout << "4. Right" << endl;
    cout << "5. Forward-Left" << endl;
    cout << "6. Forward-Right" << endl;
    cout << "7. Backward-Left" << endl;
    cout << "8. Backward-Right" << endl;
    cout<< "9. exit"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            move_forward(arr, a, b);
            break;
        case 2:
            move_backward(arr,a,b);
            break;
        case 3:
            move_left(arr,a,b);
            break;
        case 4:
            move_right(arr,a,b);
            break;
        case 5:
            move_forward_left(arr,a,b);
            break;
        case 6:
            move_forward_right(arr,a,b);
            break;
        case 7:
            move_backward_left(arr,a,b);
            break;
        case 8:
            move_backward_right(arr,a,b);
            break;
        case 9:
            now_exit(q);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

int main() {
    int arr[7][7];

     // Initialize arr to all positions with 0
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            arr[i][j] = 0;
        }
    }
    int a,b=0;
    cout<<("Enter the starting square (row column): ");
    cin>>a>>b;
    arr[a][b]=1;

    int m=1;

    while (true)
    {
    display(arr);
    askForMove(reinterpret_cast<int*>(arr), m , a , b );
    if(m==0){return 0;} 

    }
    return 0;
}
