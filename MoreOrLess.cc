#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)
using namespace std;
typedef long long ll;
int n;
bool sudoku(int i, int j, vector<vector<char>> &board, vector<int> &posiblesfila, vector<int> &posiblescol)
{
    if(i==0 && j==3&&board[0][0]=='2')
    int aasdasd=0;
    if (i == n)
    {
        fore(i, 0, n)
        {
            fore(j, 0, n)
            {
                cout << board[i * 2][j * 2];
            }
            cout << "\n";
        }
        return true;
    }
    int newI = j == (n - 1) ? i + 1 : i;
    int newJ = j == (n - 1) ? 0 : j + 1;
 
    if (board[i * 2][j * 2] == '-')
    {
        vector<int> posibles;
        fore(k,0,n){
            if((posiblescol[j] & (1 << k)) && (posiblesfila[i] & (1 << k))){
                posibles.pb(k);
            }
        }
        for (auto asd : posibles)
        {
                char c = (char)(asd+'1');
                bool horizq= j==0 || (j > 0 && (board[2*i][2 * j - 1] == '.' 
                || (board[2*i][2 * j - 1] == '<' && board[2*i][2 * (j - 1)] < c) 
                || (board[2*i][2 * j - 1] == '>' && board[2*i][2 * (j - 1)] > c)));
                bool arr = i==0 || (i > 0 && (board[2 * i - 1][2*j] == '.' 
                || (board[2 * i - 1][2*j] == '^' && board[2 * i - 2][2*j] < c) 
                || (board[2 * i - 1][2*j] == 'v' && board[2 * i - 2][2*j] > c)));
                bool abaj = i==n-1 || (i < n-1 && (board[2 * i + 1][2*j] == '.' 
                || (board[2 * i + 1][2*j] == '^' && (board[2 * i + 2][2*j] == '-' || board[2 * i + 2][2*j] > c)) 
                || (board[2 * i + 1][2*j] == 'v' && (board[2 * i + 2][2*j] == '-' || board[2 * i + 2][2*j] < c))));
                bool der = j==n-1 || (j < n-1 && (board[2*i][2 * j + 1] == '.' 
                || (board[2*i][2 * j + 1] == '<' && (board[2*i][2 * j + 2] == '-' || board[2*i][2 * j + 2] > c)) 
                || (board[2*i][2 * j + 1] == '>' && (board[2*i][2 * j + 2] == '-' || board[2*i][2 * j + 2] < c))));
                if (horizq)
                {
                    if(abaj){
                        if(der){
                            if(arr){
                                board[i * 2][2 * j] = c;
                                posiblesfila[i]&= ~(1 << ((int)(c-'1')));
                                posiblescol[j]&= ~(1 << ((int)(c-'1')));
                                if (sudoku(newI, newJ, board, posiblesfila, posiblescol))
                                    return true;
                                posiblesfila[i]|= 1<<(int)(c-'1');
                                posiblescol[j] |= 1<<(int)(c-'1');
                                board[i * 2][2 * j] = '-';
                                
                            }
                        }
                    }
                }
                
        }
    }
    else
    {
        if(sudoku(newI, newJ, board, posiblesfila, posiblescol)) 
            return true;
    }
 
    return false;
}
 
int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    vector<vector<char>> board(2 * n - 1);
    vector<int> posiblesfila(n);
    vector<int> posiblescol(n);
    fore(i, 0, n)
    {
        posiblesfila[i] = 0;
        posiblescol[i] = 0;
        fore(j, 0, n)
        {
            posiblesfila[i] |= 1<<(j);
            posiblescol[i] |= 1<<(j);
        }
    }
    fore(i, 0, 2 * n - 1)
    {
        fore(j, 0, 2 * n - 1)
        {
            char c;
            cin >> c;
            board[i].pb(c);
            if (c >= '1' && c <= '9')
            {
                int xdd = (int)(c-'1');
                posiblesfila[i / 2]&= ~(1 << (xdd));
                posiblescol[j / 2]&= ~(1 << (xdd));
            }
        }
    }
    sudoku(0, 0, board, posiblesfila, posiblescol);
    int asd = 0;
    return 0;
}