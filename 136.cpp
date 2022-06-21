#include<iostream>
using namespace std;
/*
科学计数法 精度与有效数字
*/
int p, t, b;
string m;
int main() {
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> m >> p;
        while (m.front() == '0')
            m.erase(m.begin());
        if (m.front() == '.') {
            for (int i = 1; i < m.length(); i++) {
                if (m[i] > '0') {
                    b = -i;
                    break;
                }
            }
        } else
            b = (m.find('.') == m.npos ? m.length() : m.find('.')) - 1;
        string copy{};
        for (auto i : m) {
            if (isdigit(i))
                copy += i;
        }
        while (copy.front() == '0')
            copy.erase(copy.begin());
        if (copy.length() > p) {
            if (copy[p] >= '5')
                copy[p - 1]++;
            for (int i = p - 1; i >= 1; i--) {
                copy[i - 1] += copy[i] / ('9' + 1);
                copy[i] %= '9' + 1;
                if (copy[i] < '0')
                    copy[i] += '0';
            }
            if (copy[0] == '9' + 1) {
                copy[0] %= ('9' + 1);
                if (copy[0] < '0')
                    copy[0] += '0';
                copy.insert(copy.begin(), '1');
                b++;
            }
        } else {
            for (int i = copy.length() - 1; i < p; i++)
                copy += '0';
        }
        cout << "case #" << k << ":\n" << copy[0] << ".";
        for (int i = 1; i < p; i++)
            cout << copy[i];
        if (b)
            cout << "F" << b;
        cout << endl;
    }
    return 0;
}

/* 3
123456789 8
0.0045678 3
1.8 1
 */
//神奇解法
/* auto const P(30);
int main()
{
    int T; cin >> T;
    for(int cs = 0; cs < T; cs++)
    {
       
        string m; int p; cin >> m >> p; m +='0'; // 开头补个0防溢出
        int b = 0;
        if(auto dot = m.find('.'); dot != m.npos)
        {
            b = dot - m.length() + 1;
            m.erase(dot, 1);
        }
        auto nz = m.find_first_not_of('0'); // nz: not_zero
        b += m.length() - nz - 1;
        m += string(P, '0'); // 不管精度够不够，末尾先补它30个0
        m[nz + p - 1] += m[nz + p] >= '5';
        for(int i = nz + p - 1; m[i] > '9'; i--)
        {
            m[i] -= 10; m[i - 1] += 1;
        }
        if(m[nz - 1] - '0') // 把类似10.0F1的情况改成1.0F2
        {
            nz -= 1; b += 1;
        } 
        
        cout << "case #" << cs << ":\n";
        
        cout << m[nz] << ".";
        for(size_t i = nz + 1; i < nz + p; i++)cout << m[i];
        if(b)cout << "F" << b;
        cout << "\n";
    }
} */
