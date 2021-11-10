package ai205.svetashov;

public class Prim {
    final int INF = 999999;
    private int[] selected;
    private int[][] G;
    private int min = 999999;
    private int x = 0;
    private int y = 0;

    public Prim(int[][] G) {
        this.G = new int[G.length][G.length];

        for(int i = 0; i < G.length; ++i) {
            for(int j = 0; j < G.length; ++j) {
                this.G[i][j] = G[i][j];
            }
        }

    }

    private void emptySelectedArray() {
        for(int i = 0; i < this.G.length; ++i) {
            this.selected[i] = 0;
        }

    }

    public void getResult() {
        this.selected = new int[this.G.length];
        this.emptySelectedArray();
        this.selected[0] = 1;
        int noEdge = 0;
        System.out.println("Edge : Weight");

        while(noEdge < this.G.length - 1) {
            this.min = 999999;
            this.x = 0;
            this.y = 0;

            for(int i = 0; i < this.G.length; ++i) {
                if (this.selected[i] == 1) {
                    for(int j = 0; j < this.G.length; ++j) {
                        if (this.selected[j] == 0 && this.min > this.G[i][j]) {
                            this.min = this.G[i][j];
                            this.x = i;
                            this.y = j;
                        }
                    }
                }
            }

            this.selected[this.y] = 1;
            System.out.println(this.x + " - " + this.y + " : " + this.min);
            ++noEdge;
        }

    }
}
