#include<iostream>
#include<stack>
using namespace std;

long long priTolkova[100][100];

long long broiKombinacii(long long kolkoElementa, long long otKolko){
    if(otKolko == kolkoElementa || kolkoElementa == 0){
        return 1;
    }

    if((kolkoElementa < 0) || (otKolko <= 0)|| (kolkoElementa > otKolko)){
        return 0;
    }

    if(kolkoElementa == 1){
        return otKolko;
    }

    if(priTolkova[kolkoElementa][otKolko] > 0){
        return priTolkova[kolkoElementa][otKolko];
    }

    long long bezNego = broiKombinacii(kolkoElementa, otKolko - 1);
    long long sasNego = broiKombinacii(kolkoElementa - 1, otKolko - 1);

    priTolkova[kolkoElementa][otKolko] = sasNego + bezNego;
    return sasNego+bezNego;
}




/////// todo: mislia che problema stava kogato ni dadat broiNuli = 0




long long broiSTolkovaNuliDo(long long krainoChislo, long long broiNuli){
    //cout<<"do chisloto "<<krainoChislo<<": "<<endl;

    stack<long long> s;

    while(krainoChislo > 0){
        s.push(krainoChislo & 1);

        krainoChislo >>= 1;
    }

    long long broiche = 0;

    long long broiCifriNaChisloto = s.size();

    //cout<<"ot "<<broiNuli + 1<<" do "<<broiCifriNaChisloto - 1<<endl;

    for(long long d = broiNuli + 1; d < broiCifriNaChisloto; d++){
        //cout<<"puskam za "<<broiNuli<<" ot "<<d - 1<<" i poluchavam "<<broiKombinacii(broiNuli, d - 1)<<endl;
        broiche += broiKombinacii(broiNuli, d - 1);
    }

    long long broiMinatiNuli = 0;
    s.pop();

    while(s.empty() == false){
        long long tekushtaCifra = s.top();
        s.pop();

        //cout<<tekushtaCifra<<": "<<endl;

        if(tekushtaCifra == 1){
            //cout<<"sega puskam za "<<broiNuli - broiMinatiNuli - 1<<" ot "<<s.size() + 1<<" i "<<false<<" i poluchavam ";
            //cout<<broiKombinacii(broiNuli - broiMinatiNuli - 1, s.size())<<endl;

            broiche += broiKombinacii(broiNuli - broiMinatiNuli - 1, s.size());
        }else{
            broiMinatiNuli++;
        }
    }

    return broiche;
}

int main(){
    long long otKade;
    long long doKade;

    long long broiNuli;


    cin>>otKade>>doKade>>broiNuli;

    //cout<<broiSTolkovaNuliDo(otKade, broiNuli)<<" "<<broiSTolkovaNuliDo(doKade + 1, broiNuli)<<endl;

    long long otgovor = broiSTolkovaNuliDo(doKade + 1, broiNuli) - broiSTolkovaNuliDo(otKade, broiNuli);

    cout<<otgovor<<endl;

    return 0;
}
