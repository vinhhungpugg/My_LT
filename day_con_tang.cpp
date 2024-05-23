#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
        int n;
        cin >> n;
        vector<int> M(n), N(n, 1), prev_index(n, -1); 
        for (int i = 0; i < n; i++)
            cin >> M[i];

        
        int dem = 0, end_index = 0; // end_index là chỉ số của phần tử cuối cùng trong dãy con tăng dài nhất
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (M[i] > M[j] && N[i] < N[j] + 1) 
                {
                    N[i] = N[j] + 1;
                    prev_index[i] = j; // Lưu chỉ số của phần tử trước đó trong dãy con
                }
            }
            
            if (dem < N[i]) {
                dem = N[i];
                end_index = i; // Cập nhật chỉ số của phần tử cuối cùng 
            }
        }


        cout << dem << endl;
        vector<int> lis;
        for (int i = end_index; i >= 0; i = prev_index[i]) {
            lis.push_back(M[i]); // Thêm phần tử vào dãy con 
        }
        reverse(lis.begin(), lis.end()); // Đảo ngược dãy con 
        for (int num : lis) {
            cout << num << " ";
        }
    return 0;
}
