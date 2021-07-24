#include<iostream>
#include<vector>
using namespace std;

int n;

struct CoordinatesInfo{
    int x;
    int y;
};

CoordinatesInfo whatCoordinateHasNum[1000010];

/*int atSoMany[1000][1000];

int numberOfMatryoshkas(int number, int lastTaken){
    if(number == 0){
        return 0;
    }

    if(atSoMany[number][lastTaken] > 0){
        return atSoMany[number][lastTaken];
    }

    int withoutTaking = numberOfMatryoshkas(number - 1, lastTaken);

    int taking = 0;

    if(whatCoordinateHasNum[number].x <= whatCoordinateHasNum[lastTaken].x &&
        whatCoordinateHasNum[number].y <= whatCoordinateHasNum[lastTaken].y)
    {
        taking = 1 + numberOfMatryoshkas(number - 1, number);
    }

    int toReturn = max(taking, withoutTaking);
    atSoMany[number][lastTaken] = toReturn;

    return toReturn;
}*/

int treeSize;

void findTreeSize(){
    int trSize = 1;

    while(true){
        if(trSize >= n){
            trSize *= 2;
            break;
        }

        trSize *= 2;
    }

    treeSize = trSize;
}

int getLeaf(int index){
    return index + treeSize/2;
}

int tree[2050][2050];

void update(int row, int col, int value){
    for(int rowIdx = getLeaf(row); rowIdx > 0; rowIdx /= 2){
        for(int colIdx = getLeaf(col); colIdx > 0; colIdx /= 2){
            tree[rowIdx][colIdx] = max(tree[rowIdx][colIdx], value);
        }
    }
}

int rowQuery(int row, int firstCol, int secondCol){
    int leftIdx = getLeaf(firstCol);
    int rightIdx = getLeaf(secondCol);

    int answer = max(tree[row][leftIdx], tree[row][rightIdx]);

    while(leftIdx + 1 < rightIdx){
        if(leftIdx % 2 == 0){
            answer = max(answer, tree[row][leftIdx + 1]);
        }
        if(rightIdx % 2 == 1){
            answer = max(answer, tree[row][rightIdx - 1]);
        }

        leftIdx /= 2;
        rightIdx /= 2;
    }

    return answer;
}

int query(int firstRow, int firstCol, int secondRow, int secondCol){
    int leftIdx = getLeaf(firstRow);
    int rightIdx = getLeaf(secondRow);

    int answer = max(rowQuery(leftIdx, firstCol, secondCol), rowQuery(rightIdx, firstCol, secondCol));

    while(leftIdx + 1 < rightIdx){
        if(leftIdx % 2 == 0){
            answer = max(answer, rowQuery(leftIdx + 1, firstCol, secondCol));
        }

        if(rightIdx % 2 == 1){
            answer = max(answer, rowQuery(rightIdx - 1, firstCol, secondCol));
        }

        leftIdx /= 2;
        rightIdx /= 2;
    }

    return answer;
}

/*struct DanniZaVatreshenVrah{
    int stoinost;
    int otKoiXIndexObhvashta;
    int doKoiXIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};

struct DanniZaVanshenVrah{
    vector<DanniZaVatreshenVrah> vatreshnoDarvo;
    int nomerNaKorenaVatreshnotoDarvo;
    int otKoiYIndexObhvashta;
    int doKoiYIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};

vector<DanniZaVanshenVrah> varhove;
int nomerNaKorena = -1;

int daiNovVanshenVrah(DanniZaVanshenVrah novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int daiNovVatreshenVrah(DanniZaVatreshenVrah novVrah, vector<DanniZaVatreshenVrah>& vatreshnoDarvo){
    vatreshnoDarvo.push_back(novVrah);
    return vatreshnoDarvo.size() - 1;
}

int napraviVatreshnoDarvo(int otXIndex, int doXIndex, vector<DanniZaVatreshenVrah>& vatreshnoDarvo){
    if(otXIndex == doXIndex){
        return daiNovVatreshenVrah({0, otXIndex, doXIndex, -1, -1}, vatreshnoDarvo);
    }

    int lqvoDeteNomer = napraviVatreshnoDarvo(otXIndex, (otXIndex + doXIndex)/2, vatreshnoDarvo);
    int dqsnoDeteNomer = napraviVatreshnoDarvo((otXIndex + doXIndex)/2 + 1, doXIndex, vatreshnoDarvo);

    return daiNovVatreshenVrah({0, otXIndex, doXIndex, lqvoDeteNomer, dqsnoDeteNomer}, vatreshnoDarvo);
}

int napraviDarvo(int otYIndex, int otXIndex, int doYIndex, int doXIndex){
    if(otYIndex == doYIndex){
        DanniZaVanshenVrah novVrah = {{ }, -1, otYIndex, doYIndex, -1, -1};
        novVrah.nomerNaKorenaVatreshnotoDarvo =
            napraviVatreshnoDarvo(otXIndex, doXIndex, novVrah.vatreshnoDarvo);

        return daiNovVanshenVrah(novVrah);
    }

    int lqvoDeteNomer = napraviDarvo(otYIndex, otXIndex, (otYIndex + doYIndex)/2, doXIndex);
    int dqsnoDeteNomer = napraviDarvo((otYIndex + doYIndex)/2 + 1, otXIndex, doYIndex, doXIndex);

    DanniZaVanshenVrah novVrah = {{ }, -1, otYIndex, doYIndex, lqvoDeteNomer, dqsnoDeteNomer};
    novVrah.nomerNaKorenaVatreshnotoDarvo =
        napraviVatreshnoDarvo(otXIndex, doXIndex, novVrah.vatreshnoDarvo);

    return daiNovVanshenVrah(novVrah);
}

void updateVatreshno(int korenNaPoddarvoNomer, int koiXIndex, int novaStoinost, vector<DanniZaVatreshenVrah>& vatreshnoDarvo){
    if(vatreshnoDarvo[korenNaPoddarvoNomer].otKoiXIndexObhvashta == koiXIndex &&
        vatreshnoDarvo[korenNaPoddarvoNomer].doKoiXIndexObhvashta == koiXIndex)
    {
        vatreshnoDarvo[korenNaPoddarvoNomer].stoinost = max(novaStoinost, vatreshnoDarvo[korenNaPoddarvoNomer].stoinost); ///
        return ;
    }

    if(koiXIndex < vatreshnoDarvo[korenNaPoddarvoNomer].otKoiXIndexObhvashta ||
        koiXIndex > vatreshnoDarvo[korenNaPoddarvoNomer].doKoiXIndexObhvashta)
    {
        return ;
    }

    if(vatreshnoDarvo[korenNaPoddarvoNomer].lqvoDeteVrahNomer != -1){
        updateVatreshno(vatreshnoDarvo[korenNaPoddarvoNomer].lqvoDeteVrahNomer, koiXIndex, novaStoinost, vatreshnoDarvo);

        if(vatreshnoDarvo[korenNaPoddarvoNomer].dqsnoDeteVrahNomer != -1){
            updateVatreshno(vatreshnoDarvo[korenNaPoddarvoNomer].dqsnoDeteVrahNomer, koiXIndex, novaStoinost, vatreshnoDarvo);

            vatreshnoDarvo[korenNaPoddarvoNomer].stoinost =
                max(vatreshnoDarvo[vatreshnoDarvo[korenNaPoddarvoNomer].lqvoDeteVrahNomer].stoinost,
                    vatreshnoDarvo[vatreshnoDarvo[korenNaPoddarvoNomer].dqsnoDeteVrahNomer].stoinost);
        }else{
            vatreshnoDarvo[korenNaPoddarvoNomer].stoinost =
                vatreshnoDarvo[vatreshnoDarvo[korenNaPoddarvoNomer].lqvoDeteVrahNomer].stoinost;
        }
    }
}

void update(int korenNaPoddarvoNomer, int koiYIndex, int koiXIndex, int novaStoinost){
    if(varhove[korenNaPoddarvoNomer].otKoiYIndexObhvashta == koiYIndex &&
        varhove[korenNaPoddarvoNomer].doKoiYIndexObhvashta == koiYIndex)
    {
        updateVatreshno(
            varhove[korenNaPoddarvoNomer].nomerNaKorenaVatreshnotoDarvo,
            koiXIndex,
            novaStoinost,
            varhove[korenNaPoddarvoNomer].vatreshnoDarvo);
        return ;
    }

    if(koiYIndex < varhove[korenNaPoddarvoNomer].otKoiYIndexObhvashta ||
        koiYIndex > varhove[korenNaPoddarvoNomer].doKoiYIndexObhvashta)
    {
        return ;
    }

    if(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer != -1){
        update(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer, koiYIndex, koiXIndex, novaStoinost);

        if(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer != -1){
            update(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer, koiYIndex, koiXIndex, novaStoinost);

            //varhove[korenNaPoddarvoNomer].stoinost =
                //max(varhove[varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer].stoinost,
                    //varhove[varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer].stoinost);

        }else{
            //varhove[korenNaPoddarvoNomer].stoinost = varhove[varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer].stoinost;
        }

        updateVatreshno(
            varhove[korenNaPoddarvoNomer].nomerNaKorenaVatreshnotoDarvo,
            koiXIndex,
            novaStoinost,
            varhove[korenNaPoddarvoNomer].vatreshnoDarvo);
    }
}

int queryVatreshno(int korenNaPoddarvoNomer, int otXIndex, int doXIndex, vector<DanniZaVatreshenVrah>& vatreshnoDarvo){
    if(otXIndex <= vatreshnoDarvo[korenNaPoddarvoNomer].otKoiXIndexObhvashta &&
        doXIndex >= vatreshnoDarvo[korenNaPoddarvoNomer].doKoiXIndexObhvashta)
    {
        return vatreshnoDarvo[korenNaPoddarvoNomer].stoinost;
    }

    if(otXIndex > vatreshnoDarvo[korenNaPoddarvoNomer].doKoiXIndexObhvashta ||
        doXIndex < vatreshnoDarvo[korenNaPoddarvoNomer].otKoiXIndexObhvashta)
    {
        return 0;
    }

    int zaTuk = 0;

    if(vatreshnoDarvo[korenNaPoddarvoNomer].lqvoDeteVrahNomer != -1){
        int otLqvoto =
            queryVatreshno(vatreshnoDarvo[korenNaPoddarvoNomer].lqvoDeteVrahNomer, otXIndex, doXIndex, vatreshnoDarvo);

        if(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer != -1){
            int otDqsnoto =
                queryVatreshno(vatreshnoDarvo[korenNaPoddarvoNomer].dqsnoDeteVrahNomer, otXIndex, doXIndex, vatreshnoDarvo);

            zaTuk = max(otLqvoto, otDqsnoto);
        }else{
            zaTuk = otLqvoto;
        }
    }

    return zaTuk;
}

int query(int korenNaPoddarvoNomer, int otYIndex, int otXIndex, int doYIndex, int doXIndex){
    if(otYIndex <= varhove[korenNaPoddarvoNomer].otKoiYIndexObhvashta &&
        doYIndex >= varhove[korenNaPoddarvoNomer].doKoiYIndexObhvashta)
    {
        return queryVatreshno(
                    varhove[korenNaPoddarvoNomer].nomerNaKorenaVatreshnotoDarvo,
                    otXIndex,
                    doXIndex,
                    varhove[korenNaPoddarvoNomer].vatreshnoDarvo);
    }

    if(otYIndex > varhove[korenNaPoddarvoNomer].doKoiYIndexObhvashta ||
        doYIndex < varhove[korenNaPoddarvoNomer].otKoiYIndexObhvashta)
    {
        return 0;
    }

    int zaTuk = 0;

    if(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer != -1){
        int otLqvoto =
            query(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer, otYIndex, otXIndex, doYIndex, doXIndex);

        if(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer != -1){
            int otDqsnoto =
                query(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer, otYIndex, otXIndex, doYIndex, doXIndex);

            zaTuk = max(otLqvoto, otDqsnoto);
        }else{
            zaTuk = otLqvoto;
        }
    }

    return zaTuk;
}*/

int withCycles(int forNumber){
    int answer = 0;

    for(int toNumber = 0; toNumber < forNumber; toNumber++){
        /*for(int i = 0; i < varhove.size(); i++){
            cout<<"y "<<varhove[i].otKoiYIndexObhvashta<<".."<<varhove[i].doKoiYIndexObhvashta<<":   ";
            for(auto j : varhove[i].vatreshnoDarvo){
                cout<<j.stoinost<<" ";
            }
            cout<<endl;
        }

        int here = 1 + query(nomerNaKorena, 0, 0, whatCoordinateHasNum[toNumber].y, whatCoordinateHasNum[toNumber].x);*/
        int here = 1 + query(0, 0, whatCoordinateHasNum[toNumber].y, whatCoordinateHasNum[toNumber].x);

        /*for(int i = 1; i < treeSize; i++){
            cout<<i<<":   ";
            if(i < treeSize/2){
                cout<<"deca "<<i*2<<" i "<<i*2 + 1<<"   ";
            }else{
                cout<<"listo no "<<i-4<<"   ";
            }
            for(int j = 1; j < treeSize; j++){
                cout<<tree[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"za "<<toNumber + 1<<" y "<<whatCoordinateHasNum[toNumber].y<<" x ";
        cout<<whatCoordinateHasNum[toNumber].x<<" davam "<<here - 1<<"("<<here<<")"<<endl;

        cout<<"slagam "<<here<<" na y "<<whatCoordinateHasNum[toNumber].y<<" x "<<whatCoordinateHasNum[toNumber].x<<endl;*/

        //update(nomerNaKorena, whatCoordinateHasNum[toNumber].y, whatCoordinateHasNum[toNumber].x, here);
        update(whatCoordinateHasNum[toNumber].y, whatCoordinateHasNum[toNumber].x, here);

        answer = max(answer, here);
    }

    return answer;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i = 0; i < n*n; i++){
        int here;
        cin>>here;
        here--;
        whatCoordinateHasNum[here] = {i%n, i/n};
    }

    findTreeSize();
    //nomerNaKorena = napraviDarvo(0, 0, n - 1, n - 1);

    //int answer = numberOfMatryoshkas(n*n, n*n + 1);
    int answer = withCycles(n*n);

    cout<<answer<<endl;

    return 0;
}
