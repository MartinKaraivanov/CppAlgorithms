#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

double stoinostNaCifrata(char cifra){
    if(cifra == 'I'){
        return (double)1;
    }
    if(cifra == 'V'){
        return (double)5;
    }
    if(cifra == 'X'){
        return (double)10;
    }
    if(cifra == 'L'){
        return (double)50;
    }
    if(cifra == 'C'){
        return (double)100;
    }
    if(cifra == 'D'){
        return (double)500;
    }
    if(cifra == 'M'){
        return (double)1000;
    }

    return -1;
}

double vDesetichna(string rimsko){

    double resultat = 0;

    for(int i = 0; i < (int)rimsko.size(); i++){
        double parvo = stoinostNaCifrata(rimsko[i]);

        if(i + 1 < (int)rimsko.size()){
            double vtoro = stoinostNaCifrata(rimsko[i + 1]);

            if(parvo >= vtoro){
                resultat +=  parvo;
            }else{
                resultat += vtoro - parvo;
                i++;
            }

        }else{
            resultat += parvo;
        }
    }

    return resultat;
}

int prioritet(char operaciq){
    if(operaciq == '^'){
        return 4;
    }
    if(operaciq == '~'){
        return 3;
    }
    if(operaciq == '*' || operaciq == '/'){
        return 2;
    }
    if(operaciq == '+' || operaciq == '-'){
        return 1;
    }
    return 0;
}

bool unarnaLiE(char operaciq){
    return operaciq == '~';
}

int kolkoAsociativno(char operaciq){
    if(operaciq == '^'){
        return 1;
    }
    return 0;
}

double napraviOperaciqta(double a, double b, char operaciq){
    if(operaciq == '^'){
        return pow(a, b);
    }
    if(operaciq == '+'){
        return (double)a + b;
    }
    if(operaciq == '-'){
        return (double)a - b;
    }
    if(operaciq == '*'){
        return (double)a*b;
    }
    if(operaciq == '/'){
        return (double)a/b;
    }
    return (double)-b;
}

bool bukvaLiE(char neshto){
    if(neshto == 'I' || neshto == 'V' || neshto == 'X' || neshto == 'L' || neshto == 'C' || neshto == 'D' || neshto == 'M'){
        return true;
    }

    return false;
}

double izchisliStoinostta(string izraz){
    stack<double> stoinosti;
    stack<char> operatori;

    for(int i = 0; i < (int)izraz.size(); i++){
        if(izraz[i] == ' '){
            continue;
        }else{
            if(izraz[i] == '('){
                operatori.push(izraz[i]);
            }else{
                if(bukvaLiE(izraz[i]) == true){
                    string rimskoChislo = "";

                    while(i < (int)izraz.size() && bukvaLiE(izraz[i]) == true){
                        rimskoChislo += izraz[i];
                        i++;
                    }

                    i--;
                    double istinskaStoinost = vDesetichna(rimskoChislo);

                    stoinosti.push(istinskaStoinost);
                }else{
                    if(izraz[i] == ')'){
                        while(operatori.empty() == false && operatori.top() != '('){
                            char oper = operatori.top();
                            operatori.pop();

                            double vtoraStoinost = stoinosti.top();
                            stoinosti.pop();

                            double parvaStoinost = 0;

                            if(!unarnaLiE(oper)){
                                parvaStoinost = stoinosti.top();
                                stoinosti.pop();
                            }

                            stoinosti.push(napraviOperaciqta(parvaStoinost, vtoraStoinost, oper));
                        }

                        if(operatori.empty() == false){
                            operatori.pop();
                        }
                    }else{
                        while(operatori.empty() == false &&
                                (prioritet(operatori.top()) > prioritet(izraz[i]) ||
                                (prioritet(operatori.top()) >= prioritet(izraz[i]) && kolkoAsociativno(operatori.top()) == 0)))
                        {
                            char oper = operatori.top();
                            operatori.pop();

                            double vtoraStoinost = stoinosti.top();
                            stoinosti.pop();

                            double parvaStoinost = 0;

                            if(!unarnaLiE(oper)){
                                parvaStoinost = stoinosti.top();
                                stoinosti.pop();
                            }

                            stoinosti.push(napraviOperaciqta(parvaStoinost, vtoraStoinost, oper));
                        }

                        operatori.push(izraz[i]);
                    }
                }
            }
        }
    }

    while(operatori.empty() == false){
        char oper = operatori.top();
        operatori.pop();

        cout<<oper<<endl;

        double vtoraStoinost = stoinosti.top();
        stoinosti.pop();

        double parvaStoinost = 0;

        if(!unarnaLiE(oper)){
            parvaStoinost = stoinosti.top();
            stoinosti.pop();
        }

        stoinosti.push(napraviOperaciqta(parvaStoinost, vtoraStoinost, oper));
    }

    return stoinosti.top();
}

struct DanniZaVarha{
    string stoinost;
    int lqvoDetenomer;
    int dqsnoDeteNomer;
};

vector<DanniZaVarha> varhove;

int daiNovVrah(string sasStoinost, int lqvoDete, int dqsnoDete){
    varhove.push_back({sasStoinost, lqvoDete, dqsnoDete});
    return varhove.size() - 1;
}

int napraviDarvo(string izraz){
    stack<int> stoinosti;
    stack<char> operatori;

    for(int i = 0; i < (int)izraz.size(); i++){
        if(izraz[i] == ' '){
            continue;
        }else{
            if(izraz[i] == '('){
                operatori.push(izraz[i]);
            }else{
                if(bukvaLiE(izraz[i]) == true){
                    string rimskoChislo = "";

                    while(i < (int)izraz.size() && bukvaLiE(izraz[i]) == true){
                        rimskoChislo += izraz[i];
                        i++;
                    }

                    i--;
                    double istinskaStoinost = vDesetichna(rimskoChislo);

                    string stringovaStoinost = to_string(istinskaStoinost);

                    int noviqVrah = daiNovVrah(stringovaStoinost, -1, -1);

                    stoinosti.push(noviqVrah);
                }else{
                    if(izraz[i] == ')'){
                        while(operatori.empty() == false && operatori.top() != '('){
                            char oper = operatori.top();
                            operatori.pop();

                            int vtoraStoinost = stoinosti.top();
                            stoinosti.pop();

                            int parvaStoinost = 0;

                            if(!unarnaLiE(oper)){
                                parvaStoinost = stoinosti.top();
                                stoinosti.pop();
                            }

                            string opr;
                            opr += oper;

                            int noviqVrah = daiNovVrah(opr, parvaStoinost, vtoraStoinost);

                            stoinosti.push(noviqVrah);
                        }

                        if(operatori.empty() == false){
                            operatori.pop();
                        }
                    }else{
                        while(operatori.empty() == false &&
                                (prioritet(operatori.top()) > prioritet(izraz[i]) ||
                                (prioritet(operatori.top()) >= prioritet(izraz[i]) && kolkoAsociativno(operatori.top()) == 0)))
                        {
                            char oper = operatori.top();
                            operatori.pop();

                            int vtoraStoinost = stoinosti.top();
                            stoinosti.pop();

                            int parvaStoinost = 0;

                            if(!unarnaLiE(oper)){
                                parvaStoinost = stoinosti.top();
                                stoinosti.pop();
                            }

                            string opr;
                            opr += oper;

                            int noviqVrah = daiNovVrah(opr, parvaStoinost, vtoraStoinost);

                            stoinosti.push(noviqVrah);
                        }

                        operatori.push(izraz[i]);
                    }
                }
            }
        }
    }

    while(operatori.empty() == false){
        char oper = operatori.top();
        operatori.pop();

        int vtoraStoinost = stoinosti.top();
        stoinosti.pop();

        int parvaStoinost = 0;

        if(!unarnaLiE(oper)){
            parvaStoinost = stoinosti.top();
            stoinosti.pop();
        }

        string opr;
        opr += oper;

        int noviqVrah = daiNovVrah(opr, parvaStoinost, vtoraStoinost);

        stoinosti.push(noviqVrah);
    }

   //////// cout<<stoinosti.size()<<endl;
    return stoinosti.top();
}

bool operandLiE(char simvol){
    if(simvol == '~' || simvol == '+' || simvol == '-' || simvol == '*' || simvol == '/' || simvol == '^'){
        return true;
    }
    return false;
}

double reshiSDarvo(int vrah){
    //cout<<"sega sum v nomer "<<vrah<<" koito e "<<varhove[vrah].stoinost;
    //cout<<" lqvo dete "<<varhove[vrah].lqvoDetenomer<<" dqsno dete "<<varhove[vrah].dqsnoDeteNomer<<endl;

    char tuka = varhove[vrah].stoinost[0];

    if(operandLiE(tuka) == false){
        return stod(varhove[vrah].stoinost);
    }else{
        return napraviOperaciqta(reshiSDarvo(varhove[vrah].lqvoDetenomer), reshiSDarvo(varhove[vrah].dqsnoDeteNomer), tuka);
    }
}

queue<string> prevrashtaneVOPZ(string izraz){
    queue<string> obratenPolskiZ;

    stack<char> operatori;

    for(int i = 0; i < (int)izraz.size(); i++){
        if(izraz[i] == ' '){
            continue;
        }

        if(bukvaLiE(izraz[i]) == true){
            string tuka;
            while(bukvaLiE(izraz[i]) == true){
                tuka += izraz[i];
                i++;
            }
            i--;

            obratenPolskiZ.push(tuka);
        }else{
            if(izraz[i] == '('){
                operatori.push(izraz[i]);
            }else{
                if(izraz[i] == ')'){
                    while(operatori.empty() == false && operatori.top() != '('){
                        char tukaOperator = operatori.top();
                        operatori.pop();
                        string tuka;
                        tuka += tukaOperator;
                        obratenPolskiZ.push(tuka);
                    }
                    operatori.pop();
                }else{
                    while(operatori.empty() == false && operatori.top() != '(' &&
                        (prioritet(operatori.top()) > prioritet(izraz[i]) ||
                        (prioritet(operatori.top()) >= prioritet(izraz[i]) && kolkoAsociativno(operatori.top()) == 0)))
                    {
                        char tukaOperator = operatori.top();
                        operatori.pop();
                        string tuka;
                        tuka += tukaOperator;
                        obratenPolskiZ.push(tuka);
                    }
                    operatori.push(izraz[i]);
                }
            }
        }
    }

    while(operatori.empty() == false){
        char tukaOperator = operatori.top();
        operatori.pop();
        string tuka;
        tuka += tukaOperator;
        obratenPolskiZ.push(tuka);
    }

    return obratenPolskiZ;
}

double otOPZVCHislo(queue<string> opz){
    stack<double> rezultati;

    while(opz.empty() == false){
        string naiOtpred = opz.front();
        opz.pop();

        if(bukvaLiE(naiOtpred[0]) == true){
            double chislo = vDesetichna(naiOtpred);

            rezultati.push(chislo);
        }else{
            char operaciq = naiOtpred[0];

            double vtoroChislo = rezultati.top();
            rezultati.pop();

            double parvoChislo = 0;

            if(!unarnaLiE(operaciq)){
                parvoChislo = rezultati.top();
                rezultati.pop();
            }

            double polucheno = napraviOperaciqta(parvoChislo, vtoroChislo, operaciq);

            rezultati.push(polucheno);
        }
    }

    return rezultati.top();
}

int main(){
    string rimskiIzraz;

    cin>>rimskiIzraz;

    for(int i = 0; i < (int)rimskiIzraz.size(); i++){
        if((i == 0 && rimskiIzraz[i] == '+') ||
           (rimskiIzraz[i] == '+' && rimskiIzraz[i-1] == '('))
        {
            rimskiIzraz[i] = ' ';
        }else{
            if((i == 0 && rimskiIzraz[i] == '-') ||
                (rimskiIzraz[i] == '-' && rimskiIzraz[i - 1] == '('))
            {
                rimskiIzraz[i] = '~';
            }
        }
    }

    int koren = napraviDarvo(rimskiIzraz);

    //queue<string> opz = prevrashtaneVOPZ(rimskiIzraz);

    //double otgovor = izchisliStoinostta(rimskiIzraz);
    //double otgovor = otOPZVCHislo(opz);
    double otgovor = reshiSDarvo(koren);

    cout<<otgovor<<endl;

    return 0;
}
