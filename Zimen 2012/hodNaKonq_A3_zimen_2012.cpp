#include<iostream>
using namespace std;

int maxY;
int maxX;
int k;
int t;

int numberOfCells;

long long matrix[111][111];

int getNumber(int x, int y){
    return y*maxX + x;
}

const long long mod = 10000;

void buildAdj(){

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int number = getNumber(x, y);



            if(x - 2 >= 0 && y - 1 >= 0){
                int thereNum = getNumber(x - 2, y - 1);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x - 2 >= 0 && y + 1 < maxY){
                int thereNum = getNumber(x - 2, y + 1);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x + 2 < maxX && y - 1 >= 0){
                int thereNum = getNumber(x + 2, y - 1);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x + 2 < maxX && y + 1 < maxY){
                int thereNum = getNumber(x + 2, y + 1);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x - 1 >= 0 && y - 2 >= 0){
                int thereNum = getNumber(x - 1, y - 2);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x + 1 < maxX && y - 2 >= 0){
                int thereNum = getNumber(x + 1, y - 2);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x - 1 >= 0 && y + 2 < maxY){
                int thereNum = getNumber(x - 1, y + 2);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }

            if(x + 1 < maxX && y + 2 < maxY){
                int thereNum = getNumber(x + 1, y + 2);

                matrix[number][thereNum] = 1;
                matrix[thereNum][number] = 1;
            }
        }
    }

}

void copyMatrix(long long (&from)[111][111], long long (&to)[111][111]){

    for(int i = 0; i < numberOfCells; i++){
        for(int j = 0; j < numberOfCells; j++){
            to[i][j] = from[i][j];
        }
    }
}

void multiplyMatrix(long long (&firstMatrix)[111][111], long long (&secondMatrix)[111][111]){
    long long resultMatrix[111][111];

    for(int i = 0; i < numberOfCells; i++){
        for(int j = 0; j < numberOfCells; j++){
            resultMatrix[i][j] = 0;

            for(int g = 0; g < numberOfCells; g++){
                resultMatrix[i][j] = (resultMatrix[i][j] + (firstMatrix[i][g] * secondMatrix[g][j])%mod)%mod;
            }
        }
    }

    copyMatrix(resultMatrix, firstMatrix);
}

void matrixGrading(long long (&matr)[111][111]){

    int power = k - 1;

    long long num[111][111];

    copyMatrix(matr, num);

    while(power > 0){
        if(power & 1 == 1){
            multiplyMatrix(matr, num);
        }

        multiplyMatrix(num, num);

        power >>= 1;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxY>>maxX>>k;

    numberOfCells = maxX*maxY;

    buildAdj();

    matrixGrading(matrix);

    cin>>t;

    for(int i = 0; i < t; i++){
        int from;
        int to;

        cin>>from>>to;

        cout<<matrix[from - 1][to - 1]<<endl;
    }

    return 0;
}
