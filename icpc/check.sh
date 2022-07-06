#!/bin/bash

# X = A,B,C,..., I = 1,2,3,4 って読み替えて

#--------------------------------------------------
#
#必要なファイル
#./a.out, ./judgedata/X/XI, ./judgedata/X/XI.ans, ./in, ./sample_ans
#
#作られるファイル
#./out_check, ./res_diff_check
#
#使い方
#./check.sh     (サンプル)
#./check.sh A   (ジャッジデータ)
#../check.sh    (同じディレクトリじゃなくてもいける)
#
#--------------------------------------------------




#ジャッジデータを実行(./a.out < ./judgedata/X/XI.ans > out_check)して、XI.ansと確認(diff)

#実行結果 > out_check、比較結果 > res_diff_check
if [ "$1" = "" ]; then
    # サンプルの実行確認(要 : in, sample_ans)
    #echo "sample"

    ../problem.exe < in > out_check && diff out_check sample_ans > res_diff_check

    if [ -s res_diff_check ]; then
        #間違いがある(diff_outに出力がある)ならWAを出力して、終了
        echo "sample WA"
        exit 0
    fi
else
    #１つずつファイルを実行する
    for i in `seq 4`
    do
        #テストケース番号出力
        echo $i

        # 入力した問題の実行確認
        #echo "judgedata"
        ../problem.exe < ./judgedata/$1/$1$i > out_check && diff out_check ./judgedata/$1/$1$i.ans > res_diff_check
        
        if [ -s res_diff_check ]; then
            #間違いがある(diff_outに出力がある)ならWAを出力して、終了
            echo $1$i" WA"
            exit 0
        fi
    done
fi

#間違いが１つも無ければACを出力
echo "AC"
exit 0
