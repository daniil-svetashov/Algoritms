package ai205.svetashov;

public class Kraskal {
    private int[] size;//an array of sizes of vertexes
    private boolean[] visited;//an array of visited vertexes
    private int[][] G;
    //private int
    final int INF = 999999;

    //private int V;

    public Kraskal(int[][] G) {
        this.G = new int[G.length][G.length];
        for (int i = 0; i < G.length; i++) {
            {
                for (int j = 0; j < G.length; j++) {
                    this.G[i][j] = G[i][j];
                }
            }
        }
        visited = new boolean[G.length];
        size = new int[G.length];
    }

    public void Result(int startVertex, int finishVertex) {
        for (int i = 0; i < G.length; i++) {
            visited[i] = false;
            size[i] = INF;
        }
        int minElement;
        int minElementIndex;
        size[startVertex] = 0;//because we start from 0

        do {
            minElement = INF;
            minElementIndex = INF;
            for (int i = 0; i < G.length; i++) {
                if (visited[i] == false && size[i] < minElement) {
                    minElement = size[i];
                    minElementIndex = i;
                }
            }

            if (minElementIndex != INF) {
                for (int j = 0; j < G.length; j++) {
                    if (G[minElementIndex][j] != INF) {
                        size[j] = Math.min(size[j], size[minElementIndex] + G[minElementIndex][j]);
                    }
                }
                visited[minElementIndex] = true;
            }

        } while (minElementIndex < INF);

        System.out.println("The shortest path from start vertex ( " + startVertex + " ) to all other vertices:");
        for (int i = 0; i < G.length; i++) {
            System.out.printf("To vertex: %d is %d\n", i, size[i]);
        }


        //We restore a path
        System.out.println("\nThe path from start vertex ( " + startVertex + " ) to finish vertex ( " + finishVertex + " )");

        int[] selected = new int[G.length];
        int weight = size[finishVertex];//the size of the finish vertex
        int k = 1;//index of a previous vertex
        selected[0] = finishVertex;//We will restore our path from the end, so first vertex will be the last one

        while (finishVertex != startVertex)//until we didn`t reach out start vertex
        {
            for (int i = 0; i < G.length; i++) {
                if (weight - G[i][finishVertex] == size[i]) {
                    weight = size[i];
                    finishVertex = i;
                    selected[k] = i;
                    k++;
                }
            }
        }

        for (int i = k - 1; i >= 0; i--) {
            System.out.printf("%d ", selected[i]);
        }
    }
}
