
import matplotlib.pyplot as plt


def read_input(filename):
    with open(filename, "r") as file:
        data = file.read().split()

    n = int(data[0])

    points = []
    for i in range(n):
        x = float(data[1 + 2 * i])
        y = float(data[2 + 2 * i])
        points.append((x, y))

    return points


def read_groups(filename):
    groups = []

    with open(filename, "r") as file:
        lines = file.readlines()

    if not lines:
        raise ValueError(f"Файл {filename} пустой")

    n = int(lines[0])
    pos = 1

    while pos < len(lines):
        header = lines[pos].split()

        group_id = int(header[1])
        count = int(header[2])
        pos += 1

        points = []

        for _ in range(count):
            x, y = map(float, lines[pos].split())
            points.append((x, y))
            pos += 1

        groups.append((group_id, points))

    return groups


# Читаем исходные точки и группы
input_points = read_input("input.txt")
groups = read_groups("output.txt")

plt.figure(figsize=(10, 8))

# Рисуем все исходные точки серым цветом
x = [p[0] for p in input_points]
y = [p[1] for p in input_points]

plt.scatter(
    x, y,
    color="lightgray",
    s=25,
    label="Исходные точки",
    zorder=1
)

# Рисуем группы разными цветами
colors = plt.cm.tab20.colors

for group_id, points in groups:
    x = [p[0] for p in points]
    y = [p[1] for p in points]

    color = colors[group_id % len(colors)]

    plt.scatter(
        x, y,
        color=color,
        s=50,
        label=f"Группа {group_id}",
        zorder=2
    )

    # Соединяем точки внутри группы
    if len(points) >= 2:
        px = x + [x[0]]
        py = y + [y[0]]

        plt.plot(
            px, py,
            color=color,
            linewidth=1.5,
            zorder=3
        )

plt.title("Разбиение точек на группы")
plt.xlabel("X")
plt.ylabel("Y")

plt.grid(True)
plt.axis("equal")
plt.legend()
plt.show()
