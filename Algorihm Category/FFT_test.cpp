#include <bits/stdc++.h>

const double PI = acos(-1); // PI ���� ������ ����
#define cpx complex<double>
using namespace std;

 // n-1�� ���׽� f�� n���� ���Ҽ��� DFT��. �̶� x = w
void FFT(vector<cpx> &f, cpx w){
    int n = f.size();
    if(n == 1) return; // base case
 
    // ���׽� �и�
    vector<cpx> even(n/2), odd(n/2);
    for(int i = 0; i < n; ++i)
        (i%2 ? odd : even)[i/2] = f[i];
 
    // divide: ������ ���׽��� ��������� DFT��
    FFT(even, w*w);
    FFT(odd, w*w);
 
    // conquer: ��������� �˾ƿ� DFT ����� �̹� �Լ��� ����� ���
    cpx wp(1, 0);
    for(int i = 0; i < n/2; ++i){
        // f(x) = f_even(x^2) + x * f_odd(x^2)
        f[i] = even[i] + wp*odd[i];
        // f(-x) = f_even(x^2) - x * f_odd(x^2)
        f[i + n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
    // ���׽��� ���̺��� ū �ּ��� 2�� �ŵ��������� ã�� n���� �д�
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);
 
    cpx w(cos(2*PI/n), sin(2*PI/n));
 
    // FFT�� ���� �� ���׽��� DFT�� �д�.
    FFT(a, w);
    FFT(b, w);
 
    // DFT�� ���鳢�� ���ϸ� ��� ���׽��� DFT���� �ȴ�.
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
 
    // ����ȯ: c�� DFT �����κ��� c�� ���׽� ���¸� �����Ѵ�.
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    vector<cpx> A;
    vector<cpx> B;
    A.push_back(3);
    A.push_back(4);
    B.push_back(2);
    B.push_back(3);
    vector<cpx> C = multiply(A, B);
    for (auto p: C){
        printf("%d\n", (int)round(p.real()));
    }

    return 0;
}



