package ai205.svetashov;

public class Main {

    public static void main(String[] args) {
        final int INF = 999999;
        int[][] G = {
                {INF, INF, 2, 1, INF, 8, INF, INF},
                {INF, INF, 1, 6, INF, 3, 4, INF},
                {2, 1, INF, INF, INF, INF, INF, 4},
                {1, 6, INF, INF, 4, INF, INF, INF},
                {INF, INF, INF, 4, INF, INF, 7, INF},
                {8, 3, INF, INF, INF, INF, INF, 3},
                {INF, 4, INF, INF, 7, INF, INF, 5},
                {INF, INF, 4, INF, INF, 3, 5, INF}
        };

        Prim prim = new Prim(G);
        prim.getResult();
    }
}
