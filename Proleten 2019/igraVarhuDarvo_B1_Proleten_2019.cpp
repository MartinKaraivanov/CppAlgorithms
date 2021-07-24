#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int broiVarhove;
int broiOcveteniLista;

vector<int> nasledniciNaTozi[5010];

int kolkoListaImaVPoddarvoSVrah[5010];

double priTolkova[5010][5010];

int broiListaVPoddarvoSVrah(int vrah){
    if(nasledniciNaTozi[vrah].size() == 0){
        kolkoListaImaVPoddarvoSVrah[vrah] = 1;
        return 1;
    }

    kolkoListaImaVPoddarvoSVrah[vrah] =
        broiListaVPoddarvoSVrah(nasledniciNaTozi[vrah][0]) + broiListaVPoddarvoSVrah(nasledniciNaTozi[vrah][1]);

    return kolkoListaImaVPoddarvoSVrah[vrah];
}

double shans(int nomerNaVrah, int broiCherveniVTovaPoddarvo){
    if(nasledniciNaTozi[nomerNaVrah].size() == 0){
        if(broiCherveniVTovaPoddarvo == 1){
            //cout<<nomerNaVrah<<" "<<broiCherveniVTovaPoddarvo<<" "<<1<<endl;
            return 1;
        }else{
            //cout<<nomerNaVrah<<" "<<broiCherveniVTovaPoddarvo<<" "<<0<<endl;
            return 0;
        }
    }

    if(broiCherveniVTovaPoddarvo == 0 || broiCherveniVTovaPoddarvo > kolkoListaImaVPoddarvoSVrah[nomerNaVrah]){
        //cout<<nomerNaVrah<<" "<<broiCherveniVTovaPoddarvo<<" "<<0<<endl;
        return 0;
    }

    if(priTolkova[nomerNaVrah][broiCherveniVTovaPoddarvo] > -1){
        return priTolkova[nomerNaVrah][broiCherveniVTovaPoddarvo];
    }

    double zaTuk = 0;

    if(nasledniciNaTozi[nomerNaVrah].size() == 1){
        zaTuk = shans(nasledniciNaTozi[nomerNaVrah][0], broiCherveniVTovaPoddarvo);
    }else{
        for(int broiZaLqvotoPoddarvo = 0; broiZaLqvotoPoddarvo <= broiCherveniVTovaPoddarvo; broiZaLqvotoPoddarvo++){
            double shansZaLqvotoDete = shans(nasledniciNaTozi[nomerNaVrah][0], broiZaLqvotoPoddarvo);
            double shansZaDqsnoto = shans(nasledniciNaTozi[nomerNaVrah][1], broiCherveniVTovaPoddarvo - broiZaLqvotoPoddarvo);

            double tekushto =
                max(
                    (2.0/3.0)*shansZaLqvotoDete + (1.0/3.0)*shansZaDqsnoto,
                    (1.0/3.0)*shansZaLqvotoDete + (2.0/3.0)*shansZaDqsnoto);
            zaTuk = max(zaTuk, tekushto);
        }
    }

    //cout<<nomerNaVrah<<" "<<broiCherveniVTovaPoddarvo<<" "<<zaTuk<<endl;
    priTolkova[nomerNaVrah][broiCherveniVTovaPoddarvo] = zaTuk;
    return zaTuk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove>>broiOcveteniLista;

    for(int i = 1; i <= broiVarhove; i++){
        int lqvNaslednik;
        cin>>lqvNaslednik;
        if(lqvNaslednik > 0){
            int desenNaslednik;
            cin>>desenNaslednik;
            nasledniciNaTozi[i].push_back(lqvNaslednik);
            nasledniciNaTozi[i].push_back(desenNaslednik);
        }else{
            continue;
        }
    }

    broiListaVPoddarvoSVrah(1);

    for(int i = 0; i <= broiVarhove; i++){
        for(int j = 0; j <= broiOcveteniLista; j++){
            priTolkova[i][j] = -1;
        }
    }

    double shansZaCherveno = shans(1, broiOcveteniLista);

    cout<<fixed<<setprecision(8)<<shansZaCherveno<<endl;

    return 0;
}
