#include <iostream>
#include <malloc.h>
using namespace std;

typedef class
{
	public:
	    int row,col;
	    float **matrix;//二维指针，目的是动态分配内存
} Matrix;

typedef class
{
	public:
        string name;
	    int length;
	    float *vector;
} Vector;

/*
** Function Name: ConstructorsMatrix()
** Input: Row Col
** Output: Constructed Martix
** Note: Generates a matrix with defined rows and columns
*/
Matrix ConstructorsMatrix()
{
    Matrix m;
    int row,col;
    cout << "Input the Rows and Columns Number:" << endl;
    cin >> row >> col;
    float **enterMatrix ;
    enterMatrix=(float**) malloc(row*sizeof(float*)) ;
    for(int i=0; i<row; i++)
        enterMatrix[i] = (float *)malloc(col * sizeof(float));
    cout<<"Input your matrix:"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> enterMatrix[i][j];
        }
    }
    m.col = col;
    m.row = row;
    m.matrix = enterMatrix;
    return m;
}


/*
** Function Name: ConstructorsVector()
** Input: Length
** Output: Constructed Vector
** Note: Generates a vector with defined length
*/
Vector ConstructorsVector()
{
    Vector v;
    int length;
    cout << "Input Name of the Vector:" << endl;
    cin >> v.name;
    cout << "Input Length of the Vector:" << endl;
    cin >> length;
    float *enterVector ;
    enterVector=(float*) malloc(length*sizeof(float*)) ;
    cout<<"Input Your Vector:"<<endl;
    for(int i=0; i<length; i++)
    {
        cin >> enterVector[i];
    }
    v.length = length;
    v.vector = enterVector;
    return v;
}

/*
** Function Name: ConstructorsIntermediatesMatrix()
** Input: Row Col
** Output: IntermediatesMatrix
** Note: Generates a Intermediates Matrix with defined rows and columns
*/
Matrix InitMatrix(int row,int col)
{
    Matrix m;
    float **matrix ;
    matrix=(float**) malloc(row*sizeof(float*)) ;
    for(int i=0; i<row; i++)
        matrix[i] = (float *)malloc(col * sizeof(float));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix[i][j] = 0;
        }
    }
    m.col = col;
    m.row = row;
    m.matrix = matrix;
    return m;
}

/*
** Function Name: ConstructorsIntermediatesVector()
** Input: Length number
** Output: IntermediatesMatrix
** Note: Generates a Intermediates Matrix with defined rows and columns
*/
Vector InitVector(int length, float Const)
{
    Vector v;
    float *vector;
    vector=(float*) malloc(length*sizeof(float*)) ;
    for(int i=0; i<length; i++)
    {
        vector[i] = Const;
    }
    v.length = length;
    v.vector = vector;
    return v;
}

/*
** Function Name: MatrixMatrixAdd()
** Input: Matrix_1 Matrix_2
** Output: Add results
** Note: Compute the matrix addition
*/
Matrix MatrixAdd(Matrix m1, Matrix m2)
{
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
        {
            m1.matrix[i][j] = m1.matrix[i][j] +m2.matrix[i][j];
        }
    }
    return m1;
}

/*
** Function Name: MatrixSub()
** Input: Matrix_1 Matrix_2
** Output: Sub results
** Note: Calculate the matrix difference
*/
Matrix MatrixSub(Matrix m1, Matrix m2)
{
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
        {
            m1.matrix[i][j] = m1.matrix[i][j] -m2.matrix[i][j];
        }
    }
    return m1;
}

/*
** Function Name: calRowCol()
** Input: Matrix M1,Matrix M2,int row,int col
** Output: Boolean
** Note: Judging the validity of MatrixMultiplication
*/
int calRowCol(Matrix M1,Matrix M2,int row,int col)//row为M1的行 col为m2的列
{
    int result = 0;
    int same = M1.col;
    for(int j=0; j<same; j++)
    {
        result+=M1.matrix[row][j]*M2.matrix[j][col];
    }

    return result;
}

/*
** Function Name: MatrixMul()
** Input: Matrix_1 Matrix_2
** Output: results Matrix
** Note: Compute matrix products
*/
Matrix MatrixMul(Matrix m1, Matrix m2)
{
    Matrix result = InitMatrix(m1.row,m2.col);
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m2.col; j++)
        {
            result.matrix[i][j] = calRowCol(m1,m2,i,j);
        }
    }
    return result;
}

/*
** Function Name: NumMatrixMul()
** Input: Matrix num
** Output: results Matrix
** Note: Calculate matrix numerical products
*/
Matrix NumMatrixMul(Matrix m, int num)
{
    cout<<"Numerical value:"<<num<<endl;
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
        {
            m.matrix[i][j] = m.matrix[i][j]*num;
        }
    }
    return m;
}

/*
** Function Name: MatrixNorm()
** Input: Matrix
** Output: norm
** Note: Calculate the numerical 1-norm of the matrix
*/
float MatrixNorm(Matrix m)
{
	float ColSum[m.col];
    float Norm;
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
        {
            ColSum[j] += m.matrix[i][j];	
        }
    }
    //int Norm = *max_element(ColSum,ColSum+m.col);
    Norm = ColSum[0];
    for (int j=0 ;  j < m.col-1 ; j++)
    {
        if (ColSum[j] <= ColSum[j+1])
        {
            Norm = ColSum[j+1];
        }
    }
    return Norm;
}

/*
** Function Name: MatrixTranspose()
** Input: Matrix
** Output: MatrxiT
** Note: Calculate the matrix transpose
*/
Matrix MatrixTranspose(Matrix m)
{
	Matrix result = InitMatrix(m.col,m.row);
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
        {
            result.matrix[j][i] = m.matrix[i][j];	
        }
    }
    return result;
}

/*
** Function Name: printMatri()
** Input: Matrix
** Output: none
** Note: Print matrix
*/
Matrix printMatrix(Matrix m)
{
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
        {
            cout << m.matrix[i][j] << "  ";
        }
        cout<<endl;
    }
}

/*
** Function Name: printVector()
** Input: Vector
** Output: none
** Note: Print vector
*/
Matrix printVector(Vector v)
{
    cout<< "The Vector "<< v.name <<" is:"<<endl;
    cout<< "[  ";
    for(int i=0; i<v.length; i++)
    {
        cout << v.vector[i] << "  ";
    }
    cout<< "]" <<endl;
}

int main()
{
    int num = 0;
    do
    {
        cout<<"*************************************\n";
        cout<<"*       1.Matrix MatrixAdd          *\n";
        cout<<"*       2.Matrix MatrixSub          *\n";
        cout<<"*       3.Matrix MatrixMul          *\n";
        cout<<"*       4.Matrix Num_MatrixMul      *\n";
        cout<<"*       5.Matrix Norm               *\n";
        cout<<"*       6.Matrix Transpose          *\n";
        cout<<"*       7.Vector Add                *\n";
        cout<<"*       8.Vector Sub                *\n";
        cout<<"*       9.Vector Mul                *\n";
        cout<<"*      10.Vector NumMul             *\n";
        cout<<"*************************************\n";
        cin>>num;
        if(1 == num|| 2 == num || 3 == num)
        {
            cout<<"Input Mat 1"<<endl;
            Matrix m1 = ConstructorsMatrix();
            cout<<"Input Mat 2"<<endl;
            Matrix m2 = ConstructorsMatrix();
            cout<<"The Mats are:"<<endl;
            printMatrix(m1);
            cout<<endl;
            printMatrix(m2);
            switch(num)
            {
            case 1:
            {
                if(m1.col!=m2.col || m1.row!=m2.row)
                {
                    cout<<"Dimensional Inconsistency!"<<endl;
                }
                else{
                    cout<<"Results:"<<endl;
                    printMatrix(MatrixAdd(m1,m2));
                }
                break;
            }
            case 2:
            {

                if(m1.col!=m2.col || m1.row!=m2.row)
                {
                    cout<<"Parameter error!"<<endl;
                }
                else{
                    cout<<"Results:"<<endl;
                    printMatrix(MatrixSub(m1,m2));
                }
                break;

            }
            case 3:
            {
                if(m1.col!=m2.row)
                {
                    cout<<"Parameter error!"<<endl;
                }
                else{
                    cout<<"Results:"<<endl;
                    printMatrix(MatrixMul(m1,m2));
                }
                break;
            }
            default:
                break;
            }
        }
        else if(4 == num)
        {
            int number = 1;
            cout<<"Input Mat:"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"Input MatrixMultiplier:"<<endl;
            cin>>number;
            cout<<"Mat is:"<<endl;
            printMatrix(m);
            cout<<"Resutls:"<<endl;
            cout<<number<<endl;
            printMatrix(NumMatrixMul(m,number));
        }
        else if(5 == num)
        {
            float Norm;
            cout<<"-------Input Mat--------"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"------------------------"<<endl;
            //cout<<"Mat is:"<<endl;
            //printMatrix(m);
            cout<<"Norm is:"<<endl;
            Norm = MatrixNorm(m);
            cout << Norm << endl;
        }
        else if(6 == num)
        {
            float Norm;
            cout<<"-------Input Mat--------"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"------------------------"<<endl;
            //cout<<"Mat is:"<<endl;
            //printMatrix(m);
            cout<<"Transpose is:"<<endl;
            printMatrix(MatrixTranspose(m));
        }
        else if(7 == num)  // Vector Add
        {
            float Norm;
            cout<<"-------Input Mat--------"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"------------------------"<<endl;
            //cout<<"Mat is:"<<endl;
            //printMatrix(m);
            cout<<"Transpose is:"<<endl;
            printMatrix(MatrixTranspose(m));
        }
        else if(8 == num)  // Vector Sub
        {
            float Norm;
            cout<<"-------Input Mat--------"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"------------------------"<<endl;
            //cout<<"Mat is:"<<endl;
            //printMatrix(m);
            cout<<"Transpose is:"<<endl;
            printMatrix(MatrixTranspose(m));
        }
        else if(9 == num)  // Vector Sub
        {
            float Norm;
            cout<<"-------Input Mat--------"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"------------------------"<<endl;
            //cout<<"Mat is:"<<endl;
            //printMatrix(m);
            cout<<"Transpose is:"<<endl;
            printMatrix(MatrixTranspose(m));
        }
        else if(10 == num) // Vector Sub
        {
            float Norm;
            cout<<"-------Input Mat--------"<<endl;
            Matrix m = ConstructorsMatrix();
            cout<<"------------------------"<<endl;
            //cout<<"Mat is:"<<endl;
            //printMatrix(m);
            cout<<"Transpose is:"<<endl;
            printMatrix(MatrixTranspose(m));
        }

    }
    while(1 == num|| 2 == num || 3 == num ||4 == num ||5 == num ||6 == num);
    return 0;
}
