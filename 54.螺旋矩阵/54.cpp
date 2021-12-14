#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    //按照一圈来遍历
    // l-行，r-列
    int l = matrix.size(), r = matrix[0].size();
    int dx = 0, dy = 0; //某一圈的偏移量
    int offset = 1;
    int mid;
    if(l == r)
        mid = l / 2;
    int loop = min(l, r) / 2 + 1;
    vector<int> res(l * r);
    int count = 0;
    int i = 0, j = 0; //  i和j是matrix矩阵的下标,其中i是行，j是列

    while (loop--)
    {
        i = dx;
        j = dy;
        //第一层循环,从左到右，此时在某个向量内动
        // j < r - offset表示右闭，每次循环完成offset需要+2
        //第一次循环完成 j == 3;

        for (; j < r + dx - offset; ++j)
        {
            res[count++] = matrix[i][j];
        }

        //第二层循环，从上到下，此时在多个向量的尾部动
        //第一次循环完成，i == 2
        for (; i < l + dy - offset; ++i)
        {
            res[count++] = matrix[i][j];
        }

        //第三层循环，从 右到左，此时在某个向量内动
        for (; j > dx; --j)
        {
            res[count++] = matrix[i][j];
        }

        //第四层循环，从下到上，此时在多个向量头部动
        for (; i > dy; --i)
        {
            res[count++] = matrix[i][j];
        }
        ++dx;
        ++dy;
        offset += 2;
    }
    //处理矩阵为方阵，且矩阵行为奇数的情况
    if(l == r && r%2 == 1){
        res[count++] = matrix[i][j];
    }
    return res;
}


int main(){
    vector<vector<int>> matrix = {{1,2,3}};
    vector<int> res = spiralOrder(matrix);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
}