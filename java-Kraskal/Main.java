package ai205.svetashov;

public class Main {

    public static void main(String[] args) {
        Kruskal<String> kruskal = new Kruskal<>(8);
        kruskal.setData(new String[]{"0", "1", "2", "3", "4", "5", "6", "7"});
        // (Индекс начальной точки, индекс конечной точки, вес ребра)
        int[][] set = {
                {0, 2, 2},
                {0, 3, 1},
                {0, 5, 8},
                {1, 2, 1},
                {1, 3, 6},
                {1, 5, 3},
                {1, 6, 4},
                {2, 0, 2},
                {2, 1, 1},
                {2, 7, 4},
                {3, 0, 1},
                {3, 4, 4},
                {4, 3, 4},
                {4, 6, 7},
                {5, 0, 8},
                {5, 1, 3},
                {5, 7, 3},
                {6, 1, 4},
                {6, 4, 7},
                {6, 7, 5},
                {7, 2, 4},
                {7, 5, 3},
                {7, 6, 5}

        };

        for (int i = 0; i < set.length; i++) {
            kruskal.setMatrix(set[i][0], set[i][1], set[i][2]);
        }

        kruskal.setEdges();
        kruskal.KruskalTree();
    }
}




