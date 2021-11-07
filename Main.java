package ai205.svetashov;

import java.sql.SQLOutput;

public class Main {

    public static void main(String[] args) {
        final int INF = 999999;//infinity
        //final int V = 8;//number of vertecies
        int[][] G = { //adjency matrix
                {INF, INF, 2, 1, INF, 8, INF, INF},
                {INF, INF, 1, 6, INF, 3, 4, INF},
                {2, 1, INF, INF, INF, INF, INF, 4},
                {1, 6, INF, INF, 4, INF, INF, INF},
                {INF, INF, INF, 4, INF, INF, 7, INF},
                {8, 3, INF, INF, INF, INF, INF, 3},
                {INF, 4, INF, INF, 7, INF, INF, 5},
                {INF, INF, 4, INF, INF, 3, 5, INF}
        };

        Prim prim = new Prim(G);//we sand an array to constructor
        prim.getResult();
        //System.out.println(G.length);
    }
}
