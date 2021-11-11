public class Floyd {
    private int[][] G;
    private int[][] D;
    private int INF = 999999;


    public Floyd(int[][] G) {
        this.G = new int[G.length][G.length];//создаем наш двумерный массив
        for (int i = 0; i < G.length; ++i) {//переписываем в него исходную матрицу
            for (int j = 0; j < G.length; ++j) {
                this.G[i][j] = G[i][j];
            }
        }
    }

    public void getMatrix(int [][]Matrix) {
        for (int i = 0; i < Matrix.length; i++) {
            for (int j = 0; j < Matrix.length; j++) {
                if (i != j) {
                    System.out.printf("%d\t", Matrix[i][j]);
                } else System.out.printf("-   ");
            }
            System.out.printf("\n");
        }
    }

    private void createMatrixPath() { //создание и заполнение матрицы путей
        D = new int[G.length][G.length];
        for (int i = 0; i < G.length; i++)
            for (int j = 0; j < G.length; j++) {
                D[i][j] = j;
            }
    }

    public void getResult() {
        createMatrixPath();
        for (int k = 0; k < G.length; k++) {
            for (int i = 0; i < G.length; i++) {
                for (int j = 0; j < G.length; j++) {
                    if (i != j && G[i][j] > G[i][k] + G[k][j]) {
                        G[i][j] = G[i][k] + G[k][j];
                        D[i][j] = k;
                    }
                }
            }
        }

        System.out.println("Матрица расстояний:");
        getMatrix(G);
        System.out.println("Матрица путей:");
        getMatrix(D);
    }

}

