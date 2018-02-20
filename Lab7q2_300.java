class Lab7q2_300 {
    public static void main(String args[]){
        int [][] inputA = {{5,6,7},{4,8,9}};
        int [][] inputB = {{6,4},{5,7},{1,1}};
        MyData matA = new MyData(inputA);
        MyData matB = new MyData(inputB);
        int matC_r = matA.data.length;
        int matC_c = matB.data[0].length;
        MyData matC = new MyData(matC_r,matC_c);

        Child[][] ChildThread = new Child[matC_r][matC_c];

         for(int i = 0 ; i < matC_r;i++){
               for(int j = 0 ; j < matC_c;j++){
                ChildThread[i][j] = new Child(i,j,matA,matB,matC); 
                ChildThread[i][j].start(); 
                try{
                    ChildThread[i][j].join(); 
                 } catch(InterruptedException ie){ }
               }
         }
     
        matC.show();
    }
}
class MyData {
    int [][] data;
    MyData(int r, int c){
        data = new int[r][c];
    }
    MyData(int [][] a){
        data = a;
    }
    
    void show() {
        for (int i = 0; i < data.length;i++){
            for (int j = 0; j < data[0].length;j++){
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }
}
class Child extends Thread  {
    int row , col;
    MyData datA,datB,datC;
    Child(int procssing_row,int procssing_col,MyData a, MyData b, MyData c){
        row = procssing_row; col = procssing_col;
        datA = a ; datB =b; datC =c;
    }
    public void run(){
        for(int k = 0; k < datA.data[0].length; ++k){
         datC.data[row][col] += datA.data[row][k]  * datB.data[k][col];
        }
    }
}
