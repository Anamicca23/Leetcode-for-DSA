class Robot {
    private final int width, height;
    private int x, y;
    private Direction dir;

    public Robot(final int width, final int height) {
        this.width = width;
        this.height = height;
        this.x = 0;
        this.y = 0;

        final Direction east = new Direction("East", 1, 0);
        final Direction north = new Direction("North", 0, 1);
        final Direction west = new Direction("West", -1, 0);
        final Direction south = new Direction("South", 0, -1);

        east.next = north;
        north.next = west;
        west.next = south;
        south.next = east;

        this.dir = east;
    }

    public void step(int num) {
        final int perimeter = 2 * (width + height) - 4;

        num = num % perimeter == 0 && num > 0 ? perimeter : num % perimeter;

        while (num > 0) {
            final int steps = stepsToEdge(dir.name, x, y, width, height);

            if (num <= steps) {
                x += dir.dx * num;
                y += dir.dy * num;
                num = 0;
            } else {
                x += dir.dx * steps;
                y += dir.dy * steps;

                num -= steps;
                dir = dir.next;
            }
        }
    }

    public int[] getPos() {
        return new int[] { x, y };
    }

    public String getDir() {
        return dir.name;
    }

    private int stepsToEdge(final String name, final int x, final int y, final int width, final int height) {
        switch (name) {
            case "East":
                return width - 1 - x;
            case "North":
                return height - 1 - y;
            case "West":
                return x;
            case "South":
                return y;
            default:
                return 0;
        }
    }

    private final class Direction {
        public final String name;
        public final int dx, dy;
        public Direction next;

        public Direction(final String name, final int dx, final int dy) {
            this.name = name;
            this.dx = dx;
            this.dy = dy;
        }
    }
}