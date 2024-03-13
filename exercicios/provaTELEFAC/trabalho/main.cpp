#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void add(vector<vector<string>> &table, vector<string> &var) {
    vector<string> t;
    // arrumando a tabela
    t.push_back("aA");
    table.push_back(t);
    t.clear();
    t.push_back("bB");
    t.push_back("$");
    table.push_back(t);
    t.clear();
    t.push_back("aA");
    t.push_back("bS");
    table.push_back(t);
    // terminais
    var.push_back("S");
    var.push_back("A");
    var.push_back("B");
}

int verifyStack(stack<string> &c, vector<vector<string>> paths, vector<string> var, char ch) {
    int indVar = 0, j = 0;
    char temp;
    if (!c.empty()) {
        // procura o não termianl que está no topo da fila
        while (indVar < var.size() and var[indVar] != c.top()) indVar++;
        if (var[indVar] == c.top()) {
            c.pop();
            // verifica se para aquele não terminal só tem uma derivação disponível
            if (paths[indVar].size() == 1) {
                c.push(paths[indVar][0]);
                return 1;
            }
            else {
                // verifica se o próximo caractere já é o final
                if (ch == ' ') temp = '$';
                else temp = ch;
                // procura se a derivação em um determinado não terminal tem o valor que está na fita
                while (j < paths[indVar].size() && paths[indVar][j][0] != temp)
                    j++;
                // caso ache retorna verdadeiro
                if (j < paths[indVar].size() && paths[indVar][j][0] == temp) {
                    c.push(paths[indVar][j]);
                    return 1;
                }
                else return 0;
            }
        } else return 0;
    }
}


int main()
{
    string tape;
    int n = -1, aux;

    vector<vector<string>> paths;
    vector<string> var;
    stack<string> control;

    add(paths, var);
    control.push("$");
    control.push(var[0]);
    cin >> tape;

    while (++n < tape.size() and verifyStack(control, paths, var, tape[n])) {
        string s = control.top();
        cout << control.top() << " = ";

        s = s[1];
        control.pop();
        control.push(s);

        cout << control.top() << endl;
        cout << n << endl;
    }
    cout << "saiu" << endl;
    cout << control.top() << endl;

    if (verifyStack(control, paths, var, ' ')) cout << "pilha: " << control.top() << endl;
    else cout << "pilha (erro): " << control.top() << endl;

    return 0;
}
