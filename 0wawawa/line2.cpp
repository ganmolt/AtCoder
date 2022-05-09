/*  1≤ n ≤ 10000
0.1≤ 標準重量、許容誤差、100 円あたりの重量、パッケージ重量 ≤20000.0
0.0≤ 荷台の重量 \le 500000.0≤500000.0
0.0 \le0.0≤ 標準重量 -− 許容誤差
1≤ 価格 \le 99999≤99999
1≤ 11 人の客が買う商品の個数 \le 100≤100
1≤ 会計情報の個数 \le 100≤100
*/
//ITEM_CODE.substr(0,2) --- 02量り売り
#include <iostream>
#include <string>
using namespace std;
//--------------------商品情報--------------------
int ITEMS_SIZE;
class Item{
    int ITEM_CODE;//商品コード
    double info[3];//入力情報　if( items[i].BARCODE.substr(0,2)=="02" ){//量り売り商品
    //量り売り商品なら  100円当たりの重量、パッケージ重量、許容誤差
    //そうでないなら    価格、標準重量、許容誤差
    //を表す
public:
    Item(){};
    friend void itemsInformationInput(Item[]);
    friend Item search(int, Item[]);
    friend void cashRegistar(Item[]);
};
void itemsInformationInput(Item[]);
//-----------------------------------------------

//-----------------レジ商品情報-------------------
int checkDigit(string);//チェックサム
void cashRegistar(Item[]);
//-----------------------------------------------
Item search(int itemCode, Item items[]){
    for(int i=0;i<ITEMS_SIZE;i++){
        if(items[i].ITEM_CODE==itemCode)return items[i];//一致したらreturn
    }
    Item E;E.ITEM_CODE=-1;return E;//-1を返す
}

int main(int argc, char *argv[]) {
    cin>>ITEMS_SIZE;
    Item items[ITEMS_SIZE];
    itemsInformationInput(items);//商品情報の入力
    cashRegistar(items);//レジ情報の入力
    return 0;
}
void itemsInformationInput(Item items[]){
    for(int i=0;i<ITEMS_SIZE;i++){
        cin>>items[i].ITEM_CODE;
        for(int infoI=0;infoI<3;infoI++)cin>>items[i].info[infoI];
    }
}

void cashRegistar(Item items[]){
    string barCode; int zTotalWeight=-1,totalWeight=-1;
    int totalPrice=0;
    bool _STAF_CAL_1=false,_STAF_CAL_2=false;
    bool ZSTAFCAL2=false;
    while(cin>>barCode){
        //開始終了
        if(barCode=="start"){continue;}
        if(barCode=="end"){
            //最後の判定
            double last;cin>>last;

            if(_STAF_CAL_1 and _STAF_CAL_2)cout<<"staff call: 1 2\n";
            else if(_STAF_CAL_1)cout<<"staff call: 1\n";
            else if(_STAF_CAL_2)cout<<"staff call: 2\n";
            else cout<<totalPrice<<"\n";
        }
        //-----------------------------------------
        cin>>totalWeight;
        int itemCode,price;double weight,error;

        if(checkDigit(barCode)==1){//チェックサム
            _STAF_CAL_1=true;
        }


        if(zTotalWeight==-1){//初回は気にしない
            zTotalWeight=totalWeight;
        }else{//二回目以降は　不正判定する
            if( barCode.substr(0,2)=="02" ){
                //量り売り商品なら
                itemCode=stoi(barCode.substr(2,5));
                Item PItem=search(itemCode,items);
                if(PItem.ITEM_CODE==-1){//商品が存在しなければ
                    _STAF_CAL_2=true;
                    continue;
                }
                //100円当たりの重量、パッケージ重量、許容誤差
                price=stoi(barCode.substr(7,5));
                weight=PItem.info[0]*price*1.0/100+PItem.info[1];
                error=PItem.info[2];
            }
            else{
                //量り売り商品でない
                itemCode=stoi(barCode.substr(0,12));
                Item PItem=search(itemCode,items);
                if(PItem.ITEM_CODE==-1){//商品が存在しなければ
                    _STAF_CAL_2=true;
                    continue;
                }
                //価格、標準重量、許容誤差
                price=PItem.info[0];
                weight=PItem.info[1];
                error=PItem.info[2];
            }
            totalPrice+=price;
            //直前の入力が正確(店員が呼ばれない)　かつ　（重量オーバー　or 　足りない）
            if( !ZSTAFCAL2 and
                (totalWeight-zTotalWeight<weight-error or
                weight+error<totalWeight-zTotalWeight)
            ){
                _STAF_CAL_1=true;
            }
        }
        //PItemのデータ取得完了
        ZSTAFCAL2=_STAF_CAL_2;//直前のデータの正確性
    }
}


int checkDigit(string barCode){
    if( stoi(barCode.substr(0,12))%10==(barCode[12]-'0') ){
        return 0;
    }else{
        return 1;
    }
}